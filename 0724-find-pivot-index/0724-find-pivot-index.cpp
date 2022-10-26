class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> prefixSum(n,0), suffixSum(n,0);
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        for(int i = n-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + nums[i];
        }
        for(int i = 0;i<n;i++){
            if(i == 0){
                if(suffixSum[i+1] == 0)
                    return 0;   
            }
            else if(i == n-1) {
                if(prefixSum[i-1] == 0)
                    return n-1;
            }
            else if(prefixSum[i-1] == suffixSum[i+1]) return i;
        }
        return -1;
    }
};