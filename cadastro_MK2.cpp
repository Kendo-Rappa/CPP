#include <iostream>
#include <stdlib.h>
//bloco para calcular IMC
float IMC (float h, char s){
	float imc;
	if (s == 'm' || s =='M'){
		imc = 72.7 *h -58;
	}
	else if (s=='f' || s== 'F'){
		imc = 62.1 *h -44.7;
	}
	else{
		std::cout << "sexo invalido" << std::endl;
		imc = 0;
	}
return imc;
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	float imc_fem, imc_boy;
	int i;
	char y;
	
	struct corpo{
		float altura;
		int age;
		char sex; //YES PLEASE
	};
	corpo profile[2];
	
	std::cout << "coloque a altura, idade e o sexo (M ou F) ";
	
	for(i=0; i<2; i++){
		std::cin >> profile[i].altura >> profile[i].age >> profile[i].sex /*yes please*/;
	}
	for(i=0; i<2; i++){
		if(profile[i].sex == 'f' || profile[i].sex == 'F'){
			imc_fem= IMC(profile[i].altura, profile[i].sex);
			std::cout << "i IMC da mulher é " << imc_fem << std::endl;
		}
		else if (profile[i].sex == 'm' || profile[i].sex == 'M'){
			imc_boy= IMC(profile[i].altura, profile[i].sex);
			std::cout << "i IMC do homem é " << imc_fem << std::endl;
		}
		else{
			std::cout << "seggs inválido! " << std::endl;
		}
	}
return 0;
}