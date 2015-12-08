#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"

#include <cstring>
#include <stdexcept>

using namespace std;

String::String() {
    cout << "Calling default constructor" << endl;
    m_capacity = 16;
    
    m_data = new char[m_capacity];
}

String::String(const char* cstr) : String::String() {
    cout << "Calling char constructor" << endl;
    
    int i = 0;
    while (cstr[i] != '\0') {
        cout << "C" << endl;
        cout << cstr[i] << endl;
        
        //cout << "Capacity: " + to_string(m_capacity) << endl;
        //cout << "i - 1: " + to_string(i - 1) << endl;
        if (i - 1 > m_capacity - 2) {
            resize(m_capacity * 2);
        }
        //cout << cstr[i] << endl;
        m_data[i] = cstr[i];
        
        cout << m_data << endl;
        
        
        i++;
    }
    
    m_data[i] = '\0';
}

String::String(const String& rhs) {
    cout << "Calling String copy" << endl;
    // NEEDS FIXING
    String *str = new String(rhs.data());
    str->m_capacity = rhs.capacity();
    
//    this->m_data = str->data();
//    this->m_capacity = str->capacity();
}

String::~String() {
    delete[] m_data;
}

String& String::operator=(const String& rhs) {
      cout << "Calling String assignment" << endl;
//    
//    cout << rhs << endl;
//    
//    char* p = new char[rhs.capacity()];
////    
//    for (int i = 0; i < rhs.length(); i++) {
//        cout << "looping" << endl;
//        char c = rhs[i];
//        cout << c << endl;
//        p[i] = c;
//    }
//    p[rhs.length() + 1] = '\0';
//    
//    cout << "P" << endl;
//    cout << p << endl;
//    
//    String *str;
//    str = new String(p);
//    return *str;
    
    String *str = new String(rhs.data());
    str->m_capacity = capacity();
    return *str;
}

String& String::operator=(const char* cstr) {
    
}

String& String::operator=(char ch) {
    
}

char& String::at(int i) {
    if (i > length() - 1) {
        throw std::out_of_range(i + " is not a valid index");
    }
    return m_data[i];
}

char& String::operator[](int i) const {
    return m_data[i];
}

int String::capacity() const {
    return m_capacity;
}

const char* String::data() const {
    return m_data;
}

int String::length() const {
    // NEEDS FIXING
    for (int i = 0; i < m_capacity; i++) {
        if (m_data[i] == '\0') {
            return i;
        }
    }
}

void String::resize(int n) {
    cout << "Calling resize" << endl;
    
    char* newArr = new char[n];
    
    //cout << m_data[0] << endl;
    
    for (int i = 0; i < m_capacity; i++) {
        newArr[i] = m_data[i];
    }
    newArr[18] = '\0';
    
    memcpy(newArr, m_data, m_capacity);
    
    //strcpy(newArr, m_data);
    
    // Delete old array
    delete[] m_data;
    
    // New pointers
    m_data = newArr;
    m_capacity = n;
}

ostream& operator<<(ostream &stream, const String &s) {
    string output;
    
    cout << "<<" << endl;
    cout << s.data() << endl;
    
    int i = 0;
    char c = s[i];
    while (c != '\0') {
        cout << c << endl;
        output += c;
        i++;
        c = s[i];
    }
    
    return stream << output;
}

#endif