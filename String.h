#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String {
    
    private:
        char* m_data;
        
        int m_capacity;
        
    public:
        String();
        String(const char* cstr);
        String(const String& rhs);
        //String(String&& rhs);
        ~String();
        
        String& operator=(const String& rhs);
        //String& operator=(String&& rhs);
        String& operator=(const char* cstr);
        String& operator=(char ch);
        
        char& at(int i);
        char& operator[](int i) const;
        
        const char* data() const;
        int length() const;
        void reserve(int);
        int capacity() const;
        
        //shrink_to_fit();
        //void shrink_to_fit();
        void push_back(char c);
        //resize();
        void resize(int n);
        
        String& operator+=(const String& rhs);
        String& operator+=(char* cstr);
        //operator+;
        friend bool operator==(const String& lhs, const String& rhs);
};

ostream& operator<<(std::ostream &strm, const String &s);

#endif