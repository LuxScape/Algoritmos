#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "header.h"
#include <numeric>

int minimoComunMultiplo(int a, int b) {
    return abs(a * b) / std::gcd(a, b);
}

//Ejercicio 2.1
void Ejercicio2_1() {
	int casos;
	std::cin >> casos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    unsigned long long LCMfin;

	for (int i = 0; i < casos; i++) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);

        std::vector<int> periodo;
        int value;
        while (iss >> value) {
            periodo.push_back(value);
        }
        std::sort(periodo.begin(), periodo.end(),std::greater<int>());
        LCMfin = minimoComunMultiplo(periodo[0],periodo[1]);

        for (int p = 2; p < periodo.size(); p++) {
            LCMfin = std::lcm(LCMfin, periodo[p]);
        }
        std::cout << LCMfin << std::endl;
	}
}

void Ejercicio2_2() {
    int casos;
    std::cin >> casos;
    
    for (int i = 0; i < casos; i++) {
        int num;
        std::cin >> num;
        int cont = 0;

        for (int p = 1; p < num + 1; p++) {
            if (num % p == 0) {
                cont += 1;
            }
        }
        std::cout << cont << std::endl;
    }
}
int calculadora(int a, int b, int c) {
    int MCD;
    MCD = std::gcd(a, b);
    MCD = std::gcd(MCD, c);

    return (a / MCD) + (b / MCD) + (c / MCD);
}
void Ejercicio2_3() {
    int casos;
    std::cin >> casos;

    for (int i = 0; i < casos; i++) {
        unsigned long long a;
        unsigned long long b;
        unsigned long long c;

        std::cin >> a >> b >> c;
        std::vector<unsigned long long> lista;
        lista.push_back(a); lista.push_back(b); lista.push_back(c);
        std::sort(lista.begin(), lista.end(), std::greater<unsigned long long>());
        std::cout << calculadora(lista[0], lista[1], lista[2]) << std::endl;
    }
}