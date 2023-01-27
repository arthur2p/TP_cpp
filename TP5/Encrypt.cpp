#include "Encrypt.h"
#include <fstream>

std::string Encrypt::plain() const
{
	return _plain;
}
std::string Encrypt::cipher() const
{
	return _cipher;
}
void Encrypt::read(std::string filename, char plain_or_cipher)
{
	std::string& destination = (plain_or_cipher == 'p') ? _plain : _cipher;
	std::ifstream file(filename);
	char c;
	destination = "";
	while (file.get(c)) {
		destination += c;
	}
	file.close();
}
void Encrypt::write(std::string filename, char plain_or_cipher)
{
	std::string& source = (plain_or_cipher == 'p') ? _plain : _cipher;
	std::ofstream file(filename);
	file << source;
	file.close();
}