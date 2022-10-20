class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i : s){            // storing freq
            m[i]++;
        }
        vector<pair<char,int>> A(m.begin(),m.end());
        auto comp = [&](pair<char,int> p1, pair<char,int> p2){      // comp function using stl cool right
            return p1.second>p2.second;
        };
        sort(A.begin(),A.end(),comp);           // sorted
        string ans = "";
        for(auto i : A){            // formed ans string
            for(int j = 0; j<i.second;j++){
                ans += i.first;
            }
        }
        
        return ans;
    }
};