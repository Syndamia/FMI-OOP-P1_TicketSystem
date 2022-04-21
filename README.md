# FMI-OOP-P1_TicketSystem
TicketSystem: Project 1 from module OOP in FMI Uni-Sofia

## Initial structure

![nomnoml](https://user-images.githubusercontent.com/46843671/164534217-0c6004df-7141-48d3-9ffe-7c80ff3c3db3.png)

<details>
  <summary>Diagram source</summary>

```
[Hall|
	int number
    unsigned rowCount
    unsigned seatsPerRow
]

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
    Ticket* _tickets
    Reservation* _reservations|
	Date date
    String name
    Hall hall|
    reserveTicket()
    cancelReservation()
    buyTicket()
]
[Hall]<--[Event]
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

[Venue|
	Hall* halls
    EventSystem es
]
[Hall]<--[Venue]
[EventSystem]<--[Venue]

[String]
```
</details>
