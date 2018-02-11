// Find peak
int findPeakElement(vector<int>& nums) {
    
    if (nums.size() == 0) return -1;
    
    int i = 0, j = nums.size() - 1;
    
    while (i < j) {
        
        int mid = i + (j - i) / 2;
        if (nums[mid] < nums[mid+1]) {
            i = mid + 1;
        }
        else if (nums[mid] > nums[mid+1]) {
            j = mid;
        }
    }
    return i;
}


Triangle:
int minimumTotal(vector<vector<int>>& triangle) {
    
    vector<int> array = triangle.back();
    
    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            array[j] = triangle[i][j] + min(array[j], array[j+1]);
        }
    }
    
    return array[0];
}



class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0) return -1;
        
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            int mid = i + (j - i)/2;
            if (nums[mid] == target) return mid;
            
            else if (nums[mid] > nums[r]) {
                if (target >= nums[i] && target < nums[mid]) {
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            else if (nums[mid] < nums[l]) {
                if (target <= nums[j] && target > nums[mid]) {
                    i = mid + 1;
                }
                else j = mid - 1;
            }
            else {
                
            }
        }
        return -1;

        
    }
    
};


    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0) return -1;
        
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            int mid = i + (j - i)/2;
            if (nums[mid] == target) return mid;
            // mid at right
            else if (nums[mid] < nums[i]) {
                if (target > nums[mid] && target <= nums[j]) i = mid + 1;
                else j = mid - 1;
            }
            // mid at left
            else if (nums[mid] > nums[j]) {
                if (target >= nums[i] && target < nums[mid]) j = mid - 1;
                else i = mid + 1;
            }
            // no roataion
            else {
                if (nums[mid] < target) i = mid + 1;
                else j = mid - 1;
            }
        }
        return -1;

    }