/*
 *  youth.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  This class is the representation of a youth book in a library
 *  with basic data members.
 *
 *  Features:
 *  -- Output the type of book and basic information about it.
 *  -- Has getters to get the number of youth books.
 *  -- Copy constructor to copy another youth book.
 *  -- Tracks the total number of youth books.
 *  -- Derived class from book class.
 *
 *  Implementation and Assumptions:
 *  -- Creates a youth book to add to the library.
 *
 *  Limitations:
 *  -- Data about the book is restricted to the data members I created.
 *  -- Can only get information about the youth book and create new
 *     youth books.
 */

#pragma once
#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
class Youth : public Book {

public:
    //Constructors and Desctructor
    Youth() { }
    virtual void print() const; //format/print data
    virtual void printHeader() const; //prints the header 
    virtual void setData(istream&); //set data from file
    virtual bool operator==(const Book&) const; //return true if equal
    virtual bool operator<(const Book&) const; //return true of less than
    virtual Book* create() const { return new Youth; } //used by factory
    virtual void partialSetData(istream&); //read in part of data
    virtual void printPartial() const; //called by transaction
};
