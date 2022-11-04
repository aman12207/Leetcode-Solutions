class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        for(int i = 1;i<=10;i++){
            long long n = k*i;      // we have to find all possible value there will in table of k 
            //  if k is 7 then possible unit values are 
            // 7 4 1 8 5 2 9 6 3 0
            // then to get 7 at unit digit and sum whose last digit is 7
            // we have to take a set of atleast 1 positive integer
            // similarly for 4 we require atleast 2 
            // and for 1 we require atleast 3 
            // and so ont
            if(n>num) break;
            int last = n% 10;
            if(last == num%10) return i;
        }
        return -1;
    }
};