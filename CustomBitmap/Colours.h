#include <vector>
#include <iostream>
#include <map>

#pragma once

#ifndef Colours

// Moved up here because it was complaining and it wouldn't let me pre-define it.
class Colour {
public:
	Colour(unsigned int colour, std::string name);

	unsigned int colour;
	std::string name;
};

static class Colours {
public:
	Colours();
	/*std::vector<Colour> colours = {
		Colour(White, "white"),
		Colour(Black, "black"),

		Colour(Red, "red"),
		Colour(Green, "green"),
		Colour(Blue, "blue")
	};*/

	std::map<std::string, Colour> colours = {
		{ "white", Colour(White, "white") },
		{ "black", Colour(Black, "black") },

		{ "red", Colour(Red, "red") },
		{ "green", Colour(Green, "green") },
		{ "blue", Colour(Blue, "blue") }
	};

	// W, B
	unsigned int White = 0xFFFFFF;
	unsigned int Black = 0x000000;
	
	// R, G, B
	unsigned int Red = 0xFF0000;
	unsigned int Green = 0x00FF00;
	unsigned int Blue = 0x0000FF;
	
	// Can add others later
};

#endif // !Colours