class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 1){
            if(nums[0]) return 1;
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            int element = nums[i];
            if(element != 0){
                for(int j = i;j<n;j++){
                    if(nums[j]){
                        nums[j] = nums[j] - element;
                    }
                }
                sort(nums.begin(),nums.end());      // sorting to make sure smallest element is deleted first
                ans++;
            }
        }
        return ans;
    }
};