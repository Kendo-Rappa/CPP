#include <iostream>
 
int main (void) {

    int num, num_1, num_2;
	
    std::cout << "put here the munbers" << std::endl;
    std::cin >> num >> num_1 >> num_2;

    if(num >= num_1 && num >= num_2){
		std::cout << "o maior foi " << num << std::endl;
	}
	else if (num_1 >= num && num_1 >= num_2){
		std::cout << "o maior foi " << num_1 << std::endl;
	}
	else {
		std::cout << "o maior foi " << num_2 << std::endl;
	}
	if(!(num || num_1 || num_2) % 5 || 11){
		std::cout << "e ele nao eh divisivel por 5 ou 11" << std::endl;
	}
	else{
		std::cout << "e ele eh divisivel por 5 ou 11 " << std::endl;
	}
	if((num || num_1 || num_2) < 0){
		std::cout << " o numero eh negativo";
	}
	else{
		std::cout << " o numero eh positivo";
	}
	if(!(num || num_1 || num_2) % 2){
		std::cout << " o numero eh par";
	}
	else {
		std::cout << " o numero eh impar";
	}
}