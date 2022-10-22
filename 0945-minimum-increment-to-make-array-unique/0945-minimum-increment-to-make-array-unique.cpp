class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        map<int,int> m;
        int next = 0;
        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            if(m.find(val) == m.end()){
                m[val] = 1;
                if(next>val){
                    ans = ans + (next-val);
                    next = next+1;
                }
                else {
                    next = val+1;
                }
            }
            else {
                if(next>val){
                    ans = ans + (next-val);
                    next = next+1;
                }
                else {
                    next = val+1;
                }
            }
            // for(auto i : m) cout<<i.first<<' '<<i.second<<endl;
            // cout<<ans<<' '<<next<<' '<<endl;
            // cout<<endl;
        }
        return ans;
    }
};