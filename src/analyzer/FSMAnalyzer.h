#pragma once
#include "../parser/LogParser.h"
#include <unordered_map>
#include <string>

struct LogicState {
    std::time_t last_change_time;
    std::string current_state;
    std::string last_message;
    std::string logic_name;
};

class StateMachineAnalyzer {
public:
    explicit StateMachineAnalyzer(const std::vector<LogEntry>& events);

    // Возвращает вектор строк CSV (каждая строка – одна "подвисшая" логика)
    std::vector<std::string> generateCSV(std::time_t global_last_ts) const;

private:
    std::unordered_map<int, LogicState> logic_map_;
};