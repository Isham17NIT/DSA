class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) 
    {
        int n=code.size();
        regex r("^[A-Za-z0-9_]+$");
        set<string> validLines={"electronics", "grocery", "pharmacy", "restaurant"};

        vector<pair<string,string>> coupons;
        vector<string> ans;

        for(int i=0;i<n;i++)
        {
            if(isActive[i] && regex_match(code[i], r) && validLines.find(businessLine[i])!=validLines.end())
                coupons.push_back({code[i], businessLine[i]});
        }

        sort(coupons.begin(),coupons.end(),[](pair<string,string> p1, pair<string,string> p2){
            if(p1.second==p2.second)
                return p1.first < p2.first;
            return p1.second < p2.second;
        });

        for(pair<string,string> p : coupons)
        {
            ans.push_back(p.first);
        }
        return ans;
    }
};