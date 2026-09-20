// -------------------------------------------------------Valid Approach---------------------------------------------------------------------
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         vector<string> v, vEven;
//         int n = s.size();
//         for(int i = 0; i < n; i++){
//             int a = i-1, b = i+1;
//             while(a >= 0 && b < n){
//                 if(s[a] != s[b]) break;
//                 a--;
//                 b++;
//             }
//             a++, 
//             b--;
//             v.push_back(s.substr(a, (b-a+1)));
//         }
//         int maxCount = INT_MIN, maxIndex = -1;
//         int m = v.size();
//         for(int i = 0; i < m; i++){
//             int temp = v[i].size();
//             maxCount = max(maxCount, temp);
//             if(maxCount == temp) maxIndex = i;
//         }
//         for(int i = 0; i < n; i++){
//             int a = i, b = i+1;
//             while(a >= 0 && b < n){
//                 if(s[a] != s[b]) break;
//                 a--;
//                 b++;
//             }
//             a++;
//             b--;
//             vEven.push_back(s.substr(a, (b-a+1)));
//             a = i-1, b = i;
//             while(a >= 0 && b < n){
//                 if(s[a] != s[b]) break;
//                 a--;
//                 b++;
//             }
//             a++;
//             b--;
//             vEven.push_back(s.substr(a, (b-a+1)));
//         }
//         int maxCount2 = INT_MIN, maxIndex2 = -1;
//         int o = vEven.size();
//         for(int i = 0; i < o; i++){
//             int temp = vEven[i].size();
//             maxCount2 = max(maxCount2, temp);
//             if(maxCount2 == temp) maxIndex2 = i;
//         }
//         // if(maxIndex == -1 && maxIndex2 == -1) return "";
//         if(maxIndex == -1 && maxIndex2 != -1) return vEven[maxIndex2];
//         else if(maxIndex != -1 && maxIndex == -1) return v[maxIndex];
//         else if(maxIndex != -1 && maxIndex != -1){
//             int maximum = max(maxCount, maxCount2);
//             if(maximum == maxCount) return v[maxIndex];
//             else return vEven[maxIndex2];
//         }
//         return "";
//     }
// };

//------------------------------------------------------------Optimal Approach---------------------------------------------------------------

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(s.empty()) return "";
        int start = 0, maxLength = 0;

        auto expandAroundCenter = [&](int left, int right){
            while(left >= 0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }
            return right - left -1;
        };

        for(int i = 0; i < n; i++){
            int lenOdd = expandAroundCenter(i, i);
            int lenEven = expandAroundCenter(i, i+1);

            int len = max(lenOdd, lenEven);

            if(len > maxLength){
                maxLength = len;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, maxLength);
    }
};