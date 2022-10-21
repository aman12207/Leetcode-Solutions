class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m,freq;
        for(auto i : arr){          // storing {number,count}
            m[i]++;
        }
        for(auto i : m){            // storing {count,freq}
            freq[i.second]++;
        }
        for(auto i : freq){
            if(i.second>1) return false;
        }
        return true;
    }
};