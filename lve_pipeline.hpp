#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve
{

    struct PipelineConfigInfo
    {
        /* data */
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class LvePipeline
    {
    private:
        static std::vector<char> readFile(const std::string &filePath);

        void createGraphicsPipeline(const std::string vertFilePth, const std::string fragFilePth, const PipelineConfigInfo &configInfo);

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        LveDevice &lveDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;

    public:
        LvePipeline(LveDevice &device, const std::string vertFilePth, const std::string fragFilePth, const PipelineConfigInfo &configInfo);

        ~LvePipeline();

        LvePipeline(const LvePipeline &) = delete;
        void operator=(const LvePipeline &) = delete;

        void bind(VkCommandBuffer commandBuffer);
        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
    };

}