#include <iostream>
#include <stdlib.h>
#include <string>

class registro{
public:
	std::string name;
	int turn;
};

registro coisa(std::string &n, int &t){
	setlocale (LC_ALL, "Portuguese");
	switch(t){
		case 1:
			std::cout << "o funcionario " << n << " recebe R$450,00" << std::endl;
			break;
		case 2:
			std::cout << "o funcionario " << n << " recebe R$490,00" << std::endl;
			break;
		case 3:
			std::cout << "o funcionario " << n << " recebe R$650,00" << std::endl;
			break;
		default:
			std::cerr << "erro de leitura" << std::endl;
			break;
	}
	registro consulta;
	consulta.name = n;
	consulta.turn = t;

return consulta;
}

int main(){
	setlocale (LC_ALL, "Portuguese");
	std::string nome;
	int turno, n_c, i;
	
	std::cout << "quantos consultas vao ser feitas? " << std::endl;
	if(!(std::cin >> n_c)){
		std::cerr << "erro de leitura" << std::endl;
	return 1;
	};
	
	registro consulta [n_c] = {};
	
	for(i=0;i<n_c;i++){
		std::cin.ignore();
		std::cout << "qual o nome do funcionario a ser consultado? " << std::endl;
		if(!(std::getline (std::cin >> nome))){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		};
		std::cout << "qual o turno do funcionario? " << std::endl;
		if(!(std::cin >> turno)){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		};
	consulta[i] = coisa(nome, turno);
	}
return 0;
}