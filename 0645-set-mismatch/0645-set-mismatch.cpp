class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for(auto i : nums) m[i]++;
        vector<int> ans(2,0);
        for(int i = 1;i<=n;i++){
            if(m[i] == 2) ans[0] = i;
            if(m[i] == 0) ans[1] = i;
            // if(ans[0] !=0  && ans[1] !=0 ) return ans;
        }
        return ans;
    }
};