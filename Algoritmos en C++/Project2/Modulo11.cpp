#include <iostream>
#include <vector>
#include <sstream>
#include "header.h"

//Ejercicio 11.1//
int CalculadoraBilletes(int M, const std::vector<int> denominaciones) {
    std::vector<int> LisRes(M + 1, std::numeric_limits<int>::max());
    LisRes[0] = 0;

    for (int d : denominaciones) {
        for (int i = d; i <= M; i++) {
            LisRes[i] = std::min(LisRes[i], LisRes[i - d] + 1);
        }
    }

    return LisRes[M];
}

void Ejercicio11_1() {
    int Casos;
    std::cin >> Casos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < Casos; i++) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);

        std::vector<int> Deno;
        int value;
        while (iss >> value) {
            Deno.push_back(value);
        }

        int Cantidad = Deno[0];
        Deno.erase(Deno.begin());

        int cantidad_billetes = CalculadoraBilletes(Cantidad, Deno);

        std::cout << cantidad_billetes << std::endl;
    }
}

//Ejercicio 11.2//
int max_ciudades(std::string Sug1, std::string Sug2) {
    int Num1 = Sug1.length();
    int Num2 = Sug2.length();
    std::vector<std::vector<int>> LisRes(Num1 + 1, std::vector<int>(Num2 + 1, 0));

    for (int i = Num1 - 1; i >= 0; i--) {
        for (int j = Num2 - 1; j >= 0; j--) {
            if (Sug1[i] == Sug2[j]) {
                LisRes[i][j] = LisRes[i + 1][j + 1] + 1;
            }
            else {
                LisRes[i][j] = std::max(LisRes[i + 1][j], LisRes[i][j + 1]);
            }
        }
    }

    return LisRes[0][0];
}

void Ejercicio11_2() {
    int Casos;
    std::cin >> Casos;

    for (int i = 0; i < Casos; i++) {
        std::string Sug1, Sug2;
        std::cin >> Sug1 >> Sug2;

        int max_num_ciudades = max_ciudades(Sug1, Sug2);
        std::cout << max_num_ciudades << std::endl;
    }
}


//Ejercicio 11.3//
const int INF = 1e9;

void Ejercicio11_3() {
    int cases;
    std::cin >> cases;

    for (int a = 0; a < cases; a++) {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> ResGra(n, std::vector<int>(n, INF));

        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                std::string input;
                std::cin >> input;
                if (input == "*") {
                    ResGra[b][c] = INF;
                }
                else {
                    ResGra[b][c] = std::stoi(input);
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ResGra[i][j] = std::min(ResGra[i][j], ResGra[i][k] + ResGra[k][j]);
                }
            }
        }

        std::cout << ResGra[0][n - 1] << std::endl;
    }
}