#include "bookFactory.h"
//----------------------------------------------------------------------------
//constructor
//sets the F Y and P locations to the respective book types
BookFactory::BookFactory() {
    for (int i = 0; i < hashTableSize; i++) {
        bookFactory[i] = nullptr;
    }
    bookFactory[hash('F')] = new Fiction;
    bookFactory[hash('Y')] = new Youth;
    bookFactory[hash('P')] = new Periodical;
}

//----------------------------------------------------------------------------
//destructor
BookFactory::~BookFactory() {
    for (int i = 0; i < hashTableSize; i++) {
        if (bookFactory[i] != nullptr) {
            delete bookFactory[i];
            bookFactory[i] = nullptr;
        }
    }
}

//----------------------------------------------------------------------------
//createIt
//returns null if book is not in the hashtable, otherwise returns
//a new object of that book type
Book* BookFactory::createIt(char ch) const {
    int subscript = hash(ch);
    if (bookFactory[subscript] == nullptr) return nullptr; //check for null
    return bookFactory[subscript]->create(); //return new book
}