/************************************************************************************************/
/*** Topic: create natural frequency with dw Specified sarika jalan algoritm                  ***/
/***                                                                                          ***/
/*** Version Release 17.12 rev 11256                                                Ali-Seif  ***/
/*** Date: 6/29/2022                                                                          ***/
/*** Code implemented in Microsoft Visual Studio Enterprise 2019 C++ compiler                 ***/
/*** MSI: PX60 6QD/ DDR4                                                                      ***/
/*** Run under a Intel� Core� i7-6700HQ CPU @ 2.60GHz � 64 based processor with 16 GB RAM     ***/
/************************************************************************************************/
#include <iostream>                                                                             //for cout
#include <random>                                                                               //random_device & ...
#include<fstream>                                                                   //infile & ofstream

using namespace std;
ofstream saveas2("save/data2.txt");                                                   //save data

int main() {
    int N = 101;                                                                                 //Number of node
    double dW_Specified = 0.8;
    double* W_layer1 = new double[N];                                                           //Making Array for W layer 1;
    double* W_layer2 = new double[N];                                                           //Making Array for W layer 1;

    for (int i = 1; i <= N;i++) {
        W_layer1[i - 1] = -0.5 +(i - 1.0) / (N - 1.0);
        W_layer2[i - 1] = W_layer1[i - 1];
        cout <<i <<'\t'<<W_layer2[i-1] << endl;

    }

    random_device rd;                                                           //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());                                                          //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> uniform_distribution_teta(0.0, 1.0);      //Uniform real distribution from [0 , 1)
    double dW = 0.0, sorate = 0.0, makhraj = 0.0;
    while (dW < dW_Specified) {
        sorate = 0.0, makhraj = 0.0;

        int i = floor(uniform_distribution_teta(gen) * N);
        int j = floor(uniform_distribution_teta(gen) * N);
        double Floating_storage = W_layer2[i];
        W_layer2[i] = W_layer2[j];
        W_layer2[j] = Floating_storage;

        for (int k = 0; k < N; k++) {
            sorate += abs(W_layer1[k] - W_layer2[k]);
            makhraj += abs(W_layer1[k]);
        }
        double Floating_dW = sorate / (2 * makhraj);
        if (Floating_dW < dW) {
            Floating_storage = W_layer2[i];
            W_layer2[i] = W_layer2[j];
            W_layer2[j] = Floating_storage;
        }
        else {
            dW = Floating_dW;
            cout << dW << endl;

        }
    }

    for (int i = 1; i <= N; i++) {
        cout << i << '\t' << W_layer2[i - 1] << endl;

    }
    sorate = 0.0, makhraj = 0.0;

    for (int k = 0; k < N; k++) {
        sorate += abs(W_layer1[k] - W_layer2[k]);
        makhraj += abs(W_layer1[k]);
    }
    cout<< sorate<< '\t' << (2 * makhraj) << endl;
    cout << sorate / (2 * makhraj) << endl;

    for (int i = 0; i < N; i++) {
        saveas2 << W_layer2[i] << endl;
    }
    return 0;
}