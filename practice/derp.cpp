#include <iostream>
using namespace std;

int derp(int x,int n){
  if(n == 0){
    cout << "condition1" << endl;
    return 1;}
  if(n % 2 == 0){
    cout << "condition 2" << endl;
    return derp(x * x, n/2);
  }

  cout << "condition 3" << endl;

  return x * derp(x * x,(n-1)/2);
}


int main(){
  cout << derp(2,12) << endl;
}
