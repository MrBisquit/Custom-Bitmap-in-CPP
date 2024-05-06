#include <vector>
#include <string>

#include "Bitmap.h"

#pragma once

#ifndef Utilities

static class Utilities {
public:
	static std::vector<int> HEXToRGB(unsigned int Hex);
	static unsigned int HEXToARGB(unsigned int Hex);

	// To a string
	static std::string BitmapToString(Bitmap* bitmap); // Will use HexToARGB to convert from HEX to ARGB and then store in a file
	static void SaveString(std::string filename, std::string contents);
};

#endif // !Utilities