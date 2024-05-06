#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Bitmap.h"
#include "Utilities.h"
#include "Colours.h"

Bitmap* bm;

int Instructions();

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

    std::cout << "Clearing Bitmap with the colour red.\n";
    bm->Clear(0xFF);
    std::cout << "Done!\n";

    std::cout << "Clearing Bitmap with the colour black.\n";
    bm->Clear(0x0);
    std::cout << "Done!\n";

    Instructions();

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

    std::cout << "\n\nWould you like to start again? (y/n) ";
    char start = 'n';
    std::cin >> start;

    if (start == 'y') {
        return main();
    }
    else return 1;
}

// Doesn't work
/*Colour InputColour() {
    std::cout << "Find a colour (Type it's name, no capitals): ";
    std::string name;
    std::cin >> name;

    //Colours colours;
    std::map<std::string, Colour> colours = Colours::colours;

    if (colours.colours.count(name) > 0) {
        return colours.colours[name];
    }
    else {
        std::cout << "\nColour not found.\nWould you like to view all colours? (y/n)";
        char viewAll = 'n';
        std::cin >> viewAll;

        if (viewAll == 'y') {
            std::vector<std::string> keys;
            std::vector<Colour> values;

            std::cout << "\n";
            for (const auto& key : keys) {
                std::string RGB = "";
                Colour colour(colours.colours[key]);
                std::vector<int> RGBValues = Utilities::HEXToRGB(colour.colour);
                RGB += "R:";
                RGB += std::to_string(RGBValues[0]);
                RGB += " G:";
                RGB += std::to_string(RGBValues[1]);
                RGB += " B:";
                RGB += std::to_string(RGBValues[2]);

                std::cout << "- " << key << " (" << RGB << ")" << std::endl;
            }
        }

        std::cout << std::endl;

        return InputColour();
    }
}*/

int Instructions() {
    unsigned int colour = 0xFFF; //InputColour().colour;

    std::cout << "Would you like to add\n";
    std::cout << "0 = None, continue to saving...\n";
    std::cout << "1 = A line (Point A -> Point B)\n";
    std::cout << "2 = A rectangle (Point A -> Point B)\n";
    std::cout << "3 = A filled rectangle ((Point A -> Point B) + Fill)\n";
    std::cout << "4 = A triangle (Point A -> Point B -> Point C)\n";
    std::cout << "5 = A filled triangle (Point A -> Point B -> Point C + Fill)\n";

    std::cout << "Your choice (1/2/3/4/5): ";

    int instruction = 0;
    std::cin >> instruction;

    if (instruction == 1) {
        Point start;
        Point finish;

        std::cout << "\nStart x: ";
        std::cin >> start.x;
        std::cout << "Start y: ";
        std::cin >> start.y;

        std::cout << "\nFinish x: ";
        std::cin >> finish.x;
        std::cout << "Finish y: ";
        std::cin >> finish.y;

        std::cout << "\nDrawing...\n";
        bm->DrawLine(start, finish, colour); //0xFFFFFF
        std::cout << "Done!\n";
    }
    else if (instruction == 2) {
        Point start;
        Point finish;

        std::cout << "\nStart x: ";
        std::cin >> start.x;
        std::cout << "Start y: ";
        std::cin >> start.y;

        std::cout << "\nFinish x: ";
        std::cin >> finish.x;
        std::cout << "Finish y: ";
        std::cin >> finish.y;

        std::cout << "\nDrawing...\n";
        Rectangle rect;
        rect.point1 = start;
        rect.point2 = finish;

        bm->DrawRectangle(rect, colour); //0xFFFFFF
        std::cout << "Done!\n";
    }
    else if (instruction == 3) {
        Point start;
        Point finish;

        std::cout << "\nStart x: ";
        std::cin >> start.x;
        std::cout << "Start y: ";
        std::cin >> start.y;

        std::cout << "\nFinish x: ";
        std::cin >> finish.x;
        std::cout << "Finish y: ";
        std::cin >> finish.y;

        std::cout << "\nDrawing...\n";
        Rectangle rect;
        rect.point1 = start;
        rect.point2 = finish;

        bm->DrawFilledRectangle(rect, colour); //0xFFFFFF
        std::cout << "Done!\n";
    }
    else if (instruction == 4) {
        Point point1;
        Point point2;
        Point point3;

        std::cout << "\nPoint A x: ";
        std::cin >> point1.x;
        std::cout << "Point A y: ";
        std::cin >> point1.y;

        std::cout << "\nPoint B x: ";
        std::cin >> point2.x;
        std::cout << "Point B y: ";
        std::cin >> point2.y;

        std::cout << "\nPoint C x: ";
        std::cin >> point3.x;
        std::cout << "Point C y: ";
        std::cin >> point3.y;

        std::cout << "\nDrawing...\n";
        Triangle triangle;
        triangle.point1 = point1;
        triangle.point2 = point2;
        triangle.point3 = point3;

        bm->DrawTriangle(triangle, colour); //0xFFFFFF
        std::cout << "Done!\n";
    }
    else if (instruction == 5) {
        std::cout << "Not implemented.\n";
    }

    std::cout << "Would you like to do something else with it? (y/n) ";
    char repeat = 'n';
    std::cin >> repeat;

    if (repeat == 'y') {
        Instructions();
    }
    else return 1;
}