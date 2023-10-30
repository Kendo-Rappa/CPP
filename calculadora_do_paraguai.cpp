#include <iostream>

int main (void) {
	
	char op;
	float num1, num2, res;
	
	std::cout << "coloque o primeiro e o segundo numero seguido do operador (/ * - +)" << std::endl;
	std::cin >> num1 >> num2 >> op;
	switch(op){
		case '+' :
			res = num1 + num2;
			std::cout << res;
			break;
		case '-' :
			res = num1 - num2;
			std::cout << res;
			break;
		case '*' :
			res = num1 * num2;
			std::cout << res;
			break;
		case '/' :
			res = num1 / num2;
			std::cout << res;
			break;
	default:
		std::cout << "fuking cunt";
	}
}