class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int cnt = 0;        // storing no of * tackled
        int n = s.size();
        for(auto i : s){        // traversed from left to right
            if(i == '(' ){
                st.push(i);
            }
            else if(i == '*'){
                cnt++;
            }
            else if(!st.empty())
                st.pop();
            else {
                if(cnt==0){                 // if * is already encountered then treating it as ( and balancing )  
                    // cout<<"returned false from 1st comp";
                    return false;
                }
                else cnt--;
            }
        }
        if(st.size() == 0)
            return true;
        while(!st.empty()) st.pop();
        cnt = 0;        // resetting the value of st and count and traversing from right to left
        for(int i =n-1;i>=0;i--){
            if(s[i] == ')' ){
                st.push(s[i]);
            }
            else if(s[i] == '*'){
                cnt++;
            }
            else if(!st.empty())
                st.pop();
            else {
                if(cnt==0){
                    // cout<<"returned false from 2nd comp";
                    return false;       //if * is already encountered then treating it as ) and balancing (
                }
                else cnt--;
            }
        }
        if(st.size() == 0 || cnt>= st.size()) return true;
        return false;
    }
};