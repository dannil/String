#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <array>

using namespace std;

class String {
    
    private:
        char* content[];
        
    public:
        String();
        String(const String& rhs);
        //String(String&& rhs);
        String(const char* cstr);
        ~String();
        
        String& operator=(const String& rhs);
        //String& operator=(String&& rhs);
        String& operator=(const char* cstr);
        String& operator=(char ch);
        
        char& at(int i);
        char& operator[](int i);
        
        const char* data() const;
        int length() const;
        void reserve(int);
        int capacity() const;
        
        shrink_to_fit();
        void push_back(char c);
        resize(int n);
        
        String& operator+=(const String& rhs);
        String& operator+=(char* cstr);
        //operator+;
        friend bool operator==(const String& lhs, const String& rhs);
        
        //operator<<;
};

#endif