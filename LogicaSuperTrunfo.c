#include <stdio.h>

int main() {
    char nome_carta_a[50] = "Brasil";
    long long populacao_a = 215000000;
    double pib_a = 1800.0;
    double area_a = 8515767.0;

    char nome_carta_b[50] = "Alemanha";
    long long populacao_b = 83000000;
    double pib_b = 4200.0;
    double area_b = 357588.0;

    printf("--- Super Trunfo: Comparacao de Cartas (Modulo 1) ---\n\n");

    printf("Carta A: %s\n", nome_carta_a);
    printf("  Populacao: %lld\n", populacao_a);
    printf("  PIB: %.2lf bilhoes\n", pib_a);
    printf("  Area: %.2lf km2\n\n", area_a);

    printf("Carta B: %s\n", nome_carta_b);
    printf("  Populacao: %lld\n", populacao_b);
    printf("  PIB: %.2lf bilhoes\n", pib_b);
    printf("  Area: %.2lf km2\n\n", area_b);

    printf("--- Comparando pelo atributo: Populacao ---\n\n");

    if (populacao_a > populacao_b) {
        printf("Vencedor: A Carta A (%s) tem maior populacao!\n", nome_carta_a);
    } else if (populacao_b > populacao_a) {
        printf("Vencedor: A Carta B (%s) tem maior populacao!\n", nome_carta_b);
    } else {
        printf("As cartas A e B tem a mesma populacao! Empate.\n");
    }

    printf("\nFim da comparacao. Pressione Enter para sair...\n");
    getchar();

    return 0;
}
