#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}


int searchInfiniteArray(vector<int>& arr, int target) {
    int low = 0;
    int high = 1;

    
    while (arr[high] < target) {
        low = high;
        high *= 2;
    }

    
    return binarySearch(arr, low, high, target);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int target = 6;

    int index = searchInfiniteArray(arr, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}


// Output is 

Element 6 found at index 5
