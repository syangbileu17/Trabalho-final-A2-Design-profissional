//-------------------------------------------------Inclusão das bibliotecas selecionadas------------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//-------------------------------------------------Estruturas dos Dados e Histórico-----------------------------------------------------------------------//

typedef struct {
    char tipo[30];     // Tipo da operação (ex: "Soma", "Raiz quadrada")
    double a, b;       // Operandos
    double resultado;  // Resultado da operação
    int id;            // Identificador único da operação
} Operacao;

// Define um máximo de operações que podem ser armazenadas no histórico
#define MAX_HISTORICO 100

// Array para armazenar o histórico
Operacao historico[MAX_HISTORICO]; //array de operações
int totalOperacoes = 0; // Contador de operações realizadas

// Função para adicionar uma operação ao histórico
void adicionarOperacao(const char* tipo, double a, double b, double resultado){ //função para adicionar uma operação ao histórico
    if (totalOperacoes < MAX_HISTORICO) { //verifica se o total de operações é menor que o maximo permitido
        Operacao op; //cria uma variavel do tipo Operacao
        strncpy(op.tipo, tipo, sizeof(op.tipo) - 1); //serve para copiar uma string para o campo de destino 
        op.tipo[sizeof(op.tipo) - 1] = '\0'; // Garantir terminação nula
        op.a = a; //atribui o valor do parametro a1 ao campo a1 da struct
        op.b = b;
        op.resultado = resultado; //atribui o valor do parametro resultado ao campo resultado da struct
        op.id = totalOperacoes + 1; // atribui um id único baseado no contador de operações
        historico[totalOperacoes++] = op; //adiciona a operação ao array historico e incrementa o contador de operações
    } else {
        printf("Histórico cheio! Não é possível adicionar mais operações.\n");
    }
}       
void exibirHistorico(){ //funçao para exibir o historico de operações
    printf("\nHistórico de Operações:\n");
    for (int i = 0; i < totalOperacoes; i++) { //loop para percorrer o array historico
        Operacao op = historico[i]; //pega a operação na posição i do array historico
        printf("ID: %d | Tipo: %s | a1: %.2f | a2: %.2f | Resultado: %.2f\n", // formata a saída
               op.id, op.tipo, op.a, op.b, op.resultado); //exibe os detalhes da operação
    }
    printf("\n");


}

//---------------------------------------------------Funções matemáticas básicas--------------------------------------------------------------------------//

double adicao(const double array[], int n){ //função para realizar a soma dos elementos do array
    double soma = 0; //inicializa a variavel soma com 0
    for (int i = 0; i < n; i++) { //loop para percorrer o array
        soma += array[i]; //realiza a soma dos elementos do array
    }
    return soma; //retorna o valor da soma
}
double subtracao(const double array[], int n){ //função para realizar a subtração dos elementos do array
    double resultado = array[0]; //inicializa a variavel resultado com o primeiro elemento do array
    for (int i = 1; i < n; i++) {
        resultado -= array[i];
    }
    return resultado; //retorna o valor da subtração
}
double multiplicacao(const double array[], int n){ //funcao multiplicacao elementos array}
    double produto = 1; //inicializa a variavel produto com 1
    for (int i = 0; i < n; i++) {
        produto *= array[i];
    }
    return produto; //retorna o valor do produto
}
double divisao(const double array[], int n){ //função divisão elementos array
    if (n <= 0) {
        printf("Erro: Número inválido de operandos para divisão!\n");
        return NAN;
    }
    double resultado = array[0];
    for (int i = 1; i < n; i++) { // significa que começa a partir do segundo elemento do array
        if (array[i] == 0.0) { // verifica se o elemento atual é zero
            printf("Erro: Divisão por zero!\n");
            return NAN; // Retorna Not-a-Number em caso de divisão por zero, coloquei o nan porque pesquisei e ele é utilizado para o tratamento de erros com operacoes com pontos fluantes como double e float
        }
        resultado /= array[i];
    }
    return resultado; //retorna o valor da divisão
}
int leArray(double array[], int n){ // essa função irá ler os valores de um array
    for (int i = 0; i < n; i++) { 
        printf("Digite o valor %d: ", i + 1);
        scanf("%lf", &array[i]); // lê o valor e armazena no array
    }
    return 0;
}

