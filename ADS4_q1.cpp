
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
void Bubble_sort (int n, int* A)
{
    while (1)
    {
        bool swapped =false;
        for (int i =0; i<n-1; i++)
        {
            if (A[i]>A[i+1])
            {

                swap(A[i],A[i+1]);
                swapped = true;

            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{


    int key;
    int n;
    int l;
    double e1,e2,e3=0;
    double av1,av2,av3=0;
    srand((unsigned )time(0));
    cout<< "enter the number of the elements!\n";
    cin>>n;

    for (int i=0; i<100; i++)
    {

        int *array =new int[n];
        for (int i=0; i<n; i++)
        {

            array[i]=(rand()%1000);
        }
        cout <<"the array before the sorting: \n";
        for (int i=0; i<n; i++)
        {

            cout << array[i]<<endl;
        }
        auto start = std::chrono::high_resolution_clock::now();
        Bubble_sort(n, array);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        e1+=elapsed.count();
        cout<<endl<<"the array after first sorting"<<endl;
        for (int i=0; i<n; i++)
        {

            cout << array[i]<<endl;
        }
        auto start2 = std::chrono::high_resolution_clock::now();

        Bubble_sort(n, array);

        auto finish2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed2 = finish2 - start2;
        e2+=elapsed2.count();
        cout<<endl<<"the array after second sort"<<endl;
        for (int i=0; i<n; i++)
        {

            cout << array[i]<<endl;
        }

        for (int j=0; j< n-1 ; j++)
        {
            key=array[j];
            int i=j;
            for (; i< n; i++)
            {

                if (key<array[i])
                {
                    key=array[i];
                    l =i;
                }
            }

            array[l]=array[j];
            array[j]=key;

        }
        auto start3 = std::chrono::high_resolution_clock::now();
        Bubble_sort(n, array);
        auto finish3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed3 = finish3 - start3;
        e3+=elapsed3.count();
        cout<<endl<<"the array after third sort"<<endl;

        for (int i=0; i<n; i++)
        {
            cout << array[i]<<endl;
        }
        delete []array;


    }
    av1=e1/100;
    av2=e2/100;
    av3=e3/100;
    cout << "the average time for the average case: "<<av1<<endl;
    cout <<"the average time for the best case: "<<av2<<endl;
    cout <<"the average time for the worst case: "<<av3<<endl;

}
