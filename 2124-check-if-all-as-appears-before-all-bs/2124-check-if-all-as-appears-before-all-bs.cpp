class Solution {
public:
    bool checkString(string s) {
         bool ans=true;
         for(int i:s){
            if(i=='a'){
                if(ans==false) return false;
            }
            else ans=false;
         }
         return true;
    }
};