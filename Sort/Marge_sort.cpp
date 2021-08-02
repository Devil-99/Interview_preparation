#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int temp1[n1],temp2[n2];
    for(int i=0;i<n1;i++)
    temp1[i]=a[left+i];
    for(int i=0;i<n2;i++)
    temp2[i]=a[mid+i+1];

   int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(temp1[i]<temp2[j])
            a[k++]=temp1[i++];
        else
            a[k++]=temp2[j++];
    }
    while(i<n1)
    a[k++]=temp1[i++];
    while(j<n2)
    a[k++]=temp2[j++];

}

void merge_sort(int a[],int left,int right)
{
    while(left<right)
    {
        int mid=(right+left)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);

        merge(a,left,mid,right);
    }
}
int main() {
    int arr[]={5,3,2,4,1};
    int n=5;
    merge_sort(arr,0,4);

    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";

    return 0;
}