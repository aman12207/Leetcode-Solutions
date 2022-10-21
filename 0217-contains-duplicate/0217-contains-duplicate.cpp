class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto i : nums){
            m[i]++;
            if(m[i] == 2) return true;
        }
        return false;
    }
};