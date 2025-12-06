class Solution {
public:
    void backtrack(int index, string &curr, string digits, unordered_map<char,string>&mapper, vector<string>&res){
     
     if(digits.size()==index){
         res.push_back(curr);
         return;
     }
     string alpha = mapper[digits[index]];
     for(int i=0;i<alpha.size();i++){
         curr.push_back(alpha[i]);
         backtrack(index+1,curr,digits,mapper,res);
         curr.pop_back();
      }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mapper;
        mapper['2']="abc";
        mapper['3']="def";
        mapper['4']="ghi";
        mapper['5']="jkl";
        mapper['6']="mno";
        mapper['7']="pqrs";
        mapper['8']="tuv";
        mapper['9']="wxyz";
        string curr;
        vector<string>res;
        backtrack(0,curr,digits,mapper,res);
        return res;
    }
};