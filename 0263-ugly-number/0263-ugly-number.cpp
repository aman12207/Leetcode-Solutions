class Solution {
public:
    bool isUgly(int n) {
        // A non-positive integer cannot be ugly
        if (n <= 0) {
            return false;
        }
        while(n>0 && n%2 == 0){
            n/=2;
        }
        while(n>0 && n%3 == 0){
            n/=3;
        }
        while(n>0 && n%5 == 0){
            n/=5;
        }
        return n == 1;
    }
};