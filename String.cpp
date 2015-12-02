#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"

String::String() {
    
}

String::String(const String& rhs) {
    //char* con[] = new char[4];
    content = char[rhs.length()];
    for (int i = 0; i < rhs.length(); i++) {
        content[i] = rhs[i];
    }
}

char& String::at(int i) {
    
}

char& String::operator[](int i) {
    return content[i];
}

int String::length() const {
    return sizeof(content) / sizeof(char);
}

#endif