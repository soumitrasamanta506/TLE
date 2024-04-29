// https://codeforces.com/problemset/problem/1520/F1

#include<bits/stdc++.h>
#define ONLINE_JUDGE
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

void solve()
{
    int n, t, k;
    cin >> n >> t >> k;
    int left = 1, right = n, mid, ans, sum;
    while(left<=right)
    {
        mid = (left+right)/2;
        cout << "? 1 " << mid << endl;
        cin >> sum;
        if(mid-sum>=k)
        {
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << "! " << ans << endl;
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
    // cin >> t;
    t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}