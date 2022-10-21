class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n,0);
        int count=0;
        while(nums!=temp){
            int val=INT_MAX;
            for(auto i : nums){
                if(i>0)
                    val = min(val,i);
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    nums[i]-=val;
                }
            }
            count++;
        }
        return count;
    }
};