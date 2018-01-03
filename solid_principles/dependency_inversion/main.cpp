/*
 * Specifies the best way to form dependencies between objects
 *
 * A. High-level modules should not depend on low-level modules
 *    Both should depend on abstractions (interfaces)
 *    This makes it easy to change the underlying implementation
 * B. Abstractions should not depend on details
 *    Details should depend on abstractions
 */

#include <iostream>
#include <vector>

using namespace std;

enum class Relationship {
    parent,
    child,
    sibling
};

struct Person {
    string name;
};

// Abstraction between the lower & higher level components
struct RelationshipBrowser {
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

// low-level: provides functionality for data storage
struct Relationships : RelationshipBrowser
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child) {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override {
        vector<Person> result;
        for (auto && [first, rel, second] : relations) {
            if (first.name == name && rel == Relationship::parent) {
                result.push_back(second);
            }
        }
        return result;
    }
};

// high-level
struct Research
{
    Research(RelationshipBrowser &browser) {
        for (auto &child : browser.find_all_children_of("John")) {
            cout << "John has a child called " << child.name << endl;
        }
    }

//    // Takes a direct dependency on a lower-level module
//    // If the implementation of Relationship changes this will break
//    Research(const Relationships &relationships) {
//        auto &relations = relationships.relations;
//        for (auto && [first, rel, second] : relations) {
//            if (first.name == "John" && rel == Relationship::parent) {
//                cout << "John has a child called " << second.name << endl;
//            }
//        }
//    }
};

int main() {
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return 0;
}