#include <iostream>
#include <vector>
#include <sstream>
#include "header.h"

//Ejercicio 1.1
void Ejercicio1_1() {
	int casos;
	std::cin >> casos;

	for (int  i = 0; i < casos; i++)
	{
		int Num;
		std::cin >> Num;

		float Res = sqrt((pow(Num,2) + Num) / 2);
		
		if (std::fmod(Res,1.0) == 0) {
			std::cout << Res << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}

//Ejercicio 1.2
void Ejercicio1_2() {
	while (true) {
		int M;
		std::cin >> M;

		if (M == 0) {
			break;
		}
		else {
			int cont=0;

			for (int i = 3; i < M; i++) {
				int sumizq = (((i - 1) * i * (2 * i - 1)) / 6);
				int sumder = ((M * (M + 1) * (2 * M + 1)) / 6) - (sumizq + pow(i,2));

				if (sumder % sumizq == 0) {
					cont += 1;
				}

			}
			std::cout << cont << std::endl;
		}
	}
}

unsigned long long Exponencial(int Base, int Exponente) {
	if (Exponente == 0)
		return 1;
	else if (Exponente % 2 == 0)
		return (Exponencial(Base, Exponente / 2) * Exponencial(Base, Exponente / 2)) % 49999;
	else
		return (Base * Exponencial(Base, Exponente / 2) * Exponencial(Base, Exponente / 2)) % 49999;
}

//Ejercicio 1.3
void Ejercicio1_3() {
	int casos;
	std::cin >> casos;

	for (int i = 1; i < casos+1; i++)
	{
		int sum = 0;
		int n;
		int p;
		std::cin >> n >> p;

		for (int k = 1; k < n+1; k++)
		{
			sum += Exponencial(k,p) % 49999;
		}
		sum =sum % 49999;
		std::cout << sum << std::endl;
	}
}