#ifndef HEADER_HALL
#define HEADER_HALL

class Hall {
	int number;
	unsigned rows;
	unsigned seatsPerRow;

public:
	Hall();
	Hall(int number, unsigned rows, unsigned seatsPerRow);

	int get_number() const;
	void set_number(int number);

	unsigned get_rows() const;
	void set_rows(unsigned rows);

	unsigned get_seatsPerRow() const;
	void set_seatsPerRow(unsigned seatsPerRow);

	int compare(const Hall& other);
};

#endif
