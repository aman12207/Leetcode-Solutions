class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;        //{val,index}
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i = n-1;i>=0;i--){          // just find nearest greater to the right
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
            if(!st.empty())
                ans[i] = st.top().second-i;     // insert the diff in index in ans
            st.push({temperatures[i],i});       
        }
        return ans;
    }
};