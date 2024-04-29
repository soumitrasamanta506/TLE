// https://codeforces.com/problemset/problem/1223/C

#include<bits/stdc++.h>
#include<numeric>
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

void a_type(vector<ll>& p, int x, ll a, ll common_multiple, ll mid, int& idx, ll& contribution){
    for(ll i=a; i<=mid; i+=a)
        {
            if((i%common_multiple) != 0)
            {
                contribution += (p[idx]/100)*x;
                idx++;
            }
        }
}

bool checker(vector<ll>& p, ll k,int x, int y, ll a, ll b, ll mid)
{
    ll common_multiple = lcm(a, b), i;
    int idx = 1;
    ll contribution=0;
    for(i=common_multiple; i<=mid; i+=common_multiple)
    {
        contribution += (p[idx]/100)*(x+y);
        idx++;
    }    
    
    a_type(p, x, a, common_multiple, mid, idx, contribution);
    a_type(p, y, b, common_multiple, mid, idx, contribution);
    
    return contribution >= k;
}
void solve()
{
    int n, i, x, y;
    ll a, b;
    cin >> n;
    vector<ll> p(n+1, 0);
    p[n]=1e9;
    for(i=0; i<n; i++)
        cin >> p[i];
    sort(p.begin(), p.end(), greater<ll>());
    cin >> x >> a >> y >> b;
    
    if(y>x) {swap(x, y);swap(a, b);}
    ll k;
    cin >> k;
    ll left = 1, right = n, mid, ans = -1;

    while(left<=right)
    {
        mid = (left+right)/2;
        if(checker(p, k, x, y, a, b, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
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