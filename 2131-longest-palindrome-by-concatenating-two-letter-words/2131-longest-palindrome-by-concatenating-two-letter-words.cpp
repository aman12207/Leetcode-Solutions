class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int > m;
        int ans = 0;
        for(auto &i : words){           // just traverse each string if its rev is found dec the count from map and inc the ans    
            string rev = i;
            reverse(rev.begin(),rev.end());
            if(m[rev]){
                m[rev]--;
                ans+=4;
            }
            else m[i]++;
        }
        for(auto i : m){        // we can add a palindromic string with count 1 in the middle of the final string 
            if(i.first[0] == i.first[1] && i.second == 1) {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};