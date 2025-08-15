class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<int,int>m1,m2;
        unordered_set<int>s1,s2;
        priority_queue<pair<int,int>>q1, q2;
        
        for(auto word : word1) m1[word]++;
        for(auto word : word2) m2[word]++;
        
        for(auto m : m1)s1.insert(m.first);
        for(auto m : m2)s2.insert(m.first);

        if(s1!=s2) return false;

        for(auto m : m1) q1.push({m.second,m.first});
        for(auto m : m2) q2.push({m.second,m.first});

        
        while(!q1.empty() && !q2.empty()){
            if(q1.top().first!=q2.top().first) return false;
            q1.pop();
            q2.pop();
        }
        return (q1.empty()&&q2.empty());
        
    }
};