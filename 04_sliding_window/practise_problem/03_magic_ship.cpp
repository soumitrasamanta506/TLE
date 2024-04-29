// https://codeforces.com/problemset/problem/1117/C

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
    ll x1, y1, x2, y2, n, i;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    string s;
    cin >> s;

    ll xdist = x2 - x1, ydist = y2-y1, diagonal;
    ll ans=0;
    diagonal = min(abs(xdist), abs(ydist));
    char w[2];  // x, y
    if(xdist>=0 && ydist>=0){
        w[0]='R';w[1]='U';
    }
    else if(xdist<0 && ydist>=0){
        w[0]='L';w[1]='U';
    }
    else if(xdist>=0 && ydist<0){
        w[0]='R';w[1]='D';
    }else{
        w[0]='L';w[1]='D';
    }
    while(diagonal!=0)
    {
        int day=0;
        for(i=0; i<n; i++)
        {
            if(s[i]==w[0] || s[i]==w[1])
                day++;
            if(day == diagonal)
                break;
        }
        if(i==n)
        {
            if(day==0)
            {
                cout << "-1";
                return;
            }
            ans += n*(diagonal/day);
            diagonal = (diagonal%day);
        }
        else{
            ans += (i+1);
            diagonal = 0;
        }
    }
    int remaining = max(abs(xdist), abs(ydist)) - min(abs(xdist), abs(ydist));
    int idx = (max(abs(xdist), abs(ydist))==abs(xdist))?0:1;
    while(remaining != 0)
    {
        int day=0;
        for(i=0; i<n; i++)
        {
            if(s[i]==w[idx])
                day+=2;
            if(day>=remaining)
                break;
        }
        if(i==n)
        {
            if(day == 0){
                cout << "-1";
                return;
            }
            ans += n*(remaining/day);
            remaining = (remaining%day);
        }
        else
        {
            ans += (i+1);
            remaining = 0;
        }
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
    // cin >> t;
    t = 1;
    while(t--)
    {
        solve();
    }

    return 0;
}