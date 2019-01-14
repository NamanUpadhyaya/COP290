// Assignment 1 Subtask 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    // cout << "Enter Input Matrix Size: \n";
    // float input_size;
    // cin >> input_size;
    // cout << argv[1] << argv[2];
    ifstream inputmatrixfile ("input.txt");
    string line1;
    while (getline(inputmatrixfile, line1))
    {
        cout << line1 << "\n";
    }

}
