/**
 * Ниже приведен интерфейс класса очереди с приоритетами,
 * который функционирует следующим образом:
 *
 * В очередь могут быть добавлены элементы, каждому элементу при добавлении
 * присваивается один из трех уровней приоритета (low, normal, high)
 *
 * Элементы из очереди извлекаются в соответствии с их приоритетами
 * (сначала извлекаются элементы с приоритетом high, потом normal, потом low),
 * элементы с одинаковыми приоритетами извлекаются из очереди в порядке их
 * поступления.
 *
 * В очереди так же может происходить операция акселерации – все элементы с
 * приоритетом low находящиеся в момент акселерации в очереди увеличивают свой
 * приоритет до high и «обгоняют» элементы с приоритетом normal.
 *
 * Ниже приведен интерфейс этого класса:
 * typedef enum
 * {
 *     LOW,
 *     NORMAL,
 *     HIGH
 * } ElementPriority;
 *
 * typedef struct
 * {
 *     string name;
 * } QueueElement;
 *
 * class QueueWithPriority
 * {
 *     // Конструктор, создает пустую очередь
 *    QueueWithPriority();
 *
 *     // Деструктор
 *    ~QueueWithPriority();
 *
 *     // Добавить в очередь элемент element с приоритетом priority
 *     void PutElementToQueue(const QueueElement&, ElementPriority);
 *
 *     // Получить элемент из очереди
 *     // метод должен возвращать элемент с наибольшим приоритетом, который был
 *     // добавлен в очередь раньше других
 *     QueueElement GetElementFromQueue();
 *
 *     // Выполнить акселерацию
 *     void Accelerate();
 * };
 *
 * 1) Реализовать этот класс, используя list или deque. Объяснить свой выбор.
 * 2) Протестируете программу, добавьте отладочный вывод, показывающий,
 * что  класс работает правильно.
 *
 * Разработайте программу, которая:
 * 3) Заполняет list<int> 15 случайными значениями от 1 до 20, список может
 * содержать от 0 до 20 значений (обязательно проверить на длине списка
 * 0, 1, 2, 3, 4, 5, 7, 14)
 *
 * 4) Выводит содержимое списка в следующем порядке: первый элемент, последний
 * элемент, второй элемент, предпоследний элемент, третий элемент и т.д.
 *
 * Например, если список содержит:
 * 1 2 3 4 5 6 7 8
 * то вывод будет иметь вид
 * 1 8 2 7 3 6 4 5
 *
 * [Подсказка] МОЖНО ИСПОЛЬЗОВАТЬ РЕКУРСИЮ И ДВУНАПРАВЛЕННЫЕ ИТЕРАТОРЫ
 */

////////////////////////////////
// Фомин С. (группа 23531/21) //
////////////////////////////////

#include <iostream>
#include <vector>
#include <list>

#include "QueueWithPriority.h"
#include "list_functions.h"

using namespace std;

int main() {
    // Пункты 1 и 2
    QueueWithPriority queue;

    vector<prioritizedElement> elements = {
        {"1", HIGH},
        {"2", NORMAL},
        {"3", LOW},
        {"4", NORMAL},
        {"5", LOW},
        {"6", HIGH},
        {"7", LOW}
    };

    for (auto element : elements) {
        queue.putElementToQueue(element.element, element.priority);
    }

    queue
        .render()
        .accelerate()
        .render();

    // Пункты 3 и 4
    list<int> randList;
    vector<int> listLengths = {0, 1, 2, 3, 4, 5, 7, 14};
    
    cout << endl;
    
    for (auto listLength : listLengths) {
        fillList(randList, listLength);
        
        if (randList.empty()) {
            continue;
        }
        
        printList(randList);
        printListReq(randList);
        
        randList.clear();
    }
}
