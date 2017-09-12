#ifndef Parser_h
#define Parser_h

#define PUNCT_CHAR     0
#define WORD_CHAR      1
#define SPACE_CHAR     2
#define UNDEFINED_CHAR 3

#include "Text.h"

int classifySymbol(const char symbol)
{
    string
        punctChars = ".,:;!?",
        spaceChars = "	 ",
        wordChars = "abcdefghijklmnopqrstuvwxyz0123456789";
    
    auto npos = string::npos;
    
    if (punctChars.find(symbol) != npos) {
        return PUNCT_CHAR;
    }
    
    if (spaceChars.find(symbol) != npos) {
        return SPACE_CHAR;
    }
    
    if (wordChars.find((char) tolower(symbol)) != npos) {
        return WORD_CHAR;
    }
    
    return UNDEFINED_CHAR;
}

Text parseText(const string inputText)
{
    bool reachedWordBoundary = true;
    Text parsedText;
    string word = "";
    
    for(char symbol : inputText) {
        
        if (reachedWordBoundary) {
            word = "";
        }
        
        switch (classifySymbol(symbol)) {
            case WORD_CHAR: {
                reachedWordBoundary = false;
                word += symbol;
                
                break;
            }
                
            case SPACE_CHAR: {
                if (!reachedWordBoundary) {
                    reachedWordBoundary = true;

                    parsedText.addElement({ElementType::Word, word});
                    parsedText.addElement({ElementType::Space});
                }
                
                break;
            }
                
            case PUNCT_CHAR: {
                if (!reachedWordBoundary) {
                    reachedWordBoundary = true;
                    
                    parsedText.addElement({ElementType::Word, word});
                    
                }
                
                parsedText.addElement({
                    ElementType::PunctuationMark,
                    string(1, symbol)
                });
                
                parsedText.addElement({ElementType::Space});
                
                break;
            }
                
            default: break;
        }
    }
    
    return parsedText;
}


#endif /* Parser_h */
