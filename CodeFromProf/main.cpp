/* 
 This is a calendar application that stores and edits event information from user input.
 It uses Event class objects to store information around events, and to make calculations to determine the name of the day of the week and the name of a month.
 Those objects are stored in a .dat file, which is currently named Calendar.dat
 but could be renamed easily since the name is stored in a c-string
 It also incorporates various functions to add events to the .dat file, view currently stored events, as well as update and delete events.
 */

#include <iostream>
#include "Event.h"
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void mainMenu();
void addNewEvent();
void viewDailyEvents();
void viewMonthlyEvents();
void updateEvent();
void deleteEvent();
void sortVect(vector<Event> &);
char calFile[] = "Calendar.dat";



int main() {   
    mainMenu();    
    return 0;
}

//
void mainMenu()
{    
    int choice;
    
    do{
    cout << "\n========== MENU ========== \n\n";
    cout << "\t1. Add New Event\n";
    cout << "\t2. View Daily Events\n";
    cout << "\t3. View Monthly Events\n";
    cout << "\t4. Update Event\n";
    cout << "\t5. Delete Event\n";
    cout << "\t6. Exit\n\n";
    cout << "Enter your choice (1 - 6) ";
    
    cin >> choice;
    
    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 )
    {
        cout << "Please reenter a valid menu option (1-6) ";
        cin >> choice;
    }
    
    switch (choice)
    {
        case 1 :
            addNewEvent();
            break;
            
        case 2 :viewDailyEvents();
            break;
            
        case 3 :viewMonthlyEvents();
            break;
            
        case 4 : updateEvent();
            
            
            break;
            
        case 5 : deleteEvent();
            
            break;

        case 6: cout << "\nYou are now exiting the calendar application. Goodbye." << endl << endl;
    }
    }while(choice != 6);
}


//Locally creates Event object and stores the object in a .dat file
void addNewEvent()
{
    system("clear");
    int month, day, year, hour, minute;
    
    Event calendarEntry;
    cout << "\nAdding New Event\n";
    cout << "================\n\n";
    cout << "\tYear: ";
    cin >> year;
    calendarEntry.setYear(year);
    cout << "\n\tMonth: ";
    cin >> month;
    calendarEntry.setMonth(month);
    cout << "\n\tDay: ";
    cin >> day;
    calendarEntry.setDay(day);
    cout << "\n\tHour: ";
    cin >> hour;
    calendarEntry.setHour(hour);
    cout << "\n\tMinute: ";
    cin >> minute;
    calendarEntry.setMinute(minute);
    calendarEntry.setDetails();
    
    ofstream outFile;
    outFile.open(calFile, ios::binary |ios::app); //Event entry added to end of file
    outFile.write(reinterpret_cast<char *>(&calendarEntry), sizeof(calendarEntry));
    outFile.close();
    
    cout << "\nNew event added (Event# " << calendarEntry.getEventNo();
    cout << ").\n";
  
    cout << "\nPress Enter Key to return to menu.\n";
    cin.get();
              
    system("clear");
    
}

void viewDailyEvents()
{
    //dummyEvent stores the search value for the eventNo. and is later used for the member functions that
    //return the name of day of the week and name of day of the month
    //dummyDay and tempDay are used to compare user event info against the event info stored in the .dat file
    Event dummyEvent, temp;
    int dummyDay = 0, tempDay = 0;
    int YYYY, MM, dd;
    cout << "View Daily Events\n";
    cout << "=================\n";
    cout << "\tYear : ";
    cin >> YYYY;
    cout << "\tMonth : ";
    cin >> MM;
    cout << "\tDay: ";
    cin >> dd;
    
    dummyEvent.setYear(YYYY);
    dummyEvent.setMonth(MM);
    dummyEvent.setDay(dd);
    dummyDay += static_cast<int>(dummyEvent.getEventNo() / 10000);

    
    
    
    fstream calendarFile(calFile, ios::binary | ios::in | ios::out);
  
    //Checks if a the file exists, clears screen
    if(!calendarFile)
    {
       
        cout << "\nFile could not be opened. \n";
        cin.ignore();
        cout << "\nPress Enter Key to return to menu.\n";
        cin.get();
        system("clear");
        return;
    }
    
    //A vector is used in order to store the matching Event object data and then to present the Events in
    //chronological order
    Event firstSpot;
    vector<Event> dailyEvents(1, firstSpot);
    int count = 1;//Used later to tell whether any Event objects were added to the vector
        
    while(calendarFile.read(reinterpret_cast<char *>(&temp), sizeof(temp)))
    {
        tempDay = temp.getEventNo() / 10000;
        if(dummyDay == tempDay)
        {
            dailyEvents.push_back(temp);
            count++;
        }
    }


  
    cout << "Event(s) of " << dummyEvent.nameOfDay() << ", " << dummyEvent.nameOfMonth() << " " << dummyEvent.getDay() << ", " << dummyEvent.getYear() << " :" << endl << endl;
    
    //If the vector added Event objects, the vector will be sorted chronologically and then displayed
    if(count != 1){
        sortVect(dailyEvents);
        
        //Displays the Event object for that day
        for(int i = 1; i < count; i++)
        {
            cout << "\t->" << setw(2) << setfill('0') << dailyEvents[i].getHour() << ":";
            cout << setw(2) << setfill('0') << dailyEvents[i].getMinute();
            cout << " (Event# " << dailyEvents[i].getEventNo() << "):\n";
            cout << "\t" << dailyEvents[i].getDetails() << endl;
        }
    }
    else
        cout << "\tThere are no events listed for this day.\n\n";
    
    
    calendarFile.close();
    cin.ignore();
    cout << "\nPress Enter Key to return to menu.\n";
    cin.get();

    system("clear");
              
    
}


