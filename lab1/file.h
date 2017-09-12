#ifndef file_h
#define file_h

void readFileIntoVector()
{
    cout << "Содержимое текстового файла:" << endl;
    
    FILE *file = fopen("./lorem.txt", "rb");
    
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *string = (char *) malloc(fileSize + 1);
    fread(string, fileSize, 1, file);
    fclose(file);
    
    vector<char> charVector(string, string + fileSize);
    
    free(string);
    
    for (int i = 0; i < (int) charVector.size(); i++) {
        cout << charVector[i];
    }
    
    cout << endl;
}

#endif /* file_h */
