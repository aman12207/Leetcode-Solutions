class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // cyclic sort
        int i =0;
        int n = nums.size();
        while(i<n){
            if(nums[i] != n && i != nums[i]){       // it will keep swapping the element 
                // like [3,0,1] at 0 
                // it will be [0,3,1] and i remains at 1 index
                // as it will 3 then i will be inc
                // 3 will be swapped with 1 and then again i will inc and loop will break;
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