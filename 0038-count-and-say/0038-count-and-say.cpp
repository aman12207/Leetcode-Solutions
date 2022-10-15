class Solution {
public:
    string helper(string s){
        string ans = "";
        int n = s.size();
        int count = 1;
        for(int i = 1;i<n;i++){
            if(s[i] == s[i-1] ){
                count++;
            }
            else { 
                ans.push_back(count + '0');
                ans.push_back(s[i-1]);
                count = 1;
            }
        }
        if(count){
            ans.push_back(count + '0');
            ans.push_back(s[n-1]);
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1;i<n;i++){
            ans = helper(ans);
            // cout<<ans<<endl;
        }
        return ans;
    }
};