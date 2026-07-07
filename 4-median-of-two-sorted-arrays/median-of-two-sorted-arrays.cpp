class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>temp(m+n);

        int i=0,j=0,k=0;

        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                temp[k++]=nums1[i++];
            }else{
                temp[k++]=nums2[j++];
            }
        }
            while(i<m){
                temp[k++]=nums1[i++];
            }
            while(j<n){
                temp[k++]=nums2[j++];
            }
            int sizeArr=m+n;
            //odd ke liye hai
            if(sizeArr%2==1){
                return temp[sizeArr/2];
            }
          //even ke liye hai
        return (temp[sizeArr/2]+temp[(sizeArr/2)-1])/2.0;       
    }
};