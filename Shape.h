#pragma once

#include <iostream>
#include <string>
#include <cmath>
#ifndef M_PI //This is the only way I can get this to work.
#define M_PI 3.14159
#endif
// Base Class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0; // Pure virtual
    virtual void display() const;       // Virtual
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
    void display() const override {
        std::cout << "Rectangle (" << width << " x " << height << ")";
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return M_PI * radius * radius; }
    void display() const override {
        std::cout << "Circle (radius: " << radius << ")";
    }
};
