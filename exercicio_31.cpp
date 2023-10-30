#include <iostream>
#include <locale.h>
#include <string>

class registro{//vai usar o msm nome na linha 10
public:
	float Salario_Bruto, Salario_Liquido;//salario Bruto, Horas trabalhadas,salario por hora, salario liquido
	std::string name;
};

registro calculos(std::string &A, float &H, float &V){//H de Horas V de valor da Hora
	float SB, SL;
	//Salário Bruto = Horas Trabalhadas * Salário por Hora
	SB = H * V;
	//O salário líquido é igual ao salário bruto menos 11% de INSS.
	SL = SB * 0.89;
	registro cadastro;
	cadastro.Salario_Bruto = SB;
	cadastro.Salario_Liquido = SL;
	cadastro.name = A;
return cadastro;
}

int main (){
	setlocale(LC_ALL, "Portugueses");//portuga
	int i, N_R;
	float horas, valor;
	std::string nome;
	
	std::cout << "quantos registros vão ser feitos " << std::endl;
	std::cin >> N_R;//numero de registros
	
	std::cout << "coloque aqui os dados em ordem: " << std::endl;
	std::cout << "1º Nome \n2º Horas trabalhadas \n3º valor por horas trabalhadas \n";
	
	registro cadastro[N_R] = {};/*vetor de cadastros usando o N_R como tamanho base*/
	/*^^^^ força o vetor a se inicializar com um valor padrao em caso de dados inicia usando valores primitivos
	em caso de String inicia como Vazio, 0,0 para variaveis de ponto flutuante*/
	
	for(i=0;i<N_R;i++){
		std::cin.ignore();//é usada para descartar (ignorar) os caracteres do buffer de entrada do teclado 
						  //(stdin) que ainda não foram lidos pelo programa.
		std::getline(std::cin, nome);//da entrada no nome
		if (!(std::cin >> horas >> valor)){//verifica se os valores estao sendo colocados na forma correta
			std::cerr <<"erro de leitura\n";//caso sejam colocados errados aparece essa mensagem 
			/*^^^^^^ direcina a mensagem de erro para a saida de erro padrao, normalmente terminal ou console*/
			return 1;//confirma o erro
		};//fim bloco
		cadastro[i] = calculos(nome, horas, valor);//cadastro[i] linha 35 o cadastro é usado dentro do loop...
		std::cout << "\n";//...para poder garantir que os dados vao ser armazenados corretamente
	}
	
	for(i=0;i<N_R;i++){//saida dos valores e outras coiasas
		std::cout << "o funcinoario " << cadastro[i].name << std::endl;
		std::cout << "recebe " << cadastro[i].Salario_Bruto << " Bruto" << std::endl;
		std::cout << "recebe " << cadastro[i].Salario_Liquido << " Liquido" << std::endl;
	}
	
return 0;
}