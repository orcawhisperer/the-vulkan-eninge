#pragma once

#include <string>
#include <vector>

namespace lve
{
    class LvePipeline
    {
    private:
        static std::vector<char> readFile(const std::string &filePath);

        void createGraphicsPipeline(const std::string vertFilePth, const std::string fragFilePth);

    public:
        LvePipeline(const std::string vertFilePth, const std::string fragFilePth);
    };

}