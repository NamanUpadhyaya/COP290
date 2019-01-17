// converting a vector of random floats to a vector of probabilities with softmax and sigmoid functions
// call: ./a.out input_size input.txt stride
// or call: ./a.out input_size input.txt for defualt stride=2

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    int input_size= stoi(argv[1]);
    float input[input_size][input_size];

    ifstream inputmatrixfile (argv[2]);
    string line;
    int a=0;
    while (getline(inputmatrixfile, line) && a<(input_size*input_size))
    {
        input[a%input_size][a/input_size]= stof(line);
        a++;
    }
    inputmatrixfile.close();

    int stride;

    if (argc==3)
    {
        stride=2;
    }
    else
    {
        stride= stoi(argv[3]);
    }

    int output_size= ceil(float(input_size)/stride);
    float maxpool[output_size][output_size];
    float avgpool[output_size][output_size];

    int x,y,count;
    float max,sum;
    for (int i=0; i<output_size; i++)
    {
        for (int j=0; j<output_size; j++)
        {
            x= i*stride;
            max= input[x][y];
            sum=0;
            count=0;
            while (x<((i+1)*stride) && x<input_size)
            {
                y= j*stride;
                while (y<((j+1)*stride) && y<input_size)
                {
                    if (input[x][y]>max)
                        max=input[x][y];
                    sum+= input[x][y];
                    y++;
                    count++;
                }
                x++;
            }
            maxpool[i][j]= max;
            avgpool[i][j]= sum/count;
        }
    }

    for(int i=0; i<output_size; i++)
    {
        for (int j=0; j<output_size; j++)
            cout << maxpool[i][j] << "\t";
        cout << "\n";
    }

    for(int i=0; i<output_size; i++)
    {
        for (int j=0; j<output_size; j++)
            cout << avgpool[i][j] << "\t";
        cout << "\n";
    }

   return 0;
}