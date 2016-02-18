/*
 * Esta cabezera contiene la estructura base de una caja normal que puede
 * contener un dato.
 * Autor: Francisco Enrique Córdova González
 * Última actualización: 17/02/16
 * Contacto: franciscogonzalez1307@gmail.com
 */
#pragma once
template <class T> struct caja {
  T var;
  caja<T> *siguiente;
};
