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
    long long x;
    cin >> x;
    double left = 0, right = 1e9;
    double ans = 0;
    // answer to be correct upto 7 decimal places
    double precision = 1e-7; // 10^(-7)

    // for loop will be a better option for decimal value
    for(int i=0; i<=100; i++){
        double mid = (left + right) / 2;
        if(mid <= x / mid){ // mid * mid <= x
            ans = mid;
            left = mid + precision;
        }
        else {
            right = mid - precision;
        }
    }
    cout << setprecision(8) << fixed << ans << endl; 
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