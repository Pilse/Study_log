#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a>b? a:b)
#define MAX_TERMS 101

typedef struct
{
    float coef;
    int expon;
}polynomial;
polynomial terms [MAX_TERMS]={{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};
int avail =6;

char compare(int a,int b)
{
    if(a>b) return '>';
    else if(a==b) return '=';
    else return '<';
}
polynomial polynomial_add(polynomial poly1,polynomial poly2)
{
    polynomial poly3;
    return poly3;
}

void attach(float coef,int expon)
{
    if(avail>MAX_TERMS)
    {
        fprintf(stderr,"항의 갯수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef =coef;
    terms[avail].expon =expon;
    avail ++;
}
void poly_add2(int As, int Ae, int Bs ,int Be, int *Cs, int *Ce)
{
    float tempcoef;
    *Cs =avail;
    while(As<=Ae&&Bs<=Be)
        switch (compare(terms[As].expon , terms[Bs].expon))
        {
            case '>' :
            attach(terms[As].coef,terms[As].expon);
            As ++;
            break;
            case '=' :
            tempcoef=terms[As].coef+terms[Bs].coef;
            attach(tempcoef,terms[As].expon);
            As++; Bs++;
            break;
            case'<' :
            attach(terms[Bs].coef,terms[Be].expon);
            Bs++;
            break;
        } 

    *Ce=avail -1;
}

void print_poly (int s, int e)
{
    for(int i=s;i<e;i++)
    {
        printf("%.1fx^%d +",terms[i].coef,terms[i].expon);
        printf("%.lfx^%d\n",terms[e].coef,terms[e].expon);
    }
}
int main()
{
   int As=0, Ae=2, Bs=3, Be=5, Cs,Ce;
   poly_add2(As,Ae,Bs,Be,&Cs,&Ce);
   print_poly(As,Ae);
   print_poly(Bs,Be);
   print_poly(Cs,Ce);
}