/*
 *  book.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  This class is the representation of a book in a library with
 *  basic data members.
 *
 *  Features:
 *  -- Output the type of product and basic information about it.
 *  -- Has getters to get product type and number of products.
 *  -- Tracks the number in stock 
    -- Tracks the number checked out
 *
 *  Implementation and Assumptions:
 *  -- Creates a product to add to the library.
    -- pure virtual create printheader, print, printpartial
    setData, partial set data, ==, and <
 *
 *  Limitations:
 *  -- Data about the book is restricted to the data members I created.
 *  -- Can only get information about the book, create new books,
 *     and initalize book data
 */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//----------------------------------------------------------------------------
class Book {

public:
    //Constructors and Desctructor
    Book();
    virtual ~Book();

    virtual Book* create() const = 0; // returns new book
    virtual char getType() const;  // Returns the product type

    virtual int getInstock() const; //returns ammount instock
    virtual int getCheckedOut() const; //return checked out ammount

    bool checkout(); //checks out book
    bool checkin(); //check in book

    virtual void printHeader() const = 0; //header for displaying in main
    virtual void print() const = 0; //displays info
    virtual void printPartial() const = 0; //used by transaction to print
    virtual void setData(istream&) = 0; // set data from input stream
    virtual void partialSetData(istream&) = 0; //reads in part of data
    virtual string getTitle() { return title; }
    virtual bool operator==(const Book&) const = 0; //operator==
    virtual bool operator<(const Book&) const = 0; //operator<

protected:
    int instock; //ammount of available books
    int checkedOut = 0; //ammount currently out
    int year; //stores year
    int month; //stores month

    char bookPresentation; //harcopy ect.
    char bookType; //type character
    string author; //stores author
    string title; //stores title

    //used for truncating outputs
    int AUTHOR_MAX_LENGTH = 20;
    int TITLE_MAX_WIDTH = 35;
    int PTITLE_MAX_WIDTH = 27;
    int PAUTHOR_MAX_LENGTH = 30;
    //setw lengths
    int AVAILABILITY_OUTPUT_WIDTH = 6;
    int PTITLE_OUTPUT_WIDTH = 30;
    int PAUTHOR_OUTPUT_WIDTH = 30;
    int AUTHOR_OUTPUT_WIDTH = 24;
    int TITLE_OUTPUT_WIDTH = 38;
    int MONTH_OUTPUT_WIDTH = 6;

};

