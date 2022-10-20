class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        for(auto i : nums){
            if(i%2 ==0 )  m[i]++;
        }
        pair<int,int> ans = {-1,-1};        // {num, freq}
        for(auto i : m){
            if(ans.second<i.second){
                ans = i;
            }
        }
        return ans.first;
    }
};