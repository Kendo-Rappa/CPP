#include <iostream>
#include <cstdlib>
#include <locale>
#include <cctype> // para usar o isdigit
#include <limits> // para usar numeric_limits
#include <vector> // para usar vetores

int main() {
    setlocale(LC_ALL, "Portuguese");
    int i, j, a, b;
    bool isnum = true;

    std::cout << "Qual o tamanho da linha? ";
    if (!(std::cin >> i)) {/*testa a entrada do valor*/
        isnum = false;
    }

    while (!isnum || i <= 0) {
        std::cin.clear();/*limpa a entrrada*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');/*ignora tudo o que esetiver na memoria */
        std::cerr << "Registro incorreto. Tente novamente: ";/*envia uma mensagem de erro para a tela padrao de erros*/
        if (!(std::cin >> i)) {
            isnum = false;
        } else {
            isnum = true;
        }
    }

    isnum = true; // Reseta isnum para o original 

    std::cout << "Qual o tamanho da coluna? ";
    if (!(std::cin >> j)) {
        isnum = false;
    }/*sem utilizar o Else*/

    while (!isnum || j <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Registro incorreto. Tente novamente: ";
        if (!(std::cin >> j)) {
            isnum = false;
        } else {
            isnum = true;
        }
    }
	
	std::vector<std::vector<int>> matrix(i, std::vector<int>(j)); 
	/*a matrix é transformada em um vetor para conseguir manipular melhor*/

	std::cout << "Digite os valores para a matriz:" << std::endl;

    for (a = 0; a < i; a++) {
        for (b = 0; b < j; b++) {
            std::cin >> matrix[a][b];
            while (std::cin.fail()) {/*verifica se tem algo diferente do esperado sendo colocado no Vetor*/
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Registro incorreto. Tente novamente: ";
                std::cin >> matrix[a][b];
            }
        }
    }

    std::cout << "Matriz inserida" << std::endl;

    for (a = 0; a < i; a++) {
        for (b = 0; b < j; b++) {
            std::cout << matrix[a][b] << " ";
        }
        std::cout << std::endl;
    }
	
	//soma das linhas
	
	int sum, x, somao, soma, l, c;
	
	for(a=0;a<i;a++){
		sum=0;
		for(b=0;b<j;b++){
			sum += matrix[a][b];
		}
		std::cout << "a soma da linha " << a << "é: " << sum << std::endl;
	}
	
	/*soma de posições aleatorias*/
	std::cout << "quantas posições vão ser somadas? " <<std::endl;
	if(!(std::cin >> x)){
		isnum = false;
	}
	
	while(!isnum || x<=0){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Registro incorreto. Tente novamente :";
		if(!(std::cin >> x)){
			isnum = false;
		}
		else{
			isnum = true;
		}
	}
	
	isnum = true; //reseta o isnum novamente
	
	soma = 0;
	
	for (a=0;a<x;a++){
		std::cout << "qual a linha ?" << std::endl;
		if(!(std::cin >> l)){
			isnum = false;
		}
		while(!isnum || i<0){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Registro Incorreto. Tente Novamente :";
			if(!(std::cin >> l)){
				isnum = false;
			}
			else{
				isnum = true;
			}
		}
		
		isnum = true;
		
		std::cout << "qual a coluna? " << std::endl;
		if(!(std::cin >> c)){
			isnum = false;
		}
		while(!isnum || i<0){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "registro Incorreto. Tente Novamente :";
			if(!(std::cin >> c)){
				isnum = false;
			}
			else{
				isnum = true;
			}
		}
		
		isnum = true;
		
		soma += matrix[l][c];/*posição da linha e da coluna*/
	}
	std::cout << "resultado :" << soma << std::endl;

	return 0;
}