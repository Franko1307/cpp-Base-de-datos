/*
  Autor: Francisco Enrique Córdova González
  Esta librería es para uso académico únicamente, contacto: franciscogonzalez1307@gmail.com
  Esta librería permite hacer una pila de cualquier tipo de dato que c++ permita
  como int,float,double,string,char,size_t, extensiones long, short etc...
  También permite hacer pilas dobles, donde metes dos datos a la vez
  Estas son apartes de la original y se almacenan en otro lugar.
  Es decir no están juntas.
  Última actualización 16/02/2016
*/
//Directivas al compilador
#pragma once //Para que se añade sólo una vez
#include<iostream>
#include <typeinfo>
#include <string>
#include "caja_d.h"

template <class T> struct caja {
  T valor;
  caja<T> *siguiente;
};
template <class T, class U = T> class pila {
private:
  caja<T> *principio;
  caja_doble<T,U> *principio_doble;
  size_t cantidad;
  size_t cantidad_doble;
public:
  pila(): cantidad(0), cantidad_doble(0), principio(NULL), principio_doble(NULL){};
  ~pila();
  void agregar (T a);
  void agregar (T a, U b);
  T quitar (); //Funciona sólo para las pilas unitarias
  void pintar();
  size_t obtener_cantidad(){return cantidad;};
  size_t obtener_cantidad_doble(){return cantidad_doble;};
  caja_doble<T,U> *obtener_agregado(){return principio_doble;};

};
/*
 * Destructor de la clase pila
 */
template <class T, class U> pila<T,U>::~pila() {
  caja<T> *p;
  caja_doble<T,U> *p_2;
  while (principio) {
    p = principio;
    principio = p->siguiente;
    delete p;
  }
  while (principio_doble) {
    p_2 = principio_doble;
    principio_doble = p_2->siguiente;
    delete p_2;
  }
  cantidad = 0;
  cantidad_doble = 0;
}
/*
 * Función que se encarga de agregar elementos a la pila
 * Parámetros:
 * T var; Es un elemento de la pila
 */
template <class T, class U> void pila<T,U>::agregar(T var) {
  //Construímos la nueva caja para meter a la pila
  caja<T> *nueva_caja = new caja<T>;
  //Asignamos el valor
  nueva_caja->valor = var;
  //Aquí se debería checar si hay algo o no, pero en este caso no es necesario
  //Ya que en ambos casos hacemos lo mismo
  nueva_caja->siguiente = principio;
  principio = nueva_caja;
  ++cantidad;
}
/*
 * Función que permite agregar dos elementos a una pila, dentro de la misma pila
 * Tenemos dos punteros, así que los elementos unitarios y dobles se almacenan
 * En diferentes lugares.
 */
 template <class T, class U> void pila<T,U>::agregar(T var, U var_2) {
   //Construímos una caja especial para dos elementos
   caja_doble<T,U> *nueva_caja = new caja_doble<T,U>;
   //Asignamos los valores
   nueva_caja->var = var;
   nueva_caja->var_2 = var_2;
   //Aquí se debería checar si hay algo o no, pero en este caso no es necesario
   //Ya que en ambos casos hacemos lo mismo
   nueva_caja->siguiente = principio_doble;
   principio_doble = nueva_caja;
   ++cantidad_doble;
 }
/*
 * Función que pinta la pila, es decir manda a consola todos sus elementos
 */
template <class T, class U> void pila<T,U>::pintar() {
  //Creamos un puntero para no modificar el puntero principio
  caja<T> *p = principio;
  caja_doble<T,U> *p_2 = principio_doble;
  if (principio != NULL) {
    //Utilizamos este puntero para recorrer toda la pila e ir imprimiendo sus elementos
    std::cout << "[";
    while (p) {
      std::cout << p->valor << ",";
      p = p->siguiente;
    }
    std::cout << "\b]" << std::endl;
  }
  if (principio_doble != NULL) {
    std::cout << "[";
    while (p_2) {
      std::cout << p_2->var << "|" << p_2->var_2 << ",";
      p_2 = p_2->siguiente;
    }
    std::cout << "\b]" << std::endl;
  }
}
/*
 * Función que se encarga de quitar un elemento de la pila y devolverlo
 */
template <class T, class U> T pila<T,U>::quitar() {
  //Variable para retornar el valor, ya que eliminaremos la caja
  T var;
  //Puntero para no modificar el puntero principio
  caja<T> *p;
  if (principio != NULL) {
    //Copiamos el valor del tope en p
    p = principio;
    //Movemos el principio
    principio = p->siguiente;
    //sacamos el valor de la caja
    var = p->valor;
    //Borramos la caja
    delete p;
    //Disminuimos la cantidad de elementos
    --cantidad;
    //Regresamos el valor
    return var;
    //Sino devolvemos basura que está en var, da igual.
  }else return var;
}
