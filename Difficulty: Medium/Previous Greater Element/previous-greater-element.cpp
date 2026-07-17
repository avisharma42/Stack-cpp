class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int> left(n);//agr aise size daloge to sort nhi krna padega at end
        for(int i = 0; i < n ; i++){
            if(st.empty()){
                left[i] =-1;
            }
            else if(!st.empty() && st.top()>arr[i]){
                left[i]=st.top();
            }
            else if(!st.empty() && st.top()<=arr[i]){
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                 if(st.empty()){
                     left[i] = -1;
                 }
                 else{
                     left[i] = st.top();
                 }
            }
            st.push(arr[i]);
        }
        return left;
    }
};