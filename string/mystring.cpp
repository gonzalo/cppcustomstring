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
: str_len(0)
, cadena(nullptr)
{
    //constructur vacio
}

MyString::MyString(const char * origin)
{
    
    //constructor con inicializador
    this->cadena = nullptr;
    copy(origin);
    
    
}

MyString::MyString(MyString const &origin)
{
    //constructor de copia
    this->cadena = nullptr;
    copy(origin.cadena);
}

MyString::~MyString()
{
    delete[] cadena; //comproobar delete[]
}

int MyString::len()
{
    return str_len;
}


//operator = overload
//copy de origin string into member string

MyString& MyString::operator=(const MyString & origin)
{
    
    this->copy(origin.cadena);
    
    return *this;
    
}

//operator = overload
//points members to the new origin

MyString& MyString::operator=(const char * origin)
{
    
    delete[] this->cadena;
    this->str_len= (unsigned)strlen(origin);
    
    this->massive_copy(origin, this->cadena, 0, this->str_len+1);
    return *this;
    
}

//operator << overload
//just returns the char * with the contents of string
std::ostream& operator<< (std::ostream &out, const MyString & string)
{
    if (string.cadena!=nullptr)
        out << string.cadena;
    else
        out << "";
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
    nueva->massive_copy(string2.cadena, nueva->cadena, string1_len, string2_len+1); //+1 para que copie el '\0' final
    
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
    if (cadena!=nullptr)
        delete[] cadena;
    
    this->str_len = (unsigned)strlen(origin);
    this->cadena = new char[(this->str_len)+1]; //+1 para incluir el '\0'
    if (cadena==nullptr)
    {
        printf("ERROR: Memory could not be allocated");
        return 1;
    }
    
    massive_copy(origin, this->cadena, 0, this->str_len+1);
    
    return 0;
}


//massive_copy
//massive_copy copies the origin char* contents to destiny starting from init_point
//massive_copy assumes that destination char* has enough space to allocate all contents
//this function uses some tweaks in order to improve operation

void MyString::massive_copy(const char * origin, char * destination, int init_point, int string_length)
{
    //first method
    for (int i=0; i<string_length; i++) {
        destination[i+init_point]=origin[i];
    }
    
    //alternative method copying by blocks
    
    
    
    
    
}