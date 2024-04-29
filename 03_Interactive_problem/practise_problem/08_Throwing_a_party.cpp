// https://codeforces.com/problemset/problem/1610/C

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

bool checker(vector<pair<int, int>>& ab, int invite_friend){
    int cnt=0, n=ab.size();
    for(int i=0; i<n; i++)
    {
        if(ab[i].first+1+cnt >= invite_friend && ab[i].second>=cnt)
            cnt++;
    }
    return cnt>=invite_friend;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for(int i=0; i<n; i++)
        cin >> ab[i].first >> ab[i].second;
    
    int left = 1, right = n, mid, ans;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(checker(ab, mid))
        {
            ans = mid;
            left = mid+1;
        }
        else    right = mid-1;
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