void viewMonthlyEvents()
{
    Event dummyEvent, temp;
    int dummyMonth = 0, tempMonth = 0;
    int YYYY, MM;
    cout << "View Monthly Events\n";
    cout << "=================\n";
    cout << "\tYear : ";
    cin >> YYYY;
    cout << "\tMonth : ";
    cin >> MM;
   
    
    dummyEvent.setYear(YYYY);
    dummyEvent.setMonth(MM);
    dummyMonth = static_cast<int>(dummyEvent.getEventNo() / 1000000);
    
    
    
    fstream calendarFile(calFile, ios:: binary | ios::in | ios::out );
    
    if(!calendarFile)
    {
        cout << "\nFile could not be opened. \n";
        cin.ignore();
        cout << "\nPress Enter Key to return to menu.\n";
        cin.get();
        system("clear");
        return;
    }
    
    Event firstSpot;
    vector<Event> monthlyEvents(1, firstSpot);
    int count = 1;
    while(calendarFile.read(reinterpret_cast<char *>(&temp), sizeof(temp)))
    {
        tempMonth = static_cast<int>(temp.getEventNo() / 1000000);
        if(dummyMonth == tempMonth)
        {
            
            monthlyEvents.push_back(temp);
            
            count++;
           
        }
    }
    
    cout << "Event(s) of " << dummyEvent.nameOfMonth() << " " << dummyEvent.getYear() << " :" << endl << endl;
    
    if(count != 1)
    {
        sortVect(monthlyEvents);
        
       
        
        
        for(int i = 1; i < count; i++)
        {
            cout << "\t->" << monthlyEvents[i].nameOfDay() << ", " << monthlyEvents[i].nameOfMonth() << " " <<  monthlyEvents[i].getDay();
            cout << " at ";
            cout << setw(2) << setfill('0') << monthlyEvents[i].getHour() << ":";
            cout << setw(2) << setfill('0') << monthlyEvents[i].getMinute();
            cout << " (Event# " << monthlyEvents[i].getEventNo() << "):\n";
            cout << "\t" << monthlyEvents[i].getDetails() << endl;
        }
    }
    else
        cout << "\tThere are no events listed for this month.\n\n";
    
    
    
    calendarFile.close();

    cin.ignore();
    cout << "\nPress Enter Key to return to menu.\n";
    cin.get();

    system("clear");
}


//used for sorting events chronologically for display
//bubble sort is used on the vector
void sortVect(vector<Event> &vect)
{
    int size = static_cast<int>(vect.size());
    Event temp;
    if(size != 2)
    {
        for(int i = size - 1; i > 0; i--)
        {
            
            for(int j = 0; j < i; j++)
            {
                if(vect[j].getEventNo() > vect[j+1].getEventNo())
                {
                    temp = vect[j];
                    vect[j] = vect[j+1];
                    vect[j+1] = temp;
                }
            }
            
        }
    }
}

