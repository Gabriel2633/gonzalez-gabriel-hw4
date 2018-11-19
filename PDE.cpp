//
//  PDE.cpp
//  PDE
//
//

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <cstdlib>

using namespace std;

#define N 50 //tamaño de matrix
//constantes
double k=1.62;   // conductividad termica
double cp=820; // calor especifico
double rho=2710; // densidad
double PI=3.14159265359; // PI

double d = 10.0; //diametro de varilla
double l = 50.0; //longitud

double v = k/(cp*rho);//coef. de difusión
double delta_x = 1; //variacion espacial (x,y)

double tau = 0.001; //variacion temporal (t)
double alpha =(tau*v)/(delta_x*delta_x);

double Tvarilla = 373.15; //temperatura de varilla
double Tfija = 283.15; //temperature de frontera fija


double anterior[N][N];
double actual[N][N];


int main() 
{

    
    int i, j, k;
    //condiciones de frontera
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
            if(eqn_dif<pow(d/2,2)){
                anterior[i][j] = Tvarilla;
            }
            else {
                anterior[i][j] = Tfija;
            }
        }
    }
    
    ofstream data_file;
    string file_name="fijo.txt";
    data_file.open(file_name);

    //equilibrio
    double dif = 1;
    double dif_equilibrio = 0.0001;
    while(abs(dif)>dif_equilibrio){
        // ecuacion diferencial parcial
        for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                if (i==0 || i==N-1 || j==0 || j==N-1 ){
                    actual[i][j] = Tfija;
                } else {
                    double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
                    if (eqn_dif < pow(d/2,2)){
                        actual[i][j] = Tvarilla;
                    }
                    else {
                        actual[i][j] = alpha*(anterior[i+1][j]+anterior[i][j+1])+(1-4*alpha)*anterior[i][j]+alpha*(anterior[i-1][j]+anterior[i][j-1]);
                    }
                }
                data_file << anterior[i][j] << ",";
            }
            data_file << endl;
        }

        //asignar valores de actual anterior para proxima iteracion 
        memcpy(anterior,actual,sizeof(actual));
    }
    


}