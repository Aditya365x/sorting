#include <bits/stdc++.h>
using namespace std;
int binarySearchI(int arr[], int low, int high, int target){
    //binary search is always applied in the sorted array
    while(low < high){
        int mid = low +(high-low)/2;
        if(arr[mid]== target){
            return mid;
        }else if(arr[mid] < target){
            low = mid+1;
        }else if(arr[mid]> target){
            high = mid-1;
        }
    }
    return -1;
}
//binarySearchRecursiveImplementation
int binarySearchII(int arr[], int low, int high, int target){
    //binary search is always applied in the sorted array
    while(low < high){
        int mid = low +(high-low)/2;
        if(arr[mid]== target){
            return mid;
        }else if(arr[mid] < target){
           return  binarySearchII(arr,mid+1,high,target);
        }else if(arr[mid]> target){
            return binarySearchII(arr,0,mid-1,target);
        }
    }return -1;
   
}
int main(){
    int arr[] = {2,3,4,10,20,60,90};
    int target = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans1 = binarySearchI(arr,0,n-1,target);
    int ans2 = binarySearchII(arr,0,n-1,target);
    cout<<ans2;

}
