/*
 * Esta cabezera contiene la estructura base de una caja normal que puede
 * contener dos datos.
 * Autor: Francisco Enrique Córdova González
 * Última actualización: 17/02/16
 * Contacto: franciscogonzalez1307@gmail.com
 */
#pragma once
template <class T, class U> struct caja {
  T var;
  U var_2;
  caja<T,U> *siguiente;
};
