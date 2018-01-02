/*
 *  Keep interface sizes small and maintainable
 *  Don't be tempted to put all operations into a single interface
 */

#include <iostream>

using namespace std;

struct Document;

//// This interface covers too much, it should be separated
//struct IMachine
//{
//    virtual void print(Document& doc) = 0;
//    virtual void scan(Document& doc) = 0;
//    virtual void fax(Document& doc) = 0;
//};
//
//// multifunction printer that can print, scan and fax
//struct MFP : IMachine
//{
//    void print(Document &doc) override {
//        // OK
//    }
//
//    void scan(Document &doc) override {
//        // OK
//    }
//
//    void fax(Document &doc) override {
//        // OK
//    }
//};
//
//struct Scanner : IMachine
//{
//    void print(Document &doc) override {
//        // shouldn't provide the API for this
//    }
//
//    void scan(Document &doc) override {
//        // OK
//    }
//
//    void fax(Document &doc) override {
//        // shouldn't provide the API for this
//    }
//};

struct IPrinter
{
    virtual void print(Document& doc) = 0;
};

struct IScanner
{
    virtual void scan(Document& doc) = 0;
};

struct IFax
{
    virtual void fax(Document& doc) = 0;
};

struct Printer : IPrinter
{
    void print(Document &doc) override {

    }
};

// Can combine interfaces with an intermediate interface
struct IPrinterScanner : IPrinter, IScanner {};

struct PrinterScanner : IPrinterScanner
{
    IPrinter& printer_;
    IScanner& scanner_;

    PrinterScanner(IPrinter &printer, IScanner &scanner)
            : printer_(printer), scanner_(scanner) {}

    void print(Document &doc) override {
        printer_.print(doc);
    }

    void scan(Document &doc) override {
        scanner_.scan(doc);
    }
};

int main() {

}
