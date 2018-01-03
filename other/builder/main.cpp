/*
 * Some objects are simple and can be created in a single constructor call
 * Other objects require a lot of ceremony to create
 * Having an object with 10 constructor arguments is not productive
 * Instead, opt for piecewise construction
 * Builder provides an API for constructing an object step-by-step
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class HtmlElement {

    friend class HtmlBuilder;
    string name_;
    string text_;
    vector<HtmlElement> elements_;
    const size_t indent_size = 4;

    HtmlElement() {}

    HtmlElement(const string &name, const string &text)
            : name_(name), text_(text) {}

public:

    string str(int indent = 0) const {
        ostringstream oss;
        string indentation(indent_size * indent, ' ');
        oss << indentation << "<" << name_ << ">" << endl;
        if (text_.size() > 0)
            oss << string(indent_size * (indent + 1), ' ') << text_ << endl;
        for (const auto &e : elements_)
            oss << e.str(indent + 1);
        oss << indentation << "</" << name_ << ">" << endl;
        return oss.str();
    }

    static HtmlBuilder build(string root_name) {
        return root_name;
    }
};

class HtmlBuilder {

    HtmlElement root_;

public:
    HtmlBuilder(string root_name) {
        root_.name_ = root_name;
    }

    // returning *this allows chaining of commands, for a fluent interface
    HtmlBuilder &add_child(string child_name, string child_text) {
        HtmlElement e{child_name, child_text};
        root_.elements_.emplace_back(e);
        return *this;
    }

    HtmlElement build() {
        return root_;
    }

    string str() const {
        return root_.str();
    }

    operator HtmlElement() const {
        return root_;
    }
};

int main() {
//    // Without using a builder...
//    string text = "hello";
//    string output;
//    output += "<p>";
//    output += text;
//    output += "<p>";
//    cout << output << endl;
//
//    string words[] = {"hello", "world"};
//    ostringstream oss;
//    oss << "<ul>" << endl;
//    for (string w : words)
//        oss << "<li>" << w << "</li>\n";
//    oss << "</ul>" << endl;
//    cout << oss.str();

//    // Standard Builder
//    HtmlBuilder builder{"ul"};
//    builder.add_child("li", "hello");
//    builder.add_child("li", "world");
//    cout << builder.str() << endl;

//    // Fluent Builder
//    HtmlBuilder builder{"ul"};
//    builder.add_child("li", "hello").add_child("li", "world");
//    cout << builder.str() << endl;

//    HtmlElement elem = HtmlElement::create("").add_child().build;
}
