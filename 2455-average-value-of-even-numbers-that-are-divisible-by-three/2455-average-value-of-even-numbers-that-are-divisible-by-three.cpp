class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for(auto i :nums){
            if(i%2 == 0){       // even
                int temp = i,tempsum = 0;
                while(temp!=0){
                    tempsum += temp%10;
                    temp/=10;
                }
                if(tempsum%3==0){   // divisible by 3
                    count ++;
                    sum += i;
                }
            }
        }
        if(count == 0) return 0;        // n/0 will throw error
        return sum/count;
    }
};