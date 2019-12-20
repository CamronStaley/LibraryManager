/*
dpc.h

(display product catagories)
Child class of transactions used to store checkout transactions

Features:
    --overrides create, setData, printTransaction, and process Tran

Implementation and Assumptions:
    --create() is called by a transaction factory
    --all other subclasses of transaction need the same functions

*/
#pragma once
#include "transaction.h"

using namespace std;

//----------------------------------------------------------------------------
class DPC : public Transaction {
public:

    DPC(); //constructor
    virtual Transaction* create() const { return new DPC; } //return transtype
    virtual bool setData(istream&, LibrarySystem&); //reads from file stream
    virtual void printTransaction() const; //format and print data
    virtual void processTran(LibrarySystem&) const; //print product catagories

private:
    int LINES_OUTPUT_WIDTH = 80;
};
