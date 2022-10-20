class Solution {
public:
    string intToRoman(int nums) {
        string ans = "";
        if(nums>= 1000){  // handled the thousand
            int first = nums/1000;
            nums = nums%1000;
            for(int i = 0 ;i<first;i++){
                ans.push_back('M');
            }
            nums %= 1000;
        }
        // cout<<nums<<' '<<ans<<endl;
        if(nums>=100){       // handled hunderedth
            if(nums >= 900){            // handled 900
                ans.push_back('C');
                ans.push_back('M');
            }
            else if(nums>=500){
                ans.push_back('D');
                nums %= 500;
                int first = nums/100;
                for(int i = 0 ; i<first;i++){       // handled 500 600 700 800
                    ans.push_back('C');
                }
            }
            else if(nums >= 400){           // 400
                ans.push_back('C');
                ans.push_back('D');
            }
            else {
                int first = nums/100;
                for(int i = 0 ; i<first;i++){       // handled 100 200 300
                    ans.push_back('C');
                }
            }
            nums %= 100;
        }
        // cout<<nums<<' '<<ans<<endl;
        if(nums>=10){
            if(nums >=90){      // 90
                ans.push_back('X');
                ans.push_back('C');
            }
            else if (nums >= 50){       // 50 60 70 80
                ans.push_back('L');
                nums %= 50 ;
                int first = nums / 10 ;
                for(int i = 0;i<first;i++){
                    ans.push_back('X');
                }
            }
            else if (nums >= 40){       // 40
                ans.push_back('X');
                ans.push_back('L');
            }
            else {
                int first = nums/10;    // 10 20 30
                for(int i = 0;i<first;i++){
                    ans.push_back('X');
                }
            }
                nums %= 10;
        }
        // cout<<nums<<' '<<ans<<endl;
        if(nums >= 1){
            if(nums == 9){          //9
                ans.push_back('I');
                ans.push_back('X');
            }
            else if (nums >= 5){        //5 6 7 8
                ans.push_back('V');
                nums -= 5;
                for(int i = 0 ;i<nums;i++){
                    ans.push_back('I');
                }
            }
            else if (nums == 4){            //4
                ans.push_back('I');
                ans.push_back('V');
            }
            else {
                for(int i = 0;i<nums;i++){      //1 2 3 
                    ans.push_back('I');
                }
            }
        }
            return ans;
    }
};