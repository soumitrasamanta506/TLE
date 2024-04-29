// maximum element in each window

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

vector<int> maximum_elt(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    deque<pair<int, int>> de;   // pair<value, index>
    for(int i=0; i<n; i++)
    {
        while(!de.empty() && de.back().first<=arr[i])
            de.pop_back();
        de.push_back({arr[i], i});
        if(i>=k && de.front() == make_pair(arr[i-k], i-k))
            de.pop_front();
        if(i>=k-1)
            ans.push_back(de.front().first);
    }
    return ans;
}
void solve()
{
    vector<int> arr={1, 2, 3, 4, 5};
    int k=3;
    vector<int> ans = maximum_elt(arr, k);
    for(auto x: ans)
        cout << x << ' ';
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