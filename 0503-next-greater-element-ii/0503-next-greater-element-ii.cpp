class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]) st.pop();        // trying to find nearest greater
            if(!st.empty()) ans[i] = st.top();              // if exists update the value in ans 
            st.push(nums[i]);
        }
        return ans;
    }
};