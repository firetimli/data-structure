#include <iostream>
#include <string>
using namespace std;

int main(){
  cout << "please type input" << endl;
  string input;

  while(1){
    cin >> input;

    if(input.compare("q\n") != 0){
      break;
    }
    else{
      if(input[0] == 'a' || input[0] == 'e' ||input[0] == 'i'|| input[0] == 'o' || input[0] == 'u'|| input[0] == 'y'){
        input += "ay";
      }
      else{
        char temp = input[0];
        int index = input.length()-1;
        for(int i = 0; i < index; i++){
          input[i] = input[i+1];
        }

        input[index] = temp;

        input += "ay";
      }
      cout << input << endl;
    }

  }

  return 0;

}
