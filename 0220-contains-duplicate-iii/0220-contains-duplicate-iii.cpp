class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        int minm = min(n,indexDiff);
        vector<int> temp(nums.begin(),nums.begin()+minm);
        sort(temp.begin(),temp.end());
        for(int i = 1;i<minm;i++){
            if(abs(temp[i] - temp[i-1]) <= valueDiff){
                return true;
            }
        }
        for(int i = minm ;i<n;i++){
            for(int j = i-indexDiff;j<i;j++){
                if(abs(nums[i]-nums[j]) <= valueDiff){
                    // cout<<i<<' '<<j<<endl;
                    return true;
                }
            }
        }
        return false;
    }
};