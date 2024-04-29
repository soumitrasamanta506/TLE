// https://codeforces.com/problemset/problem/1698/D

#include<bits/stdc++.h>
#define ONLINE_JUDGE
#define ll long long
#define pb push_back
using namespace std;

const int MOD=1e4+7;

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

// int missing[MOD]={0};
bool query(int l, int r, vector<int>& isSwapped)
{
    cout << "? " << l << ' ' << r << endl;
    int x, cnt=r-l+1;
    vector<int> a, missing(isSwapped.size()+1, 0);
    for (int i=l; i<=r; i++)
    {
        cin >> x;
        a.pb(x);
        missing[x]=1;
        if(x>r || x<l){
            isSwapped[x]=1;
            cnt--;
        }
    }
    for(int i=l; i<=r; i++)
            if(missing[i]==0)isSwapped[i]=1;
    // cout << cnt ;
    if((cnt&1)==0)    // even
    {
        // cout << "even";
        for(auto y: a)
            isSwapped[y]=1;
        return false;
    }
    else{

        
        return true;
    }
    // return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> isSwapped(n+1, 0);
    int left = 1, right =n, mid;

    while(left<=right)
    {
        mid = (left+right)/2;
        bool response = query(left, mid, isSwapped);
        if(response)
            right = mid - 1;
        else    left = mid+1;
    }
    // for(int i=1; i<=n; i++)cout << isSwapped[i] << ' ';
    cout << "! ";
    for(int i=1; i<=n; i++){
        if(isSwapped[i]==0){
            cout << i << endl;
            return;
        }
    }
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