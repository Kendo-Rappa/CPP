#include <iostream>
#include <locale.h>
#include <cmath>//biblioteca para utilizar pow de forma mais facil

class result{//classe funciona tipo struct
public://universal
	int mais, menos, vezes, quociente, resto_divisao;
	float potencia;//o que vai ser classificado
};

result calculos (int &a, int &b){//result aqui é o nome do bloco da classe
	int som, sub, mult, quoc, rest;
	float po;//variaveis a serem calculadas
	som = a + b;
	sub = a - b;
	mult = a * b;
	if(b!=0){
		quoc = a / b;
		rest = a % b;
	}
	po = pow(a,b); // pow = potencia (A^B) = A elevado a B
	
	result resultado;//result aqui é da classificaçao em class
	resultado.mais = som;
	resultado.menos = sub;
	resultado.vezes = mult;
	if(b!=0){
		resultado.quociente = quoc;
		resultado.resto_divisao = rest;
	}
	resultado.potencia = po;
	
return resultado;//returna os resultado da linha 20 ate 25
}

int main(){
	setlocale(LC_ALL, "Portuguese");//portuga
	int num, num_1;
	
	std::cout << "quais os numero a ser utilizados? ";
	std::cin >> num >> num_1;
	
	result resultado /*msm coisa linha 21*/ = calculos(num, num_1); //coloca os valores na linha 10
	
	std::cout << "o resultado da soma é " << resultado.mais << std::endl;
	std::cout << "o resultado da subtração é " << resultado.menos << std::endl;
	std::cout << "o resultado da multiplicação é " << resultado.vezes << std::endl;
	std::cout << "o valor do quociente é de " << resultado.quociente << std::endl;
	std::cout << "o valor do resto é de " << resultado.resto_divisao << std::endl;
	std::cout << "o resultado da potencia é de " << resultado.potencia << std::endl;
	
return 0;
}