#include "../include/competicion.h"

Competicion::Competicion() {}

Competicion::~Competicion() {}

void Competicion::formarTabla(std::vector<std::vector<int>> &tabla, int inf, int sup)
{
  int medio;
  if (sup - inf == 1)
  {
    tabla[inf][0] = sup;
    tabla[sup][0] = inf ;
  }
  else
  {
    medio = (inf + sup) / 2;
    formarTabla(tabla, inf, medio);
    formarTabla(tabla, medio + 1, sup);
    completarTabla(tabla, inf, medio, medio - inf, sup - inf - 1, medio + 1);
    completarTabla(tabla, medio + 1, sup, medio - inf, sup - inf - 1, inf);
  }
}

void Competicion::completarTabla(std::vector<std::vector<int>> &tabla, int infTeam, int supTeam, int infDay, int supDay, int initialTeam)
{
  for (int j = infDay; j <= supDay; j++)
  {
    tabla[infTeam][j] = initialTeam + j - infDay; 
  }
  for (int i = infTeam + 1; i <= supTeam; i++)
  {
    tabla[i][infDay] = tabla[i - 1][supDay];
    for (int j = infDay + 1; j <= supDay; j++)
    {
      tabla[i][j] = tabla[i - 1][j - 1];
    }
  }
}

void Competicion::calendario(std::vector<std::vector<int>> &tabla)
{
  formarTabla(tabla, 0, tabla.size() - 1);
}

