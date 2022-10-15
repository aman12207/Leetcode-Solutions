class Solution {
public:
    int compress(vector<char>& chars) {
        char prev =  chars[0];
        int count = 1;
        vector<char> ans ;
        int n = chars.size();
        ans.push_back(chars[0]);        // set all default value acc to first char  already choosen
        bool flag = false;
        for(int i =1;i<=n;i++){
            char ch = i == n ? ' ' : chars[i];
            if(ch!= prev || i == n) {
                if(count > 1){
                    string s = "";          // storing count in string and then putting it into vector
                    while(count>0){
                        int l = count%10;
                        s.push_back(l + '0');
                        count /= 10;
                    }
                    for(int i = s.size()-1;i>=0;i--){
                        ans.push_back(s[i]);
                    }
                }
                count = 1;
                prev = ch;
                if(i != n)
                ans.push_back(ch);
            }
            else {              // keep counting
                count++;
            }
        }
        chars.clear();
        for(auto i : ans) {
            chars.push_back(i);
        }       // pushing updated values in chars vector
        return ans.size();
    }
};