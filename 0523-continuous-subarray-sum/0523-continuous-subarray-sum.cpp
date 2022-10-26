class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        for(int i = 1;i<n;i++){
            nums[i] += nums[i-1];
        }
        for(int i =0;i<n;i++){
            if(i>0 && nums[i] % k == 0) return true;
            if(m.find(nums[i]%k) != m.end())      // i%k is already stored once 
                // it means there is a range in between these two indexes where all sum of all num % k == 0
            {
                if(i - m[nums[i]%k] > 1)    return true;
            }
            else m[nums[i] % k]  = i;
        }
        return false;
    }
};