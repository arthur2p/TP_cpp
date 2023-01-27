#pragma once
#include "Encrypt.h"
#include "Rotor.h"
#include "PairSwitch.h"
#include <array>

class EnigmaM3 : public Encrypt
{
public:
	EnigmaM3(std::array<uint, 3> rotors, std::array<uint, 3> offsets, uint reflector, std::vector<std::string> pair_list); // refer to rotor and pairswitch lists
	EnigmaM3(std::array<Rotor, 3> rotors, PairSwitch reflector, PairSwitch plugboard);
	void pass_through(std::string& str);
	void encode() override;
	void decode() override;
	void setOffsets(std::array<uint, 3> offsets);
private:
	std::array<Rotor, 3> _rotors;
	PairSwitch _reflector;
	PairSwitch _plugboard;
};

