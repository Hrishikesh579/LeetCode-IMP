class Solution {
public:
    bool isPalindrome(string s) {
        // transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        //     return tolower(c);
        // });
        int n = s.size();
        int i = 0, j = n-1;
        while(i < j){
            while(i < j && !isalnum(static_cast<unsigned char>(s[i]))) i++;
            while(i < j && !isalnum(static_cast<unsigned char>(s[j]))) j--;
            if(tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j]))) return false;
            i++;
            j--;
        }
        return true;
    }
};