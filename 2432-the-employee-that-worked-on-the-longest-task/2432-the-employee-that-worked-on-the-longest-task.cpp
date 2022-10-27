class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = logs[0][0],maxm = logs[0][1];
        for(int i =1;i<logs.size();i++){
            int timeTaken = logs[i][1] - logs[i-1][1];      // time taken by employee to complete task
            if(maxm <= timeTaken){
                if(maxm == timeTaken)
                    ans = min(ans,logs[i][0]);
                else{
                    maxm = timeTaken;
                    ans = logs[i][0];
                }
            }
        }
        return ans;
    }
};