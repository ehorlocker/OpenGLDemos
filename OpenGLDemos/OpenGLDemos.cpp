#include "OpenGLDemos.h"

#include "glad/glad.h"

#include "GLFW/glfw3.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include "MainMenu.h"
#include "ClearColor.h"
#include "Log.h"
#include "OpenGLDebug.h"

int main()
{
	GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "OpenGLDemos", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    GLCore::Log::Init();

    glfwSwapInterval(1);

    /* Call after making valid OpenGL context */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_ERROR("Failed to initialize GLAD");
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    {  
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
        ImGui::StyleColorsDark();

        // my laptop has a high dpi so we need to set the scale higher
        io.FontGlobalScale = 3.0f;

        scene::Scene* currentScene = nullptr;
        scene::MainMenu* mainMenu = new scene::MainMenu(currentScene);
        currentScene = mainMenu;

        mainMenu->RegisterTest<scene::ClearColor>("Clear Color");

        GLCore::EnableGLDebugging();

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            currentScene->OnUpdate(0.0f);
            currentScene->OnRender();

            currentScene->OnImGuiRender();
            
            if (currentScene != mainMenu) {
                if (ImGui::Button("<-")) {
                    delete currentScene;
                    currentScene = mainMenu;
                }
            }

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
         
            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    
    }
    glfwTerminate();

    return 0;

	return 0;
}
