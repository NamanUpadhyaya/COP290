// Assignment 1 Subtask 1
// call: ./a.out input_size input.txt kernel_size kernel.txt

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// take input size and kernel size from command line input
int main(int argc, char* argv[])
{
    int input_size= stoi(argv[1]);
    int kernel_size= stoi(argv[3]);
    float input[input_size][input_size];
    float kernel[kernel_size][kernel_size];

    ifstream inputmatrixfile (argv[2]);
    string line;
    int a=0;
    while (getline(inputmatrixfile, line) && a<(input_size*input_size))
    {
        input[a%input_size][a/input_size]= stof(line);
        a++;
    }
    inputmatrixfile.close();

    ifstream kernelmatrixfile (argv[4]);
    a=0;
    while (getline(kernelmatrixfile, line) && a<(kernel_size*kernel_size))
    {
        kernel[a%kernel_size][a/kernel_size]= stof(line);
        a++;
    }
   kernelmatrixfile.close();
   
   int output_size=input_size+kernel_size-1;
   float output[output_size][output_size];
   for(int x=0; x<output_size; x++)
   {
       for (int y=0; y<output_size; y++)
       {
           float value=0;
           for (int i= max(0,x-kernel_size+2);i<=min(input_size-1,x+1);i++)
               for (int j= max(0,x-kernel_size+2);j<=min(input_size-1,x+1);j++)
                   value+= input[i][j]*kernel[x-i+1][y-j+1];
           output[x][y]=value;
       }
   }

   for (int i=0; i<output_size; i++)
   {
       for (int j=0; j<output_size; j++)
            cout << output[i][j] << "\t";
        cout << "\n";
   }
    return 0;
}
