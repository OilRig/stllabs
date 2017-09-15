#ifndef Parser_h
#define Parser_h

#include "Text.h"

int classifySymbol(const char symbol)
{
    string
        punctChars = ".,:;!?",
        wordChars = "abcdefghijklmnopqrstuvwxyz0123456789";
    
    auto null = string::npos;
    
    if (punctChars.find(symbol) != null) {
        return Punctuation;
    }
    
    if (wordChars.find((char) tolower(symbol)) != null) {
        return Word;
    }
    
    return Space;
}

Text parseText(const string inputText)
{
    bool reachedWordBoundary = true;
    Text parsedText;
    string letters;
    
    for(char symbol : inputText) {
        if (reachedWordBoundary) {
            letters = "";
        }
        
        switch (classifySymbol(symbol)) {
            case Word: {
                reachedWordBoundary = false;
                letters += symbol;
                
                break;
            }

            case Space: {
                if (!reachedWordBoundary) {
                    reachedWordBoundary = true;

                    parsedText.addElement({Word, letters});
                    parsedText.addElement({Space});
                }
                
                break;
            }

            case Punctuation: {
                if (!reachedWordBoundary) {
                    reachedWordBoundary = true;

                    parsedText.addElement({Word, letters});
                }
                
                parsedText.addElement({
                    Punctuation,
                    string(1, symbol)
                });
                
                parsedText.addElement({Space});
                
                break;
            }
                
            default: break;
        }
    }
    
    return parsedText;
}

#endif /* Parser_h */