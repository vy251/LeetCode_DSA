class Solution {
public:
    int floor(vector<int>& arr,int x){
        int low=0,high=arr.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x) return mid;
            if(arr[mid]<x){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=floor(arr,x),j=i+1;
        vector<int>ans;
        while(k>0&&i>=0&&j<arr.size()){
            if(abs(arr[i]-x)<=abs(arr[j]-x)){
                ans.push_back(arr[i]);
                i--;
            }
            else{
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        while(k>0&&i>=0){
            ans.push_back(arr[i]);
            i--;
            k--;
        }
        while(k>0&&j<arr.size()){
            ans.push_back(arr[j]);
            j++;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};