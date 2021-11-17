
#include <bits/stdc++.h>
#define ORDER 5
using namespace std;
int step=0;
double X, h=0.01;
double b[4]={ 0.0, 1.0/2, 1.0/2, 1.0 };
double c[4]={ 1.0/6, 1.0/3, 1.0/3, 1.0/6 };
double k[4]={};
double A[4][4]={{},
    { 1.0/2 },
    { 0, 1.0/2 },
    { 0, 0, 1.0 },
}; // Butcher Table Expression

double yMem[ORDER]={}, xMem[ORDER]={};
double d[ORDER]={ 251.0/720, -1274.0/720, 2616.0/720, -2774.0/720, 1901.0/720 };
//or ORDER 4 : { -9.0/24, 37.0/24, -59.0/24, 55.0/24 };

/*
double f(double x, double y){ return 2*y*(cos(2*x)+0.5); } // eq1 (0,1,15)
double Ans(double x){ return exp(sin(2*x)+x); } */
double f(double x, double y){ return -30*y+30*x; } // eq2 (0,100,4)
double Ans(double x){ return 100.0*exp(-30.0*x)+x-1.0/30; }

void initRK4(double x, double y) // for initial values
{
    step++; if(step>=ORDER) return; 
    double delta = 0;
    for(int i=0; i<4; i++){
        double coef = 0;
        for(int j=0; j<i; j++) coef += A[i][j]*k[j];
        k[i] = f(x+h*b[i], y+h*coef);
        delta += c[i]*k[i];
    }double xn=x+h, yn=y+h*delta;
    printf("%.8lf, %.8lf\n", xn, yn-Ans(xn));
    xMem[step]=xn; yMem[step]=yn; 
    return initRK4(xn,yn);
}


void AdamsBf()
{
    if(xMem[ORDER-1] > X) return; 
    double delta = 0;
    for(int i=0; i<ORDER; i++) delta += d[i]*f(xMem[i],yMem[i]);
    for(int i=0; i<ORDER; i++) xMem[i] += h;
    for(int i=0; i<ORDER-1; i++) yMem[i]=yMem[i+1];
    yMem[ORDER-1] += h*delta; step += ORDER+1;
    printf("%.8lf, %.8lf\n", xMem[ORDER-1], yMem[ORDER-1]-Ans(xMem[ORDER-1]));
    return AdamsBf(); 
}


int main()
{
    scanf("%lf %lf %lf", &xMem[0], &yMem[0], &X);
    initRK4(xMem[0],yMem[0]); 
    step=0; AdamsBf(); printf("%d\n", step);
}






