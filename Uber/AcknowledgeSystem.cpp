/*
Design a data structure that supports 3 below operations

1. GetNextId(): It returns the auto incremental next id. i.e.1 then 2 then 3 then 4
2. Acknowledge(int i): receives the acknowledgement of the id that was sent by GetNextId
3. GetIdLevel(): It returns the minimum id that has not been acknowledged
*/

#include <set>
#include <iostream>
using namespace std;

class Id {
public:
    Id() : id(0) {}
    
    int GetNextId() {
        ++id;
        unack_ids.insert(id);
        return id;
    }
    
    void Acknowledge(int i) {
        if (unack_ids.count(i)) {
            cout << "acknowledge " << i << endl;
            unack_ids.erase(i);
        }
    }
    
    int GetIdLevel() {
        if (unack_ids.empty()) return -1;
        return *unack_ids.begin();
    }
    
private:
    int id;
    set<int> unack_ids;
};

int main() {
    Id id;
    for (int i = 0; i < 10; ++i) {
        id.GetNextId();
    }
    
    id.Acknowledge(5);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(6);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(8);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(0);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(1);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(4);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(2);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(3);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(7);
    cout << id.GetIdLevel() << endl;
    id.Acknowledge(9);
    cout << id.GetIdLevel() << endl;    
    id.Acknowledge(10);
    cout << id.GetIdLevel() << endl;    
 
    return 0;
}
