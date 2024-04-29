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
int binary_search(vector<int>& a, int qi){
    int ans, mid, left = 0, right = a.size();
    while(left<=right){
        int mid = (left+right)/2;
        if(a[mid]<=qi){
            ans = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    return ans;
}
void solve()
{
    int n, x, sum=1; cin >> n;
    vector<int> a(n+1);
    a[0]=1;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        sum+=x;
        a[i+1]=sum;
    }
    int m, qi; cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> qi;
        cout << binary_search(a, qi)+1 << endl;
    }
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