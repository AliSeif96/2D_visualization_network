/************************************************************************************************/
/*** Topic: create natural frequency with dw Specified sarika jalan algoritm                  ***/
/***                                                                                          ***/
/*** Version Release 17.12 rev 11256                                                Ali-Seif  ***/
/*** Date: 6/29/2022                                                                          ***/
/*** Code implemented in Microsoft Visual Studio Enterprise 2019 C++ compiler                 ***/
/*** MSI: PX60 6QD/ DDR4                                                                      ***/
/*** Run under a Intel® Core™ i7-6700HQ CPU @ 2.60GHz × 64 based processor with 16 GB RAM     ***/
/************************************************************************************************/
#define _USE_MATH_DEFINES // for M_PI
#include <iostream>                                                                             //for cout
#include <random>                                                                               //random_device & ...
#include<fstream>                                                                   //infile & ofstream
#include <cmath>//for M_PI


using namespace std;
ofstream saveas2("save/data.txt");                                                   //save data

int main() {
    int N = 200;                                                                                 //Number of node

    random_device rd;                                                           //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());                                                          //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> uniform_distribution_teta(-1.0, 1.0);      //Uniform real distribution from [0 , 1)

    cout << uniform_distribution_teta(gen)* M_PI << endl;

    for (int i = 0; i < N; i++) {
        //saveas2 << W_layer2[i] << endl;
        saveas2 << uniform_distribution_teta(gen) * M_PI << endl;

    }
    return 0;
}