#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int getKthLargest(vector<int>&arr, int k){
    vector<int>sumstore;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+= arr[j];
            sumstore.push_back(sum);

        }
    }
    sort(sumstore.begin(),sumstore.end());
     return sumstore[sumstore.size()-k];

}

int main(){

    return 0;
}