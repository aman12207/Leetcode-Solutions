class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string,pair<int,pair<string,int>>> m;       // creator, {sumofViews, {maxViewsId, maxViews}}
        vector<vector<string> > ans;
        int highest_prority = 0;
        int n = creators.size();
        for(int i = 0;i<n;i++){
            if(m.find(creators[i]) != m.end()){     // if creators[i] exists in map 
                int prevViews = m[creators[i]].first;
                pair<string,int> prevMax = m[creators[i]].second;
                if(prevMax.second<views[i]) prevMax = {ids[i],views[i]};        // store the maxm viewed video id and views in prev max
                if(prevMax.second == views[i]){
                    if(prevMax.first > ids[i]) prevMax = {ids[i],views[i]}; 
                }
                m[creators[i]] = {prevViews + views[i], prevMax };
                highest_prority = max(highest_prority,prevViews + views[i]);
            }
            else {
                m[creators[i]] = {views[i], {ids[i], views[i]}};
                highest_prority = max(highest_prority, views[i]);
            }
        }
        for(auto i : m ){
            if(i.second.first == highest_prority){      // 
                vector<string> temp;
                temp.push_back(i.first);
                temp.push_back(i.second.second.first);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};