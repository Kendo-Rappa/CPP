#include <iostream>
#include <locale>
#include <string>

class registro{
public:
	std::string name;
	float l_w; //liquid wage
};
				/*nome*/        /*horas*/  /*valor hora*/
registro coisas(std::string &n, float &h, float &v_h){
	
	float SB, inss, SL;
	
	SB = h * v_h;
	inss = SB * 0.89;
	SL = SB - inss;

	registro consultas;
	consultas.name = n;
	consultas.l_w = SL;
return consultas;
}

int main (){
	std::string nome;
	float horas, valor_hora;
	short int i, n_c=10;
	
	registro consultas [n_c] = {};
	
	for(i=0;i<n_c;i++){
		std::cout << "qual o nome do bastardo? " << std::endl;
		if(!(std::getline(std::cin, nome))){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		}
		std::cout << "quantas horas de trabalho foram concluidas?" << std::endl;
		if(!(std::cin >> horas) || horas < 0){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		}
		std::cout << "qual o valor cobrado pela hora? :-)" << std::endl;//sex?, YES PLEASE
		if(!(std::cin >> valor_hora) || valor_hora < 0){
			std::cerr << "erro de leitura" << std::endl;
		return 1;
		}
		consultas[i] = coisas(nome, horas, valor_hora); 
		std::cin.ignore();
	}
	for(i=0;i<n_c;i++){
		std::cout << "o trabalhador "<< consultas[i].name << " recebe " << consultas[i].l_w << " de salario" << std::endl;
	}

system("pause");
system("cls");
return 0;
}