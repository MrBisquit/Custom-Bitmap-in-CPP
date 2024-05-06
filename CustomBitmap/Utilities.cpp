#include <vector>
#include <string>

#include "Utilities.h";
#include "Bitmap.h"

std::vector<int> Utilities::HEXToRGB(unsigned int Hex) {
	// Credits: honey_the_codewitch

	uint32_t colour32 = Hex;

	uint8_t r = colour32 & 0xFF;
	uint8_t g = (colour32 >> 8) & 0xFF;
	uint8_t b = (colour32 >> 16) & 0xFF;

	return { r, g, b };
}

unsigned int Utilities::HEXToARGB(unsigned int Hex) {
	// Credits: honey_the_codewitch

	std::vector<int> RGB = HEXToRGB(Hex);
	int a = 0xFF;   // Apparently it'll always be this
	int r = RGB[0];
	int g = RGB[1];
	int b = RGB[2];

	uint32_t rgba32 = r | (g << 8) | (b << 16) | (a << 24);

	return rgba32;
}

std::string Utilities::BitmapToString(Bitmap* bitmap) {
	std::string string = "";
	string+= std::to_string(bitmap->width);
	string += ",";
	string += std::to_string(bitmap->height);
	string += ";";

	for (size_t y = 0; y < bitmap->height; y++)
	{
		for (size_t x = 0; x < bitmap->width; x++)
		{
			//unsigned int ARGB = HEXToARGB(bitmap->FetchPixel(x, y));
			std::vector<int> RGB = HEXToRGB(bitmap->FetchPixel(x, y));
			int r = RGB[0];
			int g = RGB[1];
			int b = RGB[2];

			//string += ARGB + ";";
			string += std::to_string(r);
			string += ",";
			string += std::to_string(g);
			string += ",";
			string += std::to_string(b);
			string += ";";
			//+std::to_string(g) + ', ' + std::to_string(b) + ';';
		}
	}

	return string;
}