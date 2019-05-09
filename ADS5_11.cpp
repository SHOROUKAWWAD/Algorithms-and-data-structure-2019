#include <iostream>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;

int partition (int* A, int p, int q)
{

    int x = A[p];
    int i= p;
for (int j= p+1; j<=q; j++){

        if (A[j]< x)
        {

            i=i+1;
            swap (A[i], A[j]);
        }
    }
    swap (A[i],A[p]);

    return i;
}



 partition2 (int * A,int p,int r){

 int pivot = A[(p+r)/2];
 int i = p -1;
 int j = r +1;
 while (true){
    do{
      i++;
    }while (A[i]<pivot);

    do{
         j--;
    }while (A[j]>pivot);

    if (i>=j){
   return j;
    }
    swap (A[i],A[j]);
 }


 }

 int median_of_3 (int*A, int p , int q ){
int s;
 int m = (p+q)/2;
 if ( A[p] > A[m]){

    swap (p,m);

 }
 if (A[p]> A[q]){
     swap (p,q);
 }
 if (A[m]>A[q]){

    swap (m,q);
 }
s= q-1;
 swap (m,s);
 return A [s];

 }

  partition3_med (int * A,int p,int r){

 int pivot = median_of_3(A,p,r);
 int i = p -1;
 int j = r +1;

 while (true){

    do{
      i++;
    }while (A[i]<pivot);

    do{
        j--;
    }while (A[j]>pivot);

    if (i>=j){
   return j;
    }
    swap (A[i],A[j]);
 }


 }


 QuickSort (int * A, int p, int r)
{

    if (p<r)
    {
       int q= partition (A,p,r);
        QuickSort (A,p,q);
        QuickSort (A,q+1,r);

    }
}


 QuickSort2 (int * A, int p, int r)
{

    if (p<r)
    {
       int q= partition2 (A,p,r);
        QuickSort2 (A,p,q);
        QuickSort2 (A,q+1,r);

    }
}

 QuickSort3 (int * A, int p, int r)
{

    if (p<r)
    {
        int q= partition3_med (A,p,r);
        QuickSort2 (A,p,q);
        QuickSort2 (A,q+1,r);

    }
}

int main (){
int n;
int l;
double e1,e2,e3=0;
double av1,av2,av3=0;
srand((unsigned )time(0));
for (int i=0;i<100000;i++){

int array [1000];
for (int i=0; i<1000;i++){

    array[i]=(rand()%10000);
}
cout << "went here \n";
int array2 [1000];
for (int i=0; i<1000;i++){

    array2[i]=array[i];
}
cout << "went here \n";
int array3 [1000];
for (int i=0; i<1000;i++){

    array3[i]=array[i];
}
cout << "went here \n";
auto start = std::chrono::high_resolution_clock::now();

QuickSort(array,0,999);

auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
e1+=elapsed.count();
cout << "went here \n";
// copy array
auto start2 = std::chrono::high_resolution_clock::now();
QuickSort2(array2,0,999);

auto finish2 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed2 = finish2 - start2;
e2+=elapsed2.count();

// copy array2
auto start3 = std::chrono::high_resolution_clock::now();

QuickSort3(array3,0,999);

auto finish3 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed3 = finish3 - start3;
e3+=elapsed3.count();
}
av1=e1/100000;
av2=e2/100000;
av3=e3/100000;
cout << "the lumoto case: "<<av1<<endl;
cout <<"the hoare case: "<<av2<<endl;
cout <<"the 3_median case: "<<av3<<endl;

}
