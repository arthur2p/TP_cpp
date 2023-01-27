#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
class Hotel
{
public:
	Hotel(int id, std::string name, std::string city, std::vector<Room> room);
	Hotel(int id, std::string name, std::string city);
	int id() const;
	std::string name() const;
	std::string city() const;
	std::vector<Room> room() const;
	void addChambre(Room chambre);
	void removeChambre(int position);
	void displayAllRoom();
	friend std::ostream& operator<<(std::ostream& os, const Hotel& hotel);
private:
	int _id;
	std::string _name;
	std::string _city;
	std::vector<Room> _room;
};