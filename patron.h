#pragma once
/*
 *  patrons.h
 *  Authors: Camron Staley, Jessica Chann, Alex Christensen, KJ
 *
 *  Class that represents the patrons or people who are coming in
 *  and out of the library checking out and returning books.
 *
 *  Features:
 *  -- allows library system to create patrons
    -- patrons keep track of their transaction history 
 *
 *  Implementation:
 *  -- Patrons contained in a hash table
 *  -- Keeps track of basic data members for patrons who come into the
 *     library
    -- uses <list> class to create a queue from a linked list
    to keep track of transaction history   
    -- assumes that transactions have display functions
 *
 */

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "transaction.h"
#include <list>
#include <iterator>

using namespace std;

//---------------------------------------------------------------------------
class Patron {

   
public:
    //Constructors and destructor
    Patron() { }
    ~Patron();

    bool setPatron(istream&, const int); //sets data from file 
    void displayPatron() const; //displays info
    void displayTranHistory(); //displays transaction history
    void addTransaction(Transaction*); //adds transaction to history
    string getPatronName() const; //returns the name of a patron
private:
    list <Transaction*> transQ; //transaction in order storage
    int ID; //stores the id for this patron
    string firstName; //this patrons first name
    string lastName; //this patrons last name
};