#include <iostream>
#include "bdd.h"

int main() {
  bdd<std::string,std::string> A;
  A.agregar("Cordova Gonzalez", "Francisco Enrique");
  A.agregar("Gutierrez Mendivil", "Daniel Alejandro Ramon");
  A.agregar("Chacon Palacios", "Sergio Shteffan");
  A.agregar("Bustamante Rendon", "Diego Eugenio");
  A.agregar("Castillo Lopez", "Rafael Alejandro");
  A.agregar("Salcido Ruiz", "Fernando");
  A.agregar("Gonzalez Urias", "Julia");
  std::cout << std::endl;
  A.pintar_1();
  std::cout << std::endl;
  A.pintar_2();
  std::cout << std::endl;

  return 0;
}
