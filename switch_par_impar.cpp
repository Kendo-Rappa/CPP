#include <iostream>

int main(void){
	
	int num;
	std::cout << "qual o numero que vai ser verificado" << std::endl;
	std::cin >> num;
	
	switch(num % 2){
		case 1:
			std::cout << "numero impar";
			break;
		case 0 :
			std::cout << "numero par";
			break;
	}
}