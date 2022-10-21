class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> isVisited(n+1,0);
        for(auto i : nums){
            isVisited[i] = 1;
        }
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            if(isVisited[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};