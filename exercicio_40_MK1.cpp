#include <iostream>
#include <string>

struct Atleta {
    std::string nome;
    short int modalidade;
    short int idade;
    char sexo;
};

int main() {
    const int NUM_ATLETAS = 10;
    Atleta atletas[NUM_ATLETAS];

    // Leitura dos dados dos atletas
    for (int i = 0; i < NUM_ATLETAS; i++) {
        std::cout << "Atleta " << i + 1 << ":" << std::endl;

        std::cout << "Nome: ";
        std::cin >> atletas[i].nome;

        std::cout << "Modalidade (1 = Voley, 2 = Basquete, 3 = Futsal): ";
        std::cin >> atletas[i].modalidade;

        std::cout << "Idade: ";
        std::cin >> atletas[i].idade;

        std::cout << "Sexo (M/F): ";
        std::cin >> atletas[i].sexo;

        std::cout << std::endl;
    }

    // Cálculo das médias de idade
    float mediaIdadeHomens = 0;
    float mediaIdadeMulheres = 0;
    int countHomens = 0;
    int countMulheres = 0;
    int countMulheresBasquete = 0;
    int countHomens25a30 = 0;

    for (int i = 0; i < NUM_ATLETAS; i++) {
        if (atletas[i].sexo == 'M') {
            mediaIdadeHomens += atletas[i].idade;
            countHomens++;

            if (atletas[i].idade >= 25 && atletas[i].idade <= 30) {
                countHomens25a30++;
            }
        }
        else if (atletas[i].sexo == 'F') {
            mediaIdadeMulheres += atletas[i].idade;
            countMulheres++;

            if (atletas[i].modalidade == 2) { // Basquete
                countMulheresBasquete++;
            }
        }
    }

    if (countHomens > 0) {
        mediaIdadeHomens /= countHomens;
    }

    if (countMulheres > 0) {
        mediaIdadeMulheres /= countMulheres;
    }

    // Cálculo da porcentagem de mulheres matriculadas no basquete
    float porcentagemMulheresBasquete = 0;
    if (countMulheres > 0) {
        porcentagemMulheresBasquete = static_cast<float>(countMulheresBasquete) / countMulheres * 100;
    }

    // Impressão dos resultados
    std::cout << "Média de idade dos homens: " << mediaIdadeHomens << std::endl;
    std::cout << "Média de idade das mulheres: " << mediaIdadeMulheres << std::endl;
    std::cout << "Porcentagem de mulheres matriculadas no basquete: " << porcentagemMulheresBasquete << "%" << std::endl;
    std::cout << "Número de homens com idade entre 25 e 30 anos: " << countHomens25a30 << std::endl;

    return 0;
}
