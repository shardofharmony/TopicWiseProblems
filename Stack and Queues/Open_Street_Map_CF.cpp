/* Faced multiple problems while implementing this solution

1. Out of bound, interger overflow
2. Defining large 2d arrays was causing problems, as I have defining the arrays locally, globally you can declare
array of largers size
3. Tried initializing 2d array using, "{0}", never use it, use memset if value is 0 or -1 or use for loop

*/



/*

This implemention is possibly the worst implementation of the idea, I think it is possible to reduce the two
dp like array that I have used to only one array

*/





#include<bits/stdc++.h>
using namespace std;
int grr[10000001], arr[3000][3000], dp[3000][3000], dp2[3000][3000];
void solve()
{
  int n, m, a, b;
  long long int g, x, y, z;
  cin >> n >> m >> a >> b >> g >> x >> y >> z;
  grr[0] = g;

// Block of code to assign values to array

  for (int i = 1; i <= n * m + 10; i++)
    grr[i] = ((long long int)(grr[i - 1]) * x + y) % z;


  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      arr[i][j] = grr[i * m + j];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      dp[i][j] = 0;
    }
  }

  /*

  Finding values in each column using the idea of problem : Sum of minimum in all subarrays of given length,
  here given length is a

  */

  for (int j = 0; j < m; j++)
  { deque<int> q;
    for (int i = 0; i < a; i++)
    {
      while (!q.empty() && q.back() > arr[i][j])
        q.pop_back();

      q.push_back(arr[i][j]);
    }
    dp[0][j] = q.front();
    for (int i = 1; i + a <= n; i++)
    {
      if (q.front() == arr[i - 1][j])
        q.pop_front();
      while (!q.empty() && q.back() > arr[i + a - 1][j])
        q.pop_back();

      q.push_back(arr[i + a - 1][j]);
      dp[i][j] = q.front();
    }
  }
  long long int ans = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      dp2[i][j] = 0;
    }
  }

  /*

  Finding values in each row using the idea of problem : Sum of minimum in all subarrays of given length,
  here given length is b.

  Instead of original array use previously calculated array.

  */


  for (int i = 0; i < n; i++)
  {
    deque<int> q;
    for (int j = 0; j < b; j++)
    {
      while (!q.empty() && q.back() > dp[i][j])
        q.pop_back();
      q.push_back(dp[i][j]);
    }
    dp2[i][0] = q.front();
    for (int j = 1; j + b <= m; j++)
    {
      if (q.front() == dp[i][j - 1])
        q.pop_front();
      while (!q.empty() && q.back() > dp[i][j + b - 1])
        q.pop_back();
      q.push_back(dp[i][j + b - 1]);
      dp2[i][j] = q.front();
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans += dp2[i][j];

  cout << ans;

}


int main()
{
  int t = 1;
  //cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }

}