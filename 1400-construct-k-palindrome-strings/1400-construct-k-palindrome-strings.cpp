class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int> m;
        for(auto i : s){
            m[i]++;
        }
        int count_odd = 0;
        for(auto i : m){
            if(i.second%2!=0) 
            count_odd++;
        }
        if(count_odd>k || s.size()<k){    // min no palindrome string we can make will be greater than k
            return false;
        }
        return true;
    }
};