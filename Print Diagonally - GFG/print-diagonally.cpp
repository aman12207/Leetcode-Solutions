//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
	    vector<int> v;
		int i=0;
		int col=0;
	    int row=0,diff=0;
		while(v.size()<N*N){
		    col=i;
		    if(col>=N) diff=col-N+1;
		    row=0;
		    if(diff>0){
		        row=diff;
		        col=N-1;
		    }
		    while(col>=0){
		        v.push_back(A[row][col]);
		        col--;
		        row++;
		        if(row>=N) break;
		    }
		    i++;
		}
		return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends