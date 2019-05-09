//shorouk gabr awwad
//30002030


#include <cstdlib>
#include <ctime>
#include <chrono>
#include <limits>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <time.h>

 using namespace std;
//void mergesort(float * A, int p, int r);
void merge2(float * A, int p, int q, int r);
void mergsort2(float * A, int p, int r, int c);
void insertion(float * A, int p, int r);

int main() {
        int n;
        // declaring outer counters to store the time values
        double e1, e2, e3 = 0;
        double av1, av2, av3 = 0;
        srand((unsigned) time(0));
        cout << "enter the number of the elements!\n";
        cin >> n;

        int c;
        cout << "Enter K:\n";
        cin >> c;
// this loop runs the program for the same number of entries (with different elements )100 times to get the best average case.
        for (int i = 0; i < 100; i++) {

                float * array = new float[n];

                for (int i = 0; i < n; i++) {

                        array[i] = (rand() % 1000);
                }

                for (int i = 0; i < n; i++) {

                        cout << array[i] << endl;
                }
// start time 1 : average case
                auto start = std::chrono::high_resolution_clock::now();

                mergsort2(array, 0, n - 1, c);

                auto finish = std::chrono::high_resolution_clock::now();
                std::chrono::duration < double > elapsed = finish - start;
                e1 += elapsed.count();
// finish time 1
                cout << endl << "the array after first sorting" << endl;

                for (int i = 0; i < n; i++) {

                        cout << array[i] << endl;
                }
    // start time 2
                auto start2 = std::chrono::high_resolution_clock::now();

                mergsort2(array, 0, n - 1, c);//merge sort call

                auto finish2 = std::chrono::high_resolution_clock::now();
                std::chrono::duration < double > elapsed2 = finish2 - start2;
                cout << endl << "the array after second sort" << endl;
                e2 += elapsed2.count();

        //finish time 2
                /////////**************\\\\\\\\\\\\\\\\//
                for (int i = 0; i < n; i++) {

                        cout << array[i] << endl;
                }
                /////////**************\\\\\\\\\\\\\\\\//

                float key;
                int l = 0;

                for (int j = 0; j < n - 1; j++) {

                        key = array[j];
                        int i = j;
                        for (; i < n; i++) {

                                if (key < array[i]) {
                                        key = array[i];
                                        l = i;
                                }
                        }

                        array[l] = array[j];
                        array[j] = key;

                }
               /* cout << "worst case array : \n";
                for (int i = 0; i < n; i++) {
                        cout << array[i] << " ";
                }*/
                auto start3 = std::chrono::high_resolution_clock::now();

                mergsort2(array, 0, n - 1, c);
                auto finish3 = std::chrono::high_resolution_clock::now();
                std::chrono::duration < double > elapsed3 = finish3 - start3;
                cout << endl << "the array after third sort" << endl;
                e3 += elapsed3.count();

                for (int i = 0; i < n; i++) {
                        cout << array[i] << endl;
                }
                delete[] array;
        }
        // calculating the average time
        av1 = e1 / 100;
        av2 = e2 / 100;
        av3 = e3 / 100;
        cout << "the average time for the average case: " << av1 << endl;
        cout << "the average time for the best case: " << av2 << endl;
        cout << "the average time for the worst case: " << av3 << endl;

}
void mergsort2(float * A, int p, int r, int c) {
        if (r - p + 1 <= c) {
                insertion(A, p, r);

        } else {

                int q;
                q = (p + r) / 2;
                mergsort2(A, p, q, c);
                mergsort2(A, q + 1, r, c);
                merge2(A, p, q, r);
        }
        //insertion sort
}
void insertion(float * A, int p, int r) {

        float Key;
        int j;

        for (int i = p + 1; i <= r; i++) {
                Key = A[i];
                j = i - 1;

                while (j >= p && A[j] > Key) {
                        A[j + 1] = A[j];
                        j--;
                }

                A[j + 1] = Key;

        }
}

void merge2(float * arr, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        /* create temp arrays */
        int L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                        arr[k] = L[i];
                        i++;
                } else {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }

        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
        }

        /* Copy the remaining elements of R[], if there
           are any */

        while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
        }

}



