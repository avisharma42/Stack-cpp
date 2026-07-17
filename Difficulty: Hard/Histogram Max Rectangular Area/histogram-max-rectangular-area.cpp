class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        //next greater to left 
        int n = arr.size();
        vector<int> left(n);
        stack<pair<int,int>> st;
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                left[i] = -1;
            }
            else if(!st.empty() && st.top().first<arr[i]){
                left[i] = st.top().second;
            }
            else if(!st.empty() && st.top().first>=arr[i]){
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    left[i] =-1;
                }
                else{
                    left[i] = st.top().second;
                }
            }
            st.push({arr[i],i});
        }
        vector<int> right(n);
        stack<pair<int,int>> st2;
        for(int i = n-1 ; i >=0 ; i--){
            if(st2.empty()){
                right[i] = n;
            }
            else if(!st2.empty() && st2.top().first<arr[i]){
                right[i] = st2.top().second;
            }
            else if(!st2.empty() && st2.top().first>=arr[i]){
                while(!st2.empty() && st2.top().first>=arr[i]){
                    st2.pop();
                }
                if(st2.empty()){
                    right[i] =n;
                }
                else{
                    right[i] = st2.top().second;
                }
            }
            st2.push({arr[i],i});
        }
        vector<int> width(n);
        for(int i = 0 ; i < n ; i++){
            width[i] = right[i]-left[i]-1;
        }
        vector<int> area(n);
        for(int i =0 ; i< n ;i++){
            area[i] = arr[i]*width[i];
        }
        int mx = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            mx = max(mx , area[i]);
        }
        return mx;
    }
};
