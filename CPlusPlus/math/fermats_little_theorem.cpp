/*
Problem - Given A and B (No of Digits of A,B <10^6), Calculate (A^B)%(1e9+7)
Using Fermats Little Theorem, which states, a^(m-1) ≡ 1 (mod m), to efficiently calculate the answer.
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll power(ll a, ll b, ll mod) // Time Complexity O(log n)
{
    if (b == 0)
        return 1;
    ll ans = power(a, b / 2, mod);
    ans %= mod;
    ans = (ans * ans) % mod;
    if ((b & 1) == 1)
        return (ans * a) % mod;
    return ans % mod;
}
ll stoi(string a, ll mod)
{
    ll ans = 0;
    for (size_t i = 0; i < a.length(); i++)
        ans = ((ans * 10) % mod + a[i] - '0') % mod;
    return ans;
}
int main()
{
    ll n, m, mod = 1000000007;
    ll t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        n = stoi(a, mod);
        m = stoi(b, mod - 1); // using fermats little theorem
        cout << power(n, m, mod) << endl;
    }
    return 0;
}
