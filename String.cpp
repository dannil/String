#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"

#include <stdexcept>

using namespace std;

String::String() : m_capacity(8) {
    cout << "Calling default constructor" << endl;
}

String::String(const char* cstr) : String::String() {
    cout << "Calling char constructor" << endl;
    
    cout << m_capacity << endl;
    
    int t = 0;
    while (cstr[t] != '\0') {
        m_data[t] = cstr[t];
        t++;
    }
    
    cout << m_capacity << endl;
    
//    int i = 0;
//    for (; *cstr; cstr++) {
//        //cout << capacity() << endl;
//        if (i > m_capacity) {
//            cout << "in if" << endl;
//            resize(m_capacity + 8);
//        }
//        m_data[i] = cstr[0];
//        i++;
//    }
//    m_data[i] = '\0';
    
    cout << m_data << endl;
}

String::String(const String& rhs) {
//    cout << "Copy constructor" << endl;
//    //char* con[] = new char[4];
//    m_data[rhs.length()];
//    //content = char[rhs.length()];
//    for (int i = 0; i < rhs.length(); i++) {
//        //content[i] = rhs[i];
//    }
}

String::~String() {
    
}

char& String::at(int i) {
    if (i > length()) {
        throw std::out_of_range(i + " is not a valid index");
    }
    //return *m_data[i];
}

char& String::operator[](int i) {
    //return *m_data[i];
}

int String::capacity() const {
    return m_capacity;
}

const char* String::data() const {
    return m_data;
}

int String::length() const {
    int length = 0;
    while (m_data[length] != '\0') {
        length++;
    }
    return length;
}

void String::resize(int n) {
    cout << "Calling resize" << endl;
}

#endif