//------------------------------------------------------Funções Científicas---------------------------------------------------------------------//

double potencia(double base, double expoente){ //função potencia
    return pow(base, expoente); //retorna o valor da potencia
}
double radiciacao(double radicando, double indice){ //função radiciação
    if (indice == 0) { //verifica se o indice é igual a 0
        printf("Erro: Índice não pode ser zero!\n"); 
        return NAN; // Retorna Not-a-Number em caso de índice zero
    }
    return pow(radicando, 1.0 / indice); //retorna o valor da radiciação
}
double raizQuadrada(double valor){ //função raiz quadrada
    if (valor < 0) {
        printf("Erro: Não é possível calcular a raiz quadrada de um número negativo!\n");
        return NAN; 
    }
    return sqrt(valor); //retorna o valor da raiz quadrada
}
double seno(double graus){ //função seno
    const double pi = acos(-1.0); //define o valor de pi
    return sin(graus * (pi / 180.0)); //retorna o valor do seno
}
double cosseno(double graus){ //função cosseno
    const double pi = acos(-1.0);
    return cos(graus * (pi / 180.0)); //retorna o valor do cosseno
}
double tangente(double graus){ //função tangente
    const double pi = acos(-1.0);
    return tan(graus * (pi / 180.0)); //retorna o valor da tangente
}

//-----------------------------------------------------Estatísticas-----------------------------------------------------------------------------//

double media(double array[], int n){ //função média
    double soma = 0; //inicializa a variavel soma com 0
    for (int i = 0; i < n; i++) {
        soma += array[i];
    }
    return soma / n; //retorna o valor da média
}
double mediana(double array[], int n){ //função mediana
    // Primeiro, ordena o array
    for (int i = 0; i < n - 1; i++) { //loop para percorrer o array
        for (int j = i + 1; j < n; j++) { //loop para comparar os elementos do array
            if (array[i] > array[j]) { //verifica se o elemento atual é maior que o próximo
                double temp = array[i]; //realiza a troca dos elementos
                array[i] = array[j]; //realiza a troca dos elementos
                array[j] = temp;
            }
        }
    }
    // Depois, calcula a mediana
    if (n % 2 == 0) { //verifica se o número de elementos é par
        return (array[n / 2 - 1] + array[n / 2]) / 2.0; //retorna a média dos dois elementos centrais
    } else {
        return array[n / 2];
    }
}
double desvioPadrao(double array[], int n){ //função desvio padrão
    double m = media(array, n); //chama a função média
    double somaQuadrados = 0; //inicializa a variavel somaQuadrados com 0
    for (int i = 0; i < n; i++) {
        somaQuadrados += pow(array[i] - m, 2); //realiza a soma dos quadrados das diferenças
    }
    return sqrt(somaQuadrados / n);
}

//--------------------------------------------------Derivada Numérica---------------------------------------------------------------------------//

