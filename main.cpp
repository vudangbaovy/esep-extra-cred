#include <iostream>
#include "InMemoryDB.h"
using namespace std;

int main() {
    // Your code here
    InMemoryDB inmemoryDB;

    cout << "Started in memory database program. Write END to end the program." << endl;

    string cmd;
    cin >> cmd;
    while (cmd != "END") {
        if (cmd == "BEGIN") {
            // starts a new transaction
            try { inmemoryDB.begin_transaction(); }
            catch (const std::logic_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        if (cmd == "PUT") {
            string key;
            cin >> key;
            string val;
            cin >> val;
            int value = stoi(val);
            try { inmemoryDB.put(key, value); }
            catch (const std::logic_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        if (cmd == "GET") {
            string key;
            cin >> key;
            int ret = inmemoryDB.get(key);
            cout << "Get " << key << ": " << ret << endl;
        }

        if (cmd == "COMMIT") {
            try { inmemoryDB.commit(); }
            catch (const std::logic_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        if (cmd == "ROLLBACK") {
            try { inmemoryDB.rollback(); }
            catch (const std::logic_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        cin >> cmd;
    }
    return 0;
}