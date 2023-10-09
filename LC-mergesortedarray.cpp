#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans1[m+n];
        int i=0,j=0;
        while(nums1.length()==i and nums2.size()==j){
            if(nums1[i]==0){
                i++;
            }
            if(nums2[j]==0){
                j++;
            }
            if(nums1[i]>=nums2[j]){
                ans1.pushback(nums2[j]);
                j++;
            }
            else{
                ans1.pushback(nums1[i]);
                i++;
            }
        }

        if(nums1!=i){
            while(nums1!=i){
                ans1.pushback(nums1[i]);
            }
        }
        if(nums2!=j){
            while(nums2!=j){
                ans1.pushback(nums2[j]);
            }
        }

        return ans1;
    }
};