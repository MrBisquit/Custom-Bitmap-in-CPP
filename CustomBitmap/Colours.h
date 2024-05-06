#include <vector>
#include <iostream>

#pragma once

#ifndef Colours

static class Colours {
public:
	std::vector<Colour> colours = {
		Colour(White, "white"),
		Colour(Black, "black"),

		Colour(Red, "red"),
		Colour(Green, "green"),
		Colour(Blue, "blue")
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

class Colour {
public:
	Colour(unsigned int colour, std::string name);

	unsigned int colour;
	std::string name;
};

#endif // !Colours