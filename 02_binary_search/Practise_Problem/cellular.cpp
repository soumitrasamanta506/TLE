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

int left_bs(vector<ll>& b, ll city){
    int left = 0, right = b.size()-1, ans = -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(b[mid]<=city)
        {
            ans = mid;
            left = mid+1;
        }
        else right = mid - 1;
    }
    return ans;
}
int right_bs(vector<ll>& b, ll city){
    int left = 0, right = b.size()-1, ans = -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(b[mid]>=city){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return ans;
}

void solve()
{
    int n, m, i;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<m; i++)
        cin >> b[i];
    
    ll ans = 0;
    for(i=0; i<n; i++)
    {
        ll dist = 1e10;
        int left_cellular_tower = left_bs(b, a[i]);
        if(left_cellular_tower != -1) dist = min(a[i]-b[left_cellular_tower], dist);
        ll right_cellular_tower = right_bs(b, a[i]);
        if(right_cellular_tower != -1) dist = min(dist, b[right_cellular_tower]-a[i]);
        ans = max(ans, dist);
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