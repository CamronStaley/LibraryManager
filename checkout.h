/*
checkout.h

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
class Checkout : public Transaction {
public:

    Checkout();
    virtual Transaction* create() const { return new Checkout; } //for factory
    virtual bool setData(istream&, LibrarySystem&); //file stream and library 
    virtual void printTransaction() const; //formatting for this transaction 
    virtual void processTran(LibrarySystem&) const; //checks book out

};