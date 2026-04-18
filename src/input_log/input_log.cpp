#include "input_log.h"
#include <sstream>
#include <iomanip>

namespace Input {

Timestamp::Timestamp() {}

Timestamp::Timestamp(unsigned year, unsigned month, unsigned day,
                     unsigned hour, unsigned minute, unsigned second,
                     unsigned millisec) {
    setData(year, month, day);
    setTime(hour, minute, second, millisec);
}

int Timestamp::setData(unsigned year, unsigned month, unsigned day) {
    data.year = year;
    data.month = month;
    data.day = day;
    return 0;
}

int Timestamp::setTime(unsigned hour, unsigned minute, unsigned second, unsigned millisec) {
    time.hour = hour;
    time.minute = minute;
    time.second = second;
    time.millisec = millisec;
    return 0;
}



} // namespace Input