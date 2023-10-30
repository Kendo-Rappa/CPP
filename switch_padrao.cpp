#include <iostream>

int main (void){
	
	int num;
	
	std::cout << "selecione um numero para saber quantos dias tem o mes " << std::endl;
	std::cout << "1 --> january / 2 --> february / 3 --> march" << std::endl;
	std::cout << "4 --> april / 5 --> may / 6 --> june" << std::endl;
	std::cout << "7 --> july / 8 --> august / 9 --> september" << std::endl;
	std::cout << "10 --> october / 11 --> november / 12 --> december" << std::endl;
	std::cin >> num;
	
	switch(num){
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 11:
			std::cout << "31 days";
			break;
		case 4:
		case 6:
		case 8:
		case 10:
		case 12:
			std::cout << "30 days";
			break;
		case 2:
			std::cout << "28 or 29 days";
			break;
		default:
			std::cout << std::endl <<"ass hole just use 1 to 12 ";
	}
}