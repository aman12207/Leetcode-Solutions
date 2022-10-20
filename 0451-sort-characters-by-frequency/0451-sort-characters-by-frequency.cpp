class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i : s){            // storing freq
            m[i]++;
        }
        vector<string> bucket(s.size()+1, "");      
        //put character into frequency bucket
        for(auto i : m){            // appended char with resp to their size in bucket
            bucket[i.second].append(i.second,i.first);
        }
        string ans = "";
        //form descending sorted string
        for(int i = s.size();i>0;i--){
            if(bucket[i].size()>0){
                ans += bucket[i];
            }
        }
        return ans;
    }
};