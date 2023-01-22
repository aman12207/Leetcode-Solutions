//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> longestPrefixSuffix(string s){
            int n = s.size();
            vector<int> lfs(n,0);
            int i = 1, len = 0;
            while(i<n){
                if(s[i] == s[len]){             // found lpf store it
                    len++;
                    lfs[i] = len;
                    i++;
                }
                else {
                    if(len == 0){               // no lpf found
                        lfs[i] = 0;             
                        i++;
                    }
                    else {
                        len = lfs[len-1];           // backtrack
                    }
                }
            }
            return lfs;
        }
        vector <int> search(string pat, string txt)
        {
            int n = txt.size(), m = pat.size();
            vector<int> lpf = longestPrefixSuffix(pat);
            int i = 0, j = 0;
            vector<int> ans;
            while((n-i)>= (m-j)){
                if(txt[i] == pat[j]){           // matching
                    i++;
                    j++;
                }
                if(j == m){ // pattern found
                    ans.push_back(i-m+1);           // push index
                    j = lpf[j-1];
                }
                else if(i<n && txt[i] != pat[j]){          // mismatch
                    if(j!=0){
                        j = lpf[j-1];         // backtrack
                    }
                    else i++;
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends