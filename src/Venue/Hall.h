#ifndef HEADER_HALL
#define HEADER_HALL

class Hall {
	int index;
	unsigned rowCount;
	unsigned seatsPerRow;

public:
	Hall();
	Hall(int index, unsigned rowCount, unsigned seatsPerRow);

	int get_index() const;
	void set_index(int index);

	unsigned get_rowCount() const;
	void set_rowCount(unsigned rowCount);

	unsigned get_seatsPerRow() const;
	void set_seatsPerRow(unsigned seatsPerRow);

	int compare(const Hall& other);
};

#endif
