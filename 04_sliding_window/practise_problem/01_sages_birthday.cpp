// https://codeforces.com/problemset/problem/1419/D2

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
    int n, i, ans=0;
    cin >> n;
    vector<int> a(n), final(n);
    // set<int> st;
    for(i=0; i<n; i++){
        cin >> a[i];
        // st.insert(a[i]);
    }
    sort(a.begin(), a.end());
    bool prev=false;
    int idx = 0;
    for(i=1; i<n; i+=2)
    {
        final[i] = a[idx++];
        // st.erase(st.begin());
    }
    for(i=0; i<n; i+=2)
    {
        final[i]=a[idx++];
        // st.erase(st.begin());
       
        if(i-1>=0 && prev && final[i-1]<final[i])ans++;
        prev = (i+1<n && final[i]>final[i+1])?true:false;
        
    }
    cout << ans << '\n';
    for(i=0; i<n; i++)
        cout << final[i] << ' ';
        
    cout << '\n';
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