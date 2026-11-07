class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         int f=0,t=0;
         for(int i=0;i<bills.size();i++){
            if(bills[i]==5) f++;
            else if(bills[i]==10){
              if(f==0) return false;
              t++,f--;
            }
            else{
                if(t==0&&f<3) return false;
                else if(f==0) return false;
                else{
                    if(t==0) f-=3;
                    else t--,f--;
                }
            }
         }
         return true;
    }
};