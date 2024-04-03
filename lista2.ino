#include <stdio.h>

#define ex4

#ifdef ex1
/*As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os instantes em que a ligacao foi iniciada e concluida.
Escreva um programa que recebe via teclado dois instantes dados em horas, minutos e segundo e determina o intervalo de tempo (em horas, minutos e segundos) decorrido entre eles.*/
main()
{
    int continuar;
    do
    {
        int h1,m1,s1,h2,m2,s2,his,hcs,rs,resto,h,m,s;

        do
        {
            printf("Digite a hora em que a ligacao foi iniciada:");
            scanf("%d",&h1);
        }
        while(h1<0 || h1>24);

        do
        {
            printf("Digite o minuto em que a ligacao foi iniciada:");
            scanf("%d",&m1);
        }
        while(m1<0 || m1>59);

        do
        {
            printf("Digite o segundo em que a ligacao foi iniciada:");
            scanf("%d",&s1);
        }
        while(s1<0 || s1>59);

        do
        {
            printf("Digite a hora em que a ligacao foi concluida:");
            scanf("%d",&h2);
        }
        while(h2<0 || h2>24);

        do
        {
            printf("Digite o minuto em que a ligacao foi concluida:");
            scanf("%d",&m2);
        }
        while(m2<0 || m2>59);

        do
        {
            printf("Digite o segundo em que a ligacao foi concluida:");
            scanf("%d",&s2);
        }
        while(s2<0 || s2>59);

        his=(h1*3600)+(m1*60)+s1;
        hcs=(h2*3600)+(m2*60)+s2;
        rs=hcs-his;
        h=rs/3600;
        resto=rs%3600;
        m=resto/60;
        s=resto%60;

        printf("\t%d h, %d min e %d seg",h,m,s);

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

#endif // ex1

#ifdef ex2
/*Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario pensou.
Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o comando if-else.*/

main()
{
    int continuar;

    do
    {
        int min=1,max=99,num=0;
        char esc=0;

        system("cls");

        printf("Pense em um numero de 1 a 99\nUse <, > ou = para responder as perguntas\n");

        do
        {
            printf("\nO numero e' maior, menor ou igual a %d?\n", num=(max+min)/2);
            scanf("%c",&esc);

            if(esc=='>')
            {
                min=num;
                num=(max+min)/2;
                getchar();
            }
            else if(esc=='<')
            {
                max=num;
                num=(max+min)/2;
                getchar();
            }
            printf("O numero e': %d",num);
            num=0;
        }
        while(esc!='=');

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
/*Reescreva o programa do exercicio anterior agora utilizando o comando switch.
Conte o n. de tentativas e imprima o resultado no video.*/

main()
{
    int continuar;

    do
    {
        int min=1,max=99,num;
        char esc;

        system("cls");

        do
        {
            printf("Pense em um numero de 1 a 99\nUse <, > ou = para responder as perguntas\n");
            printf("\nO numero e' maior, menor ou igual a %d?\n", num=(max+min)/2);
            scanf("%c",&esc);

            switch (esc)
            {
            case '>':
            {
                min=num;
                num=max+min/2;
                getchar();
                break;
            }
            case '<':
            {
                max=num;
                num=(max+min)/2;
                getchar();
                break;
            }
            case '=':
            {
                printf("O numero e': %d",num);
                getchar();
                break;
            }
            }
        }
        while(esc!='=');

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
#endif // ex3

#ifdef ex4
/*Escreva um programa que receba via teclado numeros inteiros positivos.
Quando o numero digitado for negativo o programa deve parar e calcular a media dos valores positivos digitados.*/

main()
{
    int continuar;

    do
    {
        int num;
        float media=0,soma,c;

        do
        {
            printf("Digite um numero:");
            scanf("%d",&num);

            if(num>0)
            {
                soma=soma+num;
                c++;
            }
        }
        while(num>0);

        media=soma/c;
        printf("A media dos numeros positivos e': %.2f", media);
        media=0;

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
#endif // ex4

#ifdef ex5
/*Receba via teclado a distancia em km e a quantidade de litros de gasolina consumidos por um carro em um percurso.
Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!*/

main()
{
    int continuar;
    float dist,lit,result;

    do
    {
        printf("Qual a distancia percorrida?\n");
        scanf("%f",&dist);

        printf("Quantos litros foram consumidos?\n");
        scanf("%f",&lit);

        result=dist/lit;

        if(result<8)
        {
            printf("\nVenda o carro!");
        }
        else if(result>8 &&result<14)
        {
            printf("\nEconomico!");
        }
        else
        {
            printf("\nSuper economico!");
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
#endif // ex5
