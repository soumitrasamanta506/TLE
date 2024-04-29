// https://codeforces.com/problemset/problem/1167/B

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
    vector<int> mul;
    int x, i, first=0;
    set<int> st = {4, 8, 15, 16, 23, 42};

    for(i=2; i<6; i++)
    {
        cout << "? 1 " << i << endl; 
        cin >> x;
        mul.pb(x);
        first = __gcd(first, x);
    }
    while(st.find(first)==st.end())
        first /= 2;
    st.erase(first);
    cout << "! " << first ;
    for(i=0; i<4; i++)
    {
        cout << ' ' << mul[i]/first;
        st.erase(mul[i]/first);
    }
    cout << ' ' << *st.begin() << endl;
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