
#include <bits/stdc++.h>
#define SIZE 7
using namespace std;
int step=0;
double X, h=0.00001, hmin=0.00001, hmax=0.04096; 
double emax=0.00001, emin=0.0000001;
double b[SIZE]={ 0.0, 1.0/5, 3.0/10, 4.0/5, 8.0/9, 1.0, 1.0 };
double c1[SIZE]={ 35.0/384, 0.0, 500.0/1113, 125.0/192, -2187.0/6784, 11.0/84, 0.0 };
double c2[SIZE]={ 5179.0/57600, 0.0, 7571.0/16695, 393.0/640, -92097.0/339200, 187.0/2100, 1.0/40 };
double k[SIZE]={};
double A[SIZE][SIZE]={{},
    { 1.0/5 },
    { 3.0/40, 9.0/40 },
    { 44.0/45, -56.0/15, 32.0/9 },
    { 19372.0/6561, -25360.0/2187, 64448.0/6561, -212.0/729 },
    { 9017.0/3168, -355.0/33, 46732.0/5247, 49.0/176, -5103.0/18656 },
    { 35.0/384, 0.0, 500.0/1113, 125.0/192, -2187.0/6784, 11.0/84 }
}; // Butcher Table Expression

/*
double f(double x, double y){ return 2*y*(cos(2*x)+0.5); }
double Ans(double x){ return exp(sin(2*x)+x); } */
double f(double x, double y){ return -30*y+30*x; } // eq2 (0,100,4)
double Ans(double x){ return 100.0*exp(-30.0*x)+x-1.0/30; }

void DormandPrince(double x, double y)
{
    if(x > X) return; 
    h=max(hmin,h); h=min(hmax,h);
    double delta1 = 0, delta2 = 0;
    for(int i=0; i<SIZE; i++){
        double coef = 0;
        for(int j=0; j<i; j++) coef += A[i][j]*k[j];
        k[i] = f(x+h*b[i], y+h*coef);
        delta1 += c1[i]*k[i]; 
        delta2 += c2[i]*k[i];
        step += i+4;
    }
    double xn = x+h, yn1 = y+h*delta1, yn2 = y+h*delta2; 
    double e = abs(yn1-yn2); step += 2;
    printf("%.8lf, %.8lf\n", xn, yn1-Ans(xn));
    if(e>emax){ h *= 0.5; step++; }
    if(e<emin){ h *= 2.0; step++; }
    return DormandPrince(xn,yn1);
}


int main()
{
    double x0, y0;
    scanf("%lf %lf %lf", &x0, &y0, &X);
    DormandPrince(x0,y0); printf("%d\n", step);
}




