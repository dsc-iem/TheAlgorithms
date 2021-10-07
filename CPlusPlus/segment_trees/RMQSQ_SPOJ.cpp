/*Problem link:-https://www.spoj.com/problems/RMQSQ/

/*You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the minimum number between the range [i, j] (inclusive).
Note: the query ranges are specified using 0-based indexing.*/

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

bool myCompare(int a, int b)
{
  return a > b;
}
int arr[N], st[N];

void buildTree(int si, int ss, int se) //si-->segment index ,ss-->segment start,se-->segment index
{
  if (ss == se)
  {
    st[si] = arr[ss];
    return;
  }

  int mid = (ss + se) / 2;
  buildTree(2 * si, ss, mid); //The left segment are stored at indices 2*i and right at 2*i+1
  buildTree(2 * si + 1, mid + 1, se);

  st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe)
{
  if (qs > se || ss > qe) //if query is outside the range of segment return infinity
    return INT_MAX;

  if (qs <= ss && se <= qe) //if it totally belongs inside the range then return that vlaue  (Assume ss as 2 ,se as 4 ,qs=1 and qe=5)
    return st[si];

  int mid = (ss + se) / 2;

  int l = query(2 * si, ss, mid, qs, qe);
  int r = query(2 * si + 1, mid + 1, se, qs, qe);

  return min(l, r);
}

void solve()
{
  int n, q, l, r;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  cin >> q;
  buildTree(1, 1, n);
  while (q--)
  {
    cin >> l >> r;
    cout << query(1, 1, n, l + 1, r + 1) << endl;
  }
}

signed main()
{

  int test=1;
  // cin>>test;

  while (test--)
  {
   
    solve();
  }

  return 0;
}
