
// reference : some parts of the code were found on https://github.com/laituan245/spoj-solution/blob/master/classical/SCUBADIV.cpp
#include<iostream>
using namespace std;
#include <set>

//comparing functions
using namespace std;
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}





int main () {

set<int> a;

  int tc;//test cases
  int oRequired;
  int nRequired;

  int Ox[1000]; //oxygen
  int Ni[1000];
  int weight[1000];
  int dp[1000][22][80];//Tabulation
  int NCylinders;//number of cylinders
  cin >> tc;
  //Reading values
  for (int z = 0; z < tc; z++) {
    cin >> oRequired >> nRequired >> NCylinders;
    for (int i = 0; i < NCylinders; i++)
      cin >> Ox[i] >> Ni[i] >> weight[i];

    // Dynamic Programming
    for (int i = 0; i < NCylinders; i++)
      for (int j = 0; j <= oRequired; j++)
        for (int k = 0; k <= nRequired; k++) {
          dp[i][j][k] = 100000000;//initialization to a very large value
          if (j == 0 && k == 0)
            dp[i][j][k] = 0;
        }
	//initialization of the weight
    for (int j = 0; j <= oRequired; j++)
      for (int k = 0; k <= nRequired; k++)
        if (j <= Ox[0] && k <= Ni[0] && (j > 0 || k > 0)) {
          dp[0][j][k] = weight[0];
        }

	// the sum algorithm
    for (int i = 1; i < NCylinders; i++)
      for (int j = 0; j <= oRequired; j++)
        for (int k = 0; k <= nRequired; k++) {
          dp[i][j][k] = dp[i-1][j][k];

          if (j <= Ox[i] && k <= Ni[i]){
    // comparing the next elements in the array to the weights and getting the minimum
            dp[i][j][k] = min(dp[i][j][k], weight[i]);

          }else
          // getting the minimum of weights sum if j> oxygen weight or k > nitrogen weight
            dp[i][j][k] = min(dp[i][j][k], weight[i] + dp[i-1][max(0,j-Ox[i])][max(0,k-Ni[i])]);

        }
// printing the minimum sum
    cout << dp[NCylinders-1][oRequired][nRequired] << "\n";
  }
  // printing the index

  int sum = dp[NCylinders-1][oRequired][nRequired];


    for (int i = 0; i < NCylinders; i++)
      for (int j=0; j<NCylinders; j++){

         if (sum == weight[i]+ weight[j]&& Ox[j]+Ox[i]> oRequired
                && Ni[i]+Ni[j]>nRequired){

                a.insert(j+1);
                a.insert(i+1);


         }
      }

  set<int>:: iterator it;

  for (it = a.begin(); it!=a.end(); it++){

    cout << *it << " ";
  }

}

