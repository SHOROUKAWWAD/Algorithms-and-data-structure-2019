#include <iostream>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <chrono>


using namespace std;

void partition(int* arr, int p, int q, int& l_i, int& r_i){

    swap(arr[p+1], arr[q]);
    if(arr[p] > arr[q]){
        swap(arr[p], arr[q]);
    }

    int l_piv = arr[p];
    int r_piv = arr[p+1];
    int l_in = p + 1;
    int r_in = p -1;
    int i = p + 1;
    while(i <= r_in){

        if(arr[i] < l_piv){
            swap(arr[i], arr[l_in]);
            l_in++;
        } else if(arr[i] >= r_piv){
            while(arr[r_in] > r_piv && i < r_in){
                r_in--;
            }
            swap(arr[i], arr[r_in]);
            r_in--;

            if(arr[i] < l_piv){
                swap(arr[i], arr[l_in]);
                l_in++;
            }
        }

        i++;
    }
    l_in--;
    r_in++;

    swap(arr[p], arr[l_in]);
    swap(arr[q], arr[r_in]);

    l_i = l_in;
    r_i= r_in;
}


void quicksort4(int* arr, int p, int q){

    if(p < q){

        int l_i, r_i;
        partition(arr, p, q, l_i, r_i);
        quicksort4(arr, p, l_i-1);
        quicksort4(arr, l_i+1, r_i-1);
        quicksort4(arr, r_i+1, q);
    }
}

int main (){

srand((unsigned )time(0));
int n;
double e1=0;
double av1=0;
cout<< "enter the number of the elements!\n";
cin>>n;
for (int i=0;i<20;i++){

int array[n];

for (int i=0; i<n;i++){

    array[i]=(rand()%1000);
}


int m; int j;

auto start = std::chrono::high_resolution_clock::now();
quicksort4(array,0,n-1);
auto finish = std::chrono::high_resolution_clock::now();
for (int i=0; i<n;i++){

    cout << array[i]<<endl;
}

std::chrono::duration<double> elapsed = finish - start;
e1+=elapsed.count();

}
av1=e1/20;
cout << "the time: "<<av1<<endl;
}

