/* C program for Merge Sort */
#include<stdio.h>
void merge(int arr[],int left,int mid,int right)
{
    int i,j,k;
    int size_left = mid - left + 1;
    int size_right = right - mid;
    int L[size_left], R[size_right];
    for(i=0;i<size_left;i++){
        L[i]=arr[left+i];
    }
    for(j=0;j<size_right;j++){
        R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<size_left && j<size_right){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<size_left){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<size_right){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int left,int right)
{
    if(left<right){
        int mid = left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

}
void printArray(int A[],int size)
{
    int i;
    for(i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {30,4,5,8,9,7,17,2};
    int length = sizeof(data)/sizeof(data[0]);
    merge_sort(data,0,length-1);
    printArray(data,length);
    return 0;
}
