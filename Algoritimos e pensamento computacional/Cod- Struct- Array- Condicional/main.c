#include <stdio.h>
#include <string.h> // Para usar strcpy

// Definição da struct 'Estudante'
struct Estudante {
    char nome[50];
    int matricula;
    float media;
    float notas[2];
    int numNotas;
};

int obterNumeroNotas() {
    int n;
    do {
        printf("Quantas notas o aluno tem (1 a 2)? ");
        scanf("%d", &n);
        if (n <= 0 || n > 2) {
            printf("Número inválido. Tente novamente.\n");
        }
    } while (n <= 0 || n > 2);
    return n;
}

float calcularMedia( float notas[], int n) {
        float soma = 0;
        for (int i = 0; i < n; i++) {
        printf(" Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
            soma += notas[i];
        }
        return soma / n;
}

int main() {
    // Declaração de uma variável do tipo Estudante
    struct Estudante aluno1;
    printf("Digite o nome e sobrenome do aluno:");
    fgets(aluno1.nome, sizeof(aluno1.nome), stdin); aluno1.nome[strcspn(aluno1.nome, "\n")] = '\0'; //usamos essa estrutura para sair o sobrenome do aluno quando der o espaço no teclado
    printf("Matrícula:  ");
    scanf("%d", &aluno1.matricula);

    aluno1.numNotas = obterNumeroNotas();
    aluno1.media = calcularMedia(aluno1.notas, aluno1.numNotas);

    printf("\n--- Dados do Aluno ---\n");
    printf("Nome: %s\n", aluno1.nome);
    printf("Matrícula: %d\n", aluno1.matricula);
    printf("Notas: ");
    for (int i = 0; i < aluno1.numNotas; i++) {
        printf("%.2f ", aluno1.notas[i]);
    }
    printf("\nMédia: %.2f\n", aluno1.media);
    
    if (aluno1.media >= 6){
        printf("Situação:Aprovado");
    }else{
         printf("Situação:Reprovado");
    }
    
    return 0;
}
