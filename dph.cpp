#include "dph.h"
#include "librarySystem.h"

//----------------------------------------------------------------------------
//constructor
//sets the transaction type character to H
DPH::DPH() {
    transactionType = 'H';
}

//----------------------------------------------------------------------------
//setData
//reads patronID
bool DPH::setData(istream& istr, LibrarySystem& system) {
    istr >> patronID;
    tempPatron = system.findPatron(patronID);
    if (tempPatron == nullptr) {
        cout << "ERROR: Patron ID " << patronID << " not in system." << endl;
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------
//printTransaction
//displays the transaction as transaction type
void DPH::printTransaction() const {
    cout << "H " << patronID << endl;
}

//----------------------------------------------------------------------------
//processTran
//displays the patron and the patron history by calling displayPatron() 
//and displayTranHistory() from the patron class 
void DPH::processTran(LibrarySystem& system) const {
    cout << setfill('-') << setw(LINES_OUTPUT_WIDTH) << "-" << endl;
    cout << setfill(' ');
    tempPatron->displayPatron();
    tempPatron->displayTranHistory();
}