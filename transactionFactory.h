/*
 *  transactionFactory.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  Class that represents a factory by using hashing to generate
 *  different transaction types
 *
 *  Features:
 *  -- allows library system to create any subclass of type transaction
 *  -- subclasses currently include return, checkout, displayPatron
 // and display product catagories
 *  -- book subclasses currently include fiction, youth, non-fiction
 *
 *  Implementation and Assumptions:
 *  -- size defaults to the number of unique askii capitals
 *  -- size should be changed when you add more subclasses
 *  -- hashing uses the type transaction
 *  -- string type should be unique to each type
 *
 */

#pragma once
#include "factory.h"
#include "transaction.h"
#include "checkout.h"
#include "return.h"
#include "dph.h"
#include "dpc.h"
using namespace std;

//---------------------------------------------------------------------------
class TransactionFactory : public Factory {

public:
    TransactionFactory();  // initializes the hashtable to the correct products
    virtual ~TransactionFactory(); // sets pointers to null and deletes hash table

    Transaction* createIt(char) const;   // gets hash loc. and return prod.

private:
    Transaction* transFactory[hashTableSize]; // hashtable storing prod types
    int hash(char ch) const { return ch; } // function uses product type to hash
};