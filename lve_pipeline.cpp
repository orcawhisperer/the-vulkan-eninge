#include "lve_pipeline.hpp"

// std
#include <fstream>
#include <stdexcept>
#include <iostream>
namespace lve
{

    LvePipeline::LvePipeline(const std::string vertFilePth, const std::string fragFilePth)
    {
        createGraphicsPipeline(vertFilePth, fragFilePth);
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

    void LvePipeline::createGraphicsPipeline(const std::string vertFilePth, const std::string fragFilePth)
    {
        auto vertCode = readFile(vertFilePth);
        auto fragCode = readFile(fragFilePth);

        std::cout << "Vertex Shader File Size: " << vertCode.size() << std::endl;
        std::cout << "Fragment Shader File Size: " << fragCode.size() << std::endl;
    }

}