class Solution {
public:
    string minWindow(string s, string t) {
        int subsize = t.size(), size = s.size();
        map<char,int> subfreq;  // storing freq of t string
        for(int i =0;i<subsize;i++){
            subfreq[t[i]]++;
        }
        string ans = "";
        int count = subfreq.size();         // keeping track of no of unique char required
        int start=0,end = 0;
        while(end<size){
            if(subfreq.find(s[end]) != subfreq.end()){          // if curr char is a required char reduce freq by 1
                subfreq[s[end]]--;
                if(subfreq[s[end]] == 0) count--;       // if we don't need this char anymore reduce count by 1
            }
            if(count == 0){           // if it is a valid substring try to get small substring
                while(start<=end && count == 0){
                    if(ans.size() == 0 || end-start+1 <ans.size()){
                        ans = s.substr(start,end-start+1);
                    }
                    if(subfreq.find(s[start]) != subfreq.end()){
                        subfreq[s[start]]++;
                        if(subfreq[s[start]]>0) count++;            // we need the char we just removed
                    }
                    start++;
                }
            }
            end++;
        }
        return ans;
    }
};