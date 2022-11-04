class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "";
        for(auto i : s){
            if(i=='a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i=='A' || i == 'E' || i == 'I' || i == 'O' || i == 'U' )
                vowel.push_back(i);
        }
        int idx = 0;
        for(int i = s.size()-1;i>= 0;i--){
            if(s[i]=='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i]=='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ){
                s[i] = vowel[idx];
                idx++;
            }
        }
        return s;
    }
};