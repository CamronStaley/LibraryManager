#include "bookContainer.h"
#include <iostream>
#include "book.h"


//---------------------------------------------------------------------------
//Default constructor
//creates empty tree
BookContainer::BookContainer() {
    root = nullptr;
}

//---------------------------------------------------------------------------
//Destructor
//calls makeEmpty to delete tree
BookContainer::~BookContainer() {
    makeEmpty();
}


//makeEmpty
//deletes all memory and clears tree by calling makeEmptyHelper
void BookContainer::makeEmpty() {
    if (root != nullptr) {
        makeEmptyHelper(root);
        root = nullptr;
    }
}

//makeEmptyHelper
//called by makeEmpty to recursively delete tree
void BookContainer::makeEmptyHelper(Node* curr) {
    if (curr != nullptr) {
        makeEmptyHelper(curr->left);
        makeEmptyHelper(curr->right);
        delete curr->data;
        curr->data = nullptr;
        delete curr;
        curr = nullptr;
    }
}

//---------------------------------------------------------------------------
//getRoot
//returns the root of the tree
Book* BookContainer::getRoot() const {
    return root->data;
}

//---------------------------------------------------------------------------
//isEmpty
//returns true if tree is empty
bool BookContainer::isEmpty() const {
    if (root == nullptr) {
        return true;
    }
    return false;
}


//---------------------------------------------------------------------------
//print
//displays the tree with an inorder traversal using the print helper func
//relies on the book having a display function
void BookContainer::print() {
    if (root == nullptr) return;
    printHelper(root);
}

//inorder helper function moves through tree to display variables
//in order and return them
void BookContainer::printHelper(Node* curr) {
    if (curr != nullptr) {
        printHelper(curr->left);
        curr->data->print();
        printHelper(curr->right);
    }
}
//---------------------------------------------------------------------------

//retrieve
//used to find the data and if it is not found then returns false
bool BookContainer::retrieve(const Book& target, Book*& point) const {
    if (root == nullptr) {
        return false;
    }
    Node* curr = root;
    while (curr != nullptr) {
        if (*curr->data == target) {
            point = curr->data;
            return true;
        }
        else if (target < *curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
//insert
//Inserts in order within tree assuming that operator< exists in Book

bool BookContainer::insert(Book* dataptr) {
    Node* ptr = new Node;
    ptr->data = dataptr;
    dataptr = nullptr;
    ptr->left = ptr->right = nullptr;
    if (isEmpty()) {
        root = ptr;
    }
    else {
        Node* current = root;
        bool inserted = false;

        // if item is less than current item, insert in left subtree,
        // otherwise insert in right subtree
        while (!inserted) {
            if (*current->data == *ptr->data) {
                delete ptr;
                ptr = nullptr;
                return false;
            }
            if (*ptr->data < *current->data) {
                if (current->left == nullptr) {      // at leaf, insert left
                    current->left = ptr;
                    inserted = true;
                }
                else
                    current = current->left;        // one step left
            }
            else {
                if (current->right == nullptr) {   // at leaf, insert right
                    current->right = ptr;
                    inserted = true;
                }
                else
                    current = current->right;    // one step right
            }
        }
    }
    return true;
}
//---------------------------------------------------------------------------