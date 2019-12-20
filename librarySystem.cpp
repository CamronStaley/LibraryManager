#include "librarySystem.h"
//---------------------------------------------------------------------------
//constructor
//initializes the productCatagories hash table and patron container
LibrarySystem::LibrarySystem() {
    for (int i = 0; i < numberOfCatagories; i++) {
        productCatagories[i] =  nullptr;
    }

    for (int i = 0; i < numberOfPatrons; i++) {
        patronContainer[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
//destructor
//deletes trees of products, transaction queue, and patrons 
LibrarySystem::~LibrarySystem() {
    //products
    for (int i = 0; i < numberOfCatagories; i++) {
        if (productCatagories != nullptr) {
            delete productCatagories[i];
            productCatagories[i] = nullptr;
        } 
    }
    //transactions
    list<Transaction*> ::iterator it;
    for (it = transactionQ.begin(); it != transactionQ.end(); ++it) {
        delete* it;
        *it = nullptr;
    }
    transactionQ.empty();
    transactionQ.clear();
    //patrons
    for (int i = 0; i < numberOfPatrons; i++) {
        if (patronContainer[i] != nullptr) {
            delete patronContainer[i];
            patronContainer[i] = nullptr;
        }
    }

}


//---------------------------------------------------------------------------
//processProducts
//takes in a file name as a string, opens the file, prints could not open
//and returns if cannot open, calls the factory to get each of the 
//objects in the file and then puts them into the correct binary tree
//within the product catagories hash table using their unique id to choose 
//their location in the hash table
void LibrarySystem::processProducts(const string filename) {
    char type = ' '; //stores the type 
    string emptyLine = " "; //used to clear line from file
    Book* temp; //stores book from factory
    BookFactory factory; //book factory for getting book objects

    fstream infile(filename);
    if (!infile) { //check for wrong file 
        cout << "File could not be opened." << endl;
        return;
    }
    for (;;) {

        infile >> type;
        if (infile.eof()) { //end of file 
            return;
        }

        temp = factory.createIt(type); //getting book from factory

        if (temp != nullptr) { //if we were able to get a book 
            temp->setData(infile);
            int key = hashBook(type);

            if (productCatagories[key] == nullptr) { //checking if new type
                productCatagories[key] = new BookContainer;
            }
            productCatagories[key]->insert(temp);//add to tree
        }
        else { //non-valid book type
            getline(infile, emptyLine); //reading in rest of line
            cout << "ERROR: '" << type << "' is not a valid book type." 
                << endl;
        }
    }
}

//---------------------------------------------------------------------------
//displayInventory
//formats and prints the inventory of each type expects tree to have
//print function, data to have have printHeader and print functions
void LibrarySystem::displayInventory() const {
    for (int i = 0; i < numberOfCatagories; i++) {
        if (productCatagories[i] != nullptr) {
            cout << setfill('-') << setw(LINES_OUTPUT_WIDTH) << "-" << endl;
            cout << setfill(' ');
            productCatagories[i]->getRoot()->printHeader(); //header for type
            productCatagories[i]->print(); //print rest of catagory
            cout << endl;           
        }
    }
}

//---------------------------------------------------------------------------
//processPatrons
//takes in file name as a string, attempts to open the file (prints error
//and returns if unable to open), creates a patron and calls setPatron, 
//hashes the ID for the patron and places it in the hashtable. Ignores patron
//that does not have an ID 1000 - 9999 also prints error if it 
//is a repeat ID
void LibrarySystem::processPatrons(const string filename) {
    int tempID;
    Patron* patronPointer;

    fstream infile(filename);
    if (!infile) { //check for wrong file 
        cout << "File could not be opened." << endl;
        return;
    }
    for (;;) { //read from file 
        infile >> tempID; 
        if (infile.eof()) { //end of file 
            return;
        }
        patronPointer = new Patron();
        if (patronPointer->setPatron(infile, tempID)) { //sets data 
            int key = hashPatronID(tempID);
            if (patronContainer[key] == nullptr) { //checks for repeats
                patronContainer[key] = patronPointer;
            }
            else { //print error if repeat id present
                cout << "ERROR: Patron ID " << tempID 
                    << " is already taken." << endl;
                delete patronPointer;
                patronPointer = nullptr;
            }
        }
        else {
            delete patronPointer;
            patronPointer = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
//displayPatrons
//formats/prints the patrons by calling printPatron in patron class
//prints them in order from smallest ID to largest.
void LibrarySystem::displayPatrons() const {
    cout << setfill('-') << setw(LINES_OUTPUT_WIDTH) << "-" << endl;
    cout << setfill(' ');
    for (int i = 0; i < numberOfPatrons; i++) {
        if (patronContainer[i] != nullptr) { //if has patron
            patronContainer[i]->displayPatron(); //print patron
        }
    }
    cout << endl;
}

//---------------------------------------------------------------------------
//readTransactions
//opens file (prints error if cannot open) 
//reads in transactions and then stores them in
//a transaction queue to be performed
void LibrarySystem::readTransactions(const string filename) {
    Transaction* tempTran;
    TransactionFactory factory;
    char tranType;

    fstream infile(filename);
    string emptyLine;
    if (!infile) { //check for wrong file 
        cout << "File could not be opened." << endl;
        return;
    }
    for (;;) {
        infile >> tranType;

        if (infile.eof()) { //end of file 
            return;
        }

        tempTran = factory.createIt(tranType); //get tran object
        if (tempTran != nullptr) { //check correct tran type
            if (tempTran->setData(infile, *this)) { //set tran data
                transactionQ.push_back(tempTran); //if set add to queue
            }
            else { //could not set data so delete it
                delete tempTran;
                tempTran = nullptr;
            }
        }
        else { //wrong tran type
            cout << "ERROR: '" << tranType
                << "' is not a valid transaction type." << endl;
            delete tempTran;
            tempTran = nullptr;
            getline(infile, emptyLine); //reading in rest of line
        }
    }
}
//---------------------------------------------------------------------------
//processTransaction
//iterates through the transactionQ and calls process on each transaction
//to perform their goal in order
void LibrarySystem::processTransactions() {
    Patron* targetPatron; //to check if tran has a patron
    Book* flag; //to check if tran has a book
    list <Transaction*> :: iterator it;
    //iterator from begginning to end of list of transactions
    for (it = transactionQ.begin(); it != transactionQ.end(); ++it) {
        Transaction* tempTran = *it;
        tempTran->processTran(*this); //process transaction
        targetPatron = tempTran->getPatron(); //getting patron from tran
        flag = tempTran->getTargetBook(); //getting book from patron
        //if transaction has a book and patron add it to their history
        if (targetPatron != nullptr && flag != nullptr) { 
            targetPatron->addTransaction(tempTran);
        }
    }
}

//---------------------------------------------------------------------------
//checkForPatron
//returns patron if stored and returns nullptr if not stored
Patron* LibrarySystem::findPatron(int id) {
    if (id < 1000 || id > 9999) { //check id in bounds
        cout << "ERROR: " << id << " is not a valid ID." << endl;
        return nullptr;
    }
    else { //id is in bounds 
        return patronContainer[id];
    }
}

//---------------------------------------------------------------------------
//findBook
//returns the book if in library, otherwise returns nullptr
Book* LibrarySystem::findBook(const Book* target) const {
    Book* searching = nullptr;
    productCatagories[target->getType()]->retrieve(*target, searching);
    return searching;
}