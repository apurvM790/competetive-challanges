class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            vector<int> mat;
            
            int i=0,j=0;
            while (i<n and j<n){
                if(ar1[i]<=ar2[j]){
                    mat.push_back(ar1[i]);
                    i++;
                }
                else{
                    mat.push_back(ar2[j]);
                    j++;
                }
            }
            while(i<n)
            {
                mat.push_back(ar1[i]);
                i++;
            }
            while(j<n)
            {
                mat.push_back(ar2[j]);
                j++;
            }
            //for(auto i:mat) cout<<i<<" ";
            //cout<<endl;
            int tot=(n*2);
            if(tot%2==1) {return mat[tot/2];}
            else return (mat[tot/2]+mat[tot/2-1]);
            
    }
};
