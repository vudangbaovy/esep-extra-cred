#include <iostream>
#include <unordered_map>
using namespace std;

class InMemoryDB {
    unordered_map<string, int> committedState;
    unordered_map<string, int> transactionState;
    bool inTransaction;
public:
    InMemoryDB() : inTransaction(false) {}
    void begin_transaction();
    int get(string key);
    void put(string key, int val);
    void commit();
    void rollback();
};