// https://codeforces.com/problemset/problem/1486/C1

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

int query(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int response;
    cin >> response;
    return response;
}
void solve()
{
    int n;
    cin >> n;
    int left = 1, right = n, ans, mid;

    while(left<=right)
    {
        if(left==right) {
            ans = left;
            break;
        }
        mid = (left+right)/2;
        int response = query(left, right);
        if(response<=mid)
        {
            if(left<mid && query(left, mid)==response)
                right = mid;
            else left = mid + 1;
        }
        else
        {
            if(mid+1<right &&  query(mid+1, right)==response)
                left = mid+1;
            else    right = mid;
        }
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
    // cin >> t;
    t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}