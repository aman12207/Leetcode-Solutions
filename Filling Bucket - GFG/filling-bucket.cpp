//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int helper(int N, int &ans,vector<int> &dp){
        if(N<=0){
            if(N==0) return 1;
            return 0;
        }
        if(dp[N] != -1) return dp[N];
        return dp[N] = (helper(N-1,ans,dp) + helper(N-2,ans,dp)) % 100000000;
    }
    int fillingBucket(int N) {
        // code here
        int ans = 0;
        vector<int> dp (N+1,-1);
        return helper(N,ans,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends