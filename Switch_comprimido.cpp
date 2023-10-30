#include <iostream>

int main(void) {
	
	char letter;
	
	std::cout << "coloque aqui a letra " << std::endl;
	std::cin >> letter;
	
	switch (letter){
		case 'a': case 'A': case 'e': case 'E': case 'i': case 'I': case 'o': case 'O': case 'u': case 'U':
			std::cout << "Vowel ";
			break;
	default:
		std::cout << "consonant";
	}
}