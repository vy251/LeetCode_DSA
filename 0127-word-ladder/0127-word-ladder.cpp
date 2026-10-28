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
                 char o=word[i];
                 for(char c='a';c<='z';c++){
                     word[i]=c;
                     if(s.find(word)!=s.end()){
                        q.push({word,steps+1});
                        s.erase(word);
                     }
                 }
                 word[i]=o;
             }
        }
        return 0;
    }
};