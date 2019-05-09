
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

Bucket_sort (float arr[],int n)
{
    vector <float> A[n];
    int index;
    for (int i=0; i<n; i++)
    {
        //the index of the bucket is equal n*value
        index = floor(n*arr[i]);
        A[index].push_back(arr[i]);
    }
    for (int i=0; i<n; i++)
    {
        //sorting the elements in each bucket
        sort(A[i].begin(),A[i].end());
    }
    int ind=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<A[i].size(); j++)
        {
            arr[ind++]= A[i][j];
        }
    }
}

int Maximum(int arr[],int n)
{
    //getting the maximum in the array
    int max = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int Minimum(int arr[],int n)
{//getting the minimum
    int min = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
Counting_Sort (int arr[], int n)
{
    int maxel = Maximum(arr,n);
    int minel = Minimum(arr,n);
    int range = maxel-minel;
//initiating the counter with range+1 elements
    int counter[range+1];
    int output[n];
//initiating the array
    for (int i=0; i<=range; i++)
    {
        counter[i]=0;
    }
//initiating the array
    for (int i=0; i<n; i++)
    {
        output[i]=0;
    }

    for(int i = 0; i <n; i++)
    {
        counter[arr[i]-minel]++;
    }
//incrementing the counter
    for(int i = 1; i < range+1; i++)
    {
        counter[i] += counter[i-1];
    }
    for(int i = n-1; i >= 0; i--)
    {
// putting elements back into the output || the counter is index
        output[ counter[arr[i]-minel] -1 ] = arr[i];
        counter[arr[i]-minel]--;
    }
    for(int i=0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void countingSortints (int arr[], int n, int k)
{
//initiation
    int output[n];
    for (int i=0; i<n; i++)
    {
        output[i]=0;
    }
//initiation
    int counter[10] = {0,0,0,0,0,0,0,0,0,0};
// an array with a counter =1 || k is the digits rank in each case
//the counter is the remainder of devision by 10 (the decimal base)
    for (int i = 0; i < n; i++)
        counter[(arr[i] / k) % 10]++;
// counter increment
    for (int i = 1; i < 10; i++)
        counter[i] += counter[i - 1];
// putting the elements of the counter back into the output function
    for (int i = n - 1; i >= 0; i--)
    {
        output[counter[(arr[i] / k) % 10]-1] = arr[i];
        counter[(arr[i] / k) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

}



void radixSortints(int arr[], int n)
{
    int k;
    k= arr[0];
    for (int i=0; i<n; i++)
    {
        if (arr[i]>k)
        {

            k=arr[i];
        }
    }
 // for loop to sort buckets of digits
    for (int i = 1; k / i > 0; i *= 10)
    {
        countingSortints(arr, n, i);
    }
}


void countSortstring(string a[], int size, size_t k )
{

    string b[size];
    // a counter with number of digits equal to char capacity
    int c[257];
    //initiation
    for (int i = 0; i <257; i++)
    {
        c[i] = 0;
    }

    for (int j = 0; j <size; j++)
    {//measuring according to the word with greatest number of characters
        if (k<a[j].size())
        {
    // the counter is equal to one at the present letter in the array
            c[(int)(unsigned char)a[j][k] + 1 ]++;
        }
        else
        {
        //increasing the element at position 0 in counter array
            c[0]++;
        }
    }

    for (int f = 1; f <257; f++)
    {
        // incrementing the counter (index forming)
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--)
    {
        // arranging the elements in the output array
        if (k<a[r].size())
        {
            b[c[(int)(unsigned char)a[r][k] + 1 ]-1]=a[r];
            c[(int)(unsigned char)a[r][k] + 1 ]--;
        }
        else
        {
            b[c[0]-1]=a[r];
            c[0]--;
        }
    }
//putting back the elements in the array after sorting
    for (int l = 0; l < size; l++)
    {
        a[l] = b[l];
    }

}

void radixSort(string b[], int r)
{
    size_t k;
    k= b[0].size();
    for (int i=0; i<r; i++)
    {
      if (b[i].size()>k)
        {
            k=b[i].size();
        }
    }
    for (size_t digit = k; digit > 0; digit--)
    {
        countSortstring(b, r, digit - 1);
    }
}


int main()
{

    float arr[7];
    arr[0]=0.9;
    arr[1]=0.1;
    arr[2]=0.6;
    arr[3]=0.7;
    arr[4]=0.6;
    arr[5]=0.3;
    arr[6]=0.1;


    Bucket_sort (arr,7);

    for (int i=0; i<7; i++)
    {
        cout<< arr[i]<<endl;
    }
    int arr2[]= {9,1,6,7,6,2,1};
     Counting_Sort(arr2,7);
     cout<<"after count sort\n";
     for (int i=0; i<7; i++)
    {
        cout<< arr2[i]<<endl;
    }
     int arr3[]= {11,1,8,7,5,0,1};
     cout<<"after radix sort\n";
    radixSortints(arr3,7);
    for (int i=0; i<7; i++)
    {
        cout<< arr3[i]<<endl;
    }

    string array []= {"word", "category","cat","new","news","world","at","work","time"};

    cout<< "strings after sorting:\n";
    radixSort(array,9);
    for (int i=0; i<9; i++)
    {
        cout<< array[i]<<endl;
    }

    return 0;
}



