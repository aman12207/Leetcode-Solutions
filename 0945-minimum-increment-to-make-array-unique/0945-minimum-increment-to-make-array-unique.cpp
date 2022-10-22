class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int next = 0;               // it will keep track of next number we can insert
        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            if(next>val){       // if next number we can insert is greater than current than 
                // we have to inc current number by next - val times
                ans = ans + (next-val);
                next = next+1;
            }
            else {              // and if it is less than or equal to current element than we don't have to increment it just set next number we can insert as current val +1
                next = val+1;
            }
        }
        return ans;
    }
};