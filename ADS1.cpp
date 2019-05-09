//shorouk gabr awwad
//30002030


#include <iostream>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include <chrono>
 using namespace std;

int main(){
int n;
float key;
int l;
double e1,e2,e3=0;
double av1,av2,av3=0;
srand((unsigned )time(0));
cout<< "enter the number of the elements!\n";
cin>>n;
for (int i=0;i<100;i++){

float *array =new float[n];
for (int i=0; i<n;i++){

    array[i]=(rand()%1000);
}
cout <<"the array before the sorting: \n";
for (int i=0; i<n;i++){

    cout << array[i]<<endl;
}

auto start = std::chrono::high_resolution_clock::now();
int j=0;
for (;j< n-1 ;j++){
    key=array[j];
    int i=j;
    for (; i< n;i++){

        if (key>array[i]){
            key=array[i];
            l =i;
        }
    }
    if (key != array[i]){
    array[l]=array[j];
    array[j]=key;
    }
}
auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
e1+=elapsed.count();

std::cout << "Elapsed time for average case: " << elapsed.count() << " ns\n";
cout<<endl<<"the array after first sorting"<<endl;

for (int i=0; i<n;i++){

    cout << array[i]<<endl;
}
auto start2 = std::chrono::high_resolution_clock::now();

for (j=0;j< n-1 ;j++){
    key=array[j];
    int i=j;
    for (; i< n;i++){

        if (key>array[i]){
            key=array[i];
            l =i;

        }
    }
    if (key != array[i]){
    array[l]=array[j];
    array[j]=key;
    }
}

auto finish2 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed2 = finish2 - start2;
std::cout << "Elapsed time for Best case: " << elapsed2.count() << " ns\n";
cout<<endl<<"the array after second sort"<<endl;
e2+=elapsed2.count();
for (int i=0; i<n;i++){

    cout << array[i]<<endl;
}

auto start3 = std::chrono::high_resolution_clock::now();

for (j=0;j< n-1 ;j++){
    key=array[j];
    int i=j;
    for (; i< n;i++){

        if (key<array[i]){
            key=array[i];
            l =i;
        }
    }

    array[l]=array[j];
    array[j]=key;

}
auto finish3 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed3 = finish3 - start3;
std::cout << "Elapsed time worst case: " << elapsed3.count() << " ns\n";
cout<<endl<<"the array after third sort"<<endl;
e3+=elapsed3.count();


for (int i=0; i<n;i++){
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
