#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <sstream> /*biblioteca que ajuda na manipulaçao direta das entradas e saidas do vetor*/

int main (){/*funciona mas esta com problemas de dupla entrada*/

	std::vector<short int> idade;
	
	short int valor;
	char r;
	
	std::cout << "iniciar o vetor? {y/n} ";
	while (!(std::cin >> r) && (r!= 'Y' || r!= 'y' || r!= 'N' || r!= 'n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Entrada errada. Tente novamente: ";
    }				   
	bool is_num = true;
	
	while(r=='y' || r=='Y'){
		std::cout << "valores do vetor: ";
		std::string input;/*cia uma string chamad input*/
		std::cin.ignore();/*limpa a memoria*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');/*apaga o lixo da memoria*/
		if(!(std::getline(std::cin, input))){/*compara a entrada dos dados em o bool*/
			is_num = false;
		}
		while(!is_num){/*valida os dados se sao letras ou numeros*/
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "entrada errada. Tente novamente ";
			if(!std::getline(std::cin, input)){
				is_num = false;
			}
			else{
				is_num = true;
			}
		}
		std::istringstream stream(input);
		while(stream >> valor){
			idade.push_back(valor);
		}
		std::cout << "mais numeros? {y/n}";
		while (!(std::cin >> r) && (r!= 'Y' || r!= 'y' || r!= 'N' || r!= 'n')) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Entrada invalida. Tente Novamente: ";
		}
	}
	
	is_num = true;
	
	for(const short int& val: idade){/*mostra os itens do vetor*/
		std::cout << val << " ";
	}
	
	std::cout << std::endl << "o tamanho do vetor é: " << idade.size() << std::endl;
	std::cout << "the end";
return 0;
}