#include <iostream>
using namespace std;

int myFun(const int &a){

  int *c = new int(a);
  int b=*c;
  return b;

}

int main(){
  int n = 8;

  cout << (myFun(n)) << endl;
}
