// In this project, you need to create a calendar application that allows users to
// add events, view daily and monthly events, update events, and delete events.

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

// Global constant variables:
const int DETAILS_SIZE = 100; // Array size
const string MONTH_NAME_ARRAY[12] = {"January", "February", "March", "April", "May", "June",
                                     "July", "August", "September", "October", "November", "December"};
const string DAY_OF_WEEK_NAME_ARRAY[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Event {
private:
    long eventNo; // event number
    int month;
    int day;
    int year;
    int hour;
    int minute;
    char details[DETAILS_SIZE]; // event details
public:
    // Default constructor.
    // Set the date and time of the event to midnight, 01/01/1753.
    Event() {
        month = 1;
        day = 1;
        year = 1753;
        hour = 0;
        minute = 0;
    }
    /**
     * Accessors for the member variables.
     */
    int getMonth() const {
        return month;
    }
    int getDay() const {
        return day;
    }
    int getYear() const {
        return year;
    }
    int getHour() const {
        return hour;
    }
    int getMinute() const {
        return minute;
    }
    char* getDetails() {
        return details;
    }
    long getEventNo() const {
        return eventNo;
    };
    /**
     * Mutators for the member variables.
     * Make sure the values stored in the member variables are valid.
     * For example, month in the range [1 – 12], hour in [0 – 23], minute in [0 – 59] ...
     */
    void setMonth(int newMonth) {
        if (newMonth >= 1 && newMonth <= 12)
            month = newMonth;
    }
    void setDay(int newDay) {
        if (newDay >=1 && newDay <=31)
            day = newDay;
    }
    void setYear(int newYear) {
        if (newYear >= 1753)
            year = newYear;
    }
    void setHour(int newHour) {
        if (newHour >= 0 && newHour <=23)
            hour = newHour;
    }
    void setMinute(int newMinute) {
        if (newMinute >= 0 && newMinute <= 59)
            minute = newMinute;
    }
    void setDetails(const char* newDetails) {
        // Copy the newDetails to the details array.
        strcpy(details, newDetails);
    }
    /**
     * A member function that updates the eventNo member variable.
     * The function generates a long integer value for the event using the following pattern: YYYYMMDDhhmm
     * For example, 202209261720 for the event occurring on 09/26/2022 at 5:20pm.
     */
    void setEventNo(int yearValue, int monthValue, int dayValue, int hourValue, int minuteValue) {
        long eventId = 0;
        eventId += static_cast<long>(yearValue) * 100000000; // 2022 * 10^8 = 202200000000
        eventId += static_cast<long>(monthValue) * 1000000;  // 09   * 10^6 =     09000000
        eventId += static_cast<long>(dayValue) * 10000;      // 26   * 10^4 =       260000
        eventId += static_cast<long>(hourValue) * 100;       // 17   * 10^2 =         17
        eventId += static_cast<long>(minuteValue);           // 20   * 10^0 =           20
        eventNo = eventId;
    }
};


// Function prototypes:
bool isLeapYear(int);
string getMonthName(int);
string getDayOfWeek(int, int, int);
void displayCalendar(int, int);
void addEvent();
void viewAllEvents();
void viewDailyEvents(int, int, int);
void viewMonthlyEvents(int, int);
void updateEvent(long);
void deleteEvent(long);


int main() {
    char ch;
    int month;
    int day;
    int year;
    long eventNo;
    do {
        system("clear"); // For Windows OS use `system("cls");`
        cout << "\n\n============ MENU ============";
        cout << "\n\t0.View All Events";
        cout << "\n\t1.Add New Event";
        cout << "\n\t2.View Daily Events";
        cout << "\n\t3.View Monthly Events";
        cout << "\n\t4.Update Event";
        cout << "\n\t5.Delete Events";
        cout << "\n\t6.Display Monthly Calendar";
        cout << "\n\t7.Exit";
        cout << "\n\nEnter your Choice (0 - 7): ";
        cin >> ch;
        system("clear"); // For Windows OS use `system("cls");`
        switch(ch){
            case '0':
                viewAllEvents();
                break;
            case '1':
                addEvent();
                break;
            case '2':
                cout << "\nView Daily Events\n";
                cout << "=================\n\n";
                cout << "\tMonth: ";
                cin >> month;
                cout << "\tDay: ";
                cin >> day;
                cout << "\tYear: ";
                cin >> year;
                viewDailyEvents(month, day, year);
                break;
            case '3':
                cout << "\nView Monthly Events\n";
                cout << "===================\n\n";
                cout << "\tMonth: ";
                cin >> month;
                cout << "\tYear: ";
                cin >> year;
                viewMonthlyEvents(month, year);
                break;
            case '4':
                cout << "\nUpdate Event\n";
                cout << "============\n\n";
                cout << "\tEnter Event Number: ";
                cin >> eventNo;
                updateEvent(eventNo);
                break;
            case '5':
                cout << "\nDelete Event\n";
                cout << "============\n\n";
                cout << "\tEnter Event Number: ";
                cin >> eventNo;
                deleteEvent(eventNo);
                break;
            case '6':
                cout << "\tMonth: ";
                cin >> month;
                cout << "\tYear: ";
                cin >> year;
                cout << endl;
                displayCalendar(month, year);
                cout << "\nPress Enter key to return to the menu. ";
                cin.ignore();
                cin.get();
                break;
            case '7':
                cout << "Exiting... Thank you!";
                exit(0);
        }
    } while (ch!='7');

    return 0;
}


/**
 * A function that tests whether the year of an event is leap.
 * Leap Years are any year that can be exactly divided by 4 (such as 2016, 2020, 2024, etc)
 * Except if it can be exactly divided by 100, then it isn't (such as 2100, 2200, 2300, etc)
 * Except if it can be exactly divided by 400, then it is (such as 2000, 2400, 2800, etc)
 */
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/**
 * A function that returns the month name of an event.
 * For example, January, February...
 */
string getMonthName(int month) {
    return MONTH_NAME_ARRAY[month - 1];
}

/**
 * A function that returns the day name of an event.
 * For example, Sunday, Monday...
 * Note that the day for January 1 of the year 1753 was a Monday.
 * Calculate the day of the week (0 = Sunday, 1 = Monday, etc.)
 */
string getDayOfWeek(int year, int month, int day) {
    int daysInMonthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    int dayOfWeekNumber;
    string dayOfWeek;
    for (int y = 1753; y < year; y++) {
        days += 365;
        if (isLeapYear(y))
            days++;
    }
    for (int m = 1; m < month; m++) {
        days += daysInMonthArray[m-1];
        if (m == 2 && isLeapYear(year))
            days++;
    }
    // days += day - 1;
    days += day;
    dayOfWeekNumber = days % 7;
    return DAY_OF_WEEK_NAME_ARRAY[dayOfWeekNumber];
}

/**
 * A function that prints monthly calendars.
 */
void displayCalendar(int month, int year) {
    // Array of integers to store the number of days in each month
    int daysInMonthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If the year is a leap year, February has 29 days
    // if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    if (isLeapYear(year))
        daysInMonthArray[1] = 29;

    // Print the month and year at the top of the calendar.
    cout << setw(11) << MONTH_NAME_ARRAY[month-1] << " " << year << endl;

    // Print the day names at the top of the calendar
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    // Calculate the day of the week for the first day of the month
    // January 1, 1753 was a Monday, so use that as a reference point.
    // int dayOfWeekNumber = 4; // Counting from 01/01/1770, January 1, 1970 was a Thursday
    // for (int i = 1970; i < year; i++) {
    int dayOfWeekNumber = 1;
    for (int i = 1753; i < year; i++) {
        dayOfWeekNumber = (dayOfWeekNumber + 365 + (isLeapYear(i) ? 1 : 0)) % 7;
    }
    for (int i = 0; i < month-1; i++) {
        dayOfWeekNumber = (dayOfWeekNumber + daysInMonthArray[i]) % 7;
    }

    // Print the appropriate number of spaces at the beginning of the calendar.
    for (int i = 0; i < dayOfWeekNumber; i++) {
        cout << "   ";
    }

    // Print the days of the month.
    for (int i = 1; i <= daysInMonthArray[month-1]; i++) {
        cout << setw(2) << i << " ";
        dayOfWeekNumber = (dayOfWeekNumber + 1) % 7;
        if (dayOfWeekNumber == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// Todo: To validate the user input (month: 1-12, day: 1-31, year: >=1753).
void addEvent() {
    Event event;
    int month;
    int day;
    int year;
    int hour;
    int minute;
    char details[DETAILS_SIZE]; // event details

    cout << "\nAdding New Event" << endl;
    cout << "================" << endl;
    cout << "\tMonth: ";
    cin >> month;
    event.setMonth(month);
    cout << "\tDay: ";
    cin >> day;
    event.setDay(day);
    cout << "\tYear: ";
    cin >> year;
    event.setYear(year);
    cout << "\tHour: ";
    cin >> hour;
    event.setHour(hour);
    cout << "\tMinute: ";
    cin >> minute;
    event.setMinute(minute);
    event.setEventNo(year, month, day, hour, minute);
    cout << "\tDetails: ";
    // Tell the cin object to skip characters (e.g., `\n`) in the keyboard buffer.
    cin.ignore();
    cin.getline(details, DETAILS_SIZE);
    event.setDetails(details);

    ofstream outputFile;
    outputFile.open("events.dat", ios::binary|ios::app);
    outputFile.write(reinterpret_cast<char *> (&event), sizeof(event));
    outputFile.close();

    cout << "\nNew event added (Event# " << event.getEventNo() << ").";
    cout << "\nPress Enter key to return to the menu. ";
    cin.ignore();
    cin.get();
}

// Todo: list in chronological order (by evenNo).
void viewAllEvents() {
    Event event;
    ifstream inputFile;
    inputFile.open("events.dat", ios::binary);
    if(!inputFile) {
        cout<<"\n\nFile could not be opened! \nPress Enter key to return to the menu. ";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\nView All Events" << endl;
    cout << "===============" << endl;

    while (inputFile.read(reinterpret_cast<char *> (&event), sizeof(event))) {
        cout << "\n-> " << getDayOfWeek(event.getYear(), event.getMonth(), event.getDay())
             << ", " << getMonthName(event.getMonth()) << " " << event.getDay()
             << " at " << event.getHour() << ":" << event.getMinute()
             << " (Event# " << event.getEventNo() << "):" << endl;
        cout << "   " << event.getDetails() << endl;
    }
    inputFile.close();

    cout << "\nPress Enter key to return to the menu. ";
    cin.ignore();
    cin.get();
}

// Todo: list in chronological order.
void viewDailyEvents(int month, int day, int year) {
    Event event;
    bool isEventExist = false;
    ifstream inputFile;
    inputFile.open("events.dat", ios::binary);
    if(!inputFile) {
        cout<<"\n\nFile could not be opened! \nPress Enter key to return to the menu. ";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\nEvent(s) of " << getDayOfWeek(event.getYear(), event.getMonth(), event.getDay())
         << ", " << getMonthName(event.getMonth()) << " " << event.getDay()
         << ", " << event.getYear() << ":" << endl;
    while (inputFile.read(reinterpret_cast<char *> (&event), sizeof(event))) {
        if (event.getMonth() == month && event.getDay() == day && event.getYear() == year) {
            cout << "\n-> At " << event.getHour() << ":" << event.getMinute()
                 << " (Event# " << event.getEventNo() << "):" << endl;
            cout << "   " << event.getDetails() << endl;
            isEventExist = true;
        }
    }
    inputFile.close();
    if (isEventExist)
        cout << "\nPress Enter key to return to the menu. ";
    else
        cout << "\n\nEvent does not exist!\nPress Enter key to return to the menu. ";
    cin.ignore();
    cin.get();
}

// Todo: list in chronological order.
void viewMonthlyEvents(int month, int year) {
    Event event;
    bool isEventExist = false;
    ifstream inputFile;
    inputFile.open("events.dat", ios::binary);
    if(!inputFile) {
        cout<<"\n\nFile could not be opened! \nPress Enter key to return to the menu. ";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\nEvent(s) of " << getMonthName(event.getMonth()) << " " << event.getDay()
         << ", " << event.getYear() << ":" << endl;
    while (inputFile.read(reinterpret_cast<char *> (&event), sizeof(event))) {
        if (event.getMonth() == month && event.getYear() == year) {
            cout << "\n-> " << getDayOfWeek(event.getYear(), event.getMonth(), event.getDay())
                 << ", " << getMonthName(event.getMonth()) << " " << event.getDay()
                 << " at " << event.getHour() << ":" << event.getMinute()
                 << " (Event# " << event.getEventNo() << "):" << endl;
            cout << "   " << event.getDetails() << endl;
            isEventExist = true;
        }
    }
    inputFile.close();
    if (isEventExist)
        cout << "\nPress Enter key to return to the menu. ";
    else
        cout << "\n\nEvent does not exist!\nPress Enter key to return to the menu. ";
    cin.ignore();
    cin.get();
}

void updateEvent(long eventNo) {
    Event event;
    int month;
    int day;
    int year;
    int hour;
    int minute;
    char details[DETAILS_SIZE]; // event details
    bool found = false;
    int filePointPosition;
    fstream file;
    file.open("events.dat", ios::binary|ios::in|ios::out);
    if(!file) {
        cout << "\n\nFile could not be opened!\nPress Enter key to return to the menu. ";
        cin.ignore();
        cin.get();
        return;
    }
    // `eof`: end of file.
    while (!file.eof() && !found) {
        file.read(reinterpret_cast<char *> (&event), sizeof(event));
        if (event.getEventNo() == eventNo) {

            cout << "\nCurrent Event Details:\n";
            cout << "\n-> " << getDayOfWeek(event.getYear(), event.getMonth(), event.getDay())
                 << ", " << getMonthName(event.getMonth()) << " " << event.getDay()
                 << ", " << event.getYear()
                 << " at " << event.getHour() << ":" << event.getMinute() << endl;
            cout << "   " << event.getDetails() << endl;

            cout << "\nEnter New Event Details:\n\n";
            cout << "\tMonth: ";
            cin >> month;
            event.setMonth(month);
            cout << "\tDay: ";
            cin >> day;
            event.setDay(day);
            cout << "\tYear: ";
            cin >> year;
            event.setYear(year);
            cout << "\tHour: ";
            cin >> hour;
            event.setHour(hour);
            cout << "\tMinute: ";
            cin >> minute;
            event.setMinute(minute);
            event.setEventNo(year, month, day, hour, minute);
            cout << "\tDetails: ";
            // Tell the cin object to skip characters (e.g., `\n`) in the keyboard buffer.
            cin.ignore();
            cin.getline(details, DETAILS_SIZE);
            event.setDetails(details);

            // Move the file pointer.
            // `(-1) * sizeof(event)` is an `unsigned long` value.
            filePointPosition = static_cast<int>((-1) * sizeof(event));
            // `seekp`: go to a location in output file.
            // `ios::cur` is a flag that can be used with the `seekp()` function to specify the current position
            // in a stream as the location to which to move the file pointer.
            file.seekp(filePointPosition, ios::cur);
            file.write(reinterpret_cast<char *> (&event), sizeof(event));

            found = true;
        }
    }
    file.close();

    if (found)
        cout << "\n\nEvent Updated.\nPress Enter key to return to the menu. ";
    else
        cout << "\n\nRecord Not Found.\nPress Enter key to return to the menu. ";
    cin.ignore();
    cin.get();
}

void deleteEvent(long eventNo) {
    Event event;
    char deleteOrNot;
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("events.dat", ios::binary);
    if(!inputFile) {
        cout << "\n\nFile could not be opened!\nPress Enter key to return to the menu. ";
        cin.ignore();
        cin.get();
        return;
    }
    outputFile.open("Temp.dat", ios::out);
    // `seekg`: go to a location in input file.
    // `ios::beg`: beginning of file.
    inputFile.seekg(0, ios::beg);

    while (inputFile.read(reinterpret_cast<char *> (&event), sizeof(event))) {
        if (event.getEventNo() == eventNo) {
            cout << "\nCurrent Event Details:\n";
            cout << "\n-> " << getDayOfWeek(event.getYear(), event.getMonth(), event.getDay())
                 << ", " << getMonthName(event.getMonth()) << " " << event.getDay()
                 << ", " << event.getYear()
                 << " at " << event.getHour() << ":" << event.getMinute() << endl;
            cout << "   " << event.getDetails() << endl;
        }
        if (event.getEventNo() != eventNo) {
            outputFile.write(reinterpret_cast<char *> (&event), sizeof(event));
        }
    }
    outputFile.close();
    inputFile.close();

    cout << "\nAre you sure you want to delete this event? (Y/N) ";
    cin >> deleteOrNot;
    switch(deleteOrNot) {
        case 'Y':
        case 'y':
            remove("events.dat");
            rename("Temp.dat", "events.dat");
            cout << "\nEvent Deleted.";
            break;
        case 'N':
        case 'n':
            remove("Temp.dat");
            break;
        default:
            remove("Temp.dat");
            break;
    }
    cout << "\nPress Enter key to return to the menu. ";
    cin.ignore();
    cin.get();
}
