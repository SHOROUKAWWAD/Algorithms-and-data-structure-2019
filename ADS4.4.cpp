#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#include <string>

using namespace std;
// mAx - heapify
void Max_heap(int i, int *A, int n)
{

    int l =2*i+1;
    int r = 2*i+2;
    int swapper;
    int largest;

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

//build max-heap
void build_maxheap(int n,int *A)
{
    int i;

    for(i = n-1/2; i >= 0; i--)

    {

        Max_heap(i,A,n);

    }

}
// max heapify (variant)
void heapvariant (int*A, int n,int i)
{
    int swapper ;
    int l=2*i+1;
    int r=2*i+2;
    int largest =0;
    int s =0;

    while (l<n&&r<n)
    {
        if (A[l]>A[r])
        {
            largest = l;

        }
        else
        {
            largest =r;
        }

        swap(A[i],A[largest]);
        i=largest;
        l=2*i+1;
        r=2*i+2;

    }

    while(i>=0)
    {

        i=((largest/2)-1);
        s= (largest/2)-2;
        if (A[largest]>A[i])
        {

            swap(A[largest],A[i]);

        }
        else if (A[largest]>A[s])
        {
            swap(A[largest],A[s]);

        }
        largest =i;
    }



}
//heap-sort
void Heap_Sort ( int* A, int n)
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
//heap sort variant
void Heap_Sortvariant ( int* A, int n)
{

    int swapp;
    build_maxheap (n,A);

    for (int j = n-1; j>=0; j--)
    {
        swapp = A[0];
        A[0]=A[j];
        A[j]=swapp;
        heapvariant(A,j,0);
    }
    if (A[0]>A[1])
    {
        swap(A[0],A[1]);
    }
}


int main ()
{
    double e1,e2=0;
    double av1,av2=0;

    int n;
    cout << "Enter the number of elements!\n";
    cin >>n;
    int array  [n];
    int array2 [n];
    for (int i=0; i<100; i++)
    {

        srand((unsigned )time(0));


        for (int i=0; i<n; i++)
        {

            array[i]= rand()%1000;
        }
/*copying the content of the first array to the
second one to have identical arrays in the comparison*/
        for (int i=0; i<n; i++)
        {
            array2[i]=array[i];

        }
        cout <<"Array before Heap sort:"<<endl;
        for (int i=0; i<n; i++)
        {
            cout << array[i]<<endl;
        }
        auto start = std::chrono::high_resolution_clock::now();
        auto start3 = std::chrono::high_resolution_clock::now();
        //calling heap sort
        Heap_Sort(array,n);
        auto finish = std::chrono::high_resolution_clock::now();
        auto finish3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::chrono::duration<double> elapsed3 = finish3 - start3;

        e1+=elapsed.count();

        cout <<"Array after Heap sort:"<<endl;
        for (int i=0; i<n; i++)
        {
            cout << array[i]<<endl;
        }

        cout << " Array Before Variant sort:\n";
        for (int i=0; i<n; i++)
        {
            cout << array2[i]<<endl;
        }
        auto start2 = std::chrono::high_resolution_clock::now();
        //calling heap sort variant
        Heap_Sortvariant (array2,n);
        auto finish2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed2 = finish2 - start2;
        e2+=elapsed2.count();

        cout << " Array after Variant sort:\n";
        for (int i=0; i<n; i++)
        {
            cout << array2[i]<<endl;
        }


    }
//the average time for both cases
    av1=e1/100;
    av2=e2/100;
    cout << "the average time for the Max_heapify case: "<<av1<<endl;
    cout <<"the average time for the variant  case: "<<av2<<endl;
    return 0;
}
