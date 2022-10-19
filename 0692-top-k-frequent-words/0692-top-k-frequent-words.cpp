class Solution {
public:
    static bool comp(pair<int,string> p1, pair<int,string> p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto i : words){        // storing freq
            m[i] ++;
        }
        vector<pair<int,string>> pq;
        for(auto i : m){            // storing elements in sorted way acc to freq
            pq.push_back({i.second,i.first});
        }
        sort(pq.begin(),pq.end(),comp);
        // for(auto i : pq) cout<<i.first<<' '<<i.second<<endl;
        vector<string> ans;
        for(int i = 0 ;i<k;i++){
            ans.push_back(pq[i].second);
        }
        return ans;
    }
};