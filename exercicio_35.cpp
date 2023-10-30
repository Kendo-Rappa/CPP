#include <iostream>
#include <locale.h>
#include <string>

class registros{
public:
	std::string name;
	float extra;
};

registros calculos(std::string &n, int &c, float &h, int &t){//linha 46 e 47
	float s_ba, com;//salario base, comissao
	
	if (c==1){
		s_ba = h * 5.00;
	}
	else if (c==2){
		s_ba = h * 8.00;
	}
	else{
		std::cerr << "codigo nao cadastrado" << std::endl;
	}
	
	if(t==1){
		com = s_ba * 1.03;
	}
	else if(t==2){
		com = s_ba * 1.04;
	}
	else if(t==3){
		com = s_ba * 1.05;
	}
	else{
		std::cerr << "turno nao cadastrado" << std::endl;
	}
	
	registros coisas;
	coisas.extra=com;
	coisas.name=n;

return coisas;
}

int main(){
	std::string nome;
	float h_t;//hora trabalhadas, salario bruto
	int cod, n_r, i, tur;//codigo, numero registros, turno
	
	std::cout << "quantos registros serao feitos ";
	if(!(std::cin >> n_r)){
		std::cerr << "erro de leitura" << std::endl;
		return 1;
	}
	
	registros coisas[n_r] = {};
	
	if(n_r<=0){
		std::cerr << "erro de leitura";
		return 1;
	}
	else{
		std::cout << "entre com o nome, codigo do cargo, horas trabalhadas e o turno"<< std::endl;
		for(i=0; i<n_r; i++){
			std::cin.ignore();
			std::getline(std::cin, nome);
			if(!(std::cin >> cod >> h_t >> tur)){//linha 27 e 28
				std::cerr << " erro de leitura";
				return 1;
			}
		coisas[i] = calculos(nome, cod, h_t, tur);
		}
	}
	for(i=0;i<n_r;i++){
		std::cout << "o cliente " << coisas[i].name;
		std::cout << " recebe " << coisas[i].extra << " de salario" << std::endl;
	}
return 0;
}