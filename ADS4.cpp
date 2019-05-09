#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void Max_heap(int i, int *A, int n)
{

    int l =2*i+1;
    int r = 2*i+2;
    int swapper;
    int largest;
    if (l<n)
    {

    }

    if (l<n && A[l]>A[i])
    {

        largest =l;
    }
    else
    {


        largest = i;
    }
    if (r<n&& A[r]>A[largest])
    {

        largest =r;
    }
    if (largest != i)
    {


        swapper=A[i];
        A[i]=A[largest];
        A[largest]=swapper;
        Max_heap(largest,A,n);

    }


}

Bubble_sort (int n, int* A)
{
    int swapper;
    for (int i =0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (A[i]>A[i+1])
            {

                swapper = A[i];
                A[i]=A[i+1];
                A[i+1]=swapper;

            }
        }
    }
}
void build_maxheap(int n,int *A)

{


    int i;

    for(i = n-1/2; i >= 0; i--)

    {

        Max_heap(i,A,n);

    }

}

Heap_Sort ( int* A, int n)
{

    int swapp;
    build_maxheap (n,A);

    for (int j = n-1; j>=0; j--)
    {
        swapp = A[0];
        A[0]=A[j];
        A[j]=swapp;
        Max_heap(0,A,j);
    }
}



int main ()
{

    int n;
    cout << "Enter the number of elements!\n";
    cin >>n;
    int *array =new int[n];
    srand((unsigned )time(0));


    for (int i=0; i<n; i++)
    {

        array[i]= rand()%1000;
    }

    for (int i=0; i<n; i++)
    {
        cout << array[i]<<endl;
    }
    cout <<"MAX"<<endl;
    Heap_Sort(array,n);
    for (int i=0; i<n; i++)
    {
        cout << array[i]<<endl;
    }




    delete []array;

}


