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
    

    

    int output_size=newinputsize-kernel_size+1;
    int size2 = output_size*output_size;
    float mult_output[size2];

    //make topleitz matrix
    float kernel_t_matrix[kernel_size*kernel_size];
    int t=0;
    for(int i=0;i<kernel_size;i++)
    {
        for(int j=0; j <kernel_size;j++)
        {
            kernel_t_matrix[t]=kernel[kernel_size-1 -i][kernel_size-1 -j];
            t++;
        }
    }

    float main_t_matrix[size2][kernel_size*kernel_size];

    for(int m=0;m<output_size;m++)
    {
        for(int n=0; n<output_size;n++)
        {
            for(int i=0;i<kernel_size;i++)
            {
                for(int j=0;j<kernel_size;j++)
                {
                    main_t_matrix[m*output_size+n][i*kernel_size+j] = temp[m+i][n+j];
                }
            }
        }
    }

    

    //mult result to mult_output
    //multiply main_t_matrix with kernel_t_matrix
    for (int i=0;i<size2;i++)
    {
        mult_output[i]=0;
        for(int j=0;j<kernel_size*kernel_size;j++)
        {
            mult_output[i]+=main_t_matrix[i][j]*kernel_t_matrix[j];
        }
    }

    //Displaying the output
    for (int j=0;j<output_size; j++)
    {
        for (int i=0; i<output_size; i++)
            cout << mult_output[j*output_size+i] << "\t";
        cout << "\n";
    }

    return 0;
}

//END
