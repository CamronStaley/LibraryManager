#include "transactionFactory.h"
//----------------------------------------------------------------------------
//constructor
//sets the C R H and D to their respective transaction types
TransactionFactory::TransactionFactory() {
    for (int i = 0; i < hashTableSize; i++) { //set all to null pointer
        transFactory[i] = nullptr;
    }
    transFactory[hash('C')] = new Checkout;
    transFactory[hash('R')] = new Return;
    transFactory[hash('H')] = new DPH;
    transFactory[hash('D')] = new DPC;
}

//----------------------------------------------------------------------------
//destructor
TransactionFactory::~TransactionFactory() {
    for (int i = 0; i < hashTableSize; i++) {
        if (transFactory[i] != nullptr) {
            delete transFactory[i];
            transFactory[i] = nullptr;
        }
    }
}

//----------------------------------------------------------------------------
//createIt
//returns nullptr if not the correct type otherwise creates new object
//of that transaction type
Transaction* TransactionFactory::createIt(char ch) const {
    int subscript = hash(ch);
    if (transFactory[subscript] == nullptr) return nullptr; //incorrect type
    return transFactory[subscript]->create();
}