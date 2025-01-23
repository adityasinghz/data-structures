class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>st;
        for(auto a: nums){
            st.insert(a);
        }
        int ct = 1;
        int ans = 0;
        while(!st.empty()){
            auto last = prev(st.end());
            int  topElement = *last;
            st.erase(last);

            if(!st.empty() && topElement-*prev(st.end())==1){
                cout<<topElement<<'-'<<*prev(st.end())<<'\n';
                ct++;
            }else{
                cout<<"break\n";
                ans = max(ans,ct);
                cout<<"ans "<<ans<<'\n';
                ct=1;
            }
        }
        return max(ans,ct);
    }
};