#include "Reservation.h"
//Constructeur
Reservation::Reservation(Date& begin_date, int night_number, const Hotel& hotel, int room_number, const Client& client) : 
	_begin_date(begin_date), _end_date(begin_date + night_number), _hotel(hotel), _room_number(room_number), _client(client)
{
	try {
		if (!_hotel.room().at(_room_number).addReservation(_begin_date, night_number, 1)) {
			throw std::string("Room reservation failed");
		}
	}
	catch (std::string str) {
		throw std::string("Room reservation failed : " + str);
	}
	_total_price = _hotel.room().at(_room_number).price() * night_number;

}

//Destructeur
Reservation::~Reservation() {
	_hotel.room().at(_room_number).removeReservation(_begin_date);
}

//Getters
Date Reservation::beginDate() const {
	return _begin_date;
}

Date Reservation::endDate() const {
	return _end_date;
}

int Reservation::nightNumber() const {
	return _end_date - _begin_date;
}

const Hotel& Reservation::hotel() const {
	return _hotel;
}

int Reservation::roomNumber() const {
    return _room_number;
}

const Client& Reservation::client() const {
	return _client;
}

int Reservation::totalPrice() const {
	return _total_price;
}
