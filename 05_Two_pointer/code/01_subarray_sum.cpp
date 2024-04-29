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
// Approach - 1
// binary_search method
// TC --> O(NlogN)
ll subarraySum(int l, int r, vector<ll>& prefix)
{
    return prefix[r]-prefix[l-1];
}
void solve1()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<ll> prefix(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i-1]+a[i];
    }

    int final_ans = 0;
    for(int i=1; i<=n; i++)
    {
        // find out the length of the longest subarray which starts at index i
        int start = i, end = n;
        int ans = 0;
        while(start<=end)
        {
            int mid = (start + end) / 2;
            if(subarraySum(i, mid, prefix) <= k)
            {
                ans = max(ans, mid - i + 1);
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        final_ans = max(final_ans, ans);
    }
    cout << final_ans << '\n';
}

// Approach - 2
// Two - pointer method

void solve2()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    int final_ans = 0;
    int rightPointer = -1;
    ll currentSum = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>k){
            rightPointer = i;
            currentSum = 0;
        }
        // find out the length of the longest subarray which starts at index i
        // right now we assume that index i has already been added
        while(rightPointer + 1 < n && currentSum + a[rightPointer + 1] <= k)
        {
            currentSum += a[rightPointer + 1];
            rightPointer++;
        }
        // we now have the maximum rightPointer for the current index i
        int currentAns = rightPointer - i + 1;
        final_ans = max(final_ans, currentAns);
        currentSum -= arr[i];
    } 
    cout << final_ans << '\n';
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