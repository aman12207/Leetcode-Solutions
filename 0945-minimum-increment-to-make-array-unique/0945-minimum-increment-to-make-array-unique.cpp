class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int next = 0;               // it will keep track of next number we can insert
        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            if(next>val){       // 
                ans = ans + (next-val);
                next = next+1;
            }
            else {
                next = val+1;
            }
        }
        return ans;
    }
};