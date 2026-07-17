class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        //we have to make a array which stores count of elements which are smaller and equal to that element
        int n = arr.size();
        vector<int> ans(n);
        
        stack<pair<int,int>> st;
        for(int i = 0 ; i< n ; i++){
            if(st.empty()){
                ans[i] = -1;
            }
            else if(!st.empty() && st.top().first>arr[i]){
                ans[i]=st.top().second;
            }
            else if(!st.empty() && st.top().first<=arr[i]){
                while(!st.empty() && st.top().first<=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = -1;
                }
                else {
                    ans[i]=st.top().second;
                }
            }
            st.push({arr[i],i});
        }
        vector<int> v(n);
       for(int i = 0 ; i < n ; i++){
           v[i] = i-ans[i];
       }
       return v;
    }
};