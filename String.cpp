#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"

#include <stdexcept>

using namespace std;

String::String() : m_data(nullptr), m_capacity(0), m_length(0) {
    
}

String::String(const char* cstr) {
    cout << "Calling constructor" << endl;
    
    m_length = 0;
    while (cstr[m_length] != '\0') {
        m_length++;
    }
    
    m_data = new char[m_length];
    for (int i = 0; i < m_length; i++) {
        m_data[i] = cstr[i];
    }
    
    m_capacity = m_length;
}

String::String(const String& rhs) {
    m_length = rhs.m_length;
    if (m_length == 0) {
        m_data = nullptr;
    } else {
        m_data = new char[m_length];
        for (int i = 0; i < m_length; i++) {
            m_data[i] = rhs.m_data[i];
        }
    }
    
    m_capacity = m_length;
}

String::~String() {
    delete[] m_data;
}

String& String::operator=(const String& rhs) {
    cout << "Calling = String" << endl;
      
    delete[] m_data;
      
    m_length = rhs.m_length;
    m_data = new char[m_length];

    for (int i = 0; i < m_length; i++) {
        m_data[i] = rhs[i];
    }

    m_capacity = rhs.m_capacity;

    return *this;
}

String& String::operator=(const char* cstr) {
    cout << "Calling = char-sequence" << endl;
    
//    String *s = new String(cstr);
//    
//    
//    
//    return *s;
}

String& String::operator=(char ch) {
    cout << "Calling = char" << endl;
}

String& String::operator+=(const String& rhs) {
    cout << "Calling += String" << endl;
    
    int totalLength = m_length + rhs.m_length;
    
    char* temp = new char[totalLength];
    
    for (int i = 0; i < m_length; i++) {
        temp[i] = m_data[i];
    }
    for (int j = 0; j < rhs.m_length; j++) {
        temp[m_length + j] = rhs.m_data[j];
    }
    
    delete[] m_data;
    
    m_data = temp;
    
    m_capacity = rhs.m_capacity;
    m_length = totalLength;
    
    return *this;
}

String& String::operator+=(char* cstr) {
    cout << "Calling += char-sequence assignment";
}

bool operator==(const String& lhs, const String& rhs) {
    // Next to if's maybe not needed?
//    if (lhs.length() == 0 && rhs.length() != 0) {
//        return false;
//    }
//    if (lhs.length() != 0 && rhs.length() == 0) {
//        return false;
//    }
    if (lhs.length() != rhs.length()) {
        return false;
    }
    
    for (int i = 0; i < lhs.length(); i++) {
        char c1 = lhs[i];
        char c2 = rhs[i];
        if (c1 != c2) {
            return false;
        }
    }
    return true;
}

char& String::at(int i) {
    if (i > m_length - 1) {
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
    return m_length;
}

void String::resize(int n) {
    cout << "Calling resize" << endl;
    
    char* temp = new char[n];
    
    int i = 0;
    while (i < m_length) {
        temp[i] = m_data[i];
        i++;
    }
    
    // Delete old array
    delete[] m_data;
    
    // New pointers
    m_data = temp;
    m_capacity = n;
}

void String::shrink_to_fit() {
    resize(m_length);
}

void String::push_back(char c) {
    int place = m_length;
    
    cout << place << endl;
    cout << m_capacity << endl;
    
    if (place >= m_capacity) {
        resize(m_capacity * 2);
    }
    
    m_data[place] = c;
    m_length++;
}

String operator+(String a, const String& b) {
    cout << "Calling + String,String" << endl;
    a += b;
    return a;
}

ostream& operator<<(ostream& stream, const String& s) {
    for (int i = 0; i < s.length(); i++) {
        stream << s[i];
    }
    
    return stream;
}

#endif