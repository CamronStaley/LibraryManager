/*
 *  librarySystem.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  This class represents a library system used for building a library
 *  data base, checking out, and returning books.
 *
 *  Features:
 *  --allows to add transaction types, book types, new products,
 more library systems, formats to save paper and be readable

 *  Implementation and Assumptions:
 *  -- data in file will be formatted correctly.
    -- any data with wrong information prints an error and ignores
 *  -- patrons stored in hash table by their unique ID.
    -- patrons have a unique id
    -- products and transactions have unique character identifiers 
 *  -- stores products by their unique catagories in a hash table.
    named product catagories
 *  -- product catagories each have their own binary tree.
 *  -- handles invalid action codes, patron ID, format code, and book.
 *  -- error messages are displayed, nothing displayed when correct.
 *  -- product catagories stored in hash table by hashing their unique type.
 *  -- product catagories hash table size is a prime > number of catagories.
    -- all children of book must follow pure virtual structure to be invoked
    -- transactions stored in a linked list from <list> class 
    -- transaction list is implemented as a queue by inserting at the back
    and taking from the front
 *
 *  Limitations:
 */

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "transaction.h"
#include "bookFactory.h"
#include "transactionFactory.h"
#include "bookContainer.h"
#include "book.h"
#include "patron.h"
#include <list>
#include <iterator>
using namespace std;

//---------------------------------------------------------------------------
class LibrarySystem {
public:
    // Constructors and Destructors
    LibrarySystem();
    ~LibrarySystem();

    // Methods used to process data and pass them onto other functions
    void processProducts(const string); // reads/stores products
    void processPatrons(const string); // reads/stores patrons
    void readTransactions(const string); // reads/stores transactions
    void processTransactions(); // performs stored transactions

    void displayInventory() const; //prints inventory of each catagory
    void displayPatrons() const; //prints patrons

    Book* findBook(const Book*) const; //finds and returns a book
    Patron* findPatron(const int); //find and returns a patron
private:
    int hashBook(char ch) const { return ch; } //hashes the product type 
    int hashPatronID(int id) const { return id; } //hashes patron id
    list <Transaction*> transactionQ; //stores transactions in order
    int static const numberOfCatagories = 91; //number of unique ASCII letters
    int static const numberOfPatrons = 10000; //max number of unique patron ids
    //setw values (P[Name] means used for periodical)
    int AVAIL_OUTPUT_WIDTH = 6;
    int TITLE_OUTPUT_WIDTH = 38;
    int AUTHOR_OUTPUT_WIDTH = 24;
    int MONTH_OUTPUT_WIDTH = 6;
    int LINES_OUTPUT_WIDTH = 80;
    int PTITLE_OUTPUT_WIDTH = 56; 

    //hashtable for product trees
    BookContainer* productCatagories[numberOfCatagories]; //hash of trees

    //hashtable for patrons
    Patron* patronContainer[numberOfPatrons];

};