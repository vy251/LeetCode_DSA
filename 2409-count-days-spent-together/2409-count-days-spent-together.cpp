class Solution {
public:
    int convert(string date){
        vector<int>month={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mon=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        int td=0;
        for(int i=0;i<mon-1;i++){
            td+=month[i];
        }
        td+=day;
        return td;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
         int aa=convert(arriveAlice);
         int la=convert(leaveAlice);
         int ab=convert(arriveBob);
         int lb=convert(leaveBob);
         int md=max(aa,ab);
         int ld=min(la,lb);
         if(md<=ld){
            return ld-md+1;
         }
         return 0;
    }
};