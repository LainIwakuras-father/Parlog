#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

2513826 PrimFSM.cpp(37) FSM: Sg.SIP.UA id: 2621; > St: 0 NUL Pr: 38418:21 SIP_UA_OPTIONS_REQ ()
2026-01-12 09:06:03.384
  
struct timestamp
{
    timestamp(const std::sstream& ss)
    {

    }
    
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
}

struct LogFormat
{
    std::string timestamp;
}


int main()
{
    // one stringstream for fill all structures
    return 0;
}