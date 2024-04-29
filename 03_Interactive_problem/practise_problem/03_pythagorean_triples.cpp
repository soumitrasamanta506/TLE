// https://codeforces.com/problemset/problem/1487/D

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int MOD=1e9+7;

// to get smallest or equal element from set
set<int>::iterator closest(set<int> &st, int i) {
  auto it = st.lower_bound(i);
  if (it == st.end() && !st.empty())
    it--;
  if (*it > i) {
    if (it == st.begin())
      it = st.end();
    else
      it--;
  }
  return it;
}
int sqrt(int a)
{
    int left = 1, right = 1e9, ans;
    ll mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(mid*mid <= a){
            ans = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    return ans;
}
void solve()
{
    int n, ans=0;
    cin >> n;
    
    ll b;
    for(ll i=3; i*i<=2*n-1; i+=2)
    {
        b = (i*i-1)/2;
        if(i<=b && b<=n && b<=(i*i-b) && (i*i-b)<=n){
            ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
  #endif
    int t;
    cin >> t;
//     t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}