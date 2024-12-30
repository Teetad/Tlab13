#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[] ,int N ,double B[]){
    
    double AM;
    double storage;
    double box;
    
    for (int i = 0; i < N; i++){
        storage += A[i];
    }
    AM = storage / N;
    B[0] = AM;
    
    double SD;
    storage = 0;
    for (int i = 0; i < N; i++){
        storage += pow(A[i] - AM, 2);
    }
    SD = sqrt(storage/(N));
    B[1] = SD;
    
    double GM;
    storage = 1;
    for (int i = 0; i < N; i++){
        storage = storage * A[i];
    }
    GM = pow(storage,(float)1/N);
    B[2] = GM;
    
    double HM;
    storage = 0;
    for (int i = 0; i < N; i++){
        storage += (double)1/A[i];
    }
    HM = (double)N / storage;
    cout << HM;
    B[3] = HM;
    
    double MAX = A[0];
    double min = A[0];
    for (int i = 0; i < N; i++){
        if (A[i] > MAX) MAX = A[i];
        if (A[i] < min) min = A[i];
    }
    B[4] = MAX; B[5] = min;
}