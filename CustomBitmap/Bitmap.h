#include <iostream>
#include <vector>

#pragma once

#ifndef Bitmap

struct Point {
	int x;
	int y;
};

struct Rectangle {
	Point point1;
	Point point2;
	Point point3;
	Point point4;
};

class Bitmap {
public:
	Bitmap(int width, int height);

	unsigned int FetchPixel(int x, int y); // std::vector<int> FetchPixel(int x, int y);
	void SetPixel(int x, int y, unsigned int colour); // void SetPixel(std::vector<int> pixel);

	// Drawing functions
	void DrawLine(Point start, Point finish, unsigned int colour);
	void DrawRectangle(Rectangle rectangle, unsigned int colour);
	void DrawFilledRectangle(Rectangle rectangle, unsigned int colour);

	int width;
	int height;
private:
	std::vector<unsigned int> pixels; // Reconsidered from std::vector<std::vector<int>> to std::vector<unsigned int>

	//int width;
	//int height;
};

#endif // !Bitmap