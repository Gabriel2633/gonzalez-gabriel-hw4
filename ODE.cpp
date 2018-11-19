//
//  ODE.cpp
//  ODE
//
//

#include <iostream>
#include <string>

using namespace std;

//constantes
int g=10;   // gravedad
double c=0.2; // esta es la friccion
double m=0.2; // masa

double funcion_prime(double t, double X,double X_prime);
double funcion_prime2(double t, double X, double X_prime);

int main() {
     cout<< "testing "<< g <<endl;


    // condiciones iniciales

    double h=0.01;
    double t=0;
    double X=0;
    int ang = 45; //angulo
    double V = 300;

    double k1=funcion_prime(t,X, V);
    double k1prime=funcion_prime2(t,X, V);
    
    double k2=funcion_prime(t+0.5*h,X+0.5*k1*h,V+0.5*k1prime*h);
    double k2prime=funcion_prime2(t+0.5*h,X+0.5*k1*h, V+0.5*k1prime*h);

    double k3=funcion_prime(t+0.5*h,X+0.5*k2*h,V+0.5*k2prime*h);
    double k3prime=funcion_prime2(t+0.5*h,X+0.5*k2*h, V+0.5*k2prime*h);

    double k4=funcion_prime(t+h,X+k3*h,V+k3prime*h);
    double k4prime=funcion_prime2(t+h,X+k3*h, V+k3prime*h);

    double promedio_k=(1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
    double promedio_kprime=(1.0/6.0)*(k1prime + 2.0*k2prime + 2.0*k3prime + k4prime);

    X = X + h*promedio_k;
    V = V + h*promedio_kprime;
    t=t+h;

    cout<< "Tiempo recorrido: "<< t <<endl;
    cout<< "Distancia recorrida: "<< X <<endl;
    cout<< "Velocidad: "<< V <<endl;


}

// double funcionprime(t,X,X_prime);

double funcion_prime(double t, double X,double X_prime){
    return X_prime;
}

double funcion_prime2(double t, double X, double X_prime){
    return -g-c*X_prime*X_prime/m;
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

// double v(double vx, double vy)
// {
//     return vx*vx+vy*vy;
// }

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
