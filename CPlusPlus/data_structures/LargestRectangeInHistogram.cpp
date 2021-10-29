/* In this solution, we are calculating the 
1. index of Next smaller element to the left (nsel), for each of the element of array (Line 12-29)
2. index of Next smaller element to the right (nser), for each of the element of array (Line 31 - 49)
3. then fetching the nsel and nser index in two separate arrays (nselIndex and nserInder) (Line 53-54)
4. then calculation the area of all possible rectangles and storing it in a separate array (ans) (Line 58-59)
5. then checking the maximum area and returning it (max) (Line 60-64) */


class Solution {
public:

    vector <int> nsel(vector<int> arr, int n){
        vector<int> nselIndex;
        stack<pair<int, int>> s;

        for(int i=0; i<n; i++){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                nselIndex.push_back(-1);
            }
            else{
                nselIndex.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return nselIndex;
    }

    vector <int> nser(vector<int> arr, int n){
        vector<int> nserIndex;
        stack<pair<int, int>> s;

        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                nserIndex.push_back(n);
            }
            else{
                nserIndex.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(nserIndex.begin(), nserIndex.end());
        return nserIndex;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nselIndex =  nsel(heights, n);
        vector<int> nserIndex =  nser(heights, n);
        vector<int> ans;
        int max = INT_MIN;

        for(int i=0; i<n; i++){
            ans.push_back((nserIndex[i] - nselIndex[i] - 1) * heights[i]);
            if(max < ans[i]){
                max = ans[i];
            }
        }
        return max;
    }
};
