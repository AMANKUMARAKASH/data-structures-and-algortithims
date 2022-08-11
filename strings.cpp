#include<iostream>

using namespace std;

 int main(){
      char arr[]="WELCOME";
      for(int i=0; arr[i]!=0; i++){
        arr[i] = arr[i] + 32;
      }
      cout<<arr;

     return 0;

 }