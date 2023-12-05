#include "InMemoryDB.h"

void InMemoryDB::begin_transaction() {
    if (inTransaction) throw std::logic_error("Transaction already in progress");
    inTransaction = true;
    transactionState = committedState; // Start with a copy of the current state
}

int InMemoryDB::get(string key) {
    if (committedState.count(key) > 0) return committedState[key]; // Return value from main state if present
    else return NULL;
}

void InMemoryDB::put(string key, int val) {
    if (!inTransaction) throw std::logic_error("Transaction not in progress");
    transactionState[key] = val;
}


void InMemoryDB::commit() {
    if (!inTransaction) throw std::logic_error("Transaction not in progress");
    committedState = transactionState;
    transactionState.clear();
    inTransaction = false;
}

void InMemoryDB::rollback() {
    if (!inTransaction) throw std::logic_error("Transaction not in progress");
    transactionState.clear();
    inTransaction = false;
}

