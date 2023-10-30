#include <iostream>
#include <string> /*usada para manipular strings*/
#include <random>/*biblioteca para gerar numeros aleatorios*/
#include <limits>/*serve para achar o limites*/
#include <locale.h>
#include <cctype>/*para usar o BOOLEAN*/
#include <vector> /*para usar vetores*/
#include <sstream>/*biblioteca que ajuda na manipulaçao direta das entradas e saidas do vetor*/


class Registro {/*classe funciona tipo Struct*/
public:/*faz o que estiver dentro da classe se tornar publico*/
	/*o que vai ser classificado*/
	std::vector<std::string> NAME;
	std::vector<short int> AGE;
	int CARD_NUM;
	float MONEY;

};
/*VVV aqui onde é feito a manipulaçao dos dados VVV*/
Registro pessoa (std::vector<std::string> &nomes,	std::vector<short int> &age,	int &card,	float &money){
/*nao esquecer de retornar os dados quando terminar a manipulação*/	

	money -= 0.5;

	Registro dados;
	dados.NAME=nomes;
	dados.AGE=age;
	dados.CARD_NUM=card;
	dados.MONEY=money;

return dados;
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	char r = 'y';
	std::vector<std::string> names;/*transforma a string em um Vetor para armazenar letras no vetor*/
	
	/************vetor onde vai ficar armazenado os nomes*************/

	while(r=='y' || r=='Y'){/*compara a entrada da resposta de {Y/N}*/
		std::string name;/*cria a String para dar entrada nos nomes ou letras*/
		std::cout << "qual o nome? " << std::endl;
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
		std::cout << "deseja colocar mais nomes? {y/n}";
		while(!(std::cin >> r) || (r!='Y' && r!='y' && r!='N' && r!='n')){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Entrada invalida. Tente Novamente: ";
		}/*usado para continuar no loop ou sair dele*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');/*limpa a memoria da entrada*/
	}
	
	/***********************fim do vetor***********************/
	
	/****************inicio e entrada das idades***********/
	r='Y';//reseta o valor de R

	std::vector<short int> idade;/*tipo de vetor*/
	
	bool is_num = true;/*compara a entrada com letra e numero*/

	short int valor;//usado na linha 44

    while (r == 'y' || r == 'Y') {
        std::cout << "qual a idades: ";
        std::string input;//cria a string para ser usada dentro do vetor																
        if (!std::getline(std::cin, input)) {/*input da String com comparaçao imediata dos dados, Getline possibilita multiplos valores separados*/
            is_num = false;
        }
        while (!is_num) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada errada. Tente novamente: ";
            if (!std::getline(std::cin, input)) {/*da entrada nos dados novamente caso a primeira vez seja falha*/
                is_num = false;
            }
            else {
                is_num = true;
            }
        }
        std::istringstream stream(input);/*usado para ler as entradas de forma unica, uma vez que estao separadas por espaços ou outros delimitadores*/
        while (stream >> valor) {
            idade.push_back(valor);
        }
        std::cout << "Mais idades? {y/n}";/*loop para mais possiveis entradas*/
		while (!(std::cin >> r) || (r!= 'Y' && r!= 'y' && r!= 'N' && r!= 'n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada invalida. Tente Novamente: ";
        }
		std::cin.ignore();/*limpa tudo o que esta para tras, impossibilita de que o loop fique sempre sendo verdadeiro*/
    }
	
	/*********************************Fim das idades*************************************/
	
	std::cout << std::endl;
	
	is_num = true;
	
	float credito=0;
	/*********** valor inicial do cartao. nao se pode comprar um cartao com 0 de credito ************/
	std::cout << "Na compra do cartão o valor inicial tera uma reduçao de 0.50 centavos" << std::endl;
	std::cout << "Nota: recarga minima de 10.00" << std::endl;
	std::cout << "Qual o valor inicial da recarga? ";
	if(!(std::cin >> credito)){
		is_num = false;
	}
	while(!is_num || credito < 10.0){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "valor errado. recarga minima de 10.00 " << std::endl;
		std::cerr << "tente novamente: ";
		if(!(std::cin>>credito) || credito < 10.0){
			is_num = false;
		}
		else{
			is_num = true;
		}
	}
	
	/***********fim dos valores para o cartao************/
	
	is_num = true;
	
	std::cout << std::endl;
	
	/***********o codigo do cartao é gerado de forma aleatoria*************/
	
	int maxint = INT_MAX;
	
	std::default_random_engine generator;/*gerador de numeros aleatorios*/
	/*define a distribuiçao para gerar inteiros*/
	std::uniform_int_distribution<int> distribution(1, maxint);/*entre o minimo 1 e o INT maximo*/
	int card_number = distribution(generator);/*funçao para salvar o numero aleatorio gerado*/
	
	/*******************depois de gerado o codigo é passado para o armazenamento********************/
	
/*   VVVVVV nome do inicio do bloco na linha 19*/      /* VVVVV nome da função da classificação na linha 19*/
	Registro dados/*nome da classificação temporaria*/ = pessoa (names, idade, card_number, credito);
	
	/**************mostra os dados na tela******************/
	
	/*() quais valores vao ser transportados para o Registro pessoa. Devem ser transportados na ordem correta*/
	for (const std::string& nome : dados.NAME){/*fas aparecer os nomes na tela*/
		std::cout << "o nome é: " << nome << std::endl ;
	}
	for(const short int& idades : dados.AGE){/*fas aparecer as idades na tela*/
		std::cout << "a idade é: " << idades << std::endl;
	}
	std::cout << "o numero do cartao é: " << dados.CARD_NUM << std::endl;
	std::cout << "saldo total é de: " << dados.MONEY << std::endl;
	
	/***************fim dos amostragem de dados***************/
	
return 0;
}