//
//  string.h
//  string
//
//  Created by Gonzalo Cao on 21/06/14.
//  Copyright (c) 2014 ___NET_ZOOGON___. All rights reserved.
//

#ifndef __string__string__
#define __string__string__

#include <iostream>


class MyString{
    
    char * cadena;
    int str_len;

public:
    MyString ();//empty constructor
    MyString (const char * origin); //initialize constructor
    MyString (MyString const & origin); //copy constructor
    
    ~MyString(); //destructor
    
    int len();
    void append(char * append_string);

    MyString & operator = (const MyString &origin);
    MyString & operator = (const char * origin);

    friend std::ostream& operator<< (std::ostream&, const MyString &string);
    friend MyString operator+ (MyString &string1, MyString &string2);

private:
    char * out(); //DEPRECATED by operator<< overload
    int copy(const char * origin);
    void massive_copy(const char * origin, char * destination, int init_point, int string_length);
    
    
};



#endif /* defined(__string__string__) */
