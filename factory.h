/*
factory.h

Parent class of any factory used in library system

Features:
    --allowed to be implemented 
    --pure virtual

Implementation and Assumptions:
    --has default hash size of 91 because 91 is highest
    askii value for unique capital characters

*/
#pragma once
#include <iostream>

using namespace std;

class Factory {
public:
    //constructor and destructor
    Factory() { };
    virtual ~Factory() { };
     
protected:
    //used by children to create hashtable 
    static const int hashTableSize = 91;
};