# FMI-OOP-P1_TicketSystem
TicketSystem: Project 1 from module OOP in FMI Uni-Sofia

## Initial structure

![FMI-OOP-P1_TicketSystem Class Diagram](https://user-images.githubusercontent.com/46843671/165101458-e5799051-6459-49c4-b2c2-24f785ada0d1.png)

<details>
  <summary>Diagram source</summary>

```
#title: FMI-OOP-P1_TicketSystem Class Diagram
#background: #fdf6e3
#bendSize: 0
#fillArrows: true
#lineWidth: 2

#.groupsfe: title=italic fill=#b2ee97
#.groupv: title=italic fill=#97c8ee
#.groupsc: title=italic

[<groupsfe> System for events
	[Ticket|
    	unsigned row
    	unsigned seat
	]

	[Reservation|
		char\[6\] password
    	unsigned row
    	unsigned seat
    	String note
	]

	[Event|
    	List<Ticket> _tickets
	    List<Reservation> _reservations|
		Date date
	    String name
    	Hall* hall|
	    reserveTicket()
    	cancelReservation()
    	buyTicket()
	]
	[Ticket]<--[Event]
	[Reservation]<--[Event]

	[EventSystem|
		createEvent()
    	cancelEvent()
	    reserveTicket(char*, Date, unsigned, unsigned)
    	cancelReservation()
    	buyTicket()
    	queryFreeSeats(Event)
    	queryReservations(Event)
    	queryBoughtTickets(Date, Date, Hall)
    	queryMostVisited()
    	queryInsufficientlyVisited()
	]
	[Event]<--[EventSystem]
]

[<groupv> Venue
	[Hall|
		int number
	    unsigned rowCount
    	unsigned seatsPerRow
	]

	[Venue|
		List<Hall> halls
    	EventSystem es
	]
	[Hall]<--[Venue]
]
[System for events]<--[Venue]

[<groupsc> Standard Classes
	[List<T>|
		T _elements*
    	unsigned _count
    	unsigned _length|
    	add(T elem)
    	operator\[\](unsigned index)
    	Rule of 4
    	Move semantics
    	Operators
	]

	[Date|
		unsigned _day
    	unsigned _month
	    int _year
    	unsigned _hour
    	unsigned _minute
	]

	[String|
		char* _str
	    unsigned _length
    	unsigned _count|
    	Rule of 4
	    Move semantics
    	Operators
	]

	[Command|
		String name
    	void (*exec)()
	]

	[Menu|
		List<Command> _commands|
    	navigate()
	]
	[Command]<--[Menu]

	[UserInterface|
		List<Menu> _menus|
	    start()
	]
	[Menu]<--[UserInterface]
    
    [List<T>]-/-[String]
    [String]-/-[Date]
]
```
</details>
