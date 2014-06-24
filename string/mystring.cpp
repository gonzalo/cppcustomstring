//
//  string.cpp
//  string
//
//  Created by Gonzalo Cao on 21/06/14.
//  Copyright (c) 2014 ___NET_ZOOGON___. All rights reserved.
//

#include <iostream>
#include "mystring.h"


MyString::MyString()
: cadena(new char[1])
,str_len(0)
{
    cadena[0] = '\0';
}

MyString::MyString(const char * origin)
{
    
    //constructor con inicializador
    this->cadena = nullptr;
    this->copy(origin);
    
    
}

MyString::MyString(MyString const &origin)
{
    //constructor de copia
    this->cadena = nullptr;
    this->copy(origin.cadena);
}

MyString::~MyString()
{
    delete[] cadena;
}

int MyString::len()
{
    return this->str_len;
}

void MyString::append(char *append_string)
{
    int total, append_string_len, old_string_len;    
    char *old_string;
    
    old_string = this->cadena;
    old_string_len = this->str_len;
    
    append_string_len = (unsigned)strlen(append_string);
    total = old_string_len + append_string_len;
    this->cadena = new char[total+1];
    
    massive_copy(old_string, this->cadena, 0, old_string_len);
    massive_copy(append_string, this->cadena, old_string_len, append_string_len);
    
    delete [] old_string;
    
}

//operator = overload
//copy de origin string into member string

MyString& MyString::operator=(const MyString & origin)
{
    
    this->copy(origin.cadena);
    
    return *this;
    
}

//operator = overload
//point or assign?
//currently it makes a copy
MyString& MyString::operator=(const char * origin)
{

    this->copy(origin);
    return *this;
    
}

//operator << overload
//just returns the char * with the contents of string
std::ostream& operator<< (std::ostream &out, const MyString & string)
{
    out << string.cadena;

    return out;
}

//operator + overload
//generates a new string object combining both origin strings
MyString operator+ (MyString &string1, MyString &string2)
{
    MyString * nueva = new MyString();
    
    int string1_len = (unsigned)strlen(string1.cadena);
    int string2_len = (unsigned)strlen(string2.cadena);
    
    int total_len = string1_len+string2_len;
    
    nueva->str_len = total_len;
    
    nueva->cadena = new char[total_len+1];
    
    nueva->massive_copy(string1.cadena, nueva->cadena, 0, string1_len);
    nueva->massive_copy(string2.cadena, nueva->cadena, string1_len, string2_len);
    
    return *nueva;
}

char * MyString::out()
{
    return cadena;
}


//private copy function
//created to be used by char * constructuro a copy constructor
//prepares the object and then calls to massive copy function

int MyString::copy(const char * origin)
{
    char * old_string;
    old_string = this->cadena;
    
    this->str_len = (unsigned)strlen(origin);
    this->cadena = new char[(this->str_len)+1]; //+1 para incluir el '\0'
    
    massive_copy(origin, this->cadena, 0, this->str_len);
    
    delete[] old_string;
    
    return 0;
}


//massive_copy
//massive_copy copies the origin char* contents to destiny starting from init_point
//massive_copy assumes that destination char* has enough space to allocate all contents
//this function uses some tweaks in order to improve operation

void MyString::massive_copy(const char * origin, char * destination, int init_point, int string_length)
{
    //first method
    //for (int i=0; i<string_length; i++) {
    //    destination[i+init_point]=origin[i];
    //}

    //copy using memcpy
    memcpy(destination+init_point, origin, string_length);
    destination[init_point+string_length]='\0';
    
/*
    //alternative method copying by blocks

    wchar_t word;
    int wchar_t_size;
    int block_iterations;
    int remainder_iterations;
    int position = 0;
    
    wchar_t_size = sizeof(wchar_t);
    
    //we will copy char array using blocks of wchart_t_size in order to reduce
    //read and write operations
    
    block_iterations = string_length / wchar_t_size;
    remainder_iterations = string_length % wchar_t_size;

    //copy blocks
    for (int i = 0; i<block_iterations; i++)
    {
        position = init_point+i*wchar_t_size;
        word = origin[position];
        destination[position] = word;
    }
    
    //copy remainder
    for (int i = init_point+wchar_t_size*block_iterations; i<remainder_iterations; i++) {
        destination[i] = origin[i];
    }
*/
}