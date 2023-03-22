#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace lve
{
    class LveWindow
    {
    private:
        /* data */
        GLFWwindow *window;
        const int width;
        const int height;
        std::string windowName;

        void initWindow();

    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow();
        bool shouldClose() { return glfwWindowShouldClose(window); }

        LveWindow(const LveWindow &) = delete;
        LveWindow &operator=(const LveWindow &) = delete;
    };

}