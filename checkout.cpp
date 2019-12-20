#include "checkout.h"
#include "librarySystem.h"

//----------------------------------------------------------------------------
//constructor
//sets the transaction type character to C 
Checkout::Checkout() {
    transactionType = 'C';
}

//----------------------------------------------------------------------------
//setData
//reads patronID, bookType, bookPresentation, creates a book of the correct
//type using the book factory and then calls partialSetData. Returns false
//if incorrect patron ID, book presentation, book type, and book not in
//catalog. Otherwise, return true.
bool Checkout::setData(istream& istr, LibrarySystem& system) {
    BookFactory factory;
    string emptyLine;

    istr >> patronID; //reading 
    istr >> bookType;
    istr >> bookPresentation;

    tempPatron = system.findPatron(patronID); //getting patron from system
    if (tempPatron == nullptr) { //checking if patron was not in system
        cout << "ERROR: Patron ID " << patronID << " not in system." << endl;
        getline(istr, emptyLine); //reading in rest of line
        return false;
    }

    if (bookPresentation != 'H') { //checking if wrong book format
        cout << "ERROR: '" << bookPresentation
            << "' is not a valid book format." << endl;
        getline(istr, emptyLine); //reading in rest of line
        return false;
    }
    else { //correct book format
        targetBook = factory.createIt(bookType); //getting book object
        if (targetBook != nullptr) { //checking if book type was correct
            targetBook->partialSetData(istr); //sets data for partial book
            book = system.findBook(targetBook); //getting book from system
            if (book == nullptr) { //book was not in system
                cout << "ERROR: " << tempPatron->getPatronName() << 
                    " tried checking out '" << targetBook->getTitle() <<
                    "' - not found in catalog." << endl; 
                delete targetBook;
                targetBook = nullptr;
                return false;
            }
        }
        else { //incorrect book type 
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
//displays the transaction as transaction type and the book
void Checkout::printTransaction() const {
    if (book != nullptr) {
        cout.setf(ios::left, ios::adjustfield);
        cout << setw(12) << "  Checkout";
        book->printPartial();
    }
}

//----------------------------------------------------------------------------
//processTran
//tries checking out the book and if cannot check it out then 
//print an error of the patron and what book could not be checked out
void Checkout::processTran(LibrarySystem& system) const {
    if (!book->checkout()) { //try checking out
        cout << setfill('-') << setw(LINES_OUTPUT_WIDTH) << "-" << endl;
        cout << setfill(' ');
        cout << "ERROR: " << tempPatron->getPatronName()
            << " tried to checkout " << book->getTitle()
            << ", but is not in stock." << endl;
    }
}