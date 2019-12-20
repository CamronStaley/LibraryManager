#include "dpc.h"
#include "librarySystem.h"

//----------------------------------------------------------------------------
//constructor
//sets the transaction type character to D 
DPC::DPC() {
    transactionType = 'D';
}

//----------------------------------------------------------------------------
//setData
//reads nothing because this transaction only reads in D
bool DPC::setData(istream& istr, LibrarySystem& system) {
    return true;
}

//----------------------------------------------------------------------------
//printTransaction
//displays the transaction as transaction type
void DPC::printTransaction() const {
    cout << "D" << endl;
}

//----------------------------------------------------------------------------
//processTran
//calls display inventory from the system to display the catagories
void DPC::processTran(LibrarySystem& system) const {
    system.displayInventory();
}