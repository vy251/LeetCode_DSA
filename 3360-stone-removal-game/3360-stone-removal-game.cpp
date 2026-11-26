class Solution {
public:
    bool canAliceWin(int n) {
        if(n==10) return true;
         if(n<10) return false;
         int required=10;
         while(n>=required){
            n-=required;
            required--;
         }
         return required%2!=0?true:false;
    }
};