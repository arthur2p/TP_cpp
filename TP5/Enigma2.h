#pragma once
#include "Encrypt.h"
#include "Rotor.h"
#include <string>
#include <array>
class Enigma2 : public Encrypt
{
public:
	Enigma2(std::array<Rotor, 2> rotors);
	Enigma2(std::array<std::string, 2> keys, std::array<uint, 2> offsets = { 0,0 }, std::array<std::vector<uint>, 2> notches = { std::vector<uint>(0), std::vector<uint>(0) });
	void encode() override;
	void decode() override;
	void setOffsets(std::array<uint, 2> offsets);
private:
	std::array<Rotor, 2> _rotors;
	
};

