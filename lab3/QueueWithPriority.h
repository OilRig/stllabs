#ifndef QueueWithPriority_h
#define QueueWithPriority_h

#include <string>
#include <list>
#include <vector>

#define SPACE " "

using namespace std;

typedef enum
{
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

struct QueueElement {
    string name;
};

struct prioritizedElement {
    QueueElement element;
    ElementPriority priority;
};

typedef list<QueueElement> elementList;

class QueueWithPriority
{
    private:
        elementList _hPriority, _nPriority, _lPriority;
    public:
        void putElementToQueue(const QueueElement &, ElementPriority);
        QueueElement getElementFromQueue();
        QueueWithPriority accelerate();
        QueueWithPriority render();
};

QueueWithPriority QueueWithPriority::render()
{
    vector<elementList*> priorityLists = {
        &_hPriority, &_nPriority, &_lPriority
    };
    
    for (auto list : priorityLists) {
        for (const auto &element : *list) {
            cout << element.name << SPACE;
        }
    }
    
    cout << endl;
    
    return *this;
}

void QueueWithPriority::putElementToQueue(
    const QueueElement &element, const ElementPriority priority)
{
    elementList *targetList = nullptr;
    
    switch (priority) {
        case HIGH: targetList = &_hPriority; break;
        case NORMAL: targetList = &_nPriority; break;
        case LOW: targetList = &_lPriority; break;
    }
    
    targetList->push_back(element);
}

QueueElement QueueWithPriority::getElementFromQueue()
{
    QueueElement element = QueueElement();
    vector<elementList*> priorityLists = {
        &_hPriority, &_nPriority, &_lPriority
    };
    
    for (auto list : priorityLists) {
        if (!list->empty()) {
            element = list->front();
            list->pop_front();
            
            break;
        }
    }
    
    return element;
}

QueueWithPriority QueueWithPriority::accelerate()
{
    _hPriority.splice(_hPriority.end(), _lPriority);
    
    return *this;
}

#endif /* QueueWithPriority_h */
