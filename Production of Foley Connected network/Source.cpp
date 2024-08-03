/************************************************************************************************/
/*** Topic: create folly connected network                                                    ***/
/***                                                                                          ***/
/*** Version Release 17.12 rev 11256                                                Ali-Seif  ***/
/*** Date: 6/29/2022                                                                          ***/
/*** Code implemented in Microsoft Visual Studio Enterprise 2019 C++ compiler                 ***/
/*** MSI: PX60 6QD/ DDR4                                                                      ***/
/*** Run under a Intel® Core™ i7-6700HQ CPU @ 2.60GHz × 64 based processor with 16 GB RAM     ***/
/************************************************************************************************/
#include <iostream>                                                                             //for cout
#include <random>                                                                               //random_device & ...
#include<fstream>                                                                   //infile & ofstream

using namespace std;
ofstream saveas("save/data.txt");                                                   //save data

int main() {
    int N = 200;                                                                                 //Number of node
    
    
    for (int i = 0; i < N; i++) {
    
        for (int j = 0; j < N; j++) {

            if (i==j) {
                if (i == N - 1) {
                    saveas << 0;
                }
                else {
                    saveas << 0 << ' ';

                }

            }
            else {

                if (j == N - 1) {
                    saveas << 1;
                }
                else {
                    saveas << 1 << ' ';

                }
            }

        }
        saveas <<endl;

    }
    
    
    return 0;
}