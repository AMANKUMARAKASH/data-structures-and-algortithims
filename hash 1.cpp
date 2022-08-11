#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
int maximumFrequency(vector<int> &arr ,int n){
    unordered_map<int,int> count;
    int MaxFreq=0;
    int maxans=0;


    for(int i=0; i<arr.size(); i++){
        count[arr[i]]++;
     MaxFreq=max(MaxFreq,count[arr[i]]);
 
    }
    for(int i =0; i<arr.size();i++){
        if(MaxFreq==count[arr[i]]) {
            maxans=arr[i];
            break;

        }
    }
}
int main(){
    return 0;

}