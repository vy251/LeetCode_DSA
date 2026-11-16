class Solution {
public:
    int check(vector<vector<int>>&m,int mid,int n){
        int r=n-1,c=0;
        int count=0;
        while(r>=0&&c<n){
            if(m[r][c]<=mid){
                count+=r+1;
                c++;
            }
            else r--;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int i=matrix[0][0],j=matrix[n-1][n-1];
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(check(matrix,mid,n)>=k){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};