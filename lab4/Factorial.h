#ifndef Factorial_h
#define Factorial_h

#include <vector>

using namespace std;

// Класс контейнера
class Factorial
{
    private:
        int _size;
    
        int calcFactorial(int number)
        {
            int factorial = 1;
            
            while (number > 0) {
                factorial *= number;
                number--;
            }
            
            return factorial;
        }
    public:
        // Внутренний класс-итератор контейнера
        class iterator : std::iterator<std::bidirectional_iterator_tag, int>
        {
            private:
                int cursor = 1;
                int value = 1;
            
                void goBackward()
                {
                    value = (--cursor <= 1) ? 1 : (value / (cursor + 1));
                }
            
                void goForward()
                {
                    value = (++cursor <= 1) ? 1 : (value * cursor);
                }
            public:
                typedef Factorial::iterator fIterator;
            
                iterator() = default;
                ~iterator() = default;

                iterator(int cursor, int value)
                {
                    this->cursor = cursor;
                    this->value = value;
                };

                bool operator == (const fIterator &rhs)
                {
                    return rhs.cursor == cursor;
                };

                bool operator != (const fIterator &rhs)
                {
                    return rhs.cursor != cursor;
                };

                fIterator& operator = (const fIterator &it)
                {
                    cursor = it.cursor;
                    value = it.value;
                    
                    return *this;
                };

                int operator * ()
                {
                    return value;
                };

                fIterator& operator ++ ()
                {
                    goForward();
                    
                    return *this;
                };

                fIterator& operator -- ()
                {
                    goBackward();
                    
                    return *this;
                };

                fIterator operator ++ (int)
                {
                    iterator temp(*this);
                    goForward();
                    
                    return temp;
                };

                fIterator operator -- (int)
                {
                    iterator temp(*this);
                    goBackward();
                    
                    return temp;
                };
        };

        Factorial()
        {
            this->_size = 10;
        };

        iterator begin()
        {
            return iterator();
        };

        iterator end()
        {
            int pastEndPosition = _size + 1;
            
            return iterator(pastEndPosition, calcFactorial(pastEndPosition));
        };

        size_t getSize()
        {
            return static_cast<size_t>(_size);
        };
};

#endif /* Factorial_h */
