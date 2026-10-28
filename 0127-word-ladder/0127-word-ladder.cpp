class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
             auto p=q.front();
             q.pop();
             string word=p.first;
             int steps=p.second;
             if(word==endWord) return steps;
             for(char i=0;i<word.size();i++){
                 string temp=word;
                 for(char c='a';c<='z';c++){
                     temp[i]=c;
                     if(s.find(temp)!=s.end()){
                        q.push({temp,steps+1});
                        s.erase(temp);
                     }
                 }
             }
        }
        return 0;
    }
};