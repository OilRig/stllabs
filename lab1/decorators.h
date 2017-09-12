#ifndef decorators_h
#define decorators_h

#include <cstdio>
#include <vector>

using namespace std;

// Бэйскласс для декораторов вектора
template <typename T>
class VectorDecorator {
protected:
    vector<T> _vector;
    VectorDecorator(){};
public:
    virtual void sort() = 0;
    void output()
    {
        cout << "Содержимое вектора: ";
        
        auto iter = _vector.begin();
        while (iter != _vector.end())
        {
            cout << *iter << " ";
            iter++;
        }
        
        cout << endl;
    }
};

// Декоратор с доступом через индексы
template <typename T>
class IndexVectorDecorator : public VectorDecorator<T> {
    typedef VectorDecorator<T> super;
    
public:
    IndexVectorDecorator(vector<T> vec)
    {
        super::_vector = vec;
    }
    
    void sort()
    {
        T temp;
        auto &vector = super::_vector;
        
        for (int i = 1; i < (int) vector.size(); ++i)
        {
            for (int j = i; j > 0 && vector[j - 1] > vector[j]; --j)
            {
                temp          = vector[j - 1];
                vector[j - 1] = vector[j];
                vector[j]     = temp;
            }
        }
        
        cout << "Сортировка с доступом по индексам выполнена" << endl;
    }
};

// Декоратор с доступом через метод at() вектора
template <typename T>
class AtVectorDecorator : public VectorDecorator<T> {
    typedef VectorDecorator<T> super;
    
public:
    AtVectorDecorator(vector<T> vec)
    {
        super::_vector = vec;
    }
    
    void sort()
    {
        T temp;
        auto &vector = super::_vector;
        
        for (int i = 1; i < (int) vector.size(); ++i)
        {
            for (int j = i; j > 0 && vector.at(j - 1) > vector.at(j); --j)
            {
                temp             = vector.at(j - 1);
                vector.at(j - 1) = vector.at(j);
                vector.at(j)     = temp;
            }
        }
        
        cout << "Сортировка с доступом по методу at() выполнена" << endl;
    }
};

// Декоратор с доступом через объект-итератор
template <typename T>
class IteratorVectorDecorator : public VectorDecorator<T> {
    typedef VectorDecorator<T> super;
    
public:
    IteratorVectorDecorator(vector<T> vec)
    {
        super::_vector = vec;
    }
    
    void sort()
    {
        T temp;
        auto &vector = super::_vector;
        auto iterI = vector.begin();
        
        while (iterI != vector.end())
        {
            iterI++;
            auto iterJ = vector.begin();
            
            while (iterJ != iterI)
            {
                if (*iterI <= *iterJ)
                {
                    temp   = *iterI;
                    *iterI = *iterJ;
                    *iterJ = temp;
                }
                iterJ++;
            }
        }
        
        cout << "Сортировка с доступом через итераторы выполнена" << endl;
    }
};

#endif /* decorators_h */
