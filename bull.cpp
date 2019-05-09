// reference : https://www.geeksforgeeks.org/maximum-path-sum-triangle/ some parts of the code were taken

#include<iostream>
#include <cstring>

using namespace std;


int maxPathSum( int n,int* arr [])
{
// copying array one into array 2
    int arr2[n][n];
    for (int i=0; i<n; i++)
    {

        for (int j =0; j<n; j++)
        {

            arr2[i][j]= arr[i][j];

        }

    }
// check for the greatest value
    for (int i=n-1; i>=0; i--)
    {

        for (int j=0; j<=i; j++)
        {
            // check the value right below  if yes sum it up to the first element
            if (arr[i+1][j] > arr[i+1][j+1])
            {

                arr[i][j] += arr[i+1][j];
            }
            else
            {
                // check the below right value then, if yes add it up
                arr[i][j] += arr[i+1][j+1];

            }

        }

    }
// the sum of the greatest path
    cout << arr[0][0]<<endl;
    cout << arr2[0][0]<<" " ;
    int m=0;
    int  sum= arr2[0][0];
// copying the path
    for (int i=1; i<n; i++)
    {
        // compare array 1's elements
        // show the corresponding elements in the copy-array
        if (arr[i][m]> arr[i][m+1])
        {

            cout << arr2[i][m]<< " " ;
            sum += arr2 [i][m];
        }
        else
        {
            cout << arr2[i][m+1]<<" ";
            sum += arr2 [i][m+1];
            m++;
        }
    }
    cout << arr[0][0]-sum<<" ";
    cout << endl;
    return arr[0][0];
}

int main()
{
    int n;
    cin >>n;
    int* arr[n];
    // initiation
    for (int i=0; i<n; i++)
    {
        arr[i] = new int [n];
    }
    for (int i=0; i<n; i++)
    {

        for (int j=0; j<n; j++)
        {
            arr[i][j] =0 ;
        }
    }

    int m=1;
    //taking input
    try {
    for (int i=0; i<n; i++)
    {
        for (int j =0; j<m; j++)
        {
            cin >> arr[i][j];
          if (arr[i][j]<1|| arr[i][j]>10000) {
            throw(arr[i][j]);
          }
        }
        m++;
    }
    }catch (int l){
    cout << "out of range \n";
    }
    maxPathSum(n-1,arr);
    return 0;
}
