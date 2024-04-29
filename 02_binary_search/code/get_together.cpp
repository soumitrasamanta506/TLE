// codeforces
// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A

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

bool checker(double time, vector<int>& x, vector<int>& v){
    pair<double, double> curr = {1e-9, 1e9};

    for(int i=0; i<x.size(); i++){
        curr.first = max(curr.first, x[i]-v[i]*time);
        curr.second = min(curr.second, x[i]+v[i]*time);
        if(curr.first>curr.second)
            return false;
    }
    return true;
}
void solve()
{
    int n, i;
    cin >> n;
    vector<int> x(n), v(n);
    for(i=0; i<n; i++)cin >> x[i] >> v[i];

    double error = 1e-7;
    double left = 0, right = 1e9;
    double ans;
    for(i=0; i<70; i++){
        double mid = (left+right)/2;
        if(checker(mid, x, v))
        {
            ans = mid;
            right = mid - error;
        }
        else{
            left = mid + error;
        }
    }
    cout << setprecision(7) << fixed << ans;
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