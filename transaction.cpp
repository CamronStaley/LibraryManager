#include "transaction.h"

//---------------------------------------------------------------------------
//destructor
//clears memory and sets pointers to null
Transaction::~Transaction() {
    tempPatron = nullptr;
    book = nullptr;
    if (targetBook != nullptr) {
        delete targetBook;
        targetBook = nullptr;
    }
}