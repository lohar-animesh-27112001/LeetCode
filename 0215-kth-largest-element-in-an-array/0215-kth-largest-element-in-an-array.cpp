class Solution {
private:
    int maxElement(vector<int>& arr, int n) {
        int temp = INT_MIN;
        for(int i = 0; i < n; i++)
            if(temp < arr[i]) temp = arr[i];
        return temp;
    }
    void countSort(vector<int>& arr, int n, int exp) {
        int output[n];
        int i, count[10] = {0};
        for(int i = 0; i < n; i++) 
            count[(arr[i] / exp) % 10]++;
        for(int i = 1; i < 10; i++)
            count[i] += count[i-1];
        for(int i = n-1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for(int i = 0; i < n; i++)
            arr[i] = output[i];
    }
    void radixSort(vector<int>& arr, int n) {
        int max = maxElement(arr, n);
        for(int i = 1; max / i > 0; i *= 10)
            countSort(arr, n, i);
    }
    int getMin(vector<int>& arr, int n) {
        int temp = INT_MAX;
        for(int i = 0; i < n; i++)
            if(temp > arr[i])
                temp = arr[i];
        return temp;
    }
    void printArr(vector<int>& arr, int n) {
        for(int i= 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int min = getMin(nums, n);
        vector<int> arr = nums;
        if(min < 0)
            for(int i = 0; i < n; i++)
                arr[i] = nums[i] + (min * (-1));
        radixSort(arr, n);
        // printArr(arr, n);
        if(min < 0)
            return arr[n-k] - (min * (-1));
        return arr[n-k];
    }
};