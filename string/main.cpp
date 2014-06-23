//
//  main.cpp
//  string
//
//  Created by Gonzalo Cao on 21/06/14.
//  Copyright (c) 2014 ___NET_ZOOGON___. All rights reserved.
//

#include <iostream>
#include "mystring.h"

int main(int argc, const char * argv[])
{

    //pruebas estáticas
    
    //cadena vacia
    MyString st_cadena_vacia;
    
    std::cout << "Pruebas estáticas"<< std::endl;
    std::cout << "Cadena vacia << " << st_cadena_vacia << std::endl;
    
    
    //cadena inicializada con char*
    MyString st_cadena_inicializada("cadena inicilizada con char*");

    std::cout << "Cadena inic. con char* len: " << st_cadena_inicializada.len() << std::endl;
    std::cout << "Cadena inic. con char* << " << st_cadena_inicializada << std::endl;
    
    //constructor de copia
    
    MyString st_cadena_copiada(st_cadena_inicializada);
    
    std::cout << "Cadena copiada << " << st_cadena_copiada<< std::endl;
    

    //prueba operador suma
    MyString cadena_para_suma_1("Primera parte");
    MyString cadena_para_suma_2("Segunda parte");
    
    std::cout << "Cadena sumada = " << cadena_para_suma_1 + cadena_para_suma_2 << std::endl;
    
    //pureba asignación desde string
    MyString cadena_para_asignar_origen("cadena para asignar");
    MyString cadena_para_asignar_destino_vacia;
    MyString cadena_para_asignar_destino_inicializada("cadena inicializada");
    
    cadena_para_asignar_destino_vacia=cadena_para_asignar_origen;
    cadena_para_asignar_destino_inicializada=cadena_para_asignar_origen;
    
    std::cout << "Cadena para asignar vacia : " << cadena_para_asignar_destino_vacia << std::endl;
    std::cout << "Cadena para asignar inicializada : " << cadena_para_asignar_destino_inicializada << std::endl;
    
    std::cout << "Cambio el contenido de cadena_para_asignar_origen" << std::endl;
    
    cadena_para_asignar_origen = "Esta es la nueva cadena en origen";
    
    std::cout << "Cadena para asignar origen : " << cadena_para_asignar_origen << std::endl;
    std::cout << "Cadena para asignar asignada : " << cadena_para_asignar_destino_vacia << std::endl;
    //prueba
    
    //pruebas dinámicas
    
    //prueba inicializador vacío
    MyString  * cadena_vacia = new MyString();
    std::cout << "Cadena_vacia.len=" << cadena_vacia->len() << "\n";
    std::cout << "Cadena_vacia content= " << *cadena_vacia << std::endl;
    
    //prueba inicializador con char *
    char cadena_ejemplo[40] = "esto es una cadena de ejemplo";
    MyString * cadena_inicializada = new MyString(cadena_ejemplo);
    
    std::cout << "Cadena_inicializada.len=" << cadena_inicializada->len() << "\n";
    std::cout << "Cadena_inicializada.cadena=" << *cadena_inicializada << "\n";

    
    //prueba constructor de copia
    MyString * cadena_copiada = new MyString(*cadena_inicializada);
    
    std::cout << "Cadena_copiada.len=" << cadena_copiada->len() << "\n";
    std::cout << "Cadena_copiada.cadena=" << *cadena_copiada << "\n";
    
    //prueba operador de salida
    std::cout << "cadena copiada << overload =" << *cadena_copiada << "\n";
    
    //prueba operador de asignación desde char *
    *cadena_copiada = *cadena_inicializada;
    
    std::cout << "sobre Cadena_copiada.len=" << cadena_copiada->len() << "\n";
    std::cout << "sobre Cadena_copiada.cadena=" << *cadena_copiada << "\n";

    
    cadena_vacia->~MyString();
    cadena_copiada->~MyString();
    
    return 0;
}

//dudas que me han ido surgiendo

//¿el operador de asignación debería realizar una copia o directamente reapuntarse al
//nuevo objeto? en caso de reapuntar ¿reapuntar al objeto o a los miembros de la clase?
//¿qué pasa con la asignación del tipo a = b + c

//¿estoy haciendo la liberación de memoria de la forma correcta?


