#include <iostream>
#include <stdlib.h>
#include <string>

class registro{
public:
	std::string name;
	int age;
	float renda_familiar;
	
};

registro calculos(std::string &n, int &i, float &r){

	if(i>=0 && i<=15){
		std::cout<< "categoria infantil " << std::endl;
	}
	else if(i>=16 && i<=18){
		std::cout << "categoria juvenil " << std::endl;
	}
	else{
		std::cout<< "categoria adulto " << std::endl;
	}
	
	if(r>=0 && r<=1000.00){
		std::cout<< "classe media baixa " << std::endl;
	}
	else if (r>=1000.01 && r<=3500.00){
		std::cout<< "classe media " << std::endl;
	}
	else{
		std::cout<< "classe media alta " << std::endl;
	}
	
	registro cadastro;
	cadastro.name = n;
	cadastro.age = i;
	cadastro.renda_familiar = r;

return cadastro;
}

int main(){
	setlocale (LC_ALL, "Portuguese");
	int n_r, i, idade;
	float renda;
	std::string nome;
	
	std::cout<<"quantas pessoas vai ser registradas? " << std::endl;
	if(!(std::cin>>n_r)){
		std::cerr<<"erro de leitura";
	return 1;
	};
	std::cout<<"coloque o nome, a idade e a renda familiar " << std::endl;
	
	registro cadastro [n_r] = {};
	
	for(i=0;i<n_r;i++){
		std::cin.ignore();
		std::getline (std::cin, nome);
		if (!(std::cin >> idade >> renda)){
			std::cerr << "erro de leitura";
		return 1;
		};
	cadastro[i] = calculos(nome, idade, renda);
	}
	
return 0;
}