#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída (para printf, scanf, fgets, getchar)
#include <string.h> // Inclui a biblioteca de manipulação de strings (para strcspn, que ajuda a remover o '\n' do fgets)


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.


/**
 * @brief Limpa o buffer de entrada do teclado.
 *
 * Esta função é essencial após o uso de `scanf` para tipos numéricos ou char
 * (ex: %d, %f, %c), pois o `scanf` deixa o caractere de nova linha ('\n')
 * no buffer de entrada. Se não for limpo, o próximo `fgets` (ou outro `scanf`)
 * pode ler esse '\n' e causar um comportamento inesperado (pulando a entrada).
 */
void limparBuffer() {
    int c;
    // Loop para ler e descartar caracteres até encontrar um '\n' ou o fim do arquivo (EOF).
    while ((c = getchar()) != '\n' && c != EOF);
}


/**
 * @brief Função principal do programa.
 *
 * Implementa o cadastro e a exibição de dados de duas cartas do Super Trunfo,
 * conforme as especificações do "Tema 1 - Cadastro das Cartas" do desafio.
 * Lê os dados do usuário para cada atributo e os exibe de forma organizada.
 *
 * @return Retorna 0 se o programa for executado com sucesso.
 */
int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Declaração das variáveis para armazenar os dados da PRIMEIRA carta
    char estado1;                   // Estado: Uma letra de 'A' a 'H' (representando um dos oito estados).
                                    // Tipo: char (um único caractere).
    char codigo1[5];                // Código da Carta: A letra do estado seguida de um número de 01 a 04 (ex: A01, B03).
                                    // Tipo: char[] (string). O tamanho 4 é para 3 caracteres ('A', '0', '1') + 1 para o terminador nulo '\0'.
    char nomeCidade1[60];           // Nome da Cidade: O nome da cidade
                                    // Tipo: char[] (string). Tamanho 50 permite nomes com até 49 caracteres + '\0'.
    unsigned long int populacao1;   // População: O número de habitantes da cidade.
                                    // Tipo: unsigned long int (número inteiro longo positivo).
    float area1;                    // Área (em km²): A área da cidade em quilômetros quadrados.
                                    // Tipo: float (número de ponto flutuante para valores decimais).
    float pib1;                     // PIB: O Produto Interno Bruto da cidade.
                                    // Tipo: float (número de ponto flutuante).
    int pontosTuristicos1;          // Número de Pontos Turísticos: A quantidade de pontos turísticos na cidade.
                                    // Tipo: int (número inteiro).
    float densidadePopulacional1;   // Densidade Populacional: Calculada como a população dividida pela área.
                                    // Tipo: float (número de ponto flutuante).
    float pibPerCapita1;            // PIB per Capita: Calculado como o PIB dividido pela população.
                                    // Tipo: float (número de ponto flutuante).
    float superPoder1;              // Super Poder: A soma de todos os atributos (população, área, PIB, pontos turísticos, densidade populacional e PIB per capita).
                                    // Tipo: float (número de ponto flutuante).
    float inversoDensidade1;        // Variável para armazenar o inverso da densidade populacional da Carta 1
                                    //Tipo: float (número de ponto flutuante).
                                    
    // Declaração das variáveis para armazenar os dados da SEGUNDA carta
    char estado2;
    char codigo2[5];
    char nomeCidade2[60];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float inversoDensidade2;
    float superPoder2;
    

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    printf("--- Cadastro da PRIMEIRA Carta ---\n");

    printf("Digite o estado da cidade (A - H): ");
    scanf(" %c", &estado1);
    limparBuffer(); // Limpa o '\n'

    printf("Digite o codigo da cidade (ex: A01): ");
    // fgets eh a forma segura de ler strings, controlando o tamanho maximo
    fgets(codigo1, sizeof(codigo1), stdin);
    // strcspn encontra a posicao do primeiro '\n' na string, e o substitui por '\0' (terminador de string)
    codigo1[strcspn(codigo1, "\n")] = 0;

    printf("Digite o nome da cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0;

    printf("Digite a populacao da cidade: ");
    scanf("%lu", &populacao1);
    limparBuffer();

    printf("Digite a area da cidade (em km^2): ");
    scanf("%f", &area1);
    limparBuffer();

    if (area1 != 0.0f) {
        densidadePopulacional1 = (float)populacao1 / area1; // Cast para float no divisor para clareza
    } else {
        densidadePopulacional1 = 0.0f; // Evita divisão por zero
    }

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);
    limparBuffer();

    if (populacao1 != 0) {
        pibPerCapita1 = pib1 / (float)populacao1; 
    } else {
        pibPerCapita1 = 0.0f;
    }

    printf("Digite o numero de pontos turisticos da cidade: ");
    scanf("%d", &pontosTuristicos1);
    limparBuffer();

    // Início do cálculo do inverso da densidade populacional para o Super Poder
    if (densidadePopulacional1 != 0.0f) {
        // O cálculo do inverso é 1 dividido pelo valor.
        // Usar 1.0f garante que a divisão seja feita com números de ponto flutuante,
        // resultando em um valor decimal preciso, mesmo que o numerador seja um inteiro.
        inversoDensidade1 = 1.0f / densidadePopulacional1;
    } else {
        inversoDensidade1 = 0.0f; // Define 0.0f se a densidade for zero para evitar divisão por zero
    }
    
    // Cálculo do Super Poder: soma de todos os atributos numéricos e o inverso da densidade populacional.
    superPoder1 = (float)(populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + inversoDensidade1);

    //----------------------------------------------------------

    printf("\n--- Cadastro da SEGUNDA Carta ---\n");

    printf("Digite o estado da cidade (A - H): ");
    scanf(" %c", &estado2);
    limparBuffer();

    printf("Digite o codigo da cidade (ex: B02): ");
    fgets(codigo2, sizeof(codigo2), stdin);
    codigo2[strcspn(codigo2, "\n")] = 0;

    printf("Digite o nome da cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;

    printf("Digite a populacao da cidade: ");
    scanf("%lu", &populacao2);
    limparBuffer();

    printf("Digite a area da cidade (em km^2): ");
    scanf("%f", &area2);
    limparBuffer();

    if (area2 != 0.0f) {
        densidadePopulacional2 = (float)populacao2 / area2;
    } else {
        densidadePopulacional2 = 0.0f;
    }

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);
    limparBuffer();

    if (populacao2 != 0) {
        pibPerCapita2 = pib2 / (float)populacao2;
    } else {
        pibPerCapita2 = 0.0f;
    }

    printf("Digite o numero de pontos turisticos da cidade: ");
    scanf("%d", &pontosTuristicos2);
    limparBuffer();

    if (densidadePopulacional2 != 0.0f) {
        inversoDensidade2 = 1.0f / densidadePopulacional2;
    } else {
        inversoDensidade2 = 0.0f;
    }
    
    superPoder2 = (float)(populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + inversoDensidade2);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1); // %lu para unsigned long int
    printf("Area: %.3f km^2\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.3f km^2\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    printf("\n--- Resultados da Comparação ---\n");

    printf("Comparando a População:\n");
    if (populacao1 > populacao2){
        printf("População: Carta 1 venceu (1)\n");
    } else if (populacao2 > populacao1){
        printf("População: Carta 2 venceu (0)\n");
    } else {
        printf("População: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("Comparando a Área:\n");
    if (area1 > area2){
        printf("Area: Carta 1 venceu (1)\n");
    } else if (area2 > area1){
        printf("Area: Carta 2 venceu (0)\n");
    } else {
        printf("Area: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("Comparando o PIB:\n");
    if (pib1 > pib2){
        printf("PIB: Carta 1 venceu (1)\n");
    } else if (pib2 > pib1){
        printf("PIB: Carta 2 venceu (0)\n");
    } else {
        printf("PIB: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("Comparando o Número de Pontos Turísticos:\n");
    if (pontosTuristicos1 > pontosTuristicos2){
        printf("Pontos Turísticos: Carta 1 venceu (1)\n");
    } else if (pontosTuristicos2 > pontosTuristicos1){
        printf("Pontos Turísticos: Carta 2 venceu (0)\n");
    } else {
        printf("Pontos Turísticos: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("Comparando a Densidade Populacional (menor valor ganha):\n");
    if (densidadePopulacional1 < densidadePopulacional2){
        printf("Densidade Populacional: Carta 1 venceu (1)\n");
    } else if (densidadePopulacional2 < densidadePopulacional1){
        printf("Densidade Populacional: Carta 2 venceu (0)\n");
    } else {
        printf("Densidade Populacional: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("Comparando o PIB per Capita:\n");
    if (pibPerCapita1 > pibPerCapita2){
        printf("PIB per Capita: Carta 1 venceu (1)\n");
    } else if (pibPerCapita2 > pibPerCapita1){
        printf("PIB per Capita: Carta 2 venceu (0)\n");
    } else {
        printf("PIB per Capita: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("Comparando o Super Poder:\n");
    if (superPoder1 > superPoder2){
        printf("Super Poder: Carta 1 venceu (1)\n");
    } else if (superPoder2 > superPoder1){
        printf("Super Poder: Carta 2 venceu (0)\n");
    } else {
        printf("Super Poder: As cidades %s e %s empataram!\n", nomeCidade1, nomeCidade2);
    }

    printf("\n--- Fim do Jogo ---\n");

    return 0;
}