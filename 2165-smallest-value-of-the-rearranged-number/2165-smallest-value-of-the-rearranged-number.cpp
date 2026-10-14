class Solution {
public:
    long long smallestNumber(long long num) {
        bool m=false;
        vector<int>freq(10,0);
        long long a=num;
        if(num<0){
            num=abs(num);
            m=true;
        }
        while(num>0){
            int r=num%10;
            freq[r]++;
            num/=10;
        }
        long long newa=0;
        if(a>0){
           if(freq[0]>0){
           for(int i=1;i<10;i++){
              if(freq[i]>0){
                newa=i*10;
                freq[i]--;
                break;
              }
           }
           for(int i=1;i<freq[0];i++){
              newa=newa*10;
           }
        }
           for(int i=1;i<10;i++){
              for(int j=1;j<=freq[i];j++){
                 newa=newa*10+i;
              }
           }
        }
        else{
            for(int i=9;i>=0;i--){
              for(int j=1;j<=freq[i];j++){
                 newa=newa*10+i;
              }
            }
        }
        return m?-newa:newa;
    }
};