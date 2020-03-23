#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "include/competicion.h"

using namespace std;

bool areArgumentsValid(int argc, char *argv[])
{

  if (argc == 2)
  {
    return 1;
  }
  cout << "Opciones no válidas :(\nModo de uso: ./competition n m\nn: número de equipos" << endl;
  return 0;
}

void printTable (std::vector<std::vector<int>> &tabla) {
  std::cout << "----Tabla final----" << std::endl;
  std::cout << " ";
  for (int i = 0; i < tabla.size() - 1; i++) {
    std::cout << " " << i + 1;
  }
  std::cout << std::endl;
  for (int i = 0; i < tabla.size(); i++) {
    std::cout << i + 1;
    for (int j = 0; j < tabla[i].size(); j++) {
      std::cout << " " << tabla[i][j] + 1;
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[])
{
  if (!areArgumentsValid(argc, argv))
  {
    return -1;
  }

  std::vector<std::vector<int>> tabla;
  double nequipos = atoi(argv[1]);
  
  tabla.resize(nequipos);
  for (int i = 0; i < tabla.size(); i++) {
    tabla[i].resize(nequipos - 1);
  }

  
  Competicion trofeoRectora;
  trofeoRectora.calendario(tabla);
  printTable(tabla);
}

