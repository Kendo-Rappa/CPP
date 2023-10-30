#include <iostream>
#include <string>
#include <locale>
#include <vector>

class registro{
public:
	std::string name;
	short int age;
	char seggs;
};

registro calculos(std::string &n, char &s, short int &m, short int &I, std::vector<short int> math){//linha 74
	float media = 0, media_1 = 0;
	
	struct pessoa{
		std::string alguem;
		char sexy;
	};
	
	std::vector<pessoa> masculino;
	std::vector<pessoa> feminino;
	
	for(const auto& pessoa : math){
		media += pessoa;
		media_1 = media;
		if(pessoa.sexy == 'm' || pessoa.sexy == 'M' ){
			masculino.push_back(pessoa);
			media /= math.size();
		}
		else if (pessoa.sexy == 'f' || pessoa.sexy == "F"){
			feminino.push_back(pessoa);
			media_1 /= math.size();
		}
		else{
			std::cerr << "no seggs allowed, baka" <<std::endl;
		}
	}
	registro consultas;
	consultas.name = media_1;
	consultas.age = media;
	consultas.seggs=s;
return consultas;
}

int main(){

	std::string nome;
	short int mod, n, i, idade;
	char sex; /*YES please*/
	
	std::cout << "quantos atletas vai ser utilizados? " << std::endl;
	if(!(std::cin >> n) || n<=0){
		std::cerr << "registro invalido" << std::endl;
	return 1;
	}
	
	registro* consultas = new registro[n];
	
	std::vector<short int> mate;
	
	std::cin.ignore();
	
	for(i=0;i<n;i++){
		std::cout << "qual o nome do atleta?" << std::endl;
		if(!(std::getline (std::cin, nome))){
			std::cerr << "registro invalido" << std::endl; 
		return 1;
		}
		std::cout << "escolha o numero da modalidade esportiva" << std::endl;
		std::cout << "1 --> voley\n2 --> basquete\n3 --> futsal" << std::endl;
		if(!(std::cin >> mod) || (mod<=0 || mod>3)){
			std::cerr << "registro invalido" <<std::endl;
		return 1;
		}
		//std::cin.ignore();
		std::cout << "qual o sexo? (M ou F)" << std::endl;
		if((!(std::cin >>sex)) || (sex != 'm' && sex != 'M' && sex != 'f' && sex != 'F')){
			std::cerr << "seggs invalido" << std::endl;
		return 1;
		}
		std::cout << "qual a idade?" << std::endl;
		if(!(std::cin >> idade)){
			std::cerr << "registro invalido" << std::endl;
		return 1;
		}
		
		mate.push_back(idade, sex);
		
		consultas[i] = calculos (nome, sex, mod, idade, mate);
		std::cin.ignore();
	}
	// Perform operations with consultas array

	delete[] consultas; // Free the dynamically allocated memory, para evitar vazamentos de memoria
	
	for(i=0;i<n;i++){
		std::cout << "memento " << consultas[i].age <<std::endl;
		std::cout << "memento " << consultas[i].name <<std::endl;
	}

return 0;
}