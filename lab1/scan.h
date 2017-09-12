#ifndef scan_h
#define scan_h

void scanIntsIntoVector()
{
    vector<int> inputVector, targetVector;
    int newInt;
    
    printf("Введите числа: \n");
    
    do {
        scanf("%d", &newInt);
        inputVector.push_back(newInt);
    } while (newInt != 0);
    
    inputVector.pop_back();
    
    vector<int>::iterator iterI = inputVector.begin();
    
    switch (inputVector.back())
    {
        case 1:
            // Удалить все четные значения
            while (iterI != inputVector.end())
            {
                if (*iterI % 2 == 1)
                {
                    targetVector.push_back(*iterI);
                }
                iterI++;
            }
            
            break;
            
        case 2:
            // После каждого кратного 3 добавить три единицы
            while (iterI != inputVector.end())
            {
                targetVector.push_back(*iterI);
                if (*iterI % 3 == 0)
                {
                    targetVector.insert(targetVector.end(), 3, 1);
                }
                iterI++;
            }
            
            break;
            
        default:
            targetVector = inputVector;
            
            break;
    }
    
    for (int i = 0; i < (int) targetVector.size(); i++) {
        cout << targetVector[i] << " ";
    }
    
    cout << endl;
}

#endif /* scan_h */
