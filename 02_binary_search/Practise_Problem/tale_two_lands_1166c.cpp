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

void solve()
{
    int n, x;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> x;
        a[i] = abs(x);
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for(int i=0; i<n; i++){
      int left = 0, right = i, mid, idx;
      while(left<=right){
        mid = (left+right)/2;
        if(a[mid]>=ceil(a[i]/2.0)){
          idx=mid;
          right = mid -1;
        }
        else left = mid+1;
      }
      ans += (i-idx);
    }
    cout << ans << endl;
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