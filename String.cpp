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
        //cout << "Capacity: " + to_string(m_capacity) << endl;
        //cout << "i - 1: " + to_string(i - 1) << endl;
        if (i - 1 > m_capacity - 2) {
            resize(m_capacity * 2);
        }
        //cout << cstr[i] << endl;
        m_data[i] = cstr[i];
        
        cout << m_data[i] << endl;
        
        i++;
    }
    cout << "I: " + to_string(i) << endl;
    
    m_data[i] = '\0';
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
    delete[] m_data;
}

char& String::at(int i) {
    if (i > length()) {
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
    //return strlen(m_data);
    
    for (int i = 0; i < m_capacity; i++) {
        cout << i << endl;
        if (m_data[i] == '\0') {
            //cout << i << endl;
            cout << "returning" << endl;
            return i;
        }
    }
    
//    int i = 0;
//    char& c = m_data[0];
//    cout << c << endl;
//    while (c != '\0') {
//        //output += s[i];
//        i++;
//        c = m_data[i];
//    }
//    return i;
}

void String::resize(int n) {
    cout << "Calling resize" << endl;
    
    char* newArr = new char[n];
    
    for (int i = 0; i < n / 2; i++) {
        newArr[i] = m_data[i];
    }
    newArr[n / 2 + 1] = '\0';
    
    delete[] m_data;
    m_data = newArr;
    
    m_capacity = n;
}

ostream& operator<<(ostream &stream, const String &s) {
    string output;
    
    int i = 0;
    char& c = s[i];
    while (c != '\0') {
        output += c;
        i++;
        c = s[i];
    }
    
    return stream << output;
}

#endif