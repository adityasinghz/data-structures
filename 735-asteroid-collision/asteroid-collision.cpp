class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>stk;
         
        for(auto ast : asteroids){
            bool alive  = true;

            while(!stk.empty() && ast < 0 && stk.back() > 0){
                if(abs(ast) > stk.back()) stk.pop_back();

                else if(abs(ast) < stk.back()){ alive = false; break;}

                else if(abs(ast)==stk.back()){stk.pop_back(); alive =false;break;}
            }
            if(alive) stk.push_back(ast);
        }
        return stk;

    }
};