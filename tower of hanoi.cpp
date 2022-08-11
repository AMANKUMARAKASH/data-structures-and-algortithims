#include<iostream>
using namespace std;
void towerofhonoi(int n ,char src, char dest, char helper){
    if(n==0){
        return;
    }
    towerofhonoi(n-1,src,helper, dest);
    cout<<"move from"<<src<<"to"<<dest <<endl;
    towerofhonoi(n-1,helper,dest,src);



    
}
int main(){
towerofhonoi(3,'a','b','c');
    return 0;
}