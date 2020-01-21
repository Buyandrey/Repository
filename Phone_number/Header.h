#pragma once

class Rectangle {
public:
    Rectangle(int width, int height);
    int GetWidth() const;
    int GetHeight() const;
    int GetPerimeter() const;
    int GetArea() const;
private:
    int width_, height_;
};