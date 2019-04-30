#include <iostream>
#include <fstream>
using namespace std;

void resolver(int L, double delta);

int main(){
    
    int L = 1;
    double delta = 1/100;
    resolver(L,delta);
}

void resolver(int L, double delta) {
    
    ofstream outfile;
    outfile.open("datos.dat");
    
    double malla[101][101];
    
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            
            malla[i][j] = 0;
        }
    }
    
    for(int j = 20; j<81; j++) {
        
        malla[40][j] = 100;
        malla[60][j] = -100;
    }
    
    double diferencia = 100;
    
    while(diferencia > 0.1) {
        double difNeta = 0;
        for(int i = 1; i < 100; i++) {
            for(int j = 1; j < 100; j++) {
                if (j != 40 || j!= 60 || i<20 || i>80) {
                    double nuevo = 0.25*(malla[i-1][j] + malla[i+1][j]  + malla[i][j-1] + malla[i][j+1] );
                    difNeta += abs(malla[i][j]-nuevo);
                    malla[i][j] = nuevo;
                }
            }
        }
        diferencia = difNeta/(100*100);
    }
    
    for(int i = 0; i < 101; i++) {
        for(int j = 1; j < 100; j++) {
            
            double x = i/100.0;
            double y = j/100.0;
            
            outfile << x  << " " << y << " " << malla[i][j] << endl;
        }
    }
    
    outfile.close();
    
}