#include "Room.h"
#include <iostream>

//Constructeur
Room::Room(int number, RoomType type, int bed_amount, int price)
	: _number(number), _type(type), _bed_amount(bed_amount), _price(price), _reserved(false)
{
	if (bed_amount != 1 && type == RoomType::Simple)
	{
		throw std::string("Simple room can only have 1 bed");
	}
	else if (bed_amount != 2 && type == RoomType::Double)
	{
		throw std::string("Double room can only have 2 beds");
	}
	else if (bed_amount < 1)
	{
		throw std::string("Room can't have less than 1 bed");
	}
}

//Getters
int Room::number() const {
	return _number;
}

RoomType Room::type() const {
	return _type;
}

int Room::bed_amount() const {
	return _bed_amount;
}

int Room::price() const {
	return _price;
}

bool Room::isReserved(Date begin_date, int night_number) const {
	for (const Reservation& reservation : _reservations)
		if (begin_date >= reservation.begin_date && begin_date < reservation.begin_date + reservation.night_number ||
			begin_date + night_number > reservation.begin_date && begin_date + night_number <= reservation.begin_date + reservation.night_number)
			return true;
	return false;
}

bool Room::addReservation(Date begin_date, int night_number, int bed_taken) {
	if (bed_taken < 1 || bed_taken > _bed_amount) throw std::string("Invalid bed amount");
	if (night_number < 1) throw std::string("Invalid night number");
	if (isReserved(begin_date, night_number)) throw std::string("Room already reserved during asked date");

	_reservations.push_back({ begin_date, night_number });
	return true;

}
bool Room::removeReservation(Date begin_date) {
	for (Reservation& reservation : _reservations)
		if (begin_date == reservation.begin_date)
			_reservations.erase(_reservations.begin() + (&reservation - &_reservations.at(0)));
	return false;
}

//Friend function
std::ostream& operator<<(std::ostream& os, const Room& room)
{
	std::string room_type;
	if (room.type() == RoomType::Simple)
		room_type = "Simple";
	else if (room.type() == RoomType::Double)
		room_type = "Double";
	else if (room.type() == RoomType::Suite)
		room_type = "Suite";
	os << "Chambre : Numero : " << room.number() << ", type : " << room_type << ", prix : " << room.price() << std::endl;
	return os;
}