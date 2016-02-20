#pragma once
#include "listas_bdd.h"
#include "pila.h"
#include "caja_d.h"

template <class T, class U = T> class bdd {
private:
  pila<T,U> *A;
  lista_orden_1<T,U> *B;
  lista_orden_2<T,U> *C;
public:
  bdd();
  ~bdd();
  void agregar(T,U);
  void pintar_1(){B->pintar();};
  void pintar_2(){C->pintar();};
};
template <class T, class U> bdd<T,U>::bdd() {
  A = new pila<T,U>;
  B = new lista_orden_1<T,U>;
  C = new lista_orden_2<T,U>;
}
template <class T, class U> bdd<T,U>::~bdd() {
  delete A;
  delete B;
  delete C;
}
template <class T, class U> void bdd<T,U>::agregar(T var, U var_2) {
  A->agregar(var,var_2);
  caja_doble<T,U> *p = A->obtener_agregado();
  B->agregar(p);
  C->agregar(p);
}
