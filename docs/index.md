# FMI Tickets System {#mainpage}

\author Kamen Mladenov; FMI Computer Science, Year 1, Group 6; Project 1, Topic 4
\date 12 May 2022
\copyright GNU General Public License v3.0

<dl>
	<dt>Source Code</dt>
	<dd>https://github.com/Syndamia/FMI-OOP-P1_TicketSystem</dd>
</dl>

## About

The "FMI Ticket System" is a small project, designed for managing the seats for different events. You can create or cancel an event in any available hall, reserve or straight out buy tickets for any given event and create some reports.

## Structure overview

The project is roughly divided into 4 main components: User Interface, Services, Models and Generic \ref fig1.
- The User Interface is the messenger between a user and the underlying application. All input and output is handled here.
- Services contain the business logic of the whole application. All requests to do anything like buying a ticket or creating an event must be sent to here.
- Models are the general classes that are used in the previous two layers.
- Generic is a place for all code that is can be used independently from the project. Stuff like Date, String or List.

This offers a fairly modular and flexible architecture, which should make big changes or additions to the code easier and more pain-free.

## Building the project

Instructions are all for `gcc`. All commands should be executed while in the `src` folder.

### Linux/BSD/MacOS

```bash
g++ *.cpp */*.cpp */*/*.cpp -o TicketSystem.out && ./TicketSystem.out
```

### Windows (PowerShell)

```bash
g++ (Get-ChildItem -Recurse *.cpp) -o TicketSystem.exe && ./TicketSystem.exe
```

## Acknowledgements

<dl>
	<dt>Wikipedia</dt>
	<dd>Leap year calculation for Date <br> https://en.wikipedia.org/wiki/Leap_year#Gregorian_calendar</dd>
	<dt>StackOverflow</dt>
	<dd>Way to clear the console in Toolbox.hpp <br> https://stackoverflow.com/a/52895729/12036073</dd>
</dl>

## Figures

\anchor fig1
**Figure 1:** Overview of the "FMI Ticket System" design

\image html "FMI-OOP-P1_TicketSystem Overview.svg" ""
\image latex "FMI-OOP-P1_TicketSystem Overview.svg" "Not available in LaTeX!"
