/*
 * Esta cabezera contiene la estructura base de una caja normal que puede
 * contener dos datos.
 * Autor: Francisco Enrique Córdova González
 * Última actualización: 17/02/16
 * Contacto: franciscogonzalez1307@gmail.com
 */
#pragma once
template <class T, class U> struct caja_doble {
  T var;
  U var_2;
  caja_doble<T,U> *siguiente;
};