double derivada(double (*func)(double), double x, double h){ //função derivada
    return (func(x + h) - func(x - h)) / (2 * h); //retorna o valor da derivada
}
double aplicarFatorial(int n){ //função aplicar fatorial
    if (n < 0) {
        printf("Erro: Fatorial não definido para números negativos!\n");
        return NAN; // Retorna Not-a-Number em caso de número negativo
    }
    if (n == 0) {
        return 1; // O fatorial de 0 é 1
    }
    double fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial; //retorna o valor do fatorial
}
double logaritmoNatural(double valor){ //função logaritmo natural
    if (valor <= 0) {
        printf("Erro: Logaritmo natural não definido para valores menores ou iguais a zero!\n");
        return NAN; // Retorna Not-a-Number em caso de valor inválido
    }
    return log(valor); //retorna o valor do logaritmo natural
}
double logaritmoBase10(double valor){ //função logaritmo base 10
    if (valor <= 0) {
        printf("Erro: Logaritmo na base 10 não definido para valores menores ou iguais a zero!\n");
        return NAN; // Retorna Not-a-Number em caso de valor inválido
    }
    return log10(valor); //retorna o valor do logaritmo base 10
}
double logaritmoBase2(double valor){ //função logaritmo base 2
    if (valor <= 0) {
        printf("Erro: Logaritmo na base 2 não definido para valores menores ou iguais a zero!\n");
        return NAN; // Retorna Not-a-Number em caso de valor inválido
    }
    return log2(valor); //retorna o valor do logaritmo base 2
}
double separarMantissaExpoente(double valor, int* expoente){ //função separar mantissa e expoente
    double mantissa = frexp(valor, expoente);
    return mantissa; //retorna o valor da mantissa
}
double restoDivisao(int dividendo, int divisor){ //função resto da divisão
    if (divisor == 0) {
        printf("Erro: Divisão por zero!\n");
        return NAN; // Retorna Not-a-Number em caso de divisão por zero
    }
    return dividendo % divisor; //retorna o valor do resto da divisão
}
double raizCubica(double valor){ //função raiz cúbica
    return cbrt(valor); //retorna o valor da raiz cúbica
}
double diferencaPositiva(double a, double b){ //função diferença positiva entre valores
    return fabs(a - b); //retorna o valor da diferença positiva
}
double mmc(int a, int b){ //função mínimo múltiplo comum
    int maior = (a > b) ? a : b;
    while (1) {
        if (maior % a == 0 && maior % b == 0) { //verifica se o numero maior é multiplo de a e b
            return maior; //retorna o valor do mmc
        }
        maior++;
    }
}
double mdc(int a, int b){ //função máximo divisor comum
    while (b != 0) { // enquanto b for diferente de 0
        int temp = b; // armazena b em uma variavel temporaria
        b = a % b; // atribui o valor do resto da divisão de a por b a b
        a = temp; // atribui o valor da variavel temporaria a
    }
    return a; //retorna o valor do mdc
}
double matrizSoma(double** matriz, int linhas, int colunas){ //função soma dos elementos de uma matriz
    double soma = 0; //inicializa a variavel soma com 0
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }
    }
    return soma; //retorna o valor da soma  
}
double matrizMultiplicacao(double** matrizA, double** matrizB, double** resultado, int linhasA, int colunasA, int colunasB){ //função multiplicação de matrizes
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            resultado[i][j] = 0; //inicializa o elemento da matriz resultado com 0
            for (int k = 0; k < colunasA; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j]; //realiza a multiplicação e soma dos elementos
            }
        }
    }
    return 0; //retorna 0 para indicar sucesso
}
int maxima_minima(double array[], int n, double* maximo, double* minimo){ //função máxima e mínima
    if (n <= 0) return -1;
    *maximo = array[0];
    *minimo = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > *maximo) {
            *maximo = array[i];
        }
        if (array[i] < *minimo) {
            *minimo = array[i];
        }
    }
    return 0; //retorna 0 para indicar sucesso
}

//-------------------------------------------------------Menu do programa-----------------------------------------------------------------------//

