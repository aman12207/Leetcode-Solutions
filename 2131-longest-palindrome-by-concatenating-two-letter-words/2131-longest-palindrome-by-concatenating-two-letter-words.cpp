class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int > m;
        for(auto i : words){
            m[i]++;
        }
        int ans = 0,ispalindromeAdded = 0;// we can add a palindrome string middle of a palindrome string
        for(auto &i : m){
            string rev = i.first;
            reverse(rev.begin(),rev.end());
            if(i.first == rev){
                if(i.second>1){
                    int curr = i.second;
                    i.second = curr%2;
                    ans += ((curr/2)*4);
                    if(!ispalindromeAdded && i.second == 1){
                        ans+=2;
                        ispalindromeAdded = 1;
                        i.second = 0;
                    }
                }
                else if(!ispalindromeAdded && i.second == 1){
                    // cout<<i.first<<' '<<i.second<<endl;
                    ans+=2;
                    ispalindromeAdded = 1;
                    i.second = 0;
                }
            }
            else if(i.second > 0){
                if(m.find(rev) != m.end()){
                    int curr = min(m[rev], i.second);
                    if(m[rev] >0){
                        ans += (curr*4);
                        m[rev]-=curr;
                        m[i.first]-=curr;
                    }
                }
            }
            // cout<<i.first<<' '<<i.second<<endl;
        }
        return ans;
    }
};