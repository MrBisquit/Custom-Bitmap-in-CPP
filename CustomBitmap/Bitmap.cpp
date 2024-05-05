#include <iostream>
#include <vector>

#include "Bitmap.h"

using namespace std;

Bitmap::Bitmap(int width, int height) {
	// Set the size of it
	this->width = width;
	this->height = height;

	// Need this
	int totalPixels = width * height;
	// Set each pixel to 0x0 (Black)

	pixels.resize(totalPixels);

	for (size_t y = 0; y < height; y++)
	{
		// Top -> Bottom
		for (size_t x = 0; x < width; x++)
		{
			// Left -> Right

			SetPixel(x, y, 0x000000); // Set every pixel to black
		}
	}
}

unsigned int Bitmap::FetchPixel(int x, int y) {
	// Maths for hunting for a pixel in the vector.
	return pixels[y * width + x];
}

void Bitmap::SetPixel(int x, int y, unsigned int colour) {
	pixels[y * width + x] = colour;
}

void Bitmap::DrawLine(Point start, Point finish, unsigned int colour) {

}

void Bitmap::DrawRectangle(Rectangle rectangle, unsigned int colour) {

}

void Bitmap::DrawFilledRectangle(Rectangle rectangle, unsigned int colour) {

}

// Old stuff I decided not to use
/*Bitmap::FetchPixel(int x, int y) {

}

Bitmap::SetPixel(int x, int y, vector<int> pixel) {

}*/