class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        
        //Naive solution
        sort(arr, arr + N);
        int cnt = 1;
        int ans = 1;
        for(int i = 1; i < N; i++){
            if(arr[i - 1] + 1 == arr[i]){
                cnt++;
                ans = max(cnt, ans);
            }
            else if(arr[i] == arr[i - 1]){
                continue;
            }
            else{
                cnt = 1;
            }
        }
        return ans;
    }
};
