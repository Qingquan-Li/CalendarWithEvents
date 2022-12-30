#ifndef Event_h
#define Event_h
#include <iostream>

using namespace std;

class Event{
private:
    long eventNo; //takes the month, day, year, hour and minute variables and stores in format of YYYYMMDDhhdd
    int month, day, year, hour, minute;
    char details[100]; //event details stored in a c-string
    static const char monthName[12][10]; //stores name of the month
    static const char dayName[7][10]; //stores name of the week
    
public:
    
    Event();

  
    long getEventNo();
    int getMonth();
    int getDay();
    int getYear();
    int getHour();
    int getMinute();
    char * getDetails();

    
    void setEventNo();
    void setEventNo(long );
    void setMonth(int );
    void setDay(int );
    void setYear(int );
    void setHour(int );
    void setMinute(int );
    void setDetails(); //function asks for input inline
    
    //tests whether the year for the Event is itself a leap year
    bool isLeap();
    
    //calculates the number of leap years preceding the year stored in an Event object
    int numLeapYears();
    
    //returns name of the weekday
    const char * nameOfDay();

    //return name of the month
    const char * nameOfMonth();

    
};



#endif

