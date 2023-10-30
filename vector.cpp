#include <iostream>
#include <vector>

int main(){
	short int elemento, n, i;
	std::vector<short int> math;
	
	std::cout << "numero de repetiçoes" <<std::endl;
	std::cin >> n;

	math.resize(n);
	
	for(i=0;i<n;i++){
		std::cout << "entrada para o vetor " <<std::endl;
		std::cin >> math[i];
		elemento += math[i];
	}
	for(i=0;i<n;i++){
		std::cout << "numero"<< math[i] <<std::endl;
	}
	std::cout << "soma dos elementos " << elemento << std::endl;
	
return 0;
}