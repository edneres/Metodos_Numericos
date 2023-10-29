/*
    Acadêmica de Engenharia Elétrica Maria Edivãnia Neres de Sousa
    Universidade Federal do Piauí
    Teresina, Piauí. 29/10/2023
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void  head(void);

double  tolerance();
void    initial_limits(double *lim_inferior, double *lim_superior);
int     limits_check(double lim_inferior, double lim_superior);
void    inputs_check(double i1, double i2, double i3);
double  abisection_method(double Ax, double Bx, double tolerancia);

int     main()
{
    system("cls");
    double tolerancia, lim_inferior, lim_superior;
    double raiz;

    head();
    printf("Funcao = x + log(x)\n");    // Sujeito à alteração
    //printf("Funcao = x^3 - 3x^2 5x - 4\n");
    tolerancia = tolerance();
    initial_limits(&lim_inferior, &lim_superior);
    printf("------------------------------------------------------\n");

    while (limits_check(lim_inferior, lim_superior) == 0)
    {
        printf("A raiz nao esta dentro dos limites informados\n");
        initial_limits(&lim_inferior, &lim_superior);
        printf("------------------------------------------------------\n");
    }
    

    inputs_check(tolerancia, lim_inferior, lim_superior);
    printf("------------------------------------------------------\n");

    raiz = abisection_method(lim_inferior, lim_superior, tolerancia);
    printf("A raiz aproximada da funcao eh %lf\n", raiz);
    printf("------------------------------------------------------\n\n\n");

    system("pause");
}

void    head(void)     // Ok
{   
    printf("\t  ----------------\n");
    printf("\t  Bisection Method\n");
    printf("\t  ----------------\n\n");
}

double  tolerance()   // Ok
{
    double tolerance = -1;

    while (tolerance < 0)
    {
        printf("Tolerancia [real e positivo] : ");
        scanf("%lf", &tolerance);
    }

    return tolerance;
}

void    initial_limits(double *lim_inferior, double *lim_superior)  // Ok
{
    printf("Limite inferior [real] : ");
    scanf("%lf", lim_inferior);

    printf("Limite superior [real] : ");
    scanf("%lf", lim_superior);
}

int     limits_check(double lim_inferior, double lim_superior)
{
    // TEOREMA DE BOLZANO //
    /*if((pow(lim_inferior, 3) - 3*pow(lim_inferior, 2) + 5*lim_inferior - 4)*(pow(lim_superior, 3) - 3*pow(lim_superior, 2) + 5*lim_superior - 4) < 0)
        return 1; */

    if((lim_inferior + log10(lim_inferior)) * (lim_superior + log10(lim_superior)) < 0) // Sujeito à alteração de acordo com a linha 26
        return 1;

    else
        return 0;
}

void    inputs_check(double i1, double i2, double i3)    // Ok
{
    printf("Tolerancia      = %lf\n", i1);
    printf("Limite Inferior = %lf\n", i2);
    printf("Limite Superior = %lf\n", i3);
}

double  abisection_method(double Ax, double Bx, double tolerancia)  // Ok
{
    double media, k;

    // QUANTIDADE DE ITERAÇÕES NECESSÁRIAS//
    k = (log10(Bx - Ax) - log10(tolerancia)) / log10(2);
    k = ceil(k);

    // ANÁLISE DE ONDE A RAÍZ ESTÁ // 
    for (size_t i = 0; i < k; i++)
    {
        media = (Ax + Bx)/2;  // lim_inferior - media - lim_superior

        if((Ax + log10(Ax)) * (media + log10(media)) < 0)   // [Ax, media]  // // Sujeito à alteração de acordo com a linha 26
        //if((pow(Ax, 3) - 3*pow(Ax, 2) + 5*Ax - 4)*(pow(Ax, 3) - 3*pow(media, 2) + 5*media - 4) < 0)
        {
            //Ax = Ax;
            Bx = media;
        }

        else    // [media, Bx]
        {
            Ax = media;
            //Bx = Bx;
        }
    }
    
    return media;
}
