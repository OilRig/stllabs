#ifndef list_functions_h
#define list_functions_h

#include <list>

void fillList(list<int> &list, size_t length)
{
    while (length) {
        list.push_back(1 + rand() % 20);
        --length;
    }
}

void printListReq(list<int> list, bool direction = true)
{
    if (list.empty()) {
        cout << endl;
        
        return;
    }
    
    cout << (direction ? list.front() : list.back()) << " ";
    
    if (direction) {
        list.pop_front();
    } else {
        list.pop_back();
    }
    
    printListReq(list, !direction);
}

void printList(list<int> &list)
{
    for (auto element : list) {
        cout << element << " ";
    }
    
    cout << endl;
}

#endif /* list_functions_h */
