/*
 *  Subtypes should be immediately substitutable for their basetypes
 *
 *  i.e. if a square inherits from rectangle, it should be useable wherever a rectangle
 *  can be used
 */

#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width_;
    int height_;

public:
    Rectangle(int width, int height)
            : width_(width), height_(height) {}

    int getWidth() const {
        return width_;
    }

    virtual void setWidth(int width) {
        width_ = width;
    }

    int getHeight() const {
        return height_;
    }

    virtual void setHeight(int height) {
        height_ = height;
    }

    int area() const {
        return width_ * height_;
    }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size) {}

    // breaks the principle, Squares are not immediately substitutable
    void setWidth(int width) override {
        this->width_ = this->height_ = width;
    }

    void setHeight(int height) override {
        this->width_ = this->height_ = height;

    }
};

// A factory would meet the principle
//struct RectangleFactory
//{
//    static Rectangle create_rectangle(int w, int h);
//    static Rectangle create_square(int size);
//};

void processRectangle(Rectangle& r)
{
    int w = r.getWidth();
    r.setHeight(10);

    cout << "Expected area: " << (w*10)
       << ", got " << r.area() << endl;
}

int main() {
    Rectangle r{3,4};
    processRectangle(r);

    Square sq{5};
    processRectangle(sq);
}
