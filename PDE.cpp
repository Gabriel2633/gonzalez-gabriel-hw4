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

void funcion_10fijo();
void funcion_abierta();
void funcion_periodica();
double promedio(double matrix[N][N]);


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

double Tvarilla = 100; //temperatura de varilla
double Tfija = 10; //temperature de frontera fija


double anterior[N][N];
double actual[N][N];

int n_steps = 2000;


int main() 
{
	funcion_10fijo();
	funcion_abierta();
	// funcion_periodica();
	return 0;
}

void funcion_10fijo(){

     int i, j, k;
    //condiciones de frontera
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
            //  cout << "eqn_dif: "<<eqn_dif << endl;
            //  cout << "pow(N/2,2): "<<pow(N/2,2) << endl;
            if(eqn_dif<=pow(N/2,2)){
                anterior[i][j] = Tvarilla;
            }
            else {
                anterior[i][j] = Tfija;
            }
        }
    }

    //equilibrio
    double dif = 1;
    double dif_equilibrio = 0.01;
    // while(abs(dif)>dif_equilibrio){
    ofstream data_file;
    for (k=0;k<=n_steps;k++){
        
        if (k==0 || k==1000 || k==2000){
            string file_name="fijo_"+to_string(k)+".txt";
            data_file.open(file_name);
        }
        // ecuacion diferencial parcial
        for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                if (i==0 || i==N-1 || j==0 || j==N-1 ){
                    actual[i][j] = Tfija;
                } else {
                    double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
                    // cout << "eqn_dif: "<<eqn_dif << endl;

                    if (eqn_dif <= pow(d/2,2)){
                        actual[i][j] = Tvarilla;
                    }
                    else {
                        //  cout << "eqn_dif: "<<eqn_dif << endl;
                        actual[i][j] = alpha*(anterior[i+1][j]+anterior[i][j+1])+(1-4*alpha)*anterior[i][j]+alpha*(anterior[i-1][j]+anterior[i][j-1]);
                    }
                }
                if (k==0 || k==1000 || k==2000){
                    data_file << anterior[i][j] << " ";
                }
            }
            if (k==0 || k==1000 || k==2000){
                data_file << endl;
            }
        }
        dif = promedio(actual) - promedio(anterior);
        // cout << "Diferencia: "<<dif << endl;
        //asignar valores de actual anterior para proxima iteracion 
        // memcpy(anterior,actual,sizeof(actual));
         for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                anterior[i][j] = actual[i][j];
            }
         }
         if (k==0 || k==1000 || k==2000){
                 data_file.close();
            }
    }
    

}

void funcion_abierta(){

     int i, j, k;
    //condiciones de frontera
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
            //  cout << "eqn_dif: "<<eqn_dif << endl;
            //  cout << "pow(N/2,2): "<<pow(N/2,2) << endl;
            if(eqn_dif<=pow(N/2,2)){
                anterior[i][j] = Tvarilla;
            }
            else {
                anterior[i][j] = Tfija;
            }
        }
    }

    //equilibrio
    double dif = 1;
    double dif_equilibrio = 0.01;
    // while(abs(dif)>dif_equilibrio){
    ofstream data_file;
    for (k=0;k<=n_steps;k++){
        
        if (k==0 || k==1000 || k==2000){
            string file_name="abierta_"+to_string(k)+".txt";
            data_file.open(file_name);
        }
        // ecuacion diferencial parcial
        for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                if (i==0 || i==N-1 || j==0 || j==N-1 ){
                    for (int i = 0; i < N; ++i)
					{
						actual[0][i]=actual[1][i];
						actual[N-1][i]=actual[N-2][i];
						actual[i][0]=actual[i][1];
						actual[i][N-1]=actual[i][N-2];
					}
                } else {
                    double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
                    // cout << "eqn_dif: "<<eqn_dif << endl;

                    if (eqn_dif <= pow(d/2,2)){
                        
                    }
                    else {
                        //  cout << "eqn_dif: "<<eqn_dif << endl;
                        actual[i][j] = alpha*(anterior[i+1][j]+anterior[i][j+1])+(1-4*alpha)*anterior[i][j]+alpha*(anterior[i-1][j]+anterior[i][j-1]);
                    }
                }
                if (k==0 || k==1000 || k==2000){
                    data_file << anterior[i][j] << " ";
                }
            }
             if (k==0 || k==1000 || k==2000){
                data_file << endl;
            }
        }
        dif = promedio(actual) - promedio(anterior);
        // cout << "Diferencia: "<<dif << endl;
        //asignar valores de actual anterior para proxima iteracion 
        // memcpy(anterior,actual,sizeof(actual));
         for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                anterior[i][j] = actual[i][j];
            }
         }
          if (k==0 || k==1000 || k==2000){
                 data_file.close();
            }
    }

} 

void funcion_periodica(){

     int i, j, k;
    //condiciones de frontera
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
            //  cout << "eqn_dif: "<<eqn_dif << endl;
            //  cout << "pow(N/2,2): "<<pow(N/2,2) << endl;
            if(eqn_dif<=pow(N/2,2)){
                anterior[i][j] = Tvarilla;
            }
            else {
                anterior[i][j] = Tfija;
            }
        }
    }

    //equilibrio
    double dif = 1;
    double dif_equilibrio = 0.01;
    // while(abs(dif)>dif_equilibrio){
    ofstream data_file;
    for (k=0;k<=n_steps;k++){
        
        if (k==0 || k==1000 || k==2000){
            string file_name="abierta_"+to_string(k)+".txt";
            data_file.open(file_name);
        }
        // ecuacion diferencial parcial
        for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                if (i==0 || i==N-1 || j==0 || j==N-1 ){
                    for (int i = 0; i < N; ++i)
					{
						actual[0][i]=actual[1][i];
						actual[N-1][i]=actual[N-2][i];
						actual[i][0]=actual[i][1];
						actual[i][N-1]=actual[i][N-2];
					}
                } else {
                    double eqn_dif = pow(i*delta_x-0.5*l,2) + pow(j*delta_x-0.5*l,2);
                    // cout << "eqn_dif: "<<eqn_dif << endl;

                    if (eqn_dif <= pow(d/2,2)){
                        
                    }
                    else {
                        //  cout << "eqn_dif: "<<eqn_dif << endl;
                        actual[i][j] = alpha*(anterior[i+1][j]+anterior[i][j+1])+(1-4*alpha)*anterior[i][j]+alpha*(anterior[i-1][j]+anterior[i][j-1]);
                    }
                }
                if (k==0 || k==1000 || k==2000){
                    data_file << anterior[i][j] << " ";
                }
            }
             if (k==0 || k==1000 || k==2000){
                data_file << endl;
            }
        }
        dif = promedio(actual) - promedio(anterior);
        // cout << "Diferencia: "<<dif << endl;
        //asignar valores de actual anterior para proxima iteracion 
        // memcpy(anterior,actual,sizeof(actual));
         for(i=0; i<N-1; i++){
            for(j=0; j<N-1; j++){
                anterior[i][j] = actual[i][j];
            }
         }
          if (k==0 || k==1000 || k==2000){
                 data_file.close();
            }
    }

} 



double promedio(double matrix[N][N])
{
    double sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += matrix[i][j];

    return sum / (N * N);
}
