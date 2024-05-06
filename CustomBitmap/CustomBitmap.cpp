#include <iostream>
#include <vector>
#include <fstream>

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

    std::cout << "\nInitialised new Bitmap\n";

    std::cout << "Saving...";
    std::string bitmap = Utilities::BitmapToString(bm);
    std::cout << "\nWhere would you like to save to? (Valid path, no spaces) ";
    std::string path = "";
    std::cin >> path;
    ofstream myfile(path);
    if (myfile.is_open()) {
        myfile << bitmap;

        myfile.close();
    }
    std::cout << "\nSaved!\nCheck " << path;

    // Once finished, clear it up
    delete bm;
}