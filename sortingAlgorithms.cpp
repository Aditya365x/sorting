#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr){//{11,2,22,34,32,112,903}
    int n = arr.size();
    //selection sort pushes the min at the front
    //in selection sort the min element will come in beginning first
    for(int i = 0; i<=n-2; i++){
        int min_idx = i;
        for(int j = i; j<=n-1; j++){
            if(arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);

    }
}
void bubble_sort(vector<int>& arr){
    int n = arr.size();
    //the max element will be accumulated at the end
    // what if the array is already sorted, then we have to prevent this from being swapped
    for(int i = n-1; i>=0; i--){
        int didswap = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap =1;
            }
        } if(didswap==0) break;

    }
} 
void Insertion_sort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i <= n-1; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
void merge_sort(vector<int> &arr, int high, int low){
    if(low>=high) return;
    int mid = (low + high)/2;
    merge_sort(arr,mid,low);
    merge_sort(arr,high, mid+1);
    merge(arr,low, mid, high);
}

//use partition1  to make the order ascending.
int partition1(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int left = low;
    int right = high;
    while(left< right){
    while(arr[left]<=pivot && left < high ){
        left++;
    }
    while(arr[right]>pivot && right > low){
        right--;
    }
     if(left < right){swap(arr[left], arr[right]);}
    }
    //now swapping the pivot index
    swap(arr[low],arr[right]);
    //and the pivot index will be at the index j
    //so
    return right;

}
//use partition 2 to make the order descending.
int partition2(vector<int>&arr, int low, int high){
    int pivot = arr[low];
    int left = low;
    int right = high;
    while(left<right){
        while(arr[left]>=pivot && left<high){
            left++;
        }
        while(arr[right]<pivot && right>low){
            right--;
        }
        if(left<right) swap(arr[left], arr[right]);
    }
    swap(arr[low],arr[right]);
    return right;
}
void quickSort(vector<int> &arr, int low, int high){
    if(low>high) return;
    if(low<high){
        int pIndex = partition2(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);

    }
}
int main(){
    vector<int>arr1 = {111111,211,22,34,32,112,903};
    quickSort(arr1,0,arr1.size()-1);
    for(int i = 0 ;i<arr1.size(); i++){
        cout<<arr1[i]<<" ";
    }
}
