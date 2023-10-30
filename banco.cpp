#include <iostream>
#include <locale.h>//biblioteca de localizaçao

int main (){
	setlocale(LC_ALL, "Portuguese");//portuga nisso 
	float VD, VT=0, VS; //Valor Deposito, Valor Total, Valor saque
	int num;// usado no Switch

	while (true){//enquanto verdade continua no bloco
	std::cout << std::endl;/*espaço para quando retornar no inicio*/
	std::cout << "selecione o número da operacao" << std::endl;
	std::cout << "1 ver saldo" << std::endl;
	std::cout << "2 fazer deposito" << std::endl;
	std::cout << "3 fazer saques" << std::endl;
	std::cout << "4 sair" << std::endl;
	std::cin >> num;//comparativo no switch
	
	switch(num){
		case 1:
			std::cout << "saldo atual é de " << VT << " reais" << std::endl;
			break;
		case 2:
			std::cout <<"quanto você deseja depositar? " << std::endl;
			std::cin >> VD;
			VT += VD;//VT = VT + VD
			std::cout << "saldo atual é de " << VT << " reais" <<  std::endl;
			break;
		case 3:
			std::cout << "quanto você deseja retirar? " << std::endl;
			std::cin >> VS;
			if(VS <= VT){
				VT -= VS;// VT = VT - VS
				std::cout <<  "Saldo atual é de " << VT << " reais" <<  std::endl;
			}
			else{//sem cheques especiais
				std::cout << "seu saldo é insuficiente " << std::endl;
			}
			break;
		case 4:
			return 0;//transforma o True em False para poder sair do loop
		default:
			std::cout << "numero invalido" <<std::endl;//caso um numero no menu nao seja selecionado
			break;
		}
	}

return 0;
}
