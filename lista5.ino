#include <stdio.h>

#define ex1

#ifdef ex1
/*Receba 2 string de ate 10 caracteres via teclado na funcao main().
Faça uma funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se DIFERENTES 0 para a funcao main().
Imprima o resultado na funcao main().
(Declare os vetores como variavel global)*/

int verifica(char s1[], char s2[]);

main()
{
    int continuar;

    do
    {
        int c,r;
        char s1[10],s2[10];

        printf("Digite um texto de ate 10 caracteres:\n");
        fgets(s1, 10, stdin);
        printf("Digite outro texto de ate 10 caracteres:\n");
        fgets(s2, 10, stdin);

        r=verifica(s1,s2);

        system("cls");
        printf("Texto 1:\n");
        puts(s1);
        printf("Texto 2:\n");
        puts(s2);

        if (r==1)
            printf("\nOs dois textos sao iguais\n");
        else
            printf("\nOs dois textos sao diferentes\n");

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);

        system("cls");
    }
    while(continuar==1);
}

int verifica(char s1[], char s2[])
{
    int i=0;

    while (s1[i]!='\0' && s2[i]!='\0')
    {
        if (s1[i]!=s2[i])
        {
            return 0;
        }
        i++;
    }

    if (s1[i] != s2[i])
        return 0;
    else
        return 1;
}
#endif // ex1

#ifdef ex2
/*Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado e imprima-os no video no seguinte formato:
(Declare os 5 vetores como variaveis globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3*/

main()
{
    int continuar;

    do
    {
        char s1[7],s2[7],s3[7],s4[7],s5[7];

        printf("Digite o 1 nome:\n");
        scanf("%s", s1);

        printf("Digite o 2 nome:\n");
        scanf("%s", s2);

        printf("Digite o 3 nome:\n");
        scanf("%s", s3);

        printf("Digite o 4 nome:\n");
        scanf("%s", s4);

        printf("Digite o 5 nome:\n");
        scanf("%s", s5);

        printf("        10        20        30        40        50       ");
        printf("\n1234567890123456789012345678901234567890123456789012345");
        printf("\n%5s %45s\n",s1,s5);
        printf("%20s %15s\n",s2,s4);
        printf("%30s\n",s3);
        //printf("\n%1s",s4);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);

        system("cls");
    }
    while(continuar==1);
}
#endif // ex2

#ifdef ex3
/*Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres para letras maiusculas.*/

void maiusculo(char s1[],char s2[]);

main()
{
    int continuar;

    do
    {
        char s1[10],s2[10];

        printf("Digite um texto de ate 10 caracteres:\n");
        fgets(s1,10,stdin);

        maiusculo(s1,s2);
        printf("%s\n",s2);
        //puts(s2);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);

        system("cls");
    }while(continuar==1);
    return 0;
}

void maiusculo(char s1[],char s2[])
{
    int i=0;
    while(s1[i]!='\0'){
        s2[i]=toupper(s1[i]);
        i++;
    }
    s2[i]='\0';
}
#endif // ex3

#ifdef ex4
/*Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres para letras minusculas.*/

void minusculo(char s1[],char s2[]);

main()
{
    int continuar;

    do
    {
        char s1[10],s2[10];

        printf("Digite um texto de ate 10 caracteres:\n");
        fgets(s1,10,stdin);

        minusculo(s1,s2);
        printf("%s\n",s2);
        //puts(s2);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);

        system("cls");
    }while(continuar==1);
    return 0;
}

void minusculo(char s1[],char s2[])
{
    int i=0;
    while(s1[i]!='\0'){
        s2[i]=tolower(s1[i]);
        i++;
    }
    s2[i]='\0';
}
#endif // ex4

#ifdef ex5
/*Escreva um programa que receba uma string na funcao main().
Faca uma funcao que calcula o comprimento de uma string recebida via teclado.
Mostre o valor do comprimento na funcao main().
(Declare o vetor como variavel global)*/

int calculo(char s1[]);

main()
{
    int continuar;

    do
    {
        char s1[30];
        int tam;

        printf("Digite um texto ate 30 caracteres:\n");
        gets(s1);

        tam=calculo(s1);

        printf("O tamanho da string e': %d\n",tam);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);

        system("cls");
    }while(continuar==1);
}

int calculo(char s1[])
{
int i=0;
    while (s1[i] != '\0') {
        i++;
    }
    return i;
}
#endif // ex5
