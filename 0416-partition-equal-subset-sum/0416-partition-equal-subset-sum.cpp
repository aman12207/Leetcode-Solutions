class Solution {
public:
    bool solve(int n, int target , vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0 ) return true;
        if(n== 0){
            if(target == arr[0]) return true;
            return false;
        }
        if(dp[n][target] != -1) return dp[n][target];         // it contains either 0 or 1 if already visited
        bool notTaken = solve(n-1, target,arr,dp);
        bool taken = false;
        if(arr[n]<= target)
             taken = solve(n-1,target-arr[n],arr,dp);
        return dp[n][target] = taken | notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto i : nums){
            sum += i;
        }
        if(sum%2!=0 || n==1) return false;      // if it has odd sum we can't divide into two equal subset sum
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};