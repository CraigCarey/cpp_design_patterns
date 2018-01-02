/*
 * SOLID Principles - The Open/Closed Principle
 * Systems should be open to extension, but closed to modification
 */

#include <iostream>
#include <vector>

using namespace std;

// enum classes are typesafe, standard enums are implicitly converted
enum class Color {
    red, green, blue
};
enum class Size {
    small, medium, large
};

struct Product {
    string name;
    Color color;
    Size size;
};

// This Class breaks the principle because it must be modified in order to add new filters
struct ProductFilter {

    vector<Product *> by_color(vector<Product *> items, Color color) {
        vector<Product *> result;

        for (auto &i : items) {
            if (i->color == color) {
                result.push_back(i);
            }
        }

        return result;
    }

    vector<Product *> by_size(vector<Product *> items, Size size) {
        vector<Product *> result;

        for (auto &i : items) {
            if (i->size == size) {
                result.push_back(i);
            }
        }

        return result;
    }

    // This technique of adding filters doesn't scale well
    vector<Product *> by_size_and_color(vector<Product *> items, Size size, Color color) {
        vector<Product *> result;

        for (auto &i : items) {
            if (i->size == size && i->color == color) {
                result.push_back(i);
            }
        }

        return result;
    }
};

template <typename T> struct AndSpecification;

template <typename T> struct Specification
{
    // pure virtual, must be defined through inheritance
    virtual bool is_satisfied(T *item) = 0;

    // Override the && operator so we don't need to explicitly create an AndSpecification
    AndSpecification<T> operator&&(Specification<T>&& other)
    {
        return AndSpecification<T>(*this, other);
    }
};

template <typename T> struct Filter
{
    // pure virtual, must be defined through inheritance
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

// The BetterFilter is Open for extension, but Closed for modification
struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec) override
    {
        vector<Product*> result;

        for (auto& item : items)
        {
            if (spec.is_satisfied(item))
            {
                result.push_back(item);
            }
        }

        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color_;

    ColorSpecification(Color color) : color_(color) {}

    bool is_satisfied(Product *item) override {
        return item->color == color_;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size_;

    SizeSpecification(Size size) : size_(size) {}

    bool is_satisfied(Product *item) override {
        return item->size == size_;
    }
};

// Combines multiple specifications
template <typename T> struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &first,
                     Specification<T> &second)
            : first(first), second(second) {}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main() {
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house};

//    ProductFilter pf;
//    auto green_things = pf.by_color(items, Color::green);
//    for (auto &item : green_things) {
//        cout << item->name << " is green " << endl;
//    }

    BetterFilter bf;
    ColorSpecification green_spec(Color::green);

    for (auto &item : bf.filter(items, green_spec))
    {
        cout << item->name << " is green " << endl;
    }

    SizeSpecification large_spec(Size::large);
//    AndSpecification<Product> green_and_large(green_spec, large_spec);

    auto green_and_large = ColorSpecification(Color::green)
        && SizeSpecification(Size::large);

    for (auto &item : bf.filter(items, green_and_large))
    {
        cout << item->name << " is green and large" << endl;
    }
}
