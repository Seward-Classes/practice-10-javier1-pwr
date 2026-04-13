//AI Disclamer: All ideas where my own. I did use AI to help with the use of
//M_PI i could not get it to work proparly. I also used it to help with my formating
// of the .h file. It took me a while to figure out how to do it mostly out of the .h
//instead of having to define a lot of things in the .cpp.


#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>

// Temporary workaround
#include "Shape.h"
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "\nArea: " << std::fixed << std::setprecision(4) << shape->getArea() << "\n\n";
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "rectangle") {
            double w, h;
            if (ss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            } else {
                std::cerr << "Line " << lineNumber << " Error: Invalid rectangle data.\n";
            }
        } 
        else if (type == "circle") {
            double r;
            if (ss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            } else {
                std::cerr << "Line " << lineNumber << " Error: Invalid circle data.\n";
            }
        } 
        else {
            std::cerr << "Line " << lineNumber << " Error: Unknown shape type '" << type << "'.\n";
        }
    }

    inputFile.close();

    std::cout << "--- Results ---\n\n";
    printAllAreas(shapes);

    return 0;
}