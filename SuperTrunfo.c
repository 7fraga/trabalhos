#include <stdio.h>

int main() {
    char estado[50];
    int codigo;
    char nome_cidade[100];
    long long populacao;
    double pib;
    double area;
    int pontos_turisticos;

    double densidade_populacional;
    double pib_per_capita;

    printf("--- Cadastro de Carta Super Trunfo: Pais/Cidade ---\n\n");

    printf("Digite o estado/regiao: ");
    scanf("%49[^\n]%*c", estado);

    printf("Digite o codigo da carta (numero inteiro): ");
    scanf("%d", &codigo);
    while (getchar() != '\n');

    printf("Digite o nome da cidade: ");
    scanf("%99[^\n]%*c", nome_cidade);

    printf("Digite a populacao da cidade (numero inteiro grande): ");
    scanf("%lld", &populacao);
    while (getchar() != '\n');

    printf("Digite o PIB da cidade (em bilhoes, ex: 123.45): ");
    scanf("%lf", &pib);
    while (getchar() != '\n');

    printf("Digite a area da cidade em km2 (ex: 567.89): ");
    scanf("%lf", &area);
    while (getchar() != '\n');

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos);
    while (getchar() != '\n');

    if (area > 0) {
        densidade_populacional = (double)populacao / area;
    } else {
        densidade_populacional = 0.0;
    }

    if (populacao > 0) {
        pib_per_capita = pib / populacao;
    } else {
        pib_per_capita = 0.0;
    }

    printf("\n--- Informacoes da Carta Cadastrada ---\n");
    printf("Estado/Regiao: %s\n", estado);
    printf("Codigo: %d\n", codigo);
    printf("Nome da Cidade: %s\n", nome_cidade);
    printf("Populacao: %lld\n", populacao);
    printf("PIB: %.2lf bilhoes\n", pib);
    printf("Area: %.2lf km2\n", area);
    printf("Pontos Turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2lf habitantes/km2\n", densidade_populacional);
    printf("PIB per Capita: %.4lf bilhoes/habitante\n", pib_per_capita);

    printf("\nCarta cadastrada com sucesso!\n");

    return 0;
}
