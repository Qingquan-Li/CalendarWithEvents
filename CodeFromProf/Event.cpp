#include "Event.h"
#include <iostream>
using namespace std;
Event::Event()
{
    month = 1;
    day = 1;
    year = 1753;
    hour = 0;
    minute = 0;
    eventNo = 175301010000;
    
}

long Event::getEventNo()
{
    return eventNo;
}
int Event::getMonth()
{
    return month;
}

int Event::getDay()
{
    return day;
}

int Event::getYear()
{
    return year;
}

int Event::getHour()
{
    return hour;
}

int Event::getMinute()
{
    return minute;
}

char * Event::getDetails()
{
    return details;
}

//updates eventNo using member variables
//Not used in main(), but could be useful in future
void Event::setEventNo()
{
    eventNo = 0;
    eventNo += static_cast<long>(year) * 100000000;
    eventNo += static_cast<long>(month) * 1000000;
    eventNo += static_cast<long>(day) * 10000;
    eventNo += static_cast<long>(hour) * 100;
    eventNo += static_cast<long>(minute);
}

//updates eventNo using an argument. This also updates all other member variables for the date, except details[]
void Event::setEventNo(long e)
{
    eventNo = e;
    long temp;
    year = static_cast<int>(eventNo / 100000000);
    temp = eventNo % 100000000;
    month = static_cast<int>(temp / 1000000);
    temp = temp %  1000000;
    day = static_cast<int>(temp / 10000);
    temp = temp %   10000;
    hour = static_cast<int>(temp / 100);
    minute = temp % 100;
}



void Event::setMonth(int m)
{
    while(m > 12 || m < 1)
    {
        cout << "\tPlease enter a correct month number: ";
        cin >> m;
    }
    
    month = m;
    setEventNo(); //calling setEventNo to update eventNo with the new month value. Used
                  //Used similarly with remaining member variables

}

void Event::setDay(int d)
{
    if(month == 1)
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
       
    }
    else if(month == 2)
    {
        if(!isLeap())
        {
            while(d > 28 || d < 1)
            {
                cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
                cin >> d;
            }
        }
        else{
            while(d > 29 || d < 1)
            {
                cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
                cin >> d;
            }
        }
        
            day = d;
            
    }
    else if(month == 3)
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
       
    }
    
    else if(month == 4)
    {
        while(d > 30 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
        
    }
    else if(month == 5)
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
        
    }
    else if(month == 6)
    {
        while(d > 30 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
        
    }
    else if(month == 7)
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
        
    }
    else if(month == 8)
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
        
    }
    else if(month == 9)
    {
        while(d > 30 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
        
    }
    else if(month == 10)
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
    }
    else if(month == 11)
    {
        while(d > 30 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
    }
    else
    {
        while(d > 31 || d < 1)
        {
            cout << "\tPlease enter a correct day value for " << monthName[month - 1] << ": ";
            cin >> d;
        }
        
        day = d;
    }
    
    setEventNo();
    
}
void Event::setYear(int y)
{
    while(y < 1753)
    {
        cout << "\tPlease enter a year after 1752: ";
        cin >> y;
    }
    
    year = y;
    
    setEventNo();
}

void Event::setHour(int h)
{
    while(h > 23 || h < 0)
    {
        cout << "\tPlease enter a correct hour: ";
        cin >> h;
    }
    
    hour = h;
    setEventNo();
}

void Event::setMinute(int m)
{
    while(m > 59 || m < 0)
    {
        cout << "\tPlease enter a correct minute: ";
        cin >> m;
    }
    
    minute = m;
    setEventNo();
}


void Event::setDetails()
{
    cout << "\n\tEnter event detail information: ";
    cin.ignore();
    cin.getline(details, 100);
}


//tests whether the value entered for year is a leap year
//A leap year is divisible by 4, but not by 100, except in cases where it is divisible by 400
bool Event::isLeap()
{
    bool leap = false;
    if(year % 4 == 0)
    {
        leap = true;
    }
    if(year % 100 == 0)
    {
        leap = false;
    }
    if(year % 400 == 0)
    {
        leap = true;
    }
    
    return leap;
}
 

//numLeapYears calculates number of leap years between 1753 and the current year.
//Since we are calculating from January 1st, 1753, we subtract the leap years that occur before 1753
 int Event::numLeapYears()
 {
     int numLeap = 0, numLeap1753 = 0;
     numLeap += (year - 1) / 4;
     numLeap -= (year - 1) / 100;
     numLeap += (year - 1) / 400;
     numLeap1753 += 1753 / 4;
     numLeap1753 -= 1753 / 100;
     numLeap1753 += 1753 / 400;
     return numLeap - numLeap1753;

 }

/*
 nameOfDay uses isLeap and numLeapYears.
 It determines the name of the day of the week by calculating the total number of days since
 January 1st, 1753. That total accounts for the number of extra leap days that occur between 1/1/1753
 and the Event object's date.
 
 */
 const char * Event::nameOfDay()
 {
     int extraLeapDays = 0; //holds no. of leap days from past years
     int weekIndex;
     int dayOfTheYear = 0; //holds the day of the year out of 365 days
     int mmDD, mm, dd;// holds month and day of the month
     
     mmDD = (eventNo /10000) % 10000;
     mm = mmDD / 100;
     dd = mmDD % 100;
     
     if(mm == 1)
     {
         dayOfTheYear = dd;
     }
     else if(mm == 2)
     {
         dayOfTheYear = dd + 31;
     }
     else if(mm == 3)
     {
         dayOfTheYear = dd + 59;
     }
     else if(mm == 4)
     {
         dayOfTheYear = dd + 90;
     }
     else if(mm == 5)
     {
         dayOfTheYear = dd + 120;
     }
     else if(mm == 6)
     {
         dayOfTheYear = dd + 151;
     }
     else if(mm == 7)
     {
         dayOfTheYear = dd + 181;
     }
     else if(mm == 8)
     {
         dayOfTheYear = dd + 212;
     }
     else if(mm == 9)
     {
         dayOfTheYear = dd + 243;
     }
     else if(mm == 10)
     {
         dayOfTheYear = dd + 273;
     }
     else if(mm == 11)
     {
         dayOfTheYear = dd + 304;
     }
     else
     {
         dayOfTheYear = dd + 334;
     }
     
     int currentYear = static_cast<int>(eventNo / 100000000);
     //If it's a leap year and the month is March or later, increment dayOfTheYear
     //The extra day in a leap year doesn't occur until February 29th
     if(mm >= 3 && isLeap())
     {
         dayOfTheYear++;
     }
     extraLeapDays = numLeapYears();
     
     //Note to self: tried before using - 1 at end, but it turned index
     //into -1 whenever 7 evenly divided into the calculation.
     //The total number of days since 1/1/1753 is the sum of all the years since multiplied by the number of days in a year,
     //together with the number of days that have elapsed since the start of the year in the Event object, plus all the leap days
     //that occurred between 1-1-1753 and the Event date. Taking the modulo of the sum produces the index for the day of the week,
     //with 0 representing Sunday, 1 Monday, etc.
     weekIndex = (((currentYear - 1753) * 365 + dayOfTheYear + extraLeapDays) % 7);
     
     return dayName[weekIndex];

 }

const char * Event::nameOfMonth()
{
    //Calculations done to get the month part of YYYYMMDDhhmm
    int mm = ((eventNo /10000) % 10000) / 100;
    
    return monthName[mm -1];
}



const char Event::monthName[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const char Event::dayName[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

