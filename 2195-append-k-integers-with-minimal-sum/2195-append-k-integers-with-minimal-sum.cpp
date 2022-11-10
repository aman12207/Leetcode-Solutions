class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long first = min(nums[0]-1, k);
        long long n = nums.size(), prevSum = ((first + 1) * first)/2 , nextSum = 0;
        long long ans = prevSum ;
        k-= first;          // took care of 0 - nums[0] numbers
        prevSum += first+1;
        for(int i = 1;i<n;i++){
            if(k <= 0) break;
            if(nums[i] > nums[i-1] && k>0){
                long long temp = min(nums[i]-1, nums[i-1] + k);     // storing the maxm no integers we can add
                nextSum = ((temp+1) * temp)/2;                 // prefix Sum
                ans += nextSum - prevSum;    
                // cout<<nums[i]<<' '<<temp<<' '<<prevSum<<' '<<nextSum<<" "<<ans<<endl;
                prevSum = nextSum + nums[i];                        // as next sum doesn't include nums[i] include it in prev sum
                k-= (nums[i]-nums[i-1] - 1);
            }
        }
        if(k>0){                                
            long long temp = nums[n-1];
            nextSum = ((temp+k) * (temp + k +1 ))/2;
            prevSum = (temp * (temp+1))/2;
            ans += nextSum - prevSum;
        }
        return ans;
    }
};