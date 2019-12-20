/*
transaction.h

Parent Transaction type

Features:
    --allows children to descend with all necessary pure virtual
    overrides to be functional in the library sytem

Implementation and Assumptions:
    --create() is called by a transaction factory
    --all other subclasses of transaction need the same functions
    --bookType is a unique capital askii that no other transactions
    have (for use by transaction factory)
    --create, setdata, print transaction, and process transaction 
    must be overwritten

*/
#pragma once
#include <iostream>
#include <string>
#include "bookContainer.h"
#include "bookFactory.h"

class Patron;
class Book;
class LibrarySystem;
using namespace std;

//----------------------------------------------------------------------------
class Transaction {

protected:
    Patron* tempPatron = nullptr; //stores the patron for this transaction
    Book* book = nullptr; //stores the book for this transaction
    Book* targetBook = nullptr; //stores the partial book for this transaction
    int LINES_OUTPUT_WIDTH = 80; //used for printing '---' lines
    string transactionType; //used for "checkout" ect.
    int patronID; //stores patronID for this transaction
    char bookType; //stores the book type for getting from factory
    char bookPresentation; //stores the format of the book 'H' hardcopy ect.
    int static const numberOfCatagories = 91; //number of unique ASCII letters
    int static const numberOfPatrons = 10000; //max number of unique patron ids
public:
    //constructor and destructor
    Transaction() { };
    virtual ~Transaction();

    virtual Transaction* create() const = 0; //used by factory
    virtual bool setData(istream&, LibrarySystem&) = 0; //sets data from file
    virtual void printTransaction() const = 0; //format/display transaction
    virtual void processTran(LibrarySystem&) const = 0; //do the action 
    virtual Book*& getTargetBook() { return book; } //returns book 
    virtual int getTargetPatron() { return patronID; } //returns id
    virtual Patron* getPatron() { return tempPatron; } //returns patron 
};