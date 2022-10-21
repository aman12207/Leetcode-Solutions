class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;       // val,idx
        for(int i =0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            }
            else {
                if(abs(m[nums[i]]- i)<=k) return true;
                else {
                    m[nums[i]] = i;             // if diff is not <= k than set current index as new idx in map
                    // to assure that next time we will get a chance
                }
            }
        }
        return false;
    }
};