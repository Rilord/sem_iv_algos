#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include "hermite.hpp"
#include "spline.hpp"
#include "imfilebrowser.h"
#include "data.hpp"
#include <iostream>
#include <string>

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

    std::vector<dot> result;

    std::vector<dot> spline_plot_data;
    std::vector<dot> newton_plot_data;
    std::vector<dot> real_values;

    float arg = 0.0;


    for (auto x = 0.0; x < 8.0; x += 0.1) {
        real_values.push_back(dot {x, x * x }); 
    }

    auto spline_method = Spline(real_values);

    for (auto x = 0.0; x < 8.0; x += 0.1) {
        spline_plot_data.push_back(spline_method.solve(x));
    }

    vector<double> x_args;
    vector<double> y_args;
    for (auto &a: real_values) {
        x_args.push_back(a.x);
    }

    for (auto &a: real_values) {
        y_args.push_back(a.y);
    }
    auto poly = newtonPolynom(3, y_args, x_args, arg).build();

    for (auto x = 0.0; x < 8.0; x += 0.1) {
        newton_plot_data.push_back(dot { x, newtonPolynom(3, y_args, x_args, x).build() });
    }

    ImVec2 *a = new ImVec2[real_values.size()];
    ImVec2 *b = new ImVec2[real_values.size()];
    ImVec2 *c = new ImVec2[real_values.size()];

    for (auto i = 0; i < spline_plot_data.size(); i++) {
        a[i].x = real_values[i].x;
        a[i].y = real_values[i].y;
    }

    for (auto i = 0; i < spline_plot_data.size(); i++) {
        b[i].x = spline_plot_data[i].x;
        b[i].y = spline_plot_data[i].y;
    }

    for (auto i = 0; i < spline_plot_data.size(); i++) {
        c[i].x = newton_plot_data[i].x;
        c[i].y = newton_plot_data[i].y;
    }


    while (!glfwWindowShouldClose(window))
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();


        ImGui::NewFrame();

        ImGui::Begin("Lab");



        ImGui::InputFloat("Enter x value:", &arg);


        if (ImGui::Button("Result:"))
        {
            auto data = readDots(selectedFile);
            auto res = Spline(data).solve(arg);
            vector<double> x;
            vector<double> y;
            for (auto &a: data) {
                x.push_back(a.x);
            }

            for (auto &a: data) {
                y.push_back(a.y);
            }
            auto poly = newtonPolynom(3, y, x, arg).build();

            result.push_back(res);
            result.push_back(dot { arg, poly});
        }

        if (ImPlot::BeginPlot("Plot")) 
        {

            ImPlot::PlotLine("Real (y = x * x)", a, real_values.size());
            ImPlot::PlotLine("Spline (y = x * x)", b, spline_plot_data.size());
            ImPlot::PlotLine("Newton (y = x * x)", c, newton_plot_data.size());

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

        if (ImGui::CollapsingHeader("Result")) {
            ImGui::BeginChild("Scrolling");
            for (int n = 0; n < result.size(); n++) {
                if (n % 2)
                    ImGui::Text("Newton = (%f, %f)", result[n].x, result[n].y);
                else 
                    ImGui::Text("Spline = (%f, %f)", result[n].x, result[n].y);
            }
            ImGui::EndChild();
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

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
