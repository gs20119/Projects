
#include <bits/stdc++.h>
#define ORDER 4
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

/*
double f(double x, double y){ return 2*y*(cos(2*x)+0.5); } // eq1 (0,1,15)
double Ans(double x){ return exp(sin(2*x)+x); } */
double f(double x, double y){ return -30*y+30*x; } // eq2 (0,100,4)
double Ans(double x){ return 100.0*exp(-30.0*x)+x-1.0/30; }

void RK4(double x, double y)
{
    if(x > X) return; 
    double delta = 0;
    for(int i=0; i<ORDER; i++){
        double coef = 0;
        for(int j=0; j<i; j++) coef += A[i][j]*k[j];
        k[i] = f(x+h*b[i], y+h*coef);
        delta += c[i]*k[i];
        step += i+3;
    }
    double xn = x+h, yn = y+h*delta; step += 1;
    printf("%.8lf, %.8lf\n", xn, yn-Ans(xn));
    return RK4(xn,yn);
}


int main()
{
    double x0, y0;
    scanf("%lf %lf %lf", &x0, &y0, &X);
    RK4(x0,y0); printf("%d\n", step); 
}


