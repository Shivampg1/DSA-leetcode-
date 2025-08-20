class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>0){
            int digit=num%10;
            sum=sum+digit;
            num=num/10;
        }
        if(sum>=10){
           return addDigits(sum);
        }
        return sum;
    }
};