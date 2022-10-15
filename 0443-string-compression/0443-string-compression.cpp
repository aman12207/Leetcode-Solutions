class Solution {
public:
    int compress(vector<char>& chars) {
        char prev =  chars[0];
        int count = 1;
        vector<char> ans ;
        ans.push_back(chars[0]);        // set all default value acc to first char  already choosen
        bool flag = false;
        for(int i =1;i<chars.size();i++){
            char ch = chars[i];
            if(ch == prev) {        // keep counting 
                count++;
            }
            else {
                if(count > 1){
                    string s = "";
                    while(count>0){
                        int l = count%10;
                        s.push_back(l + '0');
                        count /= 10;
                    }
                    for(int i = s.size()-1;i>=0;i--){
                        // cout<<s[i]<<' ';
                        ans.push_back(s[i]);
                    }
                    // cout<<endl;
                }
                count = 1;
                prev = ch;
                ans.push_back(ch);
            }
        }
        chars.clear();
        if(count>1) {
            string s = "";
            while(count>0){
                int l = count%10;
                s.push_back(l + '0');
                    count /= 10;
            }
            for(int i = s.size()-1;i>=0;i--){
                ans.push_back(s[i]);
            }
        }
        for(auto i : ans) {
            chars.push_back(i);
        }       // pushing updated values in chars vector
        return ans.size();
    }
};