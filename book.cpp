#include "book.h"

//----------------------------------------------------------------------------
//constructor
Book::Book() {

}

//----------------------------------------------------------------------------
//deconstructor 
Book::~Book() {

}

//----------------------------------------------------------------------------
//getType
//returns the product type character
char Book::getType() const {
    return bookType;
}

//----------------------------------------------------------------------------
//getInstock
//returns the number of instock books
int Book::getInstock() const {
    return instock;
}

//----------------------------------------------------------------------------
//getCheckedOut
//returns the number of checked out copies
int Book::getCheckedOut() const {
    return checkedOut;
}

//----------------------------------------------------------------------------
//checkout
//used to decrease in stock books and increase checked out books. Prints 
//error if does not have any books in stock
bool Book::checkout() {
    if (instock > 0) { //check for instock
        instock--;
        checkedOut++;
        return true;
    }
    else { //not in stock
        return false;
    }
}

//----------------------------------------------------------------------------
//checkin
//used to increase instock and decrease checked out books.
bool Book::checkin() {
    instock++;
    checkedOut--;
    return true;
}