#ifndef Parser_h
#define Parser_h

#include "WordList.h"

enum SymbolTypes {
    Punctuation,
    Word,
    Space
};

int classifySymbol(const char symbol)
{
    string
        punctChars = ".,:;!?",
        spaceChars = "	 ",
        wordChars = "abcdefghijklmnopqrstuvwxyz0123456789";
    
    auto nullPos = string::npos;

    if (punctChars.find(symbol) != nullPos) {
        return Punctuation;
    }
    
    if (wordChars.find(static_cast<char>(tolower(symbol))) != nullPos) {
        return Word;
    }

    return Space;
}

WordList parseText(const string inputText)
{
    bool reachedWordBoundary = true;
    WordList parsedText;
    string newTextElement;
    string word;
    
    for(char symbol : inputText) {
        
        if (reachedWordBoundary) {
            word = "";
        }

        switch (classifySymbol(symbol)) {
            case Word: {
                reachedWordBoundary = false;
                word += symbol;

                break;
            }

            case Space: {
                if (!reachedWordBoundary) {
                    reachedWordBoundary = true;

                    parsedText.addElement(word);
                }

                break;
            }

            case Punctuation: {
                if (!reachedWordBoundary) {
                    reachedWordBoundary = true;

                    parsedText.addElement(word);
                }

                break;
            }

            default: break;
        }
    }

    return parsedText;
}

#endif /* Parser_h */