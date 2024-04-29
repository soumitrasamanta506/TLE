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

bool possible(int x, vector<int>& arr, int k){
    int usedWorkers = 1;
    int currentWorkersWorkload = 0;

    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        if(arr[i]>x){
            return false;
        }
        if(arr[i] + currentWorkersWorkload <= x){
            currentWorkersWorkload += arr[i];
        }
        else{
            if(usedWorkers == k)
                return false;
            usedWorkers++;
            currentWorkersWorkload = 0;
            currentWorkersWorkload += arr[i];
        }
    }
    return true;
}
void solve()
{
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 17, 19};
    int n = arr.size();
    int k = 3;
    int left = 0; // can be max of array
    int right = 1e6; // can be sum of all elements

    int ans = 1e6;
    while(left<=right)
    {
        int mid = (left + right)/2;

        if(possible(mid, arr, k))
        {
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
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