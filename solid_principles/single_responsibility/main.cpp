/*
 * A Class should have a single reason to change
 * It should have a primary responsibility and not take on other responsibilities
 *
 * Separation of concerns:
 *     Journal takes care of the Journal title and entries
 *     PersistenceManager takes care of storage
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Journal {
    string title;
    vector<string> entries;

    explicit Journal(string title)
            : title{title} {
    }

    void add(const string &entry) {
        static int count = 1;
        entries.push_back(to_string(count++) + ": " + entry);
    }

    // persistence is a separate concern - this shouldn't be part of the class
    //void Journal::save(const string &filename) {
    //    ofstream ofs(filename);
    //    for (auto &s : entries)
    //        ofs << s << endl;
    //}
};

struct PersistenceManager {
    static void save(const Journal &j, const string &filename) {
        ofstream ofs(filename);
        for (auto &s : j.entries)
            ofs << s << endl;
    }
};

int main(void) {
    Journal journal{"Dear Diary"};
    journal.add("I ate a bug");
    journal.add("I cried today");

    //journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");
}
