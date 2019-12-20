/*
dph.h

(display patron history)
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
class DPH : public Transaction {
public:

    DPH(); //constructor
    virtual Transaction* create() const { return new DPH; } //return tran type
    virtual bool setData(istream&, LibrarySystem&);//set data from file
    virtual void printTransaction() const;//format and print data
    virtual void processTran(LibrarySystem&) const;//prints patron history

};