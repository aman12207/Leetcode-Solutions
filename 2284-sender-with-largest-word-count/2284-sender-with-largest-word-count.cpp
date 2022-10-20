class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        int n = senders.size();
        for(int i =0;i<n;i++){
            stringstream sobj ;
            string sender = senders[i];
            sobj<<messages[i];
            string word = "";
            while(!sobj.eof()){
                getline(sobj,word,' ');
                m[sender] ++;
            }
        }
        string ans = "";
        int count = 0;
        for(auto i : m){
            if(count<= i.second){
                ans = i.first;
                count = i.second;
            }
        }
        return ans;
    }
};