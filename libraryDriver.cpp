#include "librarySystem.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    LibrarySystem temp;
    temp.processProducts("data4books.txt"); //read/set products
    temp.processPatrons("data4patrons.txt"); //read/set patrons
    temp.readTransactions("data4commands.txt"); //read/set transactions
    temp.processTransactions(); //perform transactions


}