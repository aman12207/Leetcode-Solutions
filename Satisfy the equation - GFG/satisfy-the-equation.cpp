//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        map<int,vector<pair<int,int>>>m;
        for(int i = 0;i<N;i++){
            for(int j = i+1;j<N;j++){
                m[A[i] + A[j]].push_back({i,j});
            }
        }
        vector<int> ans;
        for(auto i : m){
            if(i.second.size()>1){
                ans.push_back(i.second[0].first);
                ans.push_back(i.second[0].second);
                ans.push_back(i.second[1].first);
                ans.push_back(i.second[1].second);
                return ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends