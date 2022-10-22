class Solution {
public:
    bool isValidSubstring(map<char,int> &freq, map<char,int> &subfreq){
        for(auto i : subfreq){
            if(i.second> freq[i.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int subsize = t.size(), size = s.size();
        map<char,int> freq;    // storing freq;
        map<char,int> subfreq;  // storing freq of t string
        for(int i =0;i<subsize;i++){
            subfreq[t[i]]++;
        }
        string ans = "";
        int start=0,end = 0;
        while(end<size){
            freq[s[end]]++;
            bool flag = isValidSubstring(freq,subfreq);
            // cout<<start<<" "<<end<<" "<<flag<<endl;
            if(flag){
                bool isValid = true;
                while(start<=end &&  isValid){
                    if(ans.size() == 0 || end-start+1 <ans.size()){
                        ans = s.substr(start,end-start+1);
                    }
                    // cout<<s.substr(start,end-start+1)<<endl;
                    freq[s[start]]--;
                    start++;
                    isValid = isValidSubstring(freq,subfreq);
                }
            }
            end++;
        }
        return ans;
    }
};