//yangna 20140421
#include<iostream>
#include<stdlib.h>
#include<linux/string.h>
using namespace std;
//merge sorted array[start...middle-1] and sorted array[middle...end] to array[start...end].
void merge(int* array, int start, int end, int middle)
{
    int n1 = middle - start;
    int n2 = end - middle;

    int* array1 = new int[n1];
    if(array1 == NULL)
        return;
    
    int* array2 = new int[n2];
    if(array2 == NULL)
        return;

    for(int i = start; i < middle; i++)
        array1[i-start] = array[i];

    for(int i = middle; i < end+1; i++)
        array2[i-middle] = array[i];

    int i = 0, j = 0;
    for(int n = start; n <= end; n++)
    {
        if(i >= n1)
        {
            if(j < n2)
            {
                array[n] = array2[j];
                j++;
            }
            else
                break;
        }
        else if(j >= n2)
        {
            array[n] = array1[i];
            i++;
        }
        else
        {
            if(array1[i] > array2[j])
            {
                array[n] = array2[j];
                j++;
            }
            else
            {
                array[n] = array1[i];
                i++;
            }
        }
    }

}

void merge_sort(int* array, int start, int end)
{
    if((end - start) < 2)
        return;

    int middle = (end - start)/2;

    merge_sort(array, start, middle-1);
    merge_sort(array, middle, end);
    merge(array, start, end, middle);
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
    
    merge_sort(d, 0, 9);
    for(int i = 0; i < 10; i++)
        cout<<d[i]<<" ";
    cout<<std::endl;
    return 0;
}

