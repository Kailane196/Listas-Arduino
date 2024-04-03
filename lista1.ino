#include <stdio.h>

#define ex5

#ifdef ex1
/*Escreva um programa que receba via teclado um tempo em segundos e converta para horas, minutos e segundos.*/

main ()
{
    int seg,m,h,s,resto;

    printf("\tDigite o valor em segundos:");
    scanf("%d",&seg);

    h = seg / 3600;
    resto = seg % 3600;
    m = resto / 60;
    s = resto % 60;

    printf("\t%d h, %d min e %d seg",h,m,s);
}
#endif // ex1

#ifdef ex2
/*Escreva um programa que receba dados via teclado para variaveis do tipo short, long, int, float, double e um char e imprima-os no video no seguinte formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char*/

main()
{
    short int s;
    long int l;
    int i;
    float d;
    double dz;
    char c;

    printf("Digite um caracter:");
    scanf("%c",&c);

    printf("Digite um numero short:");
    scanf("%d", &s);

    printf("Digite um numero long:");
    scanf("%d", &l);

    printf("Digite um numero int:");
    scanf("%d", &i);

    printf("Digite um numero float:");
    scanf("%f", &d);

    printf("Digite um numero double:");
    scanf("%lf", &dz);

    system("cls");

    printf("        10        20        30        40        50        60");
    printf("\n12345678901234567890123456789012345678901234567890123456789012345");
    printf("\n%10d",s);
    printf("%20d",l);
    printf("%20d",i);
    printf("\n%20.1f",d);
    printf("%22.7lf",dz);
    printf("%18c",c);
}
#endif // ex2

#ifdef ex3
/*Escreva um programa que determine o menor multiplo de um numero inteiro. Este multiplo deve ser maior que o limite minimo recebido.
Recebe os 2 numeros via teclado.
Ex: menor multiplo de 13 maior que 100. Resultado: 104*/

main()
{
    int nl,mult,c,menor=0;

    do{
    printf("O menor multiplo de:");
    scanf("%d",&mult);
    }while(mult<=0);

    do{
    printf("Maior que:");
    scanf("%d",&nl);
    }while(nl<=0);

    for(c=nl+mult+1;c>nl;c--)
    {
        if(c%mult==0)
        {
            if(c<menor)
            {
                menor=c;
            }
            else if(menor==0)
            {
                menor=c;
            }
        }
    }
    printf("Resultado: %d",menor);
}
#endif // ex3

#ifdef ex4
/*Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma variável auxiliar.*/

main()
{
    int a=30,b=5;

    printf("a=%d\n",a);
    printf("b=%d\n",b);

    system("pause");

    a=a+b;
    b=a-b;
    a=a%b;

    printf("As variaveis ficaram:\na=%d\nb=%d",a,b);
}
#endif // ex4

#ifdef ex5
/*Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar outro número formado pelos dígitos invertidos do número lido.
Ex:   NúmeroLido = 123
NúmeroGerado = 321*/

main()
{
    int num,a=0,b=0,c=0;

    do
    {
    printf("Digite um numero inteiro, positivo de 3 digitos: ");
    scanf("%d",&num);
    }while(num<=100);

    for(c=num;num>0;c)
    {
        a=num%10;
        b=b*10+a;
        num=num/10;
    }

    printf("O numero invertido: %d\n",b);
}
#endif // ex5
