#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String {
    
    private:
        char* m_data;
        
        int m_capacity;
        int m_length;
        
    public:
        String();
        String(const char* cstr);
        String(const String& rhs);
        //String(String&& rhs);     // VG
        ~String();
        
        String& operator=(const String& rhs);
        //String& operator=(String&& rhs);      // VG
        String& operator=(const char* cstr);
        String& operator=(char ch);
        String& operator+=(const String& rhs);
        String& operator+=(char* cstr);
        friend bool operator==(const String& lhs, const String& rhs);
        
        char& at(int i);
        char& operator[](int i) const;
        
        const char* data() const;
        int length() const;
        void reserve(int);
        int capacity() const;
        
        //shrink_to_fit();      // VG
        void shrink_to_fit();
        void push_back(char c);
        //resize();
        void resize(int n);
};

String operator+(String a, const String& b);
ostream& operator<<(std::ostream &strm, const String &s);

#endif