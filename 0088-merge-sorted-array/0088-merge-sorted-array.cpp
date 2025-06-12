class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums3(m+n);
    int i=0, j=0, k=0;
    while(i < m && j < n) {
        if(nums1[i] <= nums2[j]) {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        else {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
    }
    while(i < m) {
        nums3[k] = nums1[i];
        i++;
        k++;
    }

    while(j < n) {
        nums3[k] = nums2[j];
        j++;
        k++;
    }

for(int i=0; i<nums1.size(); i++) {
    nums1[i] = nums3[i];
}

    }
};


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i=0; i<nums2.size(); i++) {
//             nums1[m+i] = nums2[i];
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };