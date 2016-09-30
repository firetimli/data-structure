#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int main(){
  cout << "please enter sin 's', or cos 'c' " << endl;
  char input;
  int number;
  bool not_valid = true;


  while(not_valid){
    cin >> input;

    if (input != 'c' && input !='s'){
      cout <<"please enter sin 's', or cos 'c' or quit" << endl;
      if(input == 'q'){
        return 0;
      }
    }
    else{
      cout << "please input number" << endl;
      cin >> number;
      not_valid = false;

    }
  }

  if(input == 's'){
    cout << sin(number) << endl;
  }
  else{
    cout << cos(number) << endl;
  }
}
