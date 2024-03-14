#include <iostream>
#include <vector>
#include <algorithm>
#include "Header.h"
#include <sstream>


//Ejercicio 10.3//
int Knapsack(const std::vector<std::pair<int, int>>& Prod, const std::vector<int>& Capa) {
    std::vector<int> Lis(81, 0);
    for (const auto& prod : Prod) {
        int c = prod.first;
        int w = prod.second;
        for (int j = 80; j >= w; j--) {
            Lis[j] = std::max(Lis[j], Lis[j - w] + c);
        }
    }

    int Res = 0;
    for (int cap : Capa) {
        Res += Lis[cap];
    }

    return Res;
}

void Ejercicio10_3() {
    int ProdMercado;
    std::cin >> ProdMercado;

    std::vector<std::pair<int, int>> LisProd;
    for (int i = 0; i < ProdMercado; i++) {
        int Costo, Peso;
        std::cin >> Costo >> Peso;
        LisProd.push_back(std::make_pair(Costo, Peso));
    }

    int Familia;
    std::cin >> Familia;

    std::vector<int> LisCap;
    for (int i = 0; i < Familia; i++) {
        int Cap;
        std::cin >> Cap;
        LisCap.push_back(Cap);
    }

    std::cout << Knapsack(LisProd, LisCap);
}