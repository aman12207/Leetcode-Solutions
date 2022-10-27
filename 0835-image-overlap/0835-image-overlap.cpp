class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int row = img1.size(),col = img1[0].size();
        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){     // trying to shift all the places
                int count1 = 0,count2 = 0,count3 = 0,count4 = 0;
                for(int r = 0;r+i<row;r++){
                    for(int c = 0;c+j<col;c++){
                        if(img1[r+i][c+j] == 1 && img2[r][c] == 1){     // right down
                            // cout<<(r+l)<<' '<<r<< " " << (c+j)<<' '<<c<<endl;
                            count1++;
                        }
                        if(img2[r+i][c+j] == 1 && img1[r][c] == 1){     // left up
                            count2++;
                        }
                    }
                }
                for(int r = i;r<row;r++){
                    for(int c = 0;c+j<col;c++){
                        // cout<<r+i<<c+j<<' ';
                        if(img1[r-i][c+j] == 1 && img2[r][c] == 1){     // shifing in up right
                            count3++;
                        }
                        if(img2[r-i][c+j] == 1 && img1[r][c] == 1){    // shifing in bottom left direction 
                            count4++;
                        }
                    }
                    // cout<<endl;
                }
                ans = max(ans,max(count1,max(count2,max(count3,count4))));
            }
        }
        return ans;
    }
};