// Assignment 1 Subtask 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// take input size and kernel size from command line input
int main(int argc, char* argv[])
{
    int input_size= stoi(argv[1]);
    int kernel_size= stoi(argv[2]);
    float input[input_size][input_size];
    float kernel[kernel_size][kernel_size];

    ifstream inputmatrixfile ("input.txt");
    string line;
    int a=0;
    while (getline(inputmatrixfile, line) && a<(input_size*input_size))
    {
        input[a%input_size][a/input_size]= stof(line);
        a++;
    }
    inputmatrixfile.close();

    ifstream kernelmatrixfile ("kernel.txt");
    a=0;
    while (getline(kernelmatrixfile, line) && a<(kernel_size*kernel_size))
    {
        kernel[a%kernel_size][a/kernel_size]= stof(line);
        a++;
    }
   kernelmatrixfile.close();

}
