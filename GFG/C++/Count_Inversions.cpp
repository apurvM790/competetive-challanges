class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long l,long long mid,long long e, long long arr[]){
        long long i=l,j=mid+1,k=0;
        long long n=e-l+1;
        long long b[n];
        long long c=0;
        
        while (i<=mid and j<=e){
            if(arr[i]<=arr[j]){
                b[k]=arr[i];
                i++;k++;
            }
            else{
                b[k]=arr[j];
                c+=mid-i+1;
                j++;k++;
            }
        }
        
        while (i<=mid){
            b[k]=arr[i];
            i++;k++;
        }
        
        while (j<=e){
            b[k]=arr[j];
            j++;k++;
        }
        
        for(int p=0;p<n;p++){
            arr[p+l]=b[p];
        }
        return c;
        
    }
    long long mergeSort(long long strt,long long end,long long arr[]){
        if (strt<end)
        {
            long long mid=(strt+end)/2;
            long long ans1=mergeSort(strt,mid,arr);
            long long ans2=mergeSort(mid+1,end,arr);
            
            long long ans=merge(strt,mid,end,arr);
            return ans+ans1+ans2;
        }
        return 0;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long l=0,h=N-1;
        return mergeSort(l,h,arr);
    }

};
