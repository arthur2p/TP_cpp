#pragma once
#include <iostream>
#include "Date.h"
#include <vector>

enum class RoomType { Simple, Double, Suite }; 

class Room
{
public:
	Room(int number, RoomType type, int bed_amount, int price);
	
	int number() const;
	RoomType type() const;
	int bed_amount() const;
	int price() const;
	bool isReserved(Date begin_date, int night_number) const;
	
	bool addReservation(Date begin_date, int night_number, int bed_taken);
	bool removeReservation(Date begin_date);
	friend std::ostream& operator<<(std::ostream& os, const Room& room);
private:
	int _number;
	int _bed_amount;
	RoomType _type;
	int _price;
	bool _reserved;
	struct Reservation {
		Date begin_date;
		int night_number;
	};
	std::vector<Reservation> _reservations;
};
