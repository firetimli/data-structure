#include <iostream>
using namespace std;

class face {
public:
  void setName(string n);
  string getName();

private:
  string name;
  //PNG pic;
  //boolean done;
};

void face::setName(string n){
  name = n;
}

string face::getName(){
  return name;
}

int main(){
  face a, b;
  a = b;
  a.setName("ann");
  cout << a.getName() << endl;
}
