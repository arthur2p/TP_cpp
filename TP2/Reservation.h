#pragma once
#include "Date.h"
#include "Hotel.h"
#include "Client.h"
#include <assert.h> 

class Reservation
{
public:
	Reservation(Date& begin_date, int night_number, const Hotel& hotel, int room_number, const Client& client);
	~Reservation();
	Date beginDate() const;
	Date endDate() const;
	int nightNumber() const;
	const Hotel& hotel() const;
	int roomNumber() const;
	const Client& client() const;
	int totalPrice() const;
private:
	Date _begin_date;
	Date _end_date;
	const Hotel& _hotel;
	int _room_number;
	const Client& _client;
	int _total_price;
};