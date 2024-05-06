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
	// Bing AI told me how to do this.
	int x0 = start.x;
	int y0 = start.y;
	int x1 = finish.x;
	int y1 = finish.y;

	// Bresenham's Line Algorithm
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		Bitmap::SetPixel(x0, y0, colour);

		if (x0 == x1 && y0 == y1)
			break;

		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}
}

void Bitmap::DrawRectangle(Rectangle rectangle, unsigned int colour) {
	// Work out the width and height
	int width = rectangle.point2.x - rectangle.point1.x;
	int height = rectangle.point2.y - rectangle.point1.y;

	// Draw top line (First point x,y -> First point x + width,y)
	DrawLine(Bitmap::CreatePoint(rectangle.point1.x, rectangle.point1.y),
		Bitmap::CreatePoint(rectangle.point1.x + width, rectangle.point1.y), colour);

	// Draw bottom line (Last point x,y -> Last point x - width,y)
	DrawLine(Bitmap::CreatePoint(rectangle.point2.x, rectangle.point2.y),
		Bitmap::CreatePoint(rectangle.point2.x - width, rectangle.point2.y), colour);

	// Draw left (Top -> Bottom) line (First point x,y -> First point x,y + height)
	DrawLine(Bitmap::CreatePoint(rectangle.point1.x, rectangle.point1.y),
		Bitmap::CreatePoint(rectangle.point1.x, rectangle.point1.y + height), colour);

	// Draw right (Top -> Bottom) line (First point x + width,y -> Second point x,y)
	DrawLine(Bitmap::CreatePoint(rectangle.point1.x + width, rectangle.point1.y),
		Bitmap::CreatePoint(rectangle.point2.x, rectangle.point2.y), colour);
}

void Bitmap::DrawFilledRectangle(Rectangle rectangle, unsigned int colour) {
	for (size_t y = rectangle.point1.y; y < rectangle.point2.y; y++)
	{
		for (size_t x = rectangle.point1.y; x < rectangle.point2.y; x++)
		{
			SetPixel(x, y, colour); // Not most optimised but it'll do for now
		}
	}
}

void Bitmap::DrawTriangle(Triangle triangle, unsigned int colour) {
	// Point 1 -> Point 2
	DrawLine(Bitmap::CreatePoint(triangle.point1.x, triangle.point1.y),
		Bitmap::CreatePoint(triangle.point2.x, triangle.point2.y), colour);

	// Point 2 -> Point 3
	DrawLine(Bitmap::CreatePoint(triangle.point2.x, triangle.point2.y),
		Bitmap::CreatePoint(triangle.point3.x, triangle.point3.y), colour);

	// Point 3 -> Point 4
	DrawLine(Bitmap::CreatePoint(triangle.point3.x, triangle.point3.y),
		Bitmap::CreatePoint(triangle.point1.x, triangle.point1.y), colour);
}

void Bitmap::DrawFilledTriangle(Triangle triangle, unsigned int colour) {
	// Following what Bing AI says because I don't know the calculations

	int minX = std::min({ triangle.point1.x, triangle.point2.x, triangle.point3.x });
	int maxX = std::max({ triangle.point1.x, triangle.point2.x, triangle.point3.x });
	int minY = std::min({ triangle.point1.y, triangle.point2.y, triangle.point3.y });
	int maxY = std::max({ triangle.point1.y, triangle.point2.y, triangle.point3.y });

	// Nvm, I can't do that lol
}

void Bitmap::Clear(unsigned int colour) {
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			SetPixel(x, y, colour);
		}
	}
}

// Old stuff I decided not to use
/*Bitmap::FetchPixel(int x, int y) {

}

Bitmap::SetPixel(int x, int y, vector<int> pixel) {

}*/

// What I think to be the easiest way of doing this
Point Bitmap::CreatePoint(int x, int y) {
	Point point;

	point.x = x;
	point.y = y;

	return point;
}

Rectangle Bitmap::CreateRectangle(Point topLeft, Point bottomRight) {
	Rectangle rectangle;

	rectangle.point1 = topLeft;
	rectangle.point2 = bottomRight;

	return rectangle;
}

Triangle Bitmap::CreateTriangle(Point point1, Point point2, Point point3) {
	Triangle triangle;

	triangle.point1 = point1;
	triangle.point2 = point2;
	triangle.point3 = point3;

	return triangle;
}