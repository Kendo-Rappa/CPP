#include <iostream>
#include <locale.h>
#include <string>

class registros{
public:
	float salario_bruto, salario_liquido;
	std::string name;
};

registros calculos(std::string &n, float &h, float &v){
	float sb,sl;
	
	sb = h*v;
	
	if(sb<=800.00){
		sl = sb * 0.91;
	}
	else if(sb>=800.01 && sb<=1500.00){
		sl = sb * 0.9;
	}
	else{
		sl = sb * 0.89;
	}

	registros cadastro;
	cadastro.salario_bruto = sb;
	cadastro.salario_liquido = sl;
	cadastro.name = n;
	
return cadastro;
}

int main (){
	setlocale(LC_ALL, "portuguese");
	int n_r, i;
	float ht,vh;
	std::string nome;
	
	std::cout << "quantos registros vao ser feitos " << std::endl;
	if(!(std::cin >> n_r)){
		std::cerr << "erro de leitura \n";
		return 1;
	}
	std::cout << "1º nome \n2º horas trabalhadas \n3º valor da hora" << std::endl;
	
	registros cadastro[n_r] = {};
	
	for(i=0;i<n_r;i++){
		std::cin.ignore();
		std::getline(std::cin, nome);
		if(!(std::cin >> ht >> vh)){
			std::cerr << "erro de leitura";
			return 1;
		}
	cadastro[i] = calculos(nome, ht, vh);
	}
	std::cout <<"\n";
	
	for(i=0;i<n_r;i++){
		std::cout << "o funcionario " << cadastro[i].name << std::endl;
		std::cout << "recebe " << cadastro[i].salario_bruto << " de salario bruto" << std::endl;
		std::cout << "recebe " << cadastro[i].salario_liquido << " de salario liquido" << std::endl;
	}
return 0;
}