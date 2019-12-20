//---------------------------------------------------------------------------
// bookcontainer.h
// Class that represents the book container
// Authors: Camron Staley, Jessica Chann, Alex Christensen
//---------------------------------------------------------------------------
// features:
//  -- checks to see if container contains any items
//  -- empties product container
//  -- retrieves products in container
//
//  Implementation and assumptions:
//  -- book types have <, display, and == operator 
#pragma once
using namespace std;

class Book;

class BookContainer {

public:
    BookContainer(); // constructor
    ~BookContainer(); // destructor, calls makeEmpty()
    bool isEmpty() const; // true if tree is empty, otherwise false

    // make the tree empty so isEmpty returns true (calls makeEmptyHelper)
    void makeEmpty();

    bool insert(Book*); //inserts the Book in the correct location

    //iterates through tree to find target and set the pointer reference
    //equal to it. Returns false if not found
    bool retrieve(const Book&, Book*&) const;
    void print(); //prints tree in order

    Book* getRoot() const;
private:
    struct Node {
        Book* data; // pointer to data object
        Node* left; // left subtree pointer
        Node* right; // right subtree pointer
    };
    Node* root; // root of the tree
    int index = 0; //used for bstreeToArray

    // utility functions
    void printHelper(Node*);
    void makeEmptyHelper(Node*); //helper for makeEmpty
};
