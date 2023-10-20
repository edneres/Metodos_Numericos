/*
    Acadêmica de Engenharia Elétrica Maria Edivãnia Neres de Sousa
    Universidade Federal do Piauí
    Teresina, Piauí. 20/10/2023
*/

#include <stdio.h>
#include <stdlib.h>

float algoritmo_de_eudoxo(double num)
{
    double aux_anterior, aux_atual;

    for(int i = 0; i < 7; i++)
    {
        if(i == 0)
        {
            aux_atual = (1 + num) / 2;
            aux_anterior = aux_atual;
        }

        else
        {
            aux_atual = (aux_anterior + (num / aux_anterior)) / 2;
            aux_anterior = aux_atual;
        }
    }

    /*
    double x = 0.5 * (1 + num)

    for (int i = 1; i <= 7; ++i)
        x = 0.5 * (x + num / x); 
    */

    return aux_atual;
}

int main()
{
    system("cls");
    double num = -1;

    while (num < 1)
    {
        printf("Digite um numero real positivo: ");
        scanf("%lf", &num);
    }
    
    printf("\nRaiz quadrada de %.3lf: %lf\n\n", num, algoritmo_de_eudoxo(num));

    system("pause");
}