// https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/C

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

bool checker(vector<double>& c, int k)
{
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    double sum = 0;
    for(int i=0; i<k; i++)
    {
        sum += c[i];
    }
    return sum>=0;
}
void solve()
{
    int n, k, i, j;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for(i=0; i<n; i++)
        cin >> p[i].first >> p[i].second;
    

    double error = 1e-7;
    double left = 0, right = 1e6, ans;

    vector<double> c(n);
    for(i=0; i<70; i++)
    {
        double mid = (left+right)/ 2;


        for(j=0; j<n; j++)
        {
            c[j] = p[j].first - (p[j].second*mid);
        }

        if(checker(c, k))
        {
            ans = mid;
            left = mid+error;
        }
        else right = mid - error;
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