class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i+1] = -1;
                i++;
                count ++;
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(n- (2*count));
        return ans;
    }
};