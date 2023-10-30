#include <iostream>
#include <vector>
#include <limits>
#include <cctype>/*para usar o BOOLEAN*/
#include <sstream>/*biblioteca que ajuda na manipulaçao direta das entradas e saidas do vetor*/

int main() {

    std::vector<short int> idade;/*tipo de vetor*/

    char r;

    std::cout << "Iniciar o vetor? {y/n} ";
    while (!(std::cin >> r) || (r!= 'Y' && r!= 'y' && r!= 'N' && r!= 'n')) {
        std::cin.clear();/*limpa a ultima entrada, mas pode alocar lixo na memoria*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');/*garante que o lixo vai ser retirado*/
        std::cerr << "Entrada errada. Tente novamente: ";
    }
	
	std::cin.ignore();//limpa a ultima entrada de dados
    
	bool is_num = true;/*compara a entrada com letra e numero*/

	short int valor;//usado na linha 44

    while (r == 'y' || r == 'Y') {
        std::cout << "Valores do vetor: ";
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
        std::istringstream stream(input);/*usado para ler as entradas de forma unica, uma vex que estao separadas por espaços ou outros delimitadores*/
        while (stream >> valor) {
            idade.push_back(valor);
        }
        std::cout << "Mais numeros? {y/n}";/*loop travado*/
		while (!(std::cin >> r) || (r!= 'Y' && r!= 'y' && r!= 'N' && r!= 'n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada invalida. Tente Novamente: ";
        }
		std::cin.ignore();/*limpa tudo o que esta para tras, impossibilita de que o loop fique sempre sendo verdadeiro*/
    }

    is_num = true;

    for (const short int& val : idade) {/*printa os valores para a tela do usuario*/
        std::cout << val << " ";
    }

    std::cout << std::endl << "O tamanho do vetor é: " << idade.size() << std::endl; /*mostra o tamanho do vetor*/
    std::cout << "The end";
    return 0;
}