//Searches the .dat file for a matching eventNo and updates that Event object
void updateEvent()
{
    long searchEventNo;
    Event temp;
    bool found = false;
    fstream calendarFile(calFile, ios::binary | ios::in | ios::out );
    
    //tests whether the file exists and exits the function if not
    if(!calendarFile)
    {
        cout << "\nFile could not be opened. \n";
        cin.ignore();
        cout << "\nPress Enter Key to return to menu.\n";
        cin.get();
        system("clear");
        return;
    }
    
    cout << "Update Event\n";
    cout << "============\n";
    cout <<"\tEnter Event Number : ";
    cin >> searchEventNo;
    
  
    //reads the file for the Event with matching eventNo and takes
    //user input to update the Event information
    while(!calendarFile.eof() && !found)
    {
        calendarFile.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        if(temp.getEventNo() == searchEventNo)
        {
            found = true;
            cout << "Current Event Details:\n\n";
            cout << "\t->" << temp.nameOfDay() << ", " << temp.nameOfMonth() << " " <<  temp.getDay();
            cout << " at ";
            cout << setw(2) << setfill('0') << temp.getHour() << ":";
            cout << setw(2) << setfill('0') << temp.getMinute();
            cout << " (Event# " << temp.getEventNo() << "):\n";
            cout << "\t" << temp.getDetails() << endl;
            
            cout << "\nEnter New Event Details:\n\n";
            int month, day, year, hour, minute;
            cout << "\tYear: ";
            cin >> year;
            temp.setYear(year);
            cout << "\n\tMonth: ";
            cin >> month;
            temp.setMonth(month);
            cout << "\n\tDay: ";
            cin >> day;
            temp.setDay(day);
            cout << "\n\tHour: ";
            cin >> hour;
            temp.setHour(hour);
            cout << "\n\tMinute: ";
            cin >> minute;
            temp.setMinute(minute);
            temp.setDetails();
            
            //Sets position back to the Event that needs to be updated
            long pos = (-1) * sizeof(temp);
            calendarFile.seekp(pos, ios::cur);
            calendarFile.write(reinterpret_cast<char *>(&temp), sizeof(temp));
            
        }
    }
    calendarFile.close();
    if(!found)
    {
        cout << "\n\nRecord not found. \n";
        cin.ignore();
        cout << "\nPress Enter Key to return to menu.\n";
        cin.get();
        system("clear");
        return;
    }

    
    cout << "\nPress Enter Key to return to menu.\n";
    cin.get();
    system("clear");
  
}

//Searches for a corresponding Event similarly to Update
//Performs a kind of swap, where the current .dat file is deleted and replaced with
//an updated version that does not include the deleted Event object
void  deleteEvent()
{
    long searchEventNo;
    bool found = false;
    Event temp;
    ifstream inCalendarFile;
    inCalendarFile.open(calFile, ios::binary);
    if(!inCalendarFile)
    {
        cout << "\nFile could not be opened. \n";
        cin.ignore();
        cout << "\nPress Enter Key to return to menu.\n";
        cin.get();
        system("clear");
        return;
    }
    
    
    cout << "\nDelete Event\n";
    cout << "=============\n\n";
    cout << "\tEnter Event Number : ";
    
    cin >> searchEventNo;
    
    while(!inCalendarFile.eof() && !found)
    {
        inCalendarFile.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        if(temp.getEventNo() == searchEventNo)
        {
            found = true;
            cout << "Current Event Details:\n\n";
            cout << "\t->" << temp.nameOfDay() << ", " << temp.nameOfMonth() << " " <<  temp.getDay();
            cout << " at ";
            cout << setw(2) << setfill('0') << temp.getHour() << ":";
            cout << setw(2) << setfill('0') << temp.getMinute();
            cout << " (Event# " << temp.getEventNo() << "):\n";
            cout << "\t" << temp.getDetails() << endl << endl;
        }
    }
    
    if(found == false)
    {
        cout << "\n\nRecord not found. \n";
        cin.ignore();
        return;
    }
    
    cout << "Are you sure you want to delete this event? (Y/N) ";
    
    char yesNo;
    
    cin >> yesNo;
    
    while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')
    {
        cout << "\nPlease enter an appropriate response (Y/N) ";
        cin >> yesNo;
    }
    
    cout << endl;
    
    
    //Performs the deletion of the object.
    if(yesNo == 'Y' || yesNo == 'y')
    {
        //new file stream object created to hold updated information that
        //excludes the deleted object. We read from our current .dat file to a
        //temp Event object, which is used to write onto Temp.dat
        
        ofstream outCalendarFile("Temp.dat", ios::out);
        inCalendarFile.seekg(0, ios::beg);
        while(inCalendarFile.read(reinterpret_cast<char *>(&temp), sizeof(temp)))
        {
            if(temp.getEventNo() != searchEventNo)
            {
                outCalendarFile.write(reinterpret_cast<char *>(&temp), sizeof(temp));
            }
        }
        outCalendarFile.close();
        
        //The current .dat file is deleted, and Temp.dat is renamed to the current .dat file
        remove(calFile);
        rename("Temp.dat", calFile);
        cout << "\nEvent deleted.\n";
    }
    
    inCalendarFile.close();
    cin.ignore();
    cout << "\nPress Enter Key to return to menu.\n";
    cin.get();
    system("clear");
    
}

