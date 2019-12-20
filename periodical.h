/*
 *  periodical.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  This class is the representation of a periodical in a library
 *  with basic data members.
 *
 *  Features:
 *  -- Output the type of book and basic information about it.
 *  -- Has getters to get the number of periodicals.
 *  -- Copy constructor to copy another periodical.
 *  -- Tracks the total number of periodicals.
 *
 *  Implementation and Assumptions:
 *  -- Creates a periodical to add to the library.
 *
 *  Limitations:
 *  -- Data about the book is restricted to the data members I created.
 *  -- Can only get information about the periodical and create new
 *     periodicals.
 */

#pragma once
#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
class Periodical : public Book {

public:
    //Constructor
    Periodical() { }

    virtual void printHeader() const; //prints the header 
    virtual void print() const; //format/print book
    virtual void setData(istream&); //data setting
    virtual bool operator==(const Book&) const; //return true if equal
    virtual bool operator<(const Book&) const; //return true if less than
    virtual Book* create() const { return new Periodical; } //used by factory
    virtual void partialSetData(istream&); //read in part of data
    virtual void printPartial() const; //called by transaction

private:
    int TITLE_OUTPUT_WIDTH = 56; //setw for title

};

