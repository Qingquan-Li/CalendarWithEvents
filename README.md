# CalendarWithEvents

The final project of CSC 211.

Check `ProjectRequirements.pdf` for project requirements details.

## Run the Project

```bash
$ g++ main.cpp -o main
$ ./main
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 1

Adding New Event
================
	Month: 12
	Day: 24
	Year: 2022
	Hour: 20
	Minute: 30
	Details: Christmas Eve Party 🎉

New event added (Event# 202212242030).
Press Enter key to return to the menu. 


============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 1
Adding New Event
================
	Month: 12
	Day: 25
	Year: 2022
	Hour: 10
	Minute: 00
	Details: Christmas dinner!!       

New event added (Event# 202212251000).
Press Enter key to return to the menu. 
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 2

View Daily Events
=================

	Month: 12
	Day: 24
	Year: 2022

Event(s) of Monday, January 1, 1753:

-> At 20:30 (Event# 202212242030):
   Christmas Eve Party 🎉

Press Enter key to return to the menu. 
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 3

View Monthly Events
===================

	Month: 12
	Year: 2022

Event(s) of January 1, 1753:

-> Saturday, December 24 at 20:30 (Event# 202212242030):
   Christmas Eve Party 🎉

-> Sunday, December 25 at 10:0 (Event# 202212251000):
   Christmas dinner!!

Press Enter key to return to the menu. 
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 4

Update Event
============

	Enter Event Number: 202212251000

Current Event Details:

-> Sunday, December 25, 2022 at 10:0
   hristmas dinner!!

Enter New Event Details:

	Month: 12
	Day: 25
	Year: 2022
	Hour: 19
	Minute: 30
	Details: Visit the Rockefeller Christmas Tree🎄     


Event Updated.
Press Enter key to return to the menu. 
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 5

Delete Event
============

	Enter Event Number: 202212251930

Current Event Details:

-> Sunday, December 25, 2022 at 19:30
   Visit the Rockefeller Christmas Tre🎄

Are you sure you want to delete this event? (Y/N) y

Event Deleted.
Press Enter key to return to the menu. 
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 6

	Month: 12
	Year: 2022

   December 2022
Su Mo Tu We Th Fr Sa
             1  2  3 
 4  5  6  7  8  9 10 
11 12 13 14 15 16 17 
18 19 20 21 22 23 24 
25 26 27 28 29 30 31 


Press Enter key to return to the menu. 
```

```
============ MENU ============
	0.View All Events
	1.Add New Event
	2.View Daily Events
	3.View Monthly Events
	4.Update Event
	5.Delete Events
	6.Display Monthly Calendar
	7.Exit

Enter your Choice (0 - 7): 7

Exiting... Thank you!
```
