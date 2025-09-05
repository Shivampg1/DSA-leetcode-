class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
       for(int i=1;i<=60;i++){
        long long k=num1-1ll*num2*i;

        if(k<i){
            return -1;
        }
        if(i>=__builtin_popcountll(k)){
            return i;
       }
       }
        return -1;
    }
};