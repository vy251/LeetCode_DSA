class Solution {
public:
    long long smallestNumber(long long num) {
         if(num==0) return 0;
         vector<int>ans;
         bool m=false;
         long long a=num;
         if(num<0){
            num=abs(num);
            m=true;
         }
         int z=0;
         while(num>0){
            ans.push_back(num%10);
            if(ans.back()==0) z++;
            num/=10;
         }
         if(m==true){
            sort(ans.begin(),ans.end(),greater<int>());
         }
         else{
            sort(ans.begin(),ans.end());
            swap(ans[0],ans[z]);
         }
         long long newa=0;
         for(int i=0;i<ans.size();i++){
            newa=newa*10+ans[i];
         }
         return m?-newa:newa;
    }
};