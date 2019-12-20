/*
 *  fiction.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  This class is the representation of a fiction book in a library
 *         with basic data members.
 *
 *  Features:
 *  -- Output the type of book and basic information about it.
 *  -- Has getters to get the number of fiction books.
 *  -- Copy constructor to copy another fiction book.
 *  -- Tracks the total number of fiction books.
 *
 *  Implementation and Assumptions:
 *  -- Creates a fiction book to add to the library.
 *
 *   Limitations:
 *  -- Data about the book is restricted to the data members I created.
 *  -- Can only get information about the fiction book and create new
 *     fiction books.
 */

#pragma once
#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
class Fiction : public Book {

public:
    //Constructor
    Fiction() { }
    virtual void print() const; //format/print data
    virtual void printHeader() const; //prints the header 
    virtual void setData(istream&); //set data from file
    virtual bool operator==(const Book&) const; //return true if equal
    virtual bool operator<(const Book&) const; //return true if less than
    virtual Book* create() const { return new Fiction; } //used by factory
    virtual void partialSetData(istream&); //read in part of data
    virtual void printPartial() const; //called by transaction
};
