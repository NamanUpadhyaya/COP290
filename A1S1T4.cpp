// converting a vector of random floats to a vector of probabilities with softmax and sigmoid functions
// call: ./a.out vector_size vector.txt

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    int vector_size= stoi(argv[1]);
    float vector[vector_size];
    ifstream vectorfile (argv[2]);
    string line;
    int a=0;
    while (getline(vectorfile, line) && a<vector_size)
    {
        vector[a]=stof(line);
        a++;
    }
    vectorfile.close();

    for(int i=0; i<vector_size; i++)
    {
        cout << vector[i] << "\n";
    }

    float sigmoid[vector_size];
    float softmax[vector_size];

    float denom=0;
    for(int i=0; i<vector_size; i++)
    {
        sigmoid[i]= 1/(1+exp(-vector[i]));
        cout << sigmoid[i] << "\n";
        denom+= exp(vector[i]);
    }
    for(int i=0; i<vector_size; i++)
    {
        softmax[i]= exp(vector[i])/denom;
        cout << softmax[i] << "\n";
    }


    return 0;
}