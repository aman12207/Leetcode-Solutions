class Solution {
public:
    string reverseWords(string s) {
        string ans = "",word = "";
        istringstream sobj(s);
        sobj>> s;           // inputting s in sobj (buffer)
        while(sobj>> word){     // extracting word from sobj if can't extreact them break;
            s = word + ' ' + s;         
        }
        return s;
    }
};