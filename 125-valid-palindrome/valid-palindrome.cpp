class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(auto& i : s){
            int temp = static_cast<int>(i);
            if((temp >= 65 && temp <= 90) || (temp >= 97 && temp  <= 122) || (temp >= 48 && temp <= 57)){
                res += i;
            }
        }
        transform(res.begin(), res.end(), res.begin(), [](char c){
            return static_cast<char>(tolower(c));
        });
        int n = res.size();
        for(int i = 0; i < n/2; i++){
            if(res[i] != res[n-1-i]) return false;
        }
        return true;
    }
};