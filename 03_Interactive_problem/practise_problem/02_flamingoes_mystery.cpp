// https://codeforces.com/problemset/problem/1425/F

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
   int n;
   cin >> n;
   int prefix_sum = 0;
   int l=1, r= n, result, total;
   vector<int> cage;

    cout << "? " << l  << ' ' << r << endl;
    cin >> total;
    l++;
   while(l<r){
    cout << "? " << l  << ' ' << r << endl;
    cin >> result;
    cage.pb(total - result - prefix_sum);
    prefix_sum += cage.back();
    l++;
   }
    cout << "? " << 1  << ' ' << r-1 << endl;
    cin >> result;
    cage.pb(result-prefix_sum);
    cage.pb(total-result);

    cout << "! ";
    for(auto x: cage) cout << x << ' ';
    fflush(stdout);
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