int main(void){
    int opcao;
    double res = 0, maximo, minimo;
    while(1){
    printf("----CALCULADORA CIENTÍFICA----\n");
    printf("1 - Adição\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("5 - Potenciação\n");
    printf("6 - Radiciação\n");
    printf("7 - Raíz Quadrada\n");
    printf("8 - Seno\n");
    printf("9 - Cosseno\n");
    printf("10 - Tangente\n");
    printf("11 - Média\n");
    printf("12 - Mediana\n");
    printf("13 - Desvio Padrão\n");
    printf("14 - Derivada\n");
    printf("15 - Aplicar Fatorial\n");
    printf("16 - Logaritmo natural\n");
    printf("17 - Logaritmo na base 10\n");
    printf("18 - Logaritmo na base 2\n");
    printf("19 - Mantissa e Expoente\n");
    printf("20 - Resto de Divisão\n");
    printf("21 - Raíz Cúbica\n");
    printf("22 - Diferença Positiva Entre Valores\n");
    printf("23 - MMC\n");
    printf("24 - MDC\n");
    printf("25 - Máxima e Mínima\n");
    printf("26 - Matriz Soma\n");
    printf("27 - Matriz Multiplicação\n");
    printf("Escolha a opção desejada:");
    if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");

            // Limpa o buffer de entrada
            int c; // variável para ler caracteres
            while ((c = getchar()) != '\n' && c != EOF); //serve para limpar o buffer de entrada, lendo e descartando caracteres até encontrar uma nova linha ou o fim do arquivo
            continue; //volta para o início do loop while
        }

        if (opcao == 0) { //se a opção for 0, encerra o programa
            printf("Encerrando...\n");
            break;
        }

        //  switch dentro do while
        switch (opcao) {
        case 1: {
            int n;
            printf("Digite quantos numeros deseja somar:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; } //verifica se a entrada é válida
            double *array = malloc(sizeof(double) * n); // malloc para alocar memória para o array
            if (!array) { printf("Memória insuficiente.\n"); break; } //verifica se a alocação de memória foi bem sucedida
            leArray(array, n); //chama a função leArray para ler os valores do array
            double res = adicao(array, n); //chama a função adição
            printf("O resultado da adicao e: %.2f\n", res);
            adicionarOperacao("Adicao", (n>0?array[0]:0), (n>1?array[1]:0), res); //adiciona a operação ao histórico
            free(array); // serve para liberar a memória alocada para o array
            break;
        }
        case 2: {
            int n;
            printf("Digite quantos numeros deseja subtrair:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n); 
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n); 
            double res = subtracao(array, n); 
            printf("O resultado da subtracao e: %.2f\n", res); 
            adicionarOperacao("Subtracao", array[0], (n>1?array[1]:0), res); 
            free(array);
            break;
        }
        case 3: {
            int n;
            printf("Digite quantos numeros deseja multiplicar:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n);
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n);
            double res = multiplicacao(array, n);
            printf("O resultado da multiplicacao e: %.2f\n", res);
            adicionarOperacao("Multiplicacao", array[0], (n>1?array[1]:0), res);
            free(array);
            break;
        }
        case 4: {
            int n;
            printf("Digite quantos numeros deseja dividir:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n);
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n);
            double res = divisao(array, n);
            if (!isnan(res)) {
                printf("O resultado da divisao e: %.2f\n", res);
                adicionarOperacao("Divisao", array[0], (n>1?array[1]:0), res);
            }
            free(array);
            break;
        }
        default:
            printf("Opcao invalida ou ainda nao implementada nesta versao.\n");
            break;
        case 5:
            {
            double base, expoente;
            printf("Digite a base:\n");
            if (scanf("%lf", &base) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o expoente:\n");
            if (scanf("%lf", &expoente) != 1) { printf("Entrada inválida.\n"); break; }
            double res = potencia(base, expoente);
            printf("O resultado da potenciacao e: %.2f\n", res);
            adicionarOperacao("Potenciacao", base, expoente, res);
            break;
            }
        case 6:
            {
            double radicando, indice;
            printf("Digite o radicando:\n");
            if (scanf("%lf", &radicando) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o indice:\n");
            if (scanf("%lf", &indice) != 1) { printf("Entrada inválida.\n"); break; }
            double res = radiciacao(radicando, indice);
            if (!isnan(res)) {
                printf("O resultado da radiciacao e: %.2f\n", res);
                adicionarOperacao("Radiciacao", radicando, indice, res);
            }
            break;
            }
        case 7:
            {
            double valor;
            printf("Digite o valor:\n");
            if (scanf("%lf", &valor) != 1) { printf("Entrada inválida.\n"); break; }
            double res = raizQuadrada(valor);
            if (!isnan(res)) {
                printf("O resultado da raiz quadrada e: %.2f\n", res);
                adicionarOperacao("Raiz Quadrada", valor, 0, res);
            }
            break;
            }
        case 8:
            {
            double graus;
            printf("Digite o valor em graus:\n");
            if (scanf("%lf", &graus) != 1) { printf("Entrada inválida.\n"); break; }
            double res = seno(graus);
            printf("O resnn    ultado do seno e: %.2f\n", res);
            adicionarOperacao("Seno", graus, 0, res);
            break;
            }
        case 9:
            {
            double graus;
            printf("Digite o valor em graus:\n");
            if (scanf("%lf", &graus) != 1) { printf("Entrada inválida.\n"); break; }
            double res = cosseno(graus);
            printf("O resultado do cosseno e: %.2f\n", res);
            adicionarOperacao("Cosseno", graus, 0, res);
            break;
            }    
        case 10:
            {
            double graus;
            printf("Digite o valor em graus:\n");
            if (scanf("%lf", &graus) != 1) { printf("Entrada inválida.\n"); break; }
            double res = tangente(graus);
            printf("O resultado da tangente e: %.2f\n", res);
            adicionarOperacao("Tangente", graus, 0, res);
            break;
            }
        case 11:
            {
            int n;
            printf("Digite quantos numeros deseja calcular a media:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n);
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n);
            double res = media(array, n);
            printf("O resultado da media e: %.2f\n", res);
            adicionarOperacao("Media", (n>0?array[0]:0), (n>1?array[1]:0), res);
            free(array);
            break;
            }
        case 12:
            {
            int n;
            printf("Digite quantos numeros deseja calcular a mediana:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n);
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n);
            double res = mediana(array, n);
            printf("O resultado da mediana e: %.2f\n", res);
            adicionarOperacao("Mediana", (n>0?array[0]:0), (n>1?array[1]:0), res);
            free(array);
            break;
            }
        case 13:
            {
            int n;
            printf("Digite quantos numeros deseja calcular o desvio padrao:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n);
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n);
            double res = desvioPadrao(array, n);
            printf("O resultado do desvio padrao e: %.2f\n", res);
            adicionarOperacao("Desvio Padrao", (n>0?array[0]:0), (n>1?array[1]:0), res);
            free(array);
            break;
            }
        case 14:
            {
            double x, h;
            printf("Digite o valor de x:\n");
            if (scanf("%lf", &x) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o valor de h (pequeno):\n");
            if (scanf("%lf", &h) != 1) { printf("Entrada inválida.\n"); break; }
            double res = derivada(seno, x, h); //exemplo usando a função seno
            printf("O resultado da derivada no ponto %.2f e: %.2f\n", x, res);
            adicionarOperacao("Derivada", x, h, res);
            break;
            }
        case 15:
            {
            int n;
            printf("Digite um numero inteiro para calcular o fatorial:\n");
            if (scanf("%d", &n) != 1) { printf("Entrada inválida.\n"); break; }
            double res = aplicarFatorial(n);
            if (!isnan(res)) {
                printf("O resultado do fatorial de %d e: %.2f\n", n, res);
                adicionarOperacao("Fatorial", n, 0, res);
            }
            break;
            }
        case 16:
            {
            double valor;
            printf("Digite o valor para calcular o logaritmo natural:\n");
            if (scanf("%lf", &valor) != 1) { printf("Entrada inválida.\n"); break; }
            double res = logaritmoNatural(valor);
            if (!isnan(res)) {
                printf("O resultado do logaritmo natural de %.2f e: %.2f\n", valor, res);
                adicionarOperacao("Logaritmo Natural", valor, 0, res);
            }
            break;
            }
        case 17:
            {
            double valor;
            printf("Digite o valor para calcular o logaritmo na base 10:\n");
            if (scanf("%lf", &valor) != 1) { printf("Entrada inválida.\n"); break; }
            double res = logaritmoBase10(valor);
            if (!isnan(res)) { //verifica se o resultado não é NAN
                printf("O resultado do logaritmo na base 10 de %.2f e: %.2f\n", valor, res);
                adicionarOperacao("Logaritmo Base 10", valor, 0, res);
            }
            break;
            }
        case 18:
            {
            double valor;
            printf("Digite o valor para calcular o logaritmo na base 2:\n");
            if (scanf("%lf", &valor) != 1) { printf("Entrada inválida.\n"); break; }
            double res = logaritmoBase2(valor);
            if (!isnan(res)) {
                printf("O resultado do logaritmo na base 2 de %.2f e: %.2f\n", valor, res);
                adicionarOperacao("Logaritmo Base 2", valor, 0, res);
            }
            break;
            }
        case 19:
            {
            double valor;
            printf("Digite o valor para separar mantissa e expoente:\n");
            if (scanf("%lf", &valor) != 1) { printf("Entrada inválida.\n"); break; }
            int expoente;
            double mantissa = separarMantissaExpoente(valor, &expoente);
            printf("Mantissa: %.2f, Expoente: %d\n", mantissa, expoente);
            adicionarOperacao("Mantissa e Expoente", valor, 0, mantissa);
            break;
            }
        case 20:
            {
            int dividendo, divisor;
            printf("Digite o dividendo:\n");
            if (scanf("%d", &dividendo) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o divisor:\n");
            if (scanf("%d", &divisor) != 1) { printf("Entrada inválida.\n"); break; }
            double res = restoDivisao(dividendo, divisor);
            if (!isnan(res)) {
                printf("O resto da divisao de %d por %d e: %.2f\n", dividendo, divisor, res);
                adicionarOperacao("Resto Divisao", dividendo, divisor, res);
            }
            break;
            }
        case 21: {
            double valor;
            printf("Digite o valor para calcular a raiz cubica:\n");
            if (scanf("%lf", &valor) != 1) { printf("Entrada inválida.\n"); break; }
            res = raizCubica(valor);
            printf("O resultado da raiz cubica de %.2f e: %.2f\n", valor, res);
            adicionarOperacao("Raiz Cubica", valor, 0, res);
            break;
        }
        case 22: {
            double a, b;
            printf("Digite o primeiro valor:\n");
            if (scanf("%lf", &a) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o segundo valor:\n");
            if (scanf("%lf", &b) != 1) { printf("Entrada inválida.\n"); break; }
            res = diferencaPositiva(a, b);
            printf("A diferenca positiva entre %.2f e %.2f e: %.2f\n", a, b, res);
            adicionarOperacao("Diferenca Positiva", a, b, res);
            break;
        }
        case 23: {
            int a, b;
            printf("Digite o primeiro valor:\n");
            if (scanf("%d", &a) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o segundo valor:\n");
            if (scanf("%d", &b) != 1) { printf("Entrada inválida.\n"); break; }
            double res = mmc(a, b);
            printf("O MMC de %d e %d e: %.2f\n", a, b, res);
            adicionarOperacao("MMC", a, b, res);
            break;
        }
        case 24: {
            int a, b;
            printf("Digite o primeiro valor:\n");
            if (scanf("%d", &a) != 1) { printf("Entrada inválida.\n"); break; }
            printf("Digite o segundo valor:\n");
            if (scanf("%d", &b) != 1) { printf("Entrada inválida.\n"); break; }
            double res = mdc(a, b);
            printf("O MDC de %d e %d e: %.2f\n", a, b, res);
            adicionarOperacao("MDC", a, b, res);
            break;
        }
        case 25:
            {
            int n;
            printf("Digite quantos numeros deseja analisar para maxima e minima:\n");
            if (scanf("%d", &n) != 1 || n <= 0) { printf("Entrada inválida.\n"); break; }
            double *array = malloc(sizeof(double) * n);
            if (!array) { printf("Memória insuficiente.\n"); break; }
            leArray(array, n);
            double maximo, minimo; 
            if (maxima_minima(array, n, &maximo, &minimo) == 0) {
                printf("O valor maximo e: %.2f\n", maximo);
                printf("O valor minimo e: %.2f\n", minimo);
                adicionarOperacao("Maxima e Minima", (n>0?array[0]:0), (n>1?array[1]:0), maximo);
            }
            free(array);
            break;
            }
        case 26:
            {
            int linhas, colunas;
            printf("Digite o número de linhas da matriz:\n");
            if (scanf("%d", &linhas) != 1 || linhas <= 0) { printf("Entrada inválida.\n"); break; }
            printf("Digite o número de colunas da matriz:\n");
            if (scanf("%d", &colunas) != 1 || colunas <= 0) { printf("Entrada inválida.\n"); break; }
            double **matriz = malloc(linhas * sizeof(double*));
            if (!matriz) { printf("Memória insuficiente.\n"); break; }
            for (int i = 0; i < linhas; i++) {
                matriz[i] = malloc(colunas * sizeof(double));
                if (!matriz[i]) { printf("Memória insuficiente.\n"); break; }
            }
            printf("Digite os elementos da matriz:\n");
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    printf("Elemento [%d][%d]: ", i, j);
                    if (scanf("%lf", &matriz[i][j]) != 1) { printf("Entrada inválida.\n"); break; }
                }
            }
            double res = matrizSoma(matriz, linhas, colunas); //chama a função matrizSoma
            printf("O resultado da soma dos elementos da matriz e: %.2f\n", res);
            adicionarOperacao("Matriz Soma", linhas, colunas, res);
            for (int i = 0; i < linhas; i++) {
                free(matriz[i]);
            }
            free(matriz);
            break;
            }
        case 27:
            {
            int linhasA, colunasA, linhasB, colunasB;
            printf("Digite o número de linhas da matriz A:\n");
            if (scanf("%d", &linhasA) != 1 || linhasA <= 0) { printf("Entrada inválida.\n"); break; }
            printf("Digite o número de colunas da matriz A:\n");
            if (scanf("%d", &colunasA) != 1 || colunasA <= 0) { printf("Entrada inválida.\n"); break; }
            printf("Digite o número de linhas da matriz B:\n");
            if (scanf("%d", &linhasB) != 1 || linhasB <= 0) { printf("Entrada inválida.\n"); break; }
            printf("Digite o número de colunas da matriz B:\n");
            if (scanf("%d", &colunasB) != 1 || colunasB <= 0) { printf("Entrada inválida.\n"); break; }
            if (colunasA != linhasB) {
                printf("Erro: Número de colunas da matriz A deve ser igual ao número de linhas da matriz B para multiplicação.\n");
                break;
            }
            double **matrizA = malloc(linhasA * sizeof(double*));
            double **matrizB = malloc(linhasB * sizeof(double*));
            double **resultado = malloc(linhasA * sizeof(double*));
            if (!matrizA || !matrizB || !resultado) { printf("Memória insuficiente.\n"); break; }
            for (int i = 0; i < linhasA; i++) {
                matrizA[i] = malloc(colunasA * sizeof(double)); // aloca memória para cada linha da matriz A
                resultado[i] = malloc(colunasB * sizeof(double));
                if (!matrizA[i] || !resultado[i]) { printf("Memória insuficiente.\n"); break; } //verifica se a alocação de memória foi bem sucedida
            }
            for (int i = 0; i < linhasB; i++) { 
                matrizB[i] = malloc(colunasB * sizeof(double));
                if (!matrizB[i]) { printf("Memória insuficiente.\n"); break; }
            }
            printf("Digite os elementos da matriz A:\n");
            for (int i = 0; i < linhasA; i++) {
                for (int j = 0; j < colunasA; j++) {
                    printf("Elemento A[%d][%d]: ", i, j);
                    if (scanf("%lf", &matrizA[i][j]) != 1) { printf("Entrada inválida.\n"); break; }
                }
            }
            printf("Digite os elementos da matriz B:\n");
            for (int i = 0; i < linhasB; i++) {
                for (int j = 0; j < colunasB; j++) {
                    printf("Elemento B[%d][%d]: ", i, j);
                    if (scanf("%lf", &matrizB[i][j]) != 1) { printf("Entrada inválida.\n"); break; }
                }
            }
            matrizMultiplicacao(matrizA, matrizB, resultado, linhasA, colunasA, colunasB);
            printf("O resultado da multiplicacao das matrizes e:\n");
            for (int i = 0; i < linhasA; i++) {
                for (int j = 0; j < colunasB; j++) {
                    printf("%.2f ", resultado[i][j]);
                }
                printf("\n");
            }
            adicionarOperacao("Matriz Multiplicacao", linhasA, colunasB, 0); // resultado não é um único valor
            for (int i = 0; i < linhasA; i++) {
                free(matrizA[i]);
                free(resultado[i]);
            }
            for (int i = 0; i < linhasB; i++) {
                free(matrizB[i]);
            }
            free(matrizA); // free para liberar a memória alocada para a matriz A
            free(matrizB);
            free(resultado);
            break;
            }
        } // fecha switch
            exibirHistorico(); // Exibe o histórico de operações realizadas
            
    } // fecha while
    
    return 0;
}
