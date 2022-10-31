class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // cyclic sort
        int i =0;
        int n = nums.size();
        while(i<n){
            if(nums[i] != n && i != nums[i]){
                swap(nums[i],nums[nums[i]]);
            }
            else i++;
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != i){
                return i;
            }
        }
        return n;
    }
};