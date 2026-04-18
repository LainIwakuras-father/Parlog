#ifndef ANALYZER_LOG_H
#define ANALYZER_LOG_H

#include "input_log.h"
#include <string>
#include <vector>

namespace Analyzer
{

    struct OutputLog {
        ....
    };


    struct OutputLogs {
        bool isRight = true;
        OutputLog* outputLog = nullptr; 
    };

    OutputLogs analyze(std::vector<Input::InputLog>& logs);
}

#endif