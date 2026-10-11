class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;
        // stack<pair<int, int>> st;
        // vector<int> v(n);
        // for(int i = n-1; i >= 0; i--){
        //     if(i == n-1){
        //         pair<int, int> p = {height[i], i};
        //         st.push(p);
        //         v[i] = -1;
        //     } else{
        //         if(!st.empty() && st.top().first > height[i]) {
        //             v[i] = st.top().second;
        //             pair<int, int> p = {height[i], i};
        //             st.push(p);
        //         } else{
        //             if(!st.empty() && st.top().first == height[i]){
        //                 v[i] == st.top().second;
        //                 st.pop();
        //             pair<int, int> p = {height[i], i};
        //             st.push(p);
        //             } else{
        //                 while(!st.empty() && st.top().first < height[i]){
        //                     st.pop();
        //                 }
        //                 if(st.empty()) v[i] = -1;
        //                 else v[i] = st.top().second;
        //                 pair<int, int> p = {height[i], i};
        //                 st.push(p);
        //             }  
        //         }
        //     }
        // }
        // int trapped = 0;
        // int i = 0;
        // while(i < n){
        //     if(v[i] != -1){
        //         int temp = 0;
        //         int lim = min(height[i], height[v[i]]);
        //         for(int j = i+1; j < v[i]; j++){
        //             temp += lim - height[j];
        //         }
        //         trapped += temp;
        //         i = v[i];
        //     } else i++;
        // }
        // return trapped;
        vector<int> largestRight(n, -1), largestLeft(n, -1);
        int largest = -1;
        for(int i = 0; i < n; i++){
            if(height[i] > largest){
                largest = height[i];
            } else{
                largestLeft[i] = largest;
            }
        }
        largest = -1;
        for(int i = n-1; i >= 0; i--){
            if(height[i] > largest){
                largest = height[i];
            } else{
                largestRight[i] = largest;
            }
        }
        int trapped = 0;
        for(int i = 0; i < n; i++){
            if(largestRight[i] != -1 && largestLeft[i] != -1){
                trapped += min(largestRight[i], largestLeft[i]) - height[i];
            }
        }
        return trapped;
    }
};