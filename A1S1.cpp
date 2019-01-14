// Assignment 1 Subtask 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream inputmatrixfile ("input.txt");
    string line;
    while (getline(inputmatrixfile, line))
    {
        cout << line << "\n";
    }
    int input_size= stoi(argv[1]);
    float *input= new float[input_size][input_size];
}
