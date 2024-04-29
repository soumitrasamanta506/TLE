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

/*--------------********************----------------*/

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int ans = 0, l = 0, r = 0;
    map<int, int> freq;
    while(r<n)
    {
        // include the jth element in your segment
        freq[a[r]]++;
        if(l<=r && freq.size()>k)   // move left pointer 1 step right
        {
            freq[a[l]]--;
            if(freq[a[l]]==0)
                freq.erase(a[l]);
            l++;
        }
        // if current segment is valid, update your answer
        if(freq.size() <= k)
            ans = max(ans, r - l + 1);
        r++;    // move right pointer 1 step right
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