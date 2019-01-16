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
    int padsize = stoi(argv[5]);

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
   
   int newinputsize= input_size+2*padsize;

   
    float temp[newinputsize][newinputsize];
    for(int i=0;i<newinputsize;i++)
    {
        if(i<padsize||i>=newinputsize-padsize)
        {
            for(int j=0; j<newinputsize; j ++)
            {
                temp[i][j]=0;
            }
        }
        else
        {
            for(int j=0; j<newinputsize; j ++)
            {
                if(j<padsize||j>=newinputsize-padsize)
                {
                    temp[i][j]=0;
                }
                else
                {
                    temp[i][j]=input[i-padsize][j-padsize];
                }
            }
        }
    }
    

    int output_size=newinputsize -kernel_size+1;
    float output[output_size][output_size];

    for(int x=0; x<output_size; x++)
    {
        for (int y=0; y<output_size; y++)
        {
            float value=0;
            for (int i=0;i<kernel_size;i++)
                for (int j=0;j<kernel_size;j++)
                    value+= temp[x+i][y+j]*kernel[kernel_size-1-i][kernel_size-1-j];
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