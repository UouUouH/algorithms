//yangna 20140421
#include<iostream>
#include<stdlib.h>
#include<linux/string.h>
using namespace std;
//merge sorted array[start...middle-1] and sorted array[middle...end] to array[start...end].
void merge(int* array, int start, int end, int middle, bool is_debug)
{
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int i = 0, j = 0;

    if(n1&&n2 == 0)
        return;

    int* array1 = new int[n1];
    if(array1 == NULL)
        return;
    
    int* array2 = new int[n2];
    if(array2 == NULL)
    {
        delete[] array1;
        array1 = NULL;
        return;
    }
    if(is_debug)
    {
        cout<<endl;
        cout<<"--------------merge start-----------------"<<endl;
        cout<<"start: "<<start<<"end: "<<end<<"middle: "<<middle<<endl;
        cout<<"array1: ";
    }
    for(i = start; i < middle+1; i++)
    {
        array1[i-start] = array[i];
    
        if(is_debug)
            cout<<array1[i-start]<<" ";
    }
    
        
    if(is_debug)
    {
        cout<<endl;
        cout<<"array2: ";
    }

    for(i = middle+1; i < end+1; i++)
    {
        array2[i-middle-1] = array[i];

        if(is_debug)
            cout<<array2[i-middle-1]<<" ";
    }
    if(is_debug)
        cout<<endl;
    i = 0;
    j = 0;
    for(int n = start; n <= end; n++)
    {
        if(i >= n1)
        {
            if(j < n2)
            {
                array[n] = array2[j];
                j++;
            }
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
        if(is_debug)
            cout<<array[n]<<" ";
    }
    if(is_debug)
    {
        cout<<endl;
        cout<<"-----------------merge end-------------- "<<endl;
        cout<<endl;
    }
    delete[] array1;
    delete[] array2;
    array1 = NULL;
    array2 = NULL;

}

void merge_sort(int* array, int start, int end, bool is_debug)
{
    if((end - start) < 1)
        return;

    int middle = (end + start)/2;

    merge_sort(array, start, middle, is_debug);
    merge_sort(array, middle+1, end, is_debug);
    merge(array, start, end, middle, is_debug);
}
int main(int argc, char* argv[])
{
    int d[10];
    memset(d,0,10*sizeof(int));

    bool is_debug = false;
    if(argc == 2)
    {
        if((argv[1][0] == '-')&&(argv[1][1] == 'd'))
            is_debug = true;
        else
        {
            cout<<"example: merge //not debug"<<endl;
            cout<<"example: merge -d //debug"<<endl;
        }
    }

    srand(time(NULL));
    if(is_debug)
    {
        cout<<endl;
        cout<<"-----------------------------------"<<endl;
    }
    
    for(int i = 0; i < 10; i++)
    {
        d[i] = rand()%100;
        cout<<d[i]<<" ";
    }
    cout<<std::endl;
    
    merge_sort(d, 0, 9,is_debug);
    for(int i = 0; i < 10; i++)
        cout<<d[i]<<" ";
    cout<<std::endl;
    return 0;
}

