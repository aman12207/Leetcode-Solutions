//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string lower = "", upper = "";      // just create do different string of both case 
        // sort them and them merge them 
        for(auto i : str){
            if(i>= 'a' && i<= 'z'){
                lower.push_back(i);
            }
            else {
                upper.push_back(i);
            }
        }
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        int lpointer, upointer ;
        lpointer = upointer = 0;
        for(int i =0;i<n;i++){      // just merge them acc to place if it is a index where lower case is present 
        // then insert lower case element in sorted way same goes for upper case
            if(str[i]>= 'a' && str[i]<= 'z'){
                str[i] = lower[lpointer];
                lpointer++;
            }
            else {
                str[i] = upper[upointer];
                upointer++;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends