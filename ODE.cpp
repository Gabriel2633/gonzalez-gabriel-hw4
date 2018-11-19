//
//  ODE.cpp
//  ODE
//
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//constantes
int g=10;   // gravedad
double c=0.2; // esta es la friccion
double m=0.2; // masa
double PI=3.14159265359; // PI

double funcion_xprime(double t, double x,double x_prime);
double funcion_xprime2(double t, double x, double x_prime, double V);

int main() 
{
     cout<< "testing "<< g <<endl;


    // condiciones iniciales

    double h=0.01;
    double t=0;
    double X=0;
    double x=0;
    double y=0;
    int ang = 45; //angulo
    double V0=300;
    double V = V0;
    int n_steps = 100;
    int i=0;

    for(i=0;i<n_steps;i++) 
    {
        double x_prime = V*cos(PI*ang/180);
        double y_prime = V*sin(PI*ang/180);

        double k1x=funcion_xprime(t,x,x_prime);
        double k1xprime=funcion_xprime2(t,x,x_prime,V);
        
        double k2=funcion_xprime(t+0.5*h,x+0.5*k1x*h,V+0.5*k1xprime*h);
        double k2prime=funcion_xprime2(t+0.5*h,x+0.5*k1x*h, V+0.5*k1xprime*h,V);

        double k3=funcion_xprime(t+0.5*h,x+0.5*k2*h,V+0.5*k2prime*h);
        double k3prime=funcion_xprime2(t+0.5*h,x+0.5*k2*h, V+0.5*k2prime*h,V);

        double k4=funcion_xprime(t+h,x+k3*h,V+k3prime*h);
        double k4prime=funcion_xprime2(t+h,x+k3*h, V+k3prime*h,V);

        double promedio_k=(1.0/6.0)*(k1x + 2.0*k2 + 2.0*k3 + k4);
        double promedio_kprime=(1.0/6.0)*(k1xprime + 2.0*k2prime + 2.0*k3prime + k4prime);

        x = x + h*promedio_k;
        V = V + h*promedio_kprime;
        t=t+h;

        cout<< "Tiempo recorrido: "<< t <<endl;
        cout<< "Distancia recorrida: "<< x <<endl;
        cout<< "Velocidad: "<< V <<endl;
    }

}

// double funcionprime(t,X,X_prime);

double funcion_xprime(double t, double x,double x_prime)
{
    return x_prime;
}

double funcion_xprime2(double t, double x, double x_prime, double V)
{
    return -0-c*V*x_prime/m;
}

// double runge_kutta(){

// }

    
    //runge kutta
//     int i=0;
    
//     for(i=0;i<n_pts;i++) {
//         double k1=h*funcionprime(x[i-1],y[i-1]);
    
//         double k2=h*funcionprime(x[i-1]+0.5*h,y[i-1]+0.5*k1);
    
//         double k3=h*funcionprime(x[i-1]+0.5*h,y[i-1]+0.5*k2);
    
//         double k4=h*funcionprime(x[i-1]+h,y[i-1]+k3);
    
//         double promedio_k = (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
    
//         t[i]=x[i-1]+h;

//         x_1[i] = 


//         y[i]=y[i-1]+promedio_k;

//     }    
// }






// // separacion de la derivada y la solucion

double V(double vx, double vy)
{
    return pow(vx*vx+vy*vy,0.5);
}

// double funcion1x(double t, double x, double dx, double y, double dy, double m, double c)
// {
//     return dx;
// }

// double funcion2x(double t, double x, double dx, double y, double dy, double m,double c)
// {
//     return -c*v(dx,dy)*dx/m;
// }

// double funcion1y(double t, double x, double dx, double y, double dy, double m, double c,double g)
// {
//     return dy;
// }

// double funcion2x(double t, double x, double dx, double y, double dy, double m,double c,double g)
// {
//     return -g-c*v(dx,dy)*dy/m;
// }
