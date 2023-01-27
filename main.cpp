#include "date.h"
#include "Client.h"
#include "Hotel.h"
#include "Reservation.h"
#include "Room.h"
#include <iostream>

int main(int argc, char const* argv[]) {
	//Ajout de d'un hotel avec 10 chambres
	std::vector<Room> chambreHotel1;
	for (int i = 1; i < 4; i++) {
		chambreHotel1.push_back(Room(i, RoomType::Simple, 1, 100));
	}
	for (int i = 4; i < 9; i++) {
		chambreHotel1.push_back(Room(i, RoomType::Double, 2, 125));
	}
	chambreHotel1.push_back(Room(9, RoomType::Suite, 2, 200));
	chambreHotel1.push_back(Room(10, RoomType::Suite, 2, 210));
	for (int i = 0; i < chambreHotel1.size(); i++) {
		std::cout << chambreHotel1.at(i);
	}
	Hotel hotel1(1, "Ibis", "Dijon", chambreHotel1);
	std::cout << hotel1;

	//Création de clients
	std::vector<Client> client_list;
	client_list.push_back(Client(0, "PATAILLE", "Arthur"));
	client_list.push_back(Client(1, "BRAUN", "Gwendal"));
	client_list.push_back(Client(2, "FREUD", "Sigmond"));
	client_list.push_back(Client(3, "EULER", "Leonard"));
	client_list.push_back(Client(4, "STIVELL", "Alan"));

	for (Client client : client_list) std::cout << client;
	
	//Initialisation d'un vector de réservations
	std::vector<Reservation> reservation_list;

	//Check nom client
	std::cout << "Entrer le nom d'un client :" << std::endl;
	std::string client_name, client_firstname;
	int client_id;
	std::cin >> client_name >> client_firstname;
	bool client_in_list = false;
	for (Client client : client_list) {
		if (client.name() == client_name && client.firstname() == client_firstname) {
			std::cout << client << std::endl;
			client_id = client.id();
			client_in_list = true;
			break;
		}
	}
	if (!client_in_list)
	{
		client_id = client_list.size();
		client_list.push_back(Client(client_list.size(), client_name, client_firstname));
	}

	for (Client client : client_list) std::cout << client;

	//check de la date + nombre de nuits
	
	std::cout << "Donner la date de réservation(aaaa mm jj). Puis, le nombre de nuits :" << std::endl;
	int year, month, day;
	do {
		std::cin >> year >> month >> day;
	} while (!isDate(year, month, day));
	Date date(year, month, day);
	int night_number;
	do {
		std::cin >> night_number;
	} while (night_number < 1);

	//Check type de chambre + si chambre disponnible;
	std::cout << "Donnez le type de chambre souhaité (Simple, Double ou Suite) :" << std::endl;
	std::string type;
	do {
		std::cin >> type;
	} while(type != "Simple" && type != "Double" && type != "Suite");
	RoomType room_type{};
	if (type == "Simple") room_type = RoomType::Simple;
	if (type == "Double") room_type = RoomType::Double;
	if (type == "Suite") room_type = RoomType::Suite;
	std::vector<Room> option;
	for (Room room : hotel1.room()) 
		if (room.type() == room_type) if (!room.isReserved(date, night_number))
			option.push_back(room);
	
	std::cout << "Option : " << std::endl;
	for (int i = 0; i < option.size(); i++) {
		std::cout << i << " : " << option.at(i);
	}
	std::cout << "Select the one you want :\n";
	int option_nb;
	do {
		std::cin >> option_nb;
	} while (option_nb < 0 || option_nb >= option.size());
	

	//Création réservation dans la liste des réservations
	reservation_list.push_back({ date, night_number, hotel1, option.at(option_nb).number(), client_list.at(client_id) });
	
	// Affichage du prix
	std::cout << "Le prix total du séjour est de : " << reservation_list.at(0).totalPrice() << " euros" << std::endl;

	return 0;
}