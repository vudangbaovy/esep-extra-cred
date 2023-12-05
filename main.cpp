#include <iostream>
#include "InMemoryDB.h"
using namespace std;

int main() {
    // Your code here
    InMemoryDB inmemoryDB;

    // should return null, because A doesn’t exist in the DB yet
    int ret = inmemoryDB.get("A");
    cout << "Get A: " << ret << endl;

    // should throw an error because a transaction is not in progress
    try { inmemoryDB.put("A", 5); }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // starts a new transaction
    try { inmemoryDB.begin_transaction(); }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // set’s value of A to 5, but it's not committed yet
    try {
        inmemoryDB.put("A", 5);
    }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // should return null, because updates to A are not committed yet
    ret = inmemoryDB.get("A");
    cout << "Get A: " << ret << endl;

    // update A’s value to 6 within the transaction
    try {
        inmemoryDB.put("A", 6);
    }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // commits the open transaction
    try { inmemoryDB.commit(); }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // should return 6, that was the last value of A to be committed
    ret = inmemoryDB.get("A");
    cout << "Get A: " << ret << endl;

    // throws an error, because there is no open transaction
    try {
        inmemoryDB.commit();
    }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // throws an error because there is no ongoing transaction
    try {
        inmemoryDB.rollback();
    }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // should return null because B does not exist in the database
    ret = inmemoryDB.get("B");
    cout << "Get B: " << ret << endl;

    // starts a new transaction
    try { inmemoryDB.begin_transaction(); }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Set key B’s value to 10 within the transaction
    try { inmemoryDB.put("B", 10); }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Rollback the transaction - revert any changes made to B
    try { inmemoryDB.rollback(); }
    catch (const std::logic_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Should return null because changes to B were rolled back
    ret = inmemoryDB.get("B");
    cout << "Get B: " << ret << endl;

    return 0;
}