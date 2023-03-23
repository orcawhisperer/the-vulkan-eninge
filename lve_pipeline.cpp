#include "lve_pipeline.hpp"

// std
#include <fstream>
#include <stdexcept>
#include <iostream>
namespace lve
{

    LvePipeline::LvePipeline(LveDevice &device, const std::string vertFilePth, const std::string fragFilePth, const PipelineConfigInfo &configInfo) : lveDevice(device)
    {
        createGraphicsPipeline(vertFilePth, fragFilePth, configInfo);
    }

    std::vector<char> LvePipeline::readFile(const std::string &filePath)
    {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};

        if (!file.is_open())
        {
            throw std::runtime_error("failed to open file: " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string vertFilePth, const std::string fragFilePth, const PipelineConfigInfo &configInfo)
    {
        auto vertCode = readFile(vertFilePth);
        auto fragCode = readFile(fragFilePth);

        std::cout << "Vertex Shader File Size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader File Size: " << fragCode.size() << std::endl;
    }

    void LvePipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule)
    {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

        if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create shader module!");
        }
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }

}