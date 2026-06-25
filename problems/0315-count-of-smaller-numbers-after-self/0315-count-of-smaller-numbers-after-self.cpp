class Solution {
public:
    vector<pair<int,int>>pp;
    vector<int>count;

    void merge(vector<pair<int,int>>& pp,int low,int mid,int high){
        int i=low;
        int j=mid+1;
        vector<pair<int,int>>ans;
        
        while(i<=mid && j<=high){
            if(pp[i].first>pp[j].first){
                count[pp[i].second]+=high-j+1;
                ans.push_back(pp[i]);
                i++;
            }
            else{
                ans.push_back(pp[j]);
                j++;
            }
        }

        while(i<=mid){
            ans.push_back(pp[i]);
            i++;
        }
        while(j<=high){
            ans.push_back(pp[j]);
            j++;
        }

        int x=0;
        for(int k=low;k<=high;k++){
            pp[k]=ans[x++];//?
        }
    }

    void mergeSort(vector<pair<int,int>>& pp,int low,int high){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        mergeSort(pp,low,mid);
        mergeSort(pp,mid+1,high);
        merge(pp,low,mid,high);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        count.assign(n,0);
        for(int i=0;i<n;i++){
            pp.push_back({nums[i],i}); //pp.push_back(make_pair(nums[i],i);
        }
        mergeSort(pp,0,n-1);
        return count;
    }
};