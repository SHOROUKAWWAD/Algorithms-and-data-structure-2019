// inspired from: https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/


#include <iostream>
#include <vector>

using namespace std;
void successArr(vector <int> arr, int n);

int main()
{
    vector <int> arr;
    int elem;
    cin>>elem;
    while(elem>0)
    {
        arr.push_back(elem);
        cin>>elem;
    }
    int n = arr.size();
    successArr(arr, n);
    return 0;
}


void successArr(vector <int> arr, int n)
{
    vector<vector<int> > opt(n);

    opt[0].push_back(arr[0]);
// filtering the elements according to greatness and size
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] > arr[j]) && (opt[i].size() < opt[j].size()))
            {
                opt[i] = opt[j];
            }
        }
        opt[i].push_back(arr[i]);
    }
    // the maximum subset
    vector<int> max_subs = opt[0];

    for (int i =0; i<n; i++)
    {
        if ( max_subs.size()< opt[i].size())
            max_subs = opt[i];
    }
    for (auto it = max_subs.begin(); it!= max_subs.end(); it++)
    {
        cout << *it << " ";
    }
}
