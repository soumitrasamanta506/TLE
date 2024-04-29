// https://codeforces.com/problemset/problem/1807/E

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

int query(int l, int r)
{
    cout << "? " << r-l+1;
    for(int i=l; i<=r; i++) cout <<' ' <<  i;
    cout << endl;
    int response;
    cin >> response;
    return response;
}
void solve()
{
    int n, i;
    cin >> n;
    vector<int> a(n+1);
    a[0]=0;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    int left = 1, right = n, mid , ans;
    while(left<=right)
    {
        mid = (left + right)/2;
        int response = query(left, mid);
        if(response > a[mid]-a[left-1])
        {
            ans = mid;
            right = mid-1;
        }
        else    left = mid+1;
    }
    cout << "! " << ans << endl;
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