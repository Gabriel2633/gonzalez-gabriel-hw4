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
double funcion_yprime(double t, double y,double y_prime);
double funcion_yprime2(double t, double y, double y_prime, double V);
double funcion_V(double vx, double vy);

int main() 
{
    // condiciones iniciales

    double h=0.005;
    double t=0;
    double X=0;
    double x=0;
    double y=0;
    int ang = 45; //angulo
    double V0=300;
    int i=0;

    double x_prime = V0*cos(PI*ang/180);
    double y_prime = V0*sin(PI*ang/180);

    while(y>=0)
    {


        // kutta x
        double k1x=funcion_xprime(t,x,x_prime);
        double k1xprime=funcion_xprime2(t,x,x_prime,y_prime);
        double k1y=funcion_yprime(t,y,y_prime);
        double k1yprime=funcion_yprime2(t,y,x_prime,y_prime);

        double k2x=funcion_xprime(t+0.5*h, x+0.5*k1x*h, x_prime+0.5*k1xprime*h);
        double k2xprime=funcion_xprime2(t+0.5*h, x+0.5*k1x*h, x_prime+0.5*k1xprime*h, y_prime+0.5*k1yprime*h);
        double k2y=funcion_yprime(t+0.5*h, y+0.5*k1y*h, y_prime+0.5*k1yprime*h);
        double k2yprime=funcion_yprime2(t+0.5*h, y+0.5*k1y*h, x_prime+0.5*k1xprime*h, y_prime+0.5*k1yprime*h);

        double k3x=funcion_xprime(t+0.5*h, x+0.5*k2x*h, x_prime+0.5*k2xprime*h);
        double k3xprime=funcion_xprime2(t+0.5*h, x+0.5*k2x*h, x_prime+0.5*k2xprime*h, y_prime+0.5*k2yprime*h);
        double k3y=funcion_yprime(t+0.5*h, y+0.5*k2y*h, y_prime+0.5*k2yprime*h);
        double k3yprime=funcion_yprime2(t+0.5*h, y+0.5*k2y*h, x_prime+0.5*k2xprime*h, y_prime+0.5*k2yprime*h);
        
        double k4x=funcion_xprime(t+h, x+k3x*h,x_prime+k3xprime*h);
        double k4xprime=funcion_xprime2(t+h, x+k3x*h, x_prime+k3xprime*h, y_prime+k3yprime*h);
        double k4y=funcion_yprime(t+h, y+k3y*h, y_prime+k3yprime*h);
        double k4yprime=funcion_yprime2(t+h, y+k3y*h, x_prime+k3xprime*h, y_prime+k3yprime*h);
        
        // promedios

        double promedio_kx=(1.0/6.0)*(k1x + 2.0*k2x + 2.0*k3x + k4x);
        double promedio_kxprime=(1.0/6.0)*(k1xprime + 2.0*k2xprime + 2.0*k3xprime + k4xprime);

        double promedio_ky=(1.0/6.0)*(k1y + 2.0*k2y + 2.0*k3y + k4y);
        double promedio_kyprime=(1.0/6.0)*(k1yprime + 2.0*k2yprime + 2.0*k3yprime + k4yprime);

        x = x + h*promedio_kx;
        y = y + h*promedio_ky;
        x_prime = x_prime + h*promedio_kxprime;
        y_prime = y_prime + h*promedio_kyprime;
        double V = funcion_V(x_prime,y_prime);
        t=t+h;

        cout<< "Tiempo: "<< t <<endl;
        cout<< "Distancia: "<< x <<endl;
        cout<< "y : "<< y <<endl;
        cout<< "Velocidad: "<< V <<endl;
    }

}

// double funcionprime(t,X,X_prime);

double funcion_xprime(double t, double x,double x_prime)
{
    return x_prime;
}

double funcion_xprime2(double t, double x, double x_prime, double y_prime)
{
    return -c*funcion_V(x_prime,y_prime)*x_prime/m;
}

double funcion_yprime(double t, double y,double y_prime)
{
    return y_prime;
}

double funcion_yprime2(double t, double y, double x_prime, double y_prime)
{
    return -g-c*funcion_V(x_prime,y_prime)*y_prime/m;
}

double funcion_V(double vx, double vy)
{
    return pow(vx*vx+vy*vy,0.5);
}


// double runge_kutta(){

// }

    
    //runge kutta
//     int i=0;
    
//     for(i=0;i<n_pts;i++) {
//         double k1=h*funcionprime(x[i-1],y[i-1]);
    
//         double k2x=h*funcionprime(x[i-1]+0.5*h,y[i-1]+0.5*k1);
    
//         double k3x=h*funcionprime(x[i-1]+0.5*h,y[i-1]+0.5*k2x);
    
//         double k4x=h*funcionprime(x[i-1]+h,y[i-1]+k3x);
    
//         double promedio_k = (k1 + 2.0*k2x + 2.0*k3x + k4x)/6.0;
    
//         t[i]=x[i-1]+h;

//         x_1[i] = 


//         y[i]=y[i-1]+promedio_k;

//     }    
// }






// // separacion de la derivada y la solucion



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
