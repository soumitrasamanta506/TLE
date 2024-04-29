// https://codeforces.com/problemset/problem/1623/C

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
/*

// wrong idea
void solve1()
{
    int n, i, mn=1e9;
    cin >> n;
    vector<int> h(n);
    for(i=0; i<n; i++){
        cin >> h[i];
        mn = min(mn, h[i]);
    }
    vector<int> mn_idx;
    ll ans = 1e12;
    for(i=0; i<n; i++)
    {
       if(h[i]==mn)
        {
            mn_idx.pb(i);
        }
    }
    for(i=2; i<n; i++)
    {
        h[i-2]+=2*(h[i]/3);
        h[i-1]+=(h[i]/3);
        h[i]-=3*(h[i]/3);
    }
    
    for(auto x: mn_idx)
        ans = min((ll)h[x], ans);
    cout << max(ans, (ll)mn) << '\n';
}

*/

bool checker(vector<int>h, int mid)
{
    int n = h.size();
    vector<ll>  temp(n, 0);
    for(int i=n-1; i>1; i--)
    {
        if(temp[i]+h[i]<mid)
            return false;
        ll extra = min((ll)h[i], temp[i]+h[i]-mid);
        temp[i-1] += (extra/3);
        temp[i-2] += 2*(extra/3);
    }
    if(h[0]+temp[0]>=mid && h[1]+temp[1]>=mid)
        return true;
    return false;
}

// binary search on idea
void solve()
{
    int n, i, ans = 0;
    cin >> n;
    vector<int> h(n);
    for(i=0; i<n; i++)cin >> h[i];
    int left = 0, right = 1e9;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(checker(h, mid))
        {
            ans = mid;
            left = mid+1;
        }
        else    right = mid-1;
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