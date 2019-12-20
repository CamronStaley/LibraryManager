/*
 *  bookFactory.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  Class that represents a factory by using hashing to generate
 *  different product types
 *
 *  Features:
 *  -- allows library system to create any subclass of type product
 *  -- subclasses currently include books
 *  -- book subclasses currently include fiction, youth, non-fiction
 *
 *  Implementation and Assumptions:
 *  -- size defaults to number of capital ascii characters
 *  -- size should be changed when you add more subclasses
 *  -- hashing uses the type of book in a string
 *  -- string type should be unique to each product type
 *
 *  Limitations:
 */

#pragma once
#include "factory.h"
#include "book.h"
#include "youth.h"
#include "periodical.h"
#include "fiction.h"
using namespace std;

//---------------------------------------------------------------------------
class BookFactory : public Factory {

public:
    BookFactory();  // initializes the hashtable to the correct products
    virtual ~BookFactory(); // sets pointers to null and deletes hash table

    Book* createIt(char) const;   // gets hash loc. and return prod.

private:
    Book* bookFactory[hashTableSize]; // hashtable storing prod types
    int hash(char ch) const { return ch; } // function uses product type to hash
};