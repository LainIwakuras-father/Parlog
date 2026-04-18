#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// 2513826 PrimFSM.cpp(37) FSM: Sg.SIP.UA id: 2621; > St: 0 NUL Pr: 38418:21 SIP_UA_OPTIONS_REQ ()
// 2026-01-12 09:06:03.384

struct timestamp
{    
    struct Date
    {
        int day;
        int month;
        int year;
    } date;

    struct Time
    {
        int hh;
        int mm;
        int ss;
        int ms;
    } time;

    timestamp(std::stringstream& ss)
    {
        ss >> *this;  
    }

    friend std::stringstream& operator>>(std::stringstream& ss, timestamp& ts)
    {
        // Untrached wrong time
        char sep;
        
        ss >> ts.date.year >> sep >> ts.date.month >> sep >> ts.date.day
           >> ts.time.hh >> sep >> ts.time.mm >> sep >> ts.time.ss >> sep >> ts.time.ms;
        
        return ss;
    }

    friend std::ostream& operator<<(std::ostream& os, const timestamp& ts)
    {
        os << ts.date.year << "-" 
           << (ts.date.month < 10 ? "0" : "") << ts.date.month << "-"
           << (ts.date.day < 10 ? "0" : "") << ts.date.day << " "
           << (ts.time.hh < 10 ? "0" : "") << ts.time.hh << ":"
           << (ts.time.mm < 10 ? "0" : "") << ts.time.mm << ":"
           << (ts.time.ss < 10 ? "0" : "") << ts.time.ss << "."
           << (ts.time.ms < 100 ? (ts.time.ms < 10 ? "00" : "0") : "") << ts.time.ms;
        
        return os;
    }
};

int main()
{
    std::string raw = "2026-01-12 09:06:03.384 2026-02-11 19:06:03.084";
    
    // One stream for all parcing
    std::stringstream ss(raw);
    timestamp ts1(ss);
    std::cout << "ts1: " << ts1 << std::endl;

    timestamp ts2(ss);
    std::cout << "ts2: " << ts2 << std::endl;

    return 0;
}