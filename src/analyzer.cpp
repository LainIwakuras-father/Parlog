#include "analyzer_log.h"
#include <algorithm>
#include <string>

namespace Analyzer
{
    long long toMillis(const Input::Timestamp& ts) {
        auto time = ts.getTime();
        return (time.hour * 3600LL + time.minute * 60LL + time.second) * 1000LL 
               + time.millisec;
    }

    bool compareLogs(const Input::InputLog& a, const Input::InputLog& b) {
        return toMillis(a.getTimestamp()) < toMillis(b.getTimestamp());
    }

    bool isFinalState(const std::string& state) {
        return (state == "Terminated" || state == "Completed");
    }

    OutputLogs analyze(std::vector<Input::InputLog>& logs) {
        OutputLogs result;
        result.isRight = true;
        result.outputLog = nullptr;

        if (logs.empty()) return result;

        std::sort(logs.begin(), logs.end(), compareLogs);

        //  ПОСЛЕДНИЙ
        const Input::InputLog& lastLog = logs.back();
        std::string currentState = lastLog.getCurrentState();

        // ПРОВЕРКА 1: Смотрим на состояние
        if (isFinalState(currentState)) {
            // состояние финальное  всё хорошо
            return result; 
        }

   

        // Если лог всего один, а состояние не финальное — считаем, что зависло
        if (logs.size() < 2) {
             result.isRight = false;
             result.outputLog = new OutputLog();
             result.outputLog->logicID = lastLog.getLogicID();
             result.outputLog->lastState = currentState;
             return result;
        }

        // ПРЕДПОСЛЕДНИЙ 
        const Input::InputLog& preLastLog = logs[logs.size() - 2];

        long long tLast = toMillis(lastLog.getTimestamp());
        long long tPre = toMillis(preLastLog.getTimestamp());
        long long delta = tLast - tPre;

        const long long HANG_THRESHOLD = 32000; 

        if (delta > HANG_THRESHOLD) {
            // ЗАВИСЛО!
            result.isRight = false;
            
        }

        return result;
    }
}