//insertion sort 2014 4 15
//yangna

#include<iostream>
#include<stdlib.h>
#include <linux/string.h>
using namespace std;

void insertion_sort(int* data, long n)
{
    if(n < 2)
        return;

    int *pdata = data;
    int key = 0;
    for(int i = 1; i < n; i++)
    {
        key = pdata[i];
        for(int j = i-1; j >= 0 ; j--)
        {
            if(pdata[j] > key)
            {
                pdata[j+1] = pdata[j];
                pdata[j] = key;
            }
            else
                break;
        }
    }
    return;
}
int main(int argc, char* argv[])
{
    int d[10];
    memset(d,0,10*sizeof(int));

    srand(time(NULL));
    
    for(int i = 0; i < 10; i++)
    {
        d[i] = rand()%100;
        cout<<d[i]<<" ";
    }
    cout<<std::endl;
    
    insertion_sort(d, 10);
    for(int i = 0; i < 10; i++)
        cout<<d[i]<<" ";
    cout<<std::endl;
    return 0;
}



