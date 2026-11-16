class Solution {
public:
    int guess(vector<vector<int>>&matrix,int n,int mid){
        int i=n-1,j=0;
        int count=0;
        while(i>=0&&j<n){
            if(matrix[i][j]>mid){
               i--;
            }
            else{
                count+=i+1;
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int i=matrix[0][0];
        int j=matrix[n-1][n-1];
        int res=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(guess(matrix,n,mid)>=k){
                res=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return res;
    }
};