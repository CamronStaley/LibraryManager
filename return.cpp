#include "return.h"
#include "librarySystem.h"


//----------------------------------------------------------------------------
//constructor
//sets the transaction type character to R
Return::Return() {
    transactionType = 'R';
}

//----------------------------------------------------------------------------
//setData
//reads patronID, bookType, bookPresentation, creates a book of the correct
//type using the book factory and then calls partialSetData. Prints error
//for id not in system, book not in system, incorrect book format, incorrect
//book type, 
bool Return::setData(istream& istr, LibrarySystem& system) {
    BookFactory factory;
    string emptyLine;

    istr >> patronID;
    istr >> bookType;
    istr >> bookPresentation;

    tempPatron = system.findPatron(patronID); //get patron from system
    if (tempPatron == nullptr) { //check if patron wasnt in system
        cout << "ERROR: Patron ID " << patronID << " not in system." << endl;
        getline(istr, emptyLine); //reading in rest of line
        return false;
    }

    if (bookPresentation != 'H') { //check if book presentation is correct
        cout << "ERROR: '" << bookPresentation
            << "' is not a valid book format." << endl;
        getline(istr, emptyLine); //reading in rest of line
        return false;
    }
    else { //book presentation is correct
        targetBook = factory.createIt(bookType); //get book from factory
        if (targetBook != nullptr) { //book type is correct
            targetBook->partialSetData(istr); //set data for target
            book = system.findBook(targetBook); //get book from system
            if (book == nullptr) { //book was not in system
                cout << "ERROR: " << tempPatron->getPatronName() <<
                    " tried returning '" << targetBook->getTitle() <<
                    "' - not found in catalog." << endl;
                delete targetBook;
                targetBook = nullptr;
                return false;
            }
        }
        else { //book type is incorrect 
            cout << "ERROR: '" << bookType << "' is not a valid book type."
                << endl;
            getline(istr, emptyLine); //reading in rest of line
            return false;
        }
    }
    return true;
}

//----------------------------------------------------------------------------
//printTransaction
//displays the transaction as transaction type and the partial book data
void Return::printTransaction() const {
    if (book != nullptr) {
        cout.setf(ios::left, ios::adjustfield);
        cout << setw(12) << "  Return";
        book->printPartial();
    }
}

//----------------------------------------------------------------------------
//processTran
//checks book in for book in this transaction
void Return::processTran(LibrarySystem& system) const {
    book->checkin();
}