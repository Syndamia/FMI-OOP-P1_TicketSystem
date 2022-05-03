# FMI-OOP-P1_TicketSystem
TicketSystem: Project 1 from module OOP in FMI Uni-Sofia

## Initial structure

![FMI-OOP-P1_TicketSystem Class Diagram](https://user-images.githubusercontent.com/46843671/166456741-f98d6feb-1f6a-48dc-b144-68440d471bc9.svg)

<details>
  <summary>Diagram source</summary>

```
#title: FMI-OOP-P1_TicketSystem Class Diagram
#background: #fdf6e3
#bendSize: 0
#fillArrows: true
#lineWidth: 2
#leading: 1.3
#direction: right

#.groupsfe: title=italic fill=#b2ee97 direction=down
#.groupv: title=italic fill=#97c8ee direction=down
#.groupsc: title=italic direction=down

[<groupsc> Standard Classes
	[List<T>|
		- T* elements
    	- unsigned count
    	- unsigned length
        |
    	+ add(elem)
        + insertAt(elem, index)
        + removeAt(index)
        + findIndex(elem);
		+ contain(elem);
    	+ operator\[\](index)
	]
    
    [OrderedList<T>|
    	+ insert(elem)
        + remove(elem)
    ]
    [List<T>]<--[OrderedList<T>]

	[DateTime|
		- unsigned day
    	- unsigned month
	    - int year
    	- unsigned hour
    	- unsigned minute
	]

	[String|
		- char* str
	    - unsigned length
    	- unsigned count
	]

	[Command|
		- String name
    	- void (*exec)()
	]

	[Menu|
		- List<Command> _commands
        |
    	+ navigate()
	]
	[Command]<--[Menu]
    
    [Toolbox.h|
    	read()
        print()
        printLine()
        printOrderedListElem()
        resetOrderedList()
    ]
    [Menu]-/-[Toolbox.h]
    
    [String]-/-[DateTime]
    [DateTime]-/-[List<T>]
]

[<groupv> Venue
	[Hall|
		- int number
	    - unsigned rowCount
    	- unsigned seatsPerRow
	]

	[Venue|
		- List<Hall> halls
    	- EventSystem es
	]
	[Hall]<--[Venue]
]
[Standard Classes]-/-[Venue]

[<groupsfe> System for events
	[Ticket|
    	- unsigned row
    	- unsigned seat
	]

	[Reservation|
    	- Ticket ticket
		- char\[8\] password
    	- char\[32\] note
	]

	[Event|
    	- OrderedList<Ticket> _tickets
	    - OrderedList<Reservation> _reservations
		+ Date date
	    + String name
    	+ Hall* hall
        |
	    + reserveTicket()
    	+ cancelReservation()
    	+ buyTicket()
	]
	[Ticket]<--[Event]
	[Reservation]<--[Event]

	[EventSystem|
    	- OrderedList<Event> _events
        - unsigned _soonestUpcoming
        |
		+ createEvent() ★
    	+ cancelEvent()
	    + reserveTicket(eventIndex, note, row, seat) ★
    	+ cancelTicketReservation() ★
    	+ buyTicket() ★
        + queryUpcoming(hallIndex)
    	+ queryFreeSeats(eventIndex) ★
    	+ queryReservations(eventIndex)
		+ reportReservations(eventIndex) ★
    	+ queryBoughtTickets(stDate, endDate, hall) ★
    	+ queryMostVisited() ☆
    	+ queryInsufficientlyVisited() ☆
	]
	[Event]<--[EventSystem]
    
    [StatusCodes.h|
    	enum StatusCode
    ]
    [EventSystem]-/-[StatusCodes.h]
]
[Venue]-->[System for events]
</details>
