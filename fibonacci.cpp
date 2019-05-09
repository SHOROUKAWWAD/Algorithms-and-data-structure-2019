
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std;
int fibona (int n);
int fibonb (int n);
void multiply(int F[2][2], int M[2][2]);
int fib(int n);
int finbonc (int n);

void power(int F[2][2], int n);
struct fibon
{

    int n;
    struct fibon* next;

};

int main ()
{
    double e1,e2,e3,e4=0;
    double av1,av2,av3,av4=0;
    srand((unsigned )time(0));
    cout<< "enter the number of the elements!\n";
    int n;
    cin >> n;
for (int i=0; i<100; i++){
    auto start = std::chrono::high_resolution_clock::now();
    for (int i =0; i< n; i++)
    {
        fibona (i);

    }
auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
e1+=elapsed.count();

    for (int i=0; i<n; i++){
        cout <<fibona(i)<<endl;
    }

auto start2 = std::chrono::high_resolution_clock::now();
    for (int i =0; i< n; i++)
    {
        fibonb(i);
    }
auto finish2 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed2 = finish2 - start2;
e2+=elapsed2.count();

    for (int i=0; i<n; i++){
       cout <<fibonb(i)<<endl;
    }
auto start3 = std::chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++)
    {

        fib(i);
    }
auto finish3 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed3 = finish3 - start3;
e3+=elapsed3.count();

    for (int i =0; i< n; i++)
    {
        cout <<fib(i)<<endl;
    }
auto start4 = std::chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++)
    {

        finbonc(n);

    }
auto finish4 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed4 = finish4 - start4;
e4+=elapsed4.count();

    for (int i =0; i< n; i++)
    {
        cout <<finbonc(i)<<endl;
    }

}
av1=e1/100;
av2 =e2/100;
av3 =e3/100;
av4 =e4/100;
cout << "naive recurrence time: "<< av1<<endl;
cout << "bottom up time: "<< av2<<endl;
cout << "closed up time: "<< av3<<endl;
cout << "matrix time: "<< av4<<endl;

}


int fibona (int n)
{
    if (n<2)
    {

        return n;

    }
    else if (n==2){
        return 1;
    }
    {

        return fibona(n-1)+ fibona(n-2);

    }


}


int fibonb (int n)
{

    if(n == 1 || n == 0)
    {
        return n;
    }
    if (n==2){
        return 1;
    }

    int twoBehind = 1;
    int oneBehind = 1;
    int  fib = 0;

    for(int i = 2; i < n; i++)
    {

        fib = twoBehind + oneBehind;
        twoBehind = oneBehind;
        oneBehind = fib;
    }
    return fib;
}

int finbonc (int n)
{
    if (n<2){

        return n;
    }else  {

    float l = (sqrt(5)+1)/2;
    for (int i=1; i<n; i++)
    {

        l=l*(sqrt(5)+1)/2 ;

    }

    int r = nearbyint(l/sqrt(5));

    return r;

    }
}

int fib(int n)
{
    int Arr[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(Arr, n-1);
    return Arr[0][0];
}

void power(int Arr[2][2], int n)
{
    if( n == 0 || n == 1)
        return;
    int Arr2[2][2] = {{1,1},{1,0}};

    power(Arr, n/2);
    multiply(Arr, Arr);

    if (n%2 != 0)
        multiply(Arr, Arr2);
}

void multiply(int Arr[2][2], int Arr2[2][2])
{
    int xval =  Arr[0][0]*Arr2[0][0] + Arr[0][1]*Arr2[1][0];
    int yval=  Arr[0][0]*Arr2[0][1] + Arr[0][1]*Arr2[1][1];
    int zval =  Arr[1][0]*Arr2[0][0] + Arr[1][1]*Arr2[1][0];
    int wval =  Arr[1][0]*Arr2[0][1] + Arr[1][1]*Arr2[1][1];

    Arr[0][0] = xval;
    Arr[0][1] = yval;
    Arr[1][0] = zval;
    Arr[1][1] = wval;
}

