#include <iostream>
#include <locale.h> //biblioteca para usar o idioma em portugues
#include <iomanip> // biblioteca para usar o "fixed" com "setprecision"

float temperatura (float &f){
	float c;
	c =(5.0/9.0) * (f-32);//converte a temperatura
	return c; //retorna o C em F para  usar no X em baixo
}
int main (){
	setlocale(LC_ALL, "Portuguese");//setup do idioma
	
	float temp, x;
	
	std::cout << "qual a temperatura em Fahrenheit? ";
	std::cin >> temp;
	/**/
  //V X é usado para armazenar o resultado de temperatura(temp) 
	x= temperatura(temp);/*joga a temperatura em Fahrenheit para o bloco Temperatura*/
	
	std::cout << "em Celscios é " << std::fixed << std::setprecision(2) << x;
								   //^^^^^^^^^^			  VVVVVVVVVV
							/*esqueci para o que serve*/ /*coloca a precisao em 2 numeros na casa decimal*/
return 0;
}