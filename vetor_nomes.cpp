#include <iostream>
#include <vector>
#include <limits>/*serve para achar o limites*/
#include <cctype> // Para usar isdigit

int main (){
	
	char r;
	std::vector<std::string> names;/*transforma a string em um Vetor para armazenar letras no vetor*/
	
	std::cout << "deseja adicionar o nome? {Y/N} ";
	while(!(std::cin >> r) || (r!='Y' && r!='y' && r!='N' && r!='n')){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Entrada invalida. Tente Novamente: ";
	}
	
	while(r=='y' || r=='Y'){/*compara a entrada da resposta de {Y/N}*/
		std::string name;/*cria a String para dar entrada nos nomes ou letras*/
		std::cout << "qual o nome? ";
		std::cin >> std::ws;/*apaga os espaços em branco depois da ultima entrada de dados*/
		std::getline(std::cin, name);/*pega o texto digitado por completo indiferente do tamanho para a String*/
	
		bool containsDigit = false;
		
		for (char c : name){/*variavel temporaria usanda apenas para fazer a chamada de verificaçao*/
			if(std::isdigit(c)){/*verifica se por acaso tem numeros no meio das letras*/
				containsDigit = true;
			}
		}
		if(containsDigit){/*faz a comparaçao para ver se esta entrando errado ou nao */
			std::cerr << "o nome deve conter apenas letras" << std::endl;
		}
		else{
			names.push_back(name);/*da entrada dos nomes na String para o Vetor*/
		}
		std::cout << "deseja colocar mais nomes? {y/n}" << std::endl;
		while(!(std::cin >> r) || (r!='Y' && r!='y' && r!='N' && r!='n')){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Entrada invalida. Tente Novamente: ";
		}/*usado para continuar no loop ou sair dele*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');/*limpa a memoria da entrada*/
	}	
	/*exibe nomes inseridos*/
	for (const std::string& name : names){/*fas aparecer os nomes na tela*/
		std::cout << "o nome é: " << name << std::endl ;
	}
	std::cout << "the end" ;
	
return 0;
}