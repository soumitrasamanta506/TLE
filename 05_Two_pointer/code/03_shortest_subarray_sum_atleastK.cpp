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

/*--------------********************----------------*/

// first implementation
void solve1()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    // shortest subarray with sum at least k
    // fixing starting point and moving it one step forward in every iteration
    int left = 0, right = -1;
    ll sum = 0;
    int ans = 1e6;

    while(left < n)
    {
        while(right + 1 < n && sum < k)
        {
            right++;
            sum += arr[right];
        }
        // if right pointer reaches end
        // or if sum >= k

        if(sum >= k){
            ans = min(ans, right - left + 1);
        }
        sum -= arr[left];
        left++;
    }
    cout << ans << '\n';
}
// second implementation
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    // shortest subarray with sum at least k
    // fixing starting point and moving it one step forward in every iteration
    int left = 0, right = 0;
    ll sum = 0;
    int ans = 1e6;

    while(right < n)
    {
        sum += arr[right];
        while(left <= right && sum-arr[left]>=k)
        {
            sum -= arr[left];
            left++;
        }
        if(sum >= k)
            ans = min(ans, right - left + 1);
        right++;
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