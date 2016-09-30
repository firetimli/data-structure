#include <iostream>
using namespace std;

class Student{
public:
  Student(){
    name = "Sally";
    grade = 5;
  };

  void access(){
    grade += 1;
    cout << name << " is in grade "  <<  grade << endl;
  };

private:
  string name;
  int grade;
};

void graduate( Student & new_student){
  new_student.access();
}

int main(){
  Student new_student;

  graduate(new_student);
}
