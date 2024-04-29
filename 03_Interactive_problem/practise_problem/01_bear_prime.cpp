// https://codeforces.com/problemset/problem/679/A

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ONLINE_JUDGE
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
    vector<int> toCheck = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};

    int cnt = 0;
    string result;
    for(auto x: toCheck)
    {
        cout << x << endl;
        cin >> result;
        if(result == "yes") cnt++;
        if(cnt > 1)
        {
            cout << "composite" << endl;
            return;
        }
    }
    cout << "prime" << endl;
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