class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxm = 0;
        for(auto i : nums){
            maxm = max(i,maxm);
        }
        int ans = 0, count = 0, i = 0;
        while(i<nums.size()){
            if(nums[i] == maxm){
                while(i<nums.size() && nums[i] == maxm ){
                    i++;
                    count++;
                }
                ans = max(ans,count);
            }
            else {
                count = 0;
                i++;
            }
        }
        return ans;
    }
};