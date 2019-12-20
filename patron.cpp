#include "patron.h"

//----------------------------------------------------------------------------
//destructor
//clears transaction history and deletes list
Patron::~Patron() {
    transQ.empty();
    transQ.clear();
}

//----------------------------------------------------------------------------
//setPatron
//Takes istr and id as variables. Then it reads first and last name from a 
//file and sets the data accordingly returns false and prints error message 
//if invalid id
bool Patron::setPatron(istream& istr, const int id) {
    ID = id;
    istr >> lastName;
    istr >> firstName;
    if (ID < 1000 || ID > 9999) { //check for correct ID
        cout << "ERROR: " << ID << " is an invalid ID" << endl;
        return false;
    }
    else { //id is correct
        return true;
    }
}

//----------------------------------------------------------------------------
//displayPatron
//prints the patron data as ID LastName, FirstName 
void Patron::displayPatron() const {
    cout << ID << " "
        << lastName << ", "
        << firstName << ":" << endl;
}

//----------------------------------------------------------------------------
//addTransaction
//adds transaction to back of list 
void Patron::addTransaction(Transaction* tran) {
    transQ.push_back(tran);
}

//----------------------------------------------------------------------------
//displayTranHistory
//formats and displays transactions in the order they occurred for this 
//patron
void Patron::displayTranHistory() {
    if (transQ.empty()) {
        return;
    }
    list<Transaction*>::iterator it;
    //go through the transaction queue
    for (it = transQ.begin(); it != transQ.end(); ++it) {
        Transaction* tempTran = *it;
        tempTran->printTransaction();
    }
}

//----------------------------------------------------------------------------
//getPatronName
//returns the first and last name as a string
string Patron::getPatronName() const {
    return(lastName + " " + firstName);
}



