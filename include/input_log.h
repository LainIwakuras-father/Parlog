#ifndef INPUT_LOG_H
#define INPUT_LOG_H

#include <string>

namespace Input
{
    struct Data {
        unsigned year = 0;
        unsigned month = 0;
        unsigned day = 0;
    };

    struct Time {
        unsigned hour = 0;
        unsigned minute = 0;
        unsigned second = 0;
        unsigned millisec = 0;
    };

    class Timestamp {
    public:
        Timestamp();
        Timestamp(unsigned year, unsigned month, unsigned day,
                  unsigned hour, unsigned minute, unsigned second, 
                  unsigned millisec);
        
        int setData(unsigned year, unsigned month, unsigned day);
        int setTime(unsigned hour, unsigned minute,
                    unsigned second, unsigned millisec);
        Data getData() const { return data; }
        Time getTime() const { return time; }
    
    private:
        Data data;
        Time time;
    };

    struct InputMess {
        int prFirst = 0;
        int prSecond = 0;
        std::string mess = "";   
    };

    struct LogicName {
        std::string name = "default";
        int id = 0;
        std::string state = "0";
    };

    class InputLog {
    public:
        InputLog();
        
        Timestamp getTimestamp() const { return timestamp; }
        std::string getFileLocation() const { return file_location; }
        std::string getJournal() const { return journal; }
        LogicName getLogicName() const { return logicName; }
        int getLogicID() const { return logicID; }
        std::string getCurrentState() const { return currentState; }
        InputMess getInputMess() const { return inputMess; }
        std::string getAddInfo() const { return addInfo; }

    private:
        Timestamp timestamp;
        std::string log_entry;
        std::string file_location;
        std::string journal;
        LogicName logicName;
        int logicID;
        std::string currentState;
        InputMess inputMess;
        std::string addInfo;
        
        friend class InputLogBuilder;
    };

   
    class InputLogBuilder {
    public:
        InputLogBuilder() = default;
        
        InputLogBuilder& Data(unsigned year, unsigned month, unsigned day) {
            inputLog_.timestamp.setData(year, month, day);
            return *this;
        }
        
        InputLogBuilder& Time(unsigned hour, unsigned minute,
                             unsigned second, unsigned millisec) {
            inputLog_.timestamp.setTime(hour, minute, second, millisec);
            return *this;
        }
        
        InputLogBuilder& FileLocation(const std::string& location) {
            inputLog_.file_location = location;
            return *this;
        }
        
        InputLogBuilder& Journal(const std::string& journal) {
            inputLog_.journal = journal;
            return *this;
        }
        
        InputLogBuilder& LogicName(const std::string& name) {
            inputLog_.logicName.name = name;
            return *this;
        }
        
        InputLogBuilder& LogicID(int id) {
            inputLog_.logicID = id;
            return *this;
        }
        
        InputLogBuilder& CurrentState(const std::string& state) {
            inputLog_.currentState = state;
            return *this;
        }
        
        InputLogBuilder& InputMess(int prFirst, int prSecond, std::string mess) {
            inputLog_.inputMess.prFirst = prFirst;
			inputLog_.inputMess.prSecond = prSecond;
			inputLog_.inputMess.mess = mess;
            return *this;
        }
        
        InputLogBuilder& AddInfo(const std::string& info) {
            inputLog_.addInfo = info;
            return *this;
        }
        
        InputLog build() const {
            return inputLog_;
        }
        
    private:
        InputLog inputLog_;
    };
}

#endif // INPUT_LOG_H


// Input::InputLog log = Input::InputLogBuilder()
//         .Data(2026, 4, 10)                              // Дата
//         .Time(11, 27, 45, 988)                          // Время
//         .FileLocation("PrimFSM.cpp(37)")                // Файл и строка
//         .Journal("FSM")                                 // Журнал
//         .LogicName("SubscribeLogic.0.61bf91b400000002") // Имя логики
//         .LogicID(0)                                     // ID логики
//         .CurrentState("INIT_WAIT_STORAGE_CONF")         // Состояние
//         .InputMess(38405, 11, "SIP_TR_SUBSCRIBE_IND")   // ✅ PrFirst, PrSecond, mess
//         .AddInfo("(Event: test Expires: 120)")          // Доп инфа
//         .build();  