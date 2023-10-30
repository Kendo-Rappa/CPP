#include <iostream>
#include <cmath>

int main (void) {
	
	float a, b, c, delta, raiz1, raiz2, fake;
	
	std::cout <<"quais os numeros de a, b e c para calcular o delta" << std::endl;
	std::cin >> a >> b >> c;
	
	delta = pow(b,2) - 4*a*c;
	
	switch(delta>0){
		case 1:
			raiz1 = (-b - sqrt(delta)) / (2*a);
			raiz2 = (-b + sqrt(delta)) / (2*a);
			std::cout << "a raiz é " << raiz1 << " e " << raiz2;
			break;
		case 0:
			switch(delta < 0){
				case 1:
					raiz1 = raiz2 = -b / (2*a);
					fake = sqrt(-delta) / (2*a);
					std::cout <<"suas raiz sao " << raiz1 << " + " << fake <<" and "<< raiz2 << "-" << fake;
					break;
				case 0:
					raiz1 = raiz2 = -b/(2*a);
					std::cout <<"duas raiz iguais" << raiz1;
					break;
		}
	}
}