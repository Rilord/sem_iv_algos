#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "hermite.hpp"
#include "implot.h"
#include "spline.hpp"
#include "imfilebrowser.h"
#include "data.hpp"
#include <iostream>
#include <string>
#include "mean_square.hpp"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char *argv[])
{
 
    /* GLFW */

    if (!glfwInit())
    { 
        std::cout << "[FAIL] can't init glfw.\n";
        return -1;
    }
    else
    {
        std::cout << "[SUCCESS] glfw was inited.\n";
    }
#ifdef __APPLE__
    const char *glsl_version = "#version 150";
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    float highDPIscaleFactor = 1.0;
#endif

#ifdef __linux__
    const char *glsl_version = "#version 330";
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    float highDPIscaleFactor = 1.0;
#endif

    GLFWwindow* window;

    window = glfwCreateWindow(800, 600, "lab1", NULL, NULL);


    if (!window)
    {
        std::cout << "[FAIL] can't create window.\n";
        glfwTerminate();
        return -1;
    }

    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);

    /* GLFW */

    /* =================== */
    /* GLEW */
    if(GLEW_OK != glewInit()) 
    {
        std::cout << "[FAIL] can't init glew.\n";
        return -1;
    }
    else
    {
        std::cout << "[SUCCESS] glew was initialized.\n";
    }
    /* GLEW */

    /* IMGUI */
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    io.Fonts->AddFontDefault();
    ImVec4 clear_color = ImVec4(0.3f, 0.55f, 0.60f, 1.00f);


    ImGui::FileBrowser fileDialog;

    /* IMGUI */

    /* IMPLOT */
    ImPlot::CreateContext();
    /* IMPLOT */

    std::string selectedFile;


    float arg = 0.0;


    bool dots_loaded = 0;
    bool solved = 0;

    vector<vector<Dot>> approximations;

    vector<float> px, py;

    vector<Dot> loaded_dots;
    vector<float> data_x, data_y;


    while (!glfwWindowShouldClose(window))
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();


        ImGui::NewFrame();

        ImGui::Begin("Lab");






        ImGui::InputFloat("Enter x value:", &arg);
        if (ImGui::Button("Solve")) {
            approximations.clear();
            loaded_dots = readDots(selectedFile);
            data_x.clear();
            data_y.clear();

            for (auto i: loaded_dots) {
                data_x.push_back(i.x);
                data_y.push_back(i.y);
            }

            for (int degree = 1; degree < 9; degree += 2) {
                auto s = slae();
                auto approx = Approximation();
                s.build(loaded_dots, degree);

                auto solution = s.solve();

                approx.get_coeffs(solution);

                approximations.push_back(approx.build(loaded_dots));

            }

            solved = 1;
        }

        if (ImPlot::BeginPlot("Stat")) {
            int degs[4] = { 1, 3, 5, 7 };
            int i = 0;

            for (auto & a: approximations) {
                px.clear();
                py.clear();
                for (auto j: a) {
                    px.push_back(j.x);
                    py.push_back(j.y);
                }
                ImPlot::PlotLine(std::to_string(degs[i]).c_str(), px.data(), py.data(), py.size());
                i++;
            }

            ImPlot::PlotScatter("Data", data_x.data(), data_y.data(), data_x.size());
            ImPlot::EndPlot();
        }





        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open..", "Ctrl+O"))
                {
                    fileDialog.Open();

                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }


        ImGui::End();

        fileDialog.Display();

        if(fileDialog.HasSelected())
        {
            selectedFile = fileDialog.GetSelected();
            fileDialog.ClearSelected();
        }
        ImGui::Render();


        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    glDisableVertexAttribArray(0);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    ImPlot::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
