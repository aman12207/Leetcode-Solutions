class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, n= nums.size();
        vector<int> preProd(n,0), suffProd(n,0);        // finding prefix product and suffixt product and then finding prod for each index
        preProd[0]=(nums[0]);
        suffProd[n-1] = (nums[n-1]);
        for(int i = 1;i<n;i++){     
            preProd[i] = preProd[i-1] * nums[i];
        }
        for(int i = n-2;i>=0;i--){     
            suffProd[i] = suffProd[i+1] * nums[i];
        }
        for(int i = 0;i<n;i++){
            int prod = 1;
            if(i >0){
                prod*= preProd[i-1];
            }
            if(i < n-1){
                prod*= suffProd[i+1];
            }
            nums[i] = prod;
        }
        return nums;
    }
};