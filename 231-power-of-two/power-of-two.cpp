class Solution {
public:
    bool isPowerOfTwo(int n) {
   int i=0;
   while(i<=31){
    if(n != pow(2,i)){
        i++;
    }
    else{
        return true;
    }
   }
   return false;
    }
};