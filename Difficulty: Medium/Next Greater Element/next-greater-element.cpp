class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> right(n);
        for(int i = n-1 ; i>=0 ; i--){
            if(st.empty()) right[i]=-1;
            else if(!st.empty() && st.top()>arr[i]){
                right[i]=st.top();
            }
            else if(!st.empty() && st.top()<=arr[i]){
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    right[i]=-1;
                }
                else{
                    right[i] = st.top();
                }
            }
            st.push(arr[i]);
        }
        return right;
    }
};