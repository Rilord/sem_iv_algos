#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include "hermite.hpp"
#include "imfilebrowser.h"
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

    std::vector<result> res;

    int polynomDimensions[2] = { 0, 0 };

    float arg[2] = { 0.f, 0.f };

    interpolation task(1, 1, dot { 0, 0 });

    while (!glfwWindowShouldClose(window))
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();


        ImGui::NewFrame();

        ImGui::Begin("Lab");


        ImGui::InputInt2("Polynom Size: nx, ny", polynomDimensions);

        ImGui::InputFloat2("x, y: ", arg);

        if (ImGui::Button("Interpolate"))
        {
            task.setPolynomSize(polynomDimensions[0], polynomDimensions[1]);
            task.setArg(dot { arg[0], arg[1] });
            task.loadFile(selectedFile);
            result tmp;
            tmp.nx = polynomDimensions[0], tmp.ny = polynomDimensions[1];
            tmp.x = arg[0], tmp.y = arg[1];
            tmp.z = task.getPolynomial();

            res.push_back(tmp);

        }


        if (ImGui::Button("Clear table"))
        {
            res.clear();
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

        ImGui::BeginChild("Scrolling");
        for (int n = 0; n < res.size(); n++) {
            ImGui::Text("nx: %d, ny: %d, answer = (%f, %f, %f)", 
                    res[n].nx, res[n].ny, 
                    res[n].x, res[n].y, res[n].z);
        }
        ImGui::EndChild();

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
