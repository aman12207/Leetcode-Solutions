//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int> m;        // it contains alphabets of both case so we can't rely on vector
          for(int i =0;i<n;i++){
              m[x[i]] = b[i];
          }
          int sum = 0, max_sum = INT_MIN;
          string ans = "",curr = "";
          for(auto i : w){
              curr.push_back(i);
              if(m.find(i) == m.end())
                sum += i;
              else sum += m[i];         // it means it has redefined ascii value
              if(sum>max_sum){
                  ans = curr;
                  max_sum = sum;
              }
              if(sum<0 ){
                sum = 0;
                curr = "";
              }
          }
            return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends