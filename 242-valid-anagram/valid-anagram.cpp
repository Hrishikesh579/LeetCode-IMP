class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        int n = s.size(), m = t.size();
        if(n != m) return false;
        for(int i = 0; i < n; i++){
            v[s[i] - 'a']++;
        }
        for(int i = 0; i < m; i++){
            v[t[i] - 'a']--;
        }
        for(int& i : v){
            if(i != 0) return false;
        }
        return true;
    }
};