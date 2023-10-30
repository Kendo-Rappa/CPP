#include <iostream>

int main (){
	int i;
	
	struct profile{
		std::string name;
		int idade;
		float salario;
		char sexo;
	};
	profile perfil[2];
	
	std::cout << "coloque o nome, idade, salario e sexo 'M' ou 'F' "<< std::endl;
	for (i=0;i<2;i++){
		std::cin >> perfil[i].name >> perfil[i].idade >> perfil[i].salario >> perfil[i].sexo;
	}
	for (i=0;i<2;i++){
		if(perfil[i].sexo == 'M' || perfil[i].sexo == 'm'){
			std::cout << "o homem tem " << perfil[i].idade << " anos";
		}
		else{
			std::cout << " e a mulher recebe " << perfil[i].salario << " mensalmente \n\n" ;
		}
	}
	
return 0;
}