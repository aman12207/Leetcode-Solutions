class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0, count2 = 0, n = s.size();
        for(int i = 0 ;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'  )
            if(i<n/2) count1++;
            else count2++;
        }
        return count1 ==  count2;
    }
};