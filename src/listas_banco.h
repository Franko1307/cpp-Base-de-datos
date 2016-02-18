#pragma once
#include "caja.h"

enum ENCONTRADO {SI,NO};
enum DONDE {VACIO, INICIO, MITAD, FINAL};

template <class T, class U> struct contenedor {
  caja<T,U> *valor;
  contenedor<T> *siguiente;
};
template <class T, class U = T> class lista_orden_1 {
private:
  contendedor<T,U> *principio, *anterior;
  ENCONTRADO encontrado;
  DONDE donde;
  void buscar(caja<T,U> *var);
public:
  lista_orden_1(): principio(NULL), encontrado(NO), donde(VACIO){};
  ~lista_orden_1();
  bool agregar(caja<T,U> *var);
  //bool borrar(caja<T,U> *var);
  void pintar();
};
template <class T, class U> void lista_orden_1::buscar(caja<T,U> *q) {
  if (!principio) {
    encontrado = NO;
    donde = VACIO;
    anterior = NULL;
    return;
  }
  contenedor<T,U> *p = principio;
  while (p) {
    if (p->valor->var == q->var && p->valor->var_2 == q->var_2) {
      encontrado = SI;
      if (p == principio) donde = INICIO;
      else if (p->siguiente == NULL) donde = FINAL;
      else donde = MITAD;
      return;
    } else if (p->valor->var < q->var) {
      anterior = p;
      p = p->siguiente;
    } else {
      encontrado = NO;
      if (p == principio) donde = INICIO;
      else if (p->siguiente == NULL) donde = FINAL;
      else donde = MITAD;
      return;
    }
  }
  encontrado = NO;
  donde = FINAL;
}
