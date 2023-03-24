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
        VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        LveWindow(const LveWindow &) = delete;
        LveWindow &operator=(const LveWindow &) = delete;
    };

}