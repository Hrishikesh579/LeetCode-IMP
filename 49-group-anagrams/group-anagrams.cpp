class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        vector<string> v = strs;
        vector<vector<string>> res;
        for(string& i : v) {
            sort(i.begin(), i.end());
        }
        int n = strs.size();
        for(int i = 0; i < n; i++){
            um[v[i]].push_back(strs[i]);
        }
        for(auto& i : um){
            res.push_back(i.second);
        }
        return res;
    }
};