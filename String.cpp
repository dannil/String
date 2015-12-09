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
    
    m_data = new char[m_length + 1];
    for (int i = 0; i < m_length; i++) {
        m_data[i] = cstr[i];
    }
    m_data[m_length + 1] = '\0';
    
    m_capacity = m_length;
}

String::String(const String& rhs) {
    m_length = rhs.m_length;
    if (m_length == 0) {
        m_data = nullptr;
    } else {
        m_data = new char[m_length + 1];
        for (int i = 0; i < m_length; i++) {
            m_data[i] = rhs.m_data[i];
        }
        m_data[m_length + 1] = '\0';
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
    m_data = new char[m_length + 1];

    for (int i = 0; i < m_length; i++) {
        m_data[i] = rhs[i];
    }
    m_data[m_length + 1] = '\0';

    m_capacity = rhs.m_capacity;

    return *this;
}

String& String::operator=(const char* cstr) {
    cout << "Calling = char-sequence" << endl;
    
    delete[] m_data;

    int index = 0;
    while (cstr[index] != '\0') {
        push_back(cstr[index]);
        index++;
    }
    push_back('\0');
    
    m_capacity = index;
    
    return *this;
}

String& String::operator=(char ch) {
    cout << "Calling = char" << endl;
    
    delete[] m_data;
    
    m_data = new char[2];
    m_data[0] = ch;
    m_data[1] = '\0';
    
    m_length = 1;
    m_capacity = 1;
    
    return *this;
}

String& String::operator+=(const String& rhs) {
    cout << "Calling += String" << endl;
    
    int totalLength = m_length + rhs.m_length;
    
    char* newArray = new char[totalLength + 1];
    
    for (int i = 0; i < m_length; i++) {
        newArray[i] = m_data[i];
    }
    for (int j = 0; j < rhs.m_length; j++) {
        newArray[m_length + j] = rhs.m_data[j];
    }
    newArray[totalLength + 1] = '\0';
    
    delete[] m_data;
    
    m_data = newArray;
    
    m_capacity = totalLength;
    m_length = totalLength;
    
    return *this;
}

String& String::operator+=(char* cstr) {
    cout << "Calling += char-sequence assignment" << endl;
    
    int length = 0;
    while (cstr[length] != '\0') {
        length++;
    }
    
    int totalLength = m_length + length;
    
    char* newArr = new char[totalLength + 1];
    
    for (int i = 0; i < m_length; i++) {
        newArr[i] = m_data[i];
    }
    for (int j = 0; j < length; j++) {
        newArr[m_length + j] = cstr[j];
    }
    newArr[totalLength + 1] = '\0';
    
    delete[] m_data;
    
    m_data = newArr;
    
    m_capacity += length;
    m_length = totalLength;
    
    return *this;
}

bool operator==(const String& lhs, const String& rhs) {
    // Next two if's maybe not needed?
    if (lhs.length() == 0 && rhs.length() != 0) {
        return false;
    }
    if (lhs.length() != 0 && rhs.length() == 0) {
        return false;
    }
    
    // Needed to avoid unnecessary looping
    if (lhs.length() != rhs.length()) {
        return false;
    }
    
    int max = (lhs.length() > rhs.length() ? lhs.length() : rhs.length());
    
    for (int i = 0; i < max; i++) {
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

//void String::reserve(int n) {
//    cout << "Calling reserve" << endl;
//    
//    cout << n << endl;
//    cout << m_length << endl;
//    
//    if (n > m_length) {
//        for (int i = m_length; i < n; i++) {
//            cout << "Adding char" << endl;
//            m_data[i] = *new char();
//        }
//    }
//}

void String::resize(int n) {
    cout << "Calling resize" << endl;
    
    char* newArray = new char[n + 1];
    
    int i = 0;
    while (i < m_length) {
        newArray[i] = m_data[i];
        i++;
    }
    newArray[i + 1] = '\0';
    
    // Delete old array
    delete[] m_data;
    
    // New pointers
    m_data = newArray;
    m_capacity = n;
}

void String::shrink_to_fit() {
    resize(m_length);
}

void String::push_back(char c) {
    int place = m_length;
    
//    cout << place << endl;
//    cout << m_capacity << endl;
    
    if (place >= m_capacity) {
        resize((m_capacity + 1) * 2);
        //reserve((m_capacity + 1) * 2);
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