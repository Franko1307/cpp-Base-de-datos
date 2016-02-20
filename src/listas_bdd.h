#pragma once
#include "caja_d.h"

enum ENCONTRADO {SI,NO};
enum DONDE {INICIO, MITAD};

template <class T, class U> struct contenedor {
  caja_doble<T,U> *valor;
  contenedor<T,U> *siguiente;
};
template <class T, class U = T> class lista_orden_1 {
private:
  contenedor<T,U> *principio, *anterior;
  ENCONTRADO encontrado;
  DONDE donde;
  void buscar(caja_doble<T,U> *var);
public:
  lista_orden_1(): principio(NULL), anterior(NULL),encontrado(NO), donde(INICIO){};
  ~lista_orden_1();
  bool agregar(caja_doble<T,U> *var);
  void pintar();
};
template <class T, class U> lista_orden_1<T,U>::~lista_orden_1() {
  contenedor<T,U> *p;
  while (principio) {
    p = principio;
    principio = p->siguiente;
    delete p;
  }
  anterior = NULL;
  encontrado = NO;
  donde = INICIO;
}
template <class T, class U> void lista_orden_1<T,U>::buscar(caja_doble<T,U> *q) {
  if (!principio) {
    encontrado = NO;
    donde = INICIO;
    anterior = NULL;
    return;
  }
  contenedor<T,U> *p = principio;
  while (p) {
    if (p->valor->var == q->var && p->valor->var_2 == q->var_2) {
      encontrado = SI;
      if (p == principio) donde = INICIO;
      else donde = MITAD;
      return;
    }  else if (p->valor->var < q->var) {
      anterior = p;
      p = p->siguiente;
    } else if (p->valor->var == q->var) {
      if (p->valor->var_2 < q->var_2) {
        anterior = p;
        p = p->siguiente;
      } else {
        encontrado = NO;
        if (p == principio) donde = INICIO;
        else donde = MITAD;
        return;
      }
    } else {
      encontrado = NO;
      if (principio == p) donde = INICIO;
      else donde = MITAD;
      return;
    }
  }
  encontrado = NO;
  donde = MITAD;
}
template <class T, class U> bool lista_orden_1<T,U>::agregar(caja_doble<T,U> *q) {
  buscar(q);
  if (encontrado == SI) return false;
  contenedor<T,U> *p = new contenedor<T,U>;
  p->valor = q;
  if (donde == INICIO) {
    p->siguiente = principio;
    principio = p;
  } else {
    p->siguiente = anterior->siguiente;
    anterior->siguiente = p;
  }
  return true;
}
template <class T, class U> void lista_orden_1<T,U>::pintar() {
  contenedor<T,U> *p = principio;
  std::cout << "{ ";
  while (p) {
    std::cout << "[" <<p->valor->var << " " << p->valor->var_2 << "] ";
    p = p->siguiente;
  }
  std::cout << "}" << std::endl;
}
//--------------------------------------------------------------------
template <class T, class U> class lista_orden_2 {
private:
  contenedor<T,U> *principio, *anterior;
  ENCONTRADO encontrado;
  DONDE donde;
  void buscar(caja_doble<T,U> *var);
public:
  lista_orden_2(): encontrado(NO), donde(INICIO), principio(NULL), anterior(NULL){};
  ~lista_orden_2();
  bool agregar(caja_doble<T,U> *var);
  void pintar();
};
template <class T, class U> lista_orden_2<T,U>::~lista_orden_2() {
  contenedor<T,U> *p = principio;
  while (principio) {
    p = principio;
    principio = p->siguiente;
    delete p;
  }
  anterior = NULL;
  donde = INICIO;
  encontrado = NO;
}
template <class T, class U> void lista_orden_2<T,U>::buscar(caja_doble<T,U> *q) {
  if (principio == NULL) {
    encontrado = NO;
    donde = INICIO;
    anterior = NULL;
    return;
  }
  contenedor<T,U> *p = principio;
  while (p) {
    if (p->valor->var == q->var && p->valor->var_2 == q->var_2) {
      encontrado = SI;
      if (p == principio) donde = INICIO;
      else donde = MITAD;
    }
    else if (p->valor->var_2 < q->var_2) {
      anterior = p;
      p = p->siguiente;
    } else if (p->valor->var_2 == q->var_2) {
      if (p->valor->var < q->var_2){
        anterior = p;
        p = p->siguiente;
      } else {
        encontrado = NO;
        if (principio == p) donde = INICIO;
        else donde = MITAD;
        return;
      }
    } else {
      encontrado = NO;
      if (principio == p) donde = INICIO;
      else donde = MITAD;
      return;
    }
  }
  encontrado = NO;
  donde = MITAD;
}
template <class T, class U> bool lista_orden_2<T,U>::agregar(caja_doble<T,U> *q) {
  buscar(q);
  if (encontrado == SI) return false;
  contenedor<T,U> *p = new contenedor<T,U>;
  p->valor = q;
  if (donde == INICIO) {
    p->siguiente = principio;
    principio = p;
  } else {
    p->siguiente = anterior->siguiente;
    anterior->siguiente = p;
  }
  return true;
}
template <class T, class U> void lista_orden_2<T,U>::pintar() {
  contenedor<T,U> *p = principio;
  std::cout << "{ ";
  while (p) {
    std::cout << "[" <<p->valor->var_2 << " " << p->valor->var << "] ";
    p = p->siguiente;
  }
  std::cout << "}" << std::endl;
}
