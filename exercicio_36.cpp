#include <iostream>
#include <stdlib.h>
#include <locale>
#include <string>

class registro{
public:
	std::string name;
	int child;
};

registro coisas(std::string &n, int &c){

	if(c==1){
		std::cout << "voce possui um desconto de 10% na mensalidade" << std::endl;

	}
	else if(c==2 || c==3){
		std::cout << "voce possui um desconto de 15% na mensalidade" << std::endl;

	}
	else if(c>=4){
		std::cout << "voce possui um desconto de 20% na mensalidade" << std::endl;

	}
	else {
		std::cerr << "erro de leitura" << std::endl;

	}

	registro consulta;
	consulta.name = n;
	consulta.child = c;

return consulta;
}

int main(){
	setlocale (LC_ALL, "Portuguese");
	std::string nome;
	int cria, n_c,i;
	
	std::cout << "quantas consultas? " << std::endl;
	if(!(std::cin >> n_c)){
		std::cerr << "erro de leitura" << std::endl;
	return 1;
	};
	
	registro consulta [n_c] = {};
	
	for(i=0;i<n_c;i++){
		std::cin.ignore();
		std::cout << "qual o nome do responsavel? " << std::endl;
		if(!(std::getline (std::cin >> nome))){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		};
		std::cout << "quantos filhos estao matriculados " << std::endl;
		if(!(std::cin >> cria)){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		};
	consulta[i] = coisas(nome,cria);
	}
return 0;
}