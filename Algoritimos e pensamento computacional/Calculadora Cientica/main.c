#include <stdio.h>
#include <math.h>
int main()
{
    // definindo variáveis para armazenar valores inteiros
    int opcao, n, n3, n4;
    // definindo variáveis para armazenar valores inteiros ou quebrados
    float num1, num2, res, A, B, a, b, c, x1, x2, x;
    // criando uma variável para armazenar o valor de pi
    // normalmente será uma variável double ou const (constante)
    // a função M_PI é da biblioteca math.h, é o valor de PI
    double pi = M_PI;
    // definindo variáveis para armazenar dois ou mais valores;
    // ang_rad e ang_g armazenarão angulos radianos e angulos em graus em cálculos de
    // seno, cosseno e tangente e variações
    double ang_rad, ang_g, n2, r2, r3;
    // mostrando as opções para o usuário
    double array[4]; // Armazena os dois números
    double resultado;
    printf("Bem vindo a Calculadora Cientifica!\n");
    printf("Escolha a operacao que deseja realizar:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Potenciacao\n");
    printf("6 - Radiciacao\n");
    printf("7 - Raiz quadrada\n");
    printf("8 - Sen\n");
    printf("9 - Cos\n");
    printf("10 - Tan\n");
    printf("11 - Arco Seno\n");
    printf("12 - Arco Cosseno\n");
    printf("13 - Arco Tangente\n");
    printf("14 - Derivada\n");
    printf("15 - Aplicar Fatorial\n");
    printf("16 - Logaritmo natural\n");
    printf("17 - Logaritmo na base 10\n");
    printf("18 - Logaritmo na base 2\n");
    printf("19 - Mantissa e Expoente\n");
    printf("20 - Resto de Divisão\n");
    printf("21 - Raíz Cúbica\n");
    printf("22 - Diferença Positiva Entre Valores\n");
    printf("23 - Seno hiperbólico\n");
    printf("24 - Cosseno hiperbólico\n");
    printf("25 - Tangente hiperbólico\n");
    // scanf é o padrão de input (inserção de informação)
    // ou seja, o usuário vai inserir uma informação
    //%d pois será um número inteiro (uma opção de 1 até 25), se fosse um número quebrado seria %f e etc
    //&variável armazena o valor inserido dentro da variável
    // pegamos a opção do usuário (um valor de 1 até 25) e armazenamos na variável opção
    scanf("%d", &opcao);
    // switch case é a estrutura condicional para variáveis que se alteram muito
    // ela avalia diversas condições e executa algo diferente para cada condição
    // então switch(opção) vai avaliar a variável opção (armazenou a opção do usuário) e fazer algo diferente
    // de acordo com a escolha que vai aparecer ali naqueles cases
    // tenta entender algo como "avalie(variável){*caso x: *faça isso - *pare; *case y: *faça aquilo - *pare;}"
    // esse "pare" na minha abstração seria o "break;" no final de cada caso, que é necessário
    // coloquei um * pra tentar sinalizar onde está o exemplo que eu abstraí
    //  Entrada dos dois núme
    // Switch-case para escolher a operação
switch (opcao) {
    case 1: // Soma
        printf("Digite 4 números (inteiros ou decimais):\n");
        for (int i = 0; i < 4; i++) {
            printf("Número %d: ", i + 1);
            scanf("%lf", &array[i]);
        }

        resultado = 0;
        for (int i = 0; i < 4; i++) {
            resultado += array[i];
        }
        printf("Resultado da soma: %.2lf\n", resultado);
        break;

    case 2: // Subtração
        printf("Digite 4 números (inteiros ou decimais):\n");
        for (int i = 0; i < 4; i++) {
            printf("Número %d: ", i + 1);
            scanf("%lf", &array[i]);
        }

        resultado = array[0];
        for (int i = 1; i < 4; i++) {
            resultado -= array[i];
        }
        printf("Resultado da subtração: %.2lf\n", resultado);
        break;

    case 3: // Multiplicação
        printf("Digite 4 números (inteiros ou decimais):\n");
        for (int i = 0; i < 4; i++) {
            printf("Número %d: ", i + 1);
            scanf("%lf", &array[i]);
        }

        resultado = 1;
        for (int i = 0; i < 4; i++) {
            resultado *= array[i];
        }
        printf("Resultado da multiplicação: %.2lf\n", resultado);
        break;

    case 4: // Divisão
        printf("Digite 4 números (inteiros ou decimais):\n");
        for (int i = 0; i < 4; i++) {
            printf("Número %d: ", i + 1);
            scanf("%lf", &array[i]);
        }

        resultado = array[0];
        for (int i = 1; i < 4; i++) {
            if (array[i] != 0) {
                resultado /= array[i];
            } else {
                printf("Erro: divisão por zero não é permitida.\n");
                return 1;
            }
        }
        printf("Resultado da divisão: %.2lf\n", resultado);
        break;
        
    case 5: // POTENCIAÇÃO
        // pedindo e armazenando valores em variáveis conforme explicado
        printf("Digite a base:\n");
        scanf("%f", &num1);
        printf("Digite o expoente:\n");
        scanf("%f", &num2);
        // variável res RECEBE o valor de uma equação
        // a equação é feita através da função pow() da biblioteca math.h
        // ela calcula potenciação pra gente, o primeiro parâmetro é a base e o segundo é o expoente
        res = pow(num1, num2);
        // desenhando o resultado na tela conforme já explicado
        printf("O resultado da potenciacao e: %.2f\n", res);
        break;
    case 6: // Radiciação
        // pedindo dois valores e armazenando em variáveis conforme já explicado
        printf("Digite o radicando:\n");
        scanf("%f", &num1);
        printf("Digite o indice:\n");
        scanf("%f", &num2);
        // acontece que para calcular radiciação o indice não pode ser 0 se não fodeu
        // daí a gente vai fazer uma outra estrutura condicional aqui dentro, a mais simples
        // if(parâmetro){código}else{outro-codigo}
        // if pode ser lido como "se", então a gente coloca o parâmetro que queremos entre os parênteses
        // o parâmetro é se o indice é 0, o indice está armazenado na variável num2
        // então o que tá escrito aqui é "se o indice (na variável num2) for igual a 0, execute o que está entre as chaves"
        if (num2 == 0)
        {
            printf("Erro: Indice nao pode ser zero.\n");
        }
        else
        {
            res = pow(num1, 1.0 / num2);
            // escrevendo o texto do resultado e substituindo a % pela variável após a string
            //%.2f pois é um número flutuante com duas casas decimais e está sendo substituído pela variável res que armazena o resultado
            printf("O resultado da radiciacao e: %.2f\n", res);
        }
        break;
    case 7: // RAÍZ QUADRADA
        // pedindo e armazenando o valor
        printf("Digite o valor:\n");
        scanf("%f", &num1);
        // se o número for negativo, não dá pra tirar raíz quadrada e a variável num retornaria um valor
        // que não pode ser desenhado dentro da nossa formatação, o mesmo problema do indice ser 0 na radiciação
        // então a gente repete a estrutura dizendo que se for menor que 0 (negativo) vai dar a telinha de erro
        if (num1 < 0)
        {
            printf("Erro: Raiz quadrada de numero negativo nao e permitida.\n");
        }
        else
        {
            // então se puder rodar o código
            // variável res RECEBE a raíz do número que o usuário digitou e foi armazenado na variável num1
            // a função sqrt (square root) da biblioteca math.h calcula raíz quadrada
            res = sqrt(num1);
            // escrevendo o texto do resultado e substituindo a % pela variável após a string
            //%.2f pois é um número flutuante com duas casas decimais e está sendo substituído pela variável res que armazena o resultado
            printf("O resultado da raiz quadrada e: %.2f\n", res);
        }
        break;
    case 8: // SENO
        // pedindo e armazenando o valor na variável num1
        printf("Digite o valor em graus:\n");
        scanf("%f", &num1);
        // a função sin da biblioteca math.h calcula o seno de um angulo fornecido em radianos
        // aqui estamos pedindo o ângulo em graus, multiplicando ele por pi dividido por 180 para entregar o resultado em radianos
        // M_PI da biblioteca math.h é simplesmente pi (3,14blablabla)
        res = sin(num1 * (M_PI / 180.0));
        printf("O resultado do seno e: %.2f\n", res);
        break;
    case 9: // COSSENO
        // pedindo e armazenando valores na variável num1
        printf("Digite o valor em graus:\n");
        scanf("%f", &num1);
        // a função cos da biblioteca math.h calcula o cosseno de um angulo fornecido em radianos
        // aqui estamos pedindo o ângulo em graus, multiplicando ele por pi dividido por 180 para entregar o resultado em radianos
        // M_PI da biblioteca math.h é simplesmente pi (3,14blablabla)
        res = cos(num1 * (M_PI / 180.0));
        printf("O resultado do cosseno e: %.2f\n", res);
        break;
    case 10: // TANGENTE
        // pedindo e armazenando valores na variável num1
        printf("Digite o valor em graus:\n");
        scanf("%f", &num1);
        // a função tan da biblioteca math.h calcula a tangente de um angulo fornecido em radianos
        // aqui estamos pedindo o ângulo em graus, multiplicando ele por pi dividido por 180 para entregar o resultado em radianos
        // M_PI da biblioteca math.h é simplesmente pi (3,14blablabla)
        res = tan(num1 * (M_PI / 180.0));
        printf("O resultado da tangente e: %.2f\n", res);
        break;
    case 11:
        printf("Digite o seno: ");
        scanf("%f", &x);
        ang_rad = asin(x);
        ang_g = ang_rad * (180.0 / pi);
        printf("O arco seno de %f é %f radianos;\n", x, ang_rad);
        printf("O arco seno de %f é %f graus;\n", x, ang_g);
        break;
    case 12:
        printf("Digite o cosseno: ");
        scanf("%f", &x);
        ang_rad = acos(x);
        ang_g = ang_rad * (180 / pi);
        printf("O arco cosseno de %f é %f radianos;\n", x, ang_rad);
        printf("O arco cosseno de %f é %f graus;\n", x, ang_g);
        break;
    case 13:
        printf("Digite a tangente: ");
        scanf("%f", &x);
        ang_rad = atan(x);
        ang_g = ang_rad * (180 / pi);
        printf("O arco tangente de %.2f é %f em graus\n", x, ang_g);
        printf("O arco tangente de %.2f é %f radianos\n", x, ang_rad);
        break;
    case 14:
        int p;
        float f, e;
        printf("insira o valor do coeficiente: ");
        scanf("%f", &a);
        printf("insira o valor de x: ");
        scanf("%f", &x);
        printf("insira o valor de n(expoente): ");
        scanf("%d", &n);
        p = n - 1;
        e = pow(x, p);
        f = n * a * e;
        res = f;
        printf("A derivada da funcao no ponto = P é: %f\n", res);
        break;
    case 15: // o código desta equação foi copiado do gemini e por isto é esse megazord estranho
             // é gritante a diferença entre um código copiado e os outros (em que eu compreendi o que fazia)
             // se eu pudesse parar pra entender fatorial, tentaria algo menos robusto. Não sei se é possível
        int i;
        long long fatorial = 1; // Usar long long para evitar estouro com números maiores
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &n);
        // Verifica se o número é negativo, pois fatorial não é definido para negativos
        if (n < 0)
        {
            printf("Fatorial não definido para números negativos.\n");
        }
        else
        {
            // O fatorial de 0 é 1
            if (n == 0)
            {
                fatorial = 1;
            }
            else
            {
                // Calcula o fatorial usando um loop for
                for (i = 1; i <= n; i++)
                {
                    fatorial *= i; // Multiplica o fatorial pelo número atual (i)
                }
            }
            printf("O fatorial de %d é %lld\n", n, fatorial);
        }
        break;
    case 16:
        printf("Digite o valor: ");
        scanf("%lf", &n2);
        r2 = log(n2);
        printf("O logaritmo natural de %.2f é: %f\n", n2, r2);
        break;
    case 17:
        printf("Digite o valor: ");
        scanf("%lf", &n2);
        r2 = log10(n2);
        printf("O logaritmo de %.2f na base 10 é: %f\n", n2, r2);
        break;
    case 18:
        printf("Digite o valor: ");
        scanf("%lf", &n2);
        r2 = log2(n2);
        printf("O logaritmo de %.2f na base 2 é: %f\n", n2, r2);
        break;
    case 19:
        double mantissa;
        printf("Digite o número a ser separado: ");
        scanf("%lf", &n2);
        r2 = frexp(n2, &n);
        mantissa = r2;
        printf("Número original: %lf\n", n2);
        printf("Mantissa: %lf\n", mantissa);
        printf("Expoente: %d\n", n);
        break;
    case 20:
        printf("Digite o valor do dividendo: ");
        scanf("%d", &n);
        printf("Digite o valor do divisor: ");
        scanf("%d", &n3);
        res = n % n3;
        printf("O resto da divisão de %d por %d é: %.2lf\n.", n, n3, res);
        break;
    case 21:
        printf("Digite o valor: ");
        scanf("%lf", &n2);
        r2 = cbrt(n2);
        printf("A raíz cúbica de %lf é: %lf", n2, r2);
        break;
    case 22:
        printf("Digite o primeiro valor: ");
        scanf("%d", &n);
        printf("Digite o segundo valor: ");
        scanf("%d", &n3);
        if (n > n3)
        {
            n4 = n - n3;
        }
        else
        {
            n4 = n3 - n;
        }
        printf("A diferença positiva é: %d\n", n4);
        break;
    case 23:
        printf("Digite o valor de entrada: ");
        scanf("%lf", &n2);
        r2 = sinh(n2);
        printf("O seno hiperbólico de %lf é: %lf", n2, r2);
        break;
    case 24:
        printf("Digite o valor de entrada: ");
        scanf("%lf", &n2);
        r2 = cosh(n2);
        printf("O cosseno hiperbólico de %lf é: %lf", n2, r2);
        break;
    case 25:
        printf("Digite o valor de entrada: ");
        scanf("%lf", &n2);
        r2 = tanh(n2);
        // tá arredondando pra cima, o que é um problema pq isso aqui é usado pra calcular uns resultados tipo 0,9999944
        // daí tá sempre dando 1
        // me ajudem a resolver isto por favor <2
        printf("O tangente hiperbólico de %lf é: %lf", n2, r2);
        break;
    default:
        printf("Opcao invalida.\n");
        break;
        return 0;
    }
}
