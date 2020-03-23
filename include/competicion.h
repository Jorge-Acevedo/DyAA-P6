#pragma once
#include <iostream>
#include <cmath>
#include <vector>


class Competicion
{
    public:
    Competicion();
    ~Competicion();

    void formarTabla(std::vector<std::vector<int>> &tabla, int inf, int sup);
    void completarTabla(std::vector<std::vector<int>> &tabla, int infTeam, int supTeam, int infDay, int supDay, int initialTeam);
    void calendario(std::vector<std::vector<int>> &tabla);
};