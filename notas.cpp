#include <iostream>
#include <locale.h>

class result{/*usado para fazer o "cadastro" ou classificar a media normal e aritimetica*/
public:// torna a classificaçao publica
	float media; 
	float media_aritimetica;
};

/*VVVV*/ // nao necessariamente precisa ser um tipo de variavel
result calculos(float &a, float &b, float &c, float &pt, float &mt, float &di){
	//precisa declarar e mencionar todas as variaveis a serem utilizadas
	setlocale(LC_ALL, "Portugues");/* portuga nisso*/
	float me, mea;
	me = (pt + mt + di) / 3;
	mea = (pt*a + mt*b + di*c) / (a+b+c);
	result resultado;// result é da classificaçao resultado é um ALIAS
	resultado.media = me; //.media é usado para poder mensionar a variavel Media na classificaçao
	resultado.media_aritimetica = mea;// msm de cima
	return resultado;//so se pode retornar uma unica variavel
	/*as vezes precisa guambiarrar para funcionar*/
	/*a calassificaçao foi a guambiarra*/
}

int main (){
	
	setlocale(LC_ALL, "Portugues");
	float peso_1, peso_2, peso_3, por, mat, dir;//variaveis
	
	std::cout << "quais os pesos das materias Portugues, Matematica e Direito respectivamente" << std::endl;
	std::cin >> peso_1 >> peso_2 >> peso_3;/*pega os pessos*/
	std::cout << "quais as notas das materias Portugues, Matematica e Direito respectivamente" << std::endl;
	std::cin >> por >> mat >> dir;/*pega as notas de Portugues, Matematica e Direito*/
	
	result/*classificaçao*/ resultado /*Alias na linha 17*/= calculos(peso_1,peso_2,peso_3, por, mat, dir);/*joga os pessos no bloco onde vai se ter os calculos*/
	
	std::cout << "Media é " << resultado.media << std::endl;
	std::cout << "Media Aritimetica " << resultado.media_aritimetica << std::endl;
	
	return 0;
}