class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        vector<vector<int>>result;
        for(int i=0;i<arr.size()-1;i++){
            ans=min(ans,arr[i+1]-arr[i]);
        }

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==ans){
                result.push_back({arr[i],arr[i+1]});
            }
        }
        return result;
    }
};