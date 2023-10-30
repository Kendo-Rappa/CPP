#include <iostream>
#include <locale.h>

int main (){
	setlocale(LC_ALL, "Portuguese");//possibilita usar caracteres especiais do Portugues
	float speed,res; 
	
	std::cout << "coloque a velocidade em m/s ";
	std::cin >> speed; 
	
	res = speed * 3.6;/*calculo da velocidade*/
	
	std::cout << " sua velocidade é " << res << " km/h";
	return 0;
}