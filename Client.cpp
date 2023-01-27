#include "Client.h"
//Constructeur
Client::Client(int id, std::string name, std::string firstname) :_id(id), _name(name), _firstname(firstname){

}

//Getters
int Client::id() const {
	return _id;
}

std::string Client::name() const {
	return _name;
}

std::string Client::firstname() const {
	return _firstname;
}


//Friend function
std::ostream& operator<<(std::ostream& os, const Client& client)
{
	os << "Client : Identifiant : " << client.id() << ", Nom : " << client.name() << ", prenom : " << client.firstname() << std::endl;
	return os;
}