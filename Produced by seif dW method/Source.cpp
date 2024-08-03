#include <iostream>
#include <string>
#include<cmath>
#include<vector>                                                                    //for vector
#include<fstream>                                                                   //infile
using namespace std;
ofstream saveas("save/data.txt");                                                   //save data
ofstream saveas2("save/data2.txt");                                                   //save data

ifstream data_omega("Example/Omega.txt"); //_test                                      //read data
using vec1d = vector<double>;                                                       //using of vector double one dimensional
using vec1s = vector<string>;                                                       //using of vector string one dimensional
double max_sum_w = 0.0;
double in_w = 0.0;
//int factorial(int n);
int main()
{
    //###############################################################################
    //                        read data and move to string
    //###############################################################################
    int number_of_node = 1002;                                                       //maximom number_of_node=101
    vec1s datas(number_of_node);                                                       //create st vectore 1d with size step 101 
    number_of_node = 0;                                                             //maximom number_of_node=0
    string reader= "n";
    while (reader == "n") {
        data_omega >> datas[number_of_node];
        if (datas[number_of_node] == "y") { break; }
        number_of_node++;
    }
    data_omega.close();
    cout << "number of W=" << number_of_node << endl;
    //###############################################################################
    //               convert data string to double //calculated maximum & minimum dW
    //###############################################################################
    vec1d datad(number_of_node);                                                       //create st vectore 1d with size step 101 
    vec1d datad_stable(number_of_node);
    for (int i = 0; i < number_of_node; i++) {
        datad[i] = stod(datas[i]);
        datad_stable[i] = datad[i];
        max_sum_w += abs(datad[i]);
    }

    double sum = 0;
    int last = number_of_node - 1;
    for (int i = 0; i < number_of_node; i++) {
        sum += abs(datad[last] + datad[i]);
        last--;
    }

    max_sum_w = max_sum_w * 2;
    //cout << max_sum_w << endl;
    //cout << sum << endl;
    cout << "Minimum Delta W:" << 0 << "\t\t Round Delta W:" << 0 << endl;
    cout << "Maximum Delta W:" << (1 - double(sum) / double(max_sum_w)) << "\t Round Delta W:" << round((1 - double(sum) / double(max_sum_w)) * 10) / 10 << endl << endl << endl;
    //###############################################################################
    //                        calculated maximum dW
    //###############################################################################
    cout << "How much do you mean?  ";
    cin >> in_w;
    in_w = round(in_w * 10) / 10;
    cout << "The desired round value=" << in_w << endl << endl << endl;
    for (int i = 1; i <= number_of_node; i++) {
        saveas << "node:" << i << "\t";
    }
    saveas << "Delta W:" << "\t Round Delta W:" << endl;

    string reader2 = "n";
    int changer = 0;


    vec1d datachanger(number_of_node);                                                       //create st vectore 1d with size step 101 
    sum = 0;
    for (int i = 0; i < number_of_node; i++) {
        datachanger[i] = datad[i];
        sum += abs(datad[i] + datad_stable[i]);
    }
    double dw_exact = (1 - double(sum) / double(max_sum_w));
    double dw = round(dw_exact * 10) / 10;
    //cout << dw_exact << endl;
    while (reader2 == "n") {
        if (dw < in_w) {

            datad[changer] = datachanger[(number_of_node - 1) - changer];
            datad[(number_of_node-1)- changer] = datachanger[changer];
            changer++;

        }
        else if (dw > in_w)
        {

            changer--;
            datad[changer] = datachanger[(number_of_node - 1) - changer];
            datad[(number_of_node - 1) - changer] = datachanger[changer];
            changer+=2;
            datad[changer] = datachanger[(number_of_node - 1) - changer];
            datad[(number_of_node - 1) - changer] = datachanger[changer];
        }
        else if (in_w== dw) {

            for (int i = 0; i < number_of_node; i++) {
                saveas << datad[i] << '\t';
                saveas2<< datad[i] << endl;
            }
            cout << endl << endl << "___________Done___________Exact Delta W:"<< dw_exact<< "\t Round Delta W:" << dw <<endl<<endl;
            saveas << dw_exact << '\t'<< dw;
            exit(0);

        }
        sum = 0;
        for (int i = 0; i < number_of_node; i++) {
            datachanger[i] = datad[i];
            sum += abs(datad[i] + datad_stable[i]);
        }
        dw_exact = (1 - double(sum) / double(max_sum_w));
        dw = round(dw_exact * 500) / 500;                       //Approximate value
        cout << dw_exact <<'\t'<< dw << endl;

    }
    return 0;
}

/*int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}*/