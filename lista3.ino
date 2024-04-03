#include <stdio.h>

#define ex5

#ifdef ex1
/*Escreva um programa que receba dois numeros inteiros e execute as seguintes funcoes:
-Verificar se o numero é positivo ou negativo. Sendo que o valor de retorno sera 1 se positivo, 0 se negativo ou -1 se for igual a 0.
-Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre eles.
-Se os 2 numeros sao negativos, retorne a multiplicacao dos n numeros existentes entre eles.
-Se 1 numero for positivo e 1 negativo, faca a divisao entre eles.*/

int multiplicacao(int num1,int num2);
float divisao(int num1,int num2);
int soma(int num1,int num2);
int subtracao(int num1,int num2);

main()
{
    int num1,num2,continuar,verif1,verif2;

    do
    {
        printf("Digite um numero:\n");
        scanf("%d", &num1);
        printf("Digite um outro numero:\n");
        scanf("%d", &num2);

        verif1=verificar(num1);
        verif2=verificar(num2);

        if (verif1==1 && verif2==1)
        {
            printf("A soma do intervalo desses numeros\n");
            int s=soma(num1,num2);
            printf("%d", s);
        }
        else if (verif1==0 && verif2==0)
        {
            printf("A multiplicacao do intervalo desses numeros\n");
            int m=multiplicacao(num1,num2);
            printf("%d", m);
        }
        else if (verif1==1 && verif2==0)
        {
            printf("A divisao desses numeros\n");
            float d=divisao(num1,num2);
            printf("%.2f", d);
        }
        else if (verif1==0 && verif2==1)
        {
            printf("A divisao desses numeros\n");
            float d=divisao(num1,num2);
            printf("%.2f", d);
        }
        else if (verif1==-1 || verif2==-1)
        {
            printf("Um dos números digitado é 0\n");
        }

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

float divisao(int num1,int num2)
{
    return (float) num1/num2;
}

int multiplicacao(int num1, int num2)
{
    int result=1,aux;
    if (num1<num2)
        aux=1;
    else if (num1>num2)
        aux=2;
    else
        aux=3;

    if (aux==1)
    {
        while (num1<=num2)
        {
            result=result*num1;
            num1=num1+1;
        }
        return result;
    }

    else if (aux==2)
    {
        num1=num1+num2;
        num2=num1-num2;
        num1=num1-num2;

        while (num1<=num2)
        {
            result=result*num1;
            num1=num1+1;
        }
        return result;
    }

    else
        return num1*num2;
}

int soma(int num1, int num2)
{
    int aux,result=0;

    if (num1<num2)
        aux=1;
    else if (num1>num2)
        aux=2;
    else
        aux=3;

    if (aux==1)
    {
        while (num1<=num2)
        {
            result=result+num1;
            num1=num1+1;
        }
        return result;
    }

    else if (aux==2)
    {
        num1=num1+num2;
        num2=num1-num2;
        num1=num1-num2;

        while (num1<=num2)
        {
            result=result+num1;
            num1=num1+1;
        }
        return result;
    }

    else
    {
        return num1+num2;
    }
}

int verificar(int num)
{
    if(num>0)
    {
        return 1;
    }
    else if(num==0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
#endif // ex1

#ifdef ex2
/*Escreva um programa que receba um numero N via teclado. Escreva uma funcao que retorne a soma dos algarismos do resultado de N!.
O resultado deve ser mostrado na funcao main().*/

int fatorial(int n);

main()
{
    int continuar;
    do
    {
        int n,fat;

        system("cls");

        do
        {
            printf("Digite um numero inteiro\n");
            scanf("%d", &n);
        }
        while(n<0);

        fat=fatorial(n);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1&&continuar!=0);

    }
    while(continuar==1);
}

int fatorial(int n)
{
    int fat;
    for(fat=1; n>1; n=n-1)
        fat = fat * n;

    printf("Fatorial:%d\n", fat);
}
#endif // ex2

#ifdef ex3
/*Escreva um programa que receba na função main() 2 valores inteiros.
Escreva uma função para cada operação aritmetica e passe como parametro os 2 valores recebidos na funçao main().
Retorne os resultados usando o comando return e imprima os 4 resultados no vídeo na função main().*/

int multiplicacao(int num1,int num2);
float divisao(int num1,int num2);
int soma(int num1,int num2);
int subtracao(int num1,int num2);

main()
{
    int continuar;

    do
    {
        int rmult,rsoma,rsub,num1,num2;
        float rdiv;

        system("cls");

        printf("Digite um numero:\n");
        scanf("%d", &num1);
        printf("Digite outro numero:\n");
        scanf("%d", &num2);

        rsoma=soma(num1,num2);
        rsub=subtracao(num1,num2);
        rdiv=divisao(num1,num2);
        rmult=multiplicacao(num1,num2);

        printf("soma:%d\nsubtacao:%d\ndivisao:%.2f\nmultiplicacao:%d\n", rsoma,rsub,rdiv,rmult);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d",&continuar);
        }
        while(continuar!=1 && continuar!=0);
    }
    while(continuar==1);
}

int multiplicacao(int num1, int num2)
{
    return num1*num2;
}

float divisao(int num1, int num2)
{
    return (float) num1/num2;
}

int subtracao(int num1, int num2)
{
    return num1-num2;
}

int soma(int num1, int num2)
{
    return num1+num2;
}
#endif // ex3

#ifdef ex4
/*Reescreva o programa do exercício anterior para receber via teclado n valores.
Os n valores não são definidos previamente.*/

int multiplicacao(int num1,int num2);
float divisao(int num1,int num2);
int soma(int num1,int num2);
int subtracao(int num1,int num2);

main()
{
    int continuar;

    do
    {
        int num1,num2,rmult=1,rsub=0,rsoma=0,i,numero;
        float rdiv;

        system("cls");

        printf("Digite o 1 numero:\n");
        scanf("%d",&num1);

        printf("Digite o 2 numero:\n");
        scanf("%d",&num2);

        rsoma = soma(num1,num2);
        rsub = subtracao(num1,num2);
        rmult = multiplicacao(num1,num2);
        rdiv = divisao(num1,num2);

        printf("Digite 0 para parar de calcular\n\n");
        for(int i=3; 1==1; i++)
        {
            printf("Digite o %d valor a ser calculado:\n",i);
            scanf("%d", &num2);

            if(num2==0)
                break;

            rsoma = soma(rsoma,num2);
            rsub = subtracao(rsub,num2);
            rmult = multiplicacao(rmult,num2);
            rdiv = divisao(rdiv,num2);

        }

        printf("O resultado da soma e: %d\n", rsoma);
        printf("O resultado da subtracao e: %d\n", rsub);
        printf("O resultado da multiplicacao e: %d\n", rmult);
        printf("O resultado da divisao e: %.2f\n", rdiv);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d",&continuar);
        }
        while(continuar!=1 && continuar!=0);
    }
    while(continuar==1);
}

int soma(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    return a - b;
}

int multiplicacao(int a, int b)
{
    return a * b;
}

float divisao(int a, int b)
{
    return (float) a / b;
}
#endif // ex4

#ifdef ex5
/*Escreva um programa que receba n valores inteiros via teclado na funcao main().
Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser mostrado na funcao main().*/

int multiplicacao(int num1,int num2);
float divisao(int num1,int num2);
int soma(int num1,int num2);
int subtracao(int num1,int num2);

int main()
{
    int continuar;

    do
    {
        int n,i,num1,num2,op1,op,result;

        system("cls");

        printf("Digite o 1 numero:\n");
        scanf("%d",&num1);

        printf("Digite o 2 numero:\n");
        scanf("%d",&num2);

        printf("Digite a opcao:\n1-Soma\n2-Subtracao\n3-Multiplicacao\n4-Divisao\n");
        scanf("%d",&op1);

        if (op1==1)
            result=soma(num1,num2);
        if(op1==2)
            result=subtracao(num1,num2);
        if(op1==3)
            result=multiplicacao(num1,num2);
        if(op1==4)
            result=divisao(num1,num2);

        printf("Digite 0 para parar de calcular\n\n");
        for (i=3; 1==1; i++)
        {
            printf("Digite o %d numero:\n",i);
            scanf("%d", &num2);

            if(num2==0)
                break;

            printf("Digite a opcao:\n1-Soma\n2-Subtracao\n3-Multiplicacao\n4-Divisao\n");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                result=soma(result,num2);
                break;

            case 2:
                result=subtracao(result,num2);
                break;

            case 3:
                result=multiplicacao(result,num2);
                break;

            case 4:
                result=divisao(result,num2);
                break;
            }
        }

        printf("Resultado:%d\n", result);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d",&continuar);
        }
        while(continuar!=1 && continuar!=0);

    }
    while(continuar==1);
}

int soma(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    return a - b;
}

int multiplicacao(int a, int b)
{
    return a * b;
}

float divisao(int a, int b)
{
    return  (float) a / b;
}
#endif // ex5
