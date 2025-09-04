class Solution {
public:
    int findClosest(int x, int y, int z) {
        int i=abs(z-x);
        int j=abs(z-y);
      
        if(i<j){
            return 1;
        }
        if(i>j){
            return 2;
        }
        return 0;
    }
};