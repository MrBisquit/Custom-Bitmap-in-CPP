#include <iostream>
#include <vector>

using namespace std;

#include "Bitmap.h"
#include "Utilities.h"

Bitmap* bm;

int main()
{
    int width;
    int height;

    std::cout << "CustomBitmap\n";
    std::cout << "Define new bitmap:\nWidth (In px): ";

    std::cin >> width;

    std::cout << "Height (In px): ";

    std::cin >> height;

    std::cout << "\n\nTotal pixels: " << width * height << ", Total vector entries: " << (width * height) * 3;

    std::cout << "\nInitialising new Bitmap...";

    bm = new Bitmap(width, height);

    std::cout << "\nInitialised new Bitmap";

    std::cout << Utilities::BitmapToString(bm);

    // Once finished, clear it up
    delete bm;
}