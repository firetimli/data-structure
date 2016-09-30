#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        const Square & operator= (const Square & source);
        const Square & operator+ (const Square & source);
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;

};

Square::Square(){
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}


void Square::setName(string newName){name = newName;}
void Square::setLength(double newVal){*lengthptr = newVal;}
string Square::getName() const {return name;}
double Square::getLength() const {return *lengthptr;}

Square::Square(const Square & other){
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square const  & Square::operator=(const Square & source){
      name = source.name;
      lengthptr = new double;
      lengthptr = source.lengthptr;

      return *this;
}

Square const  & Square::operator+ (const Square & source){

      name = name + source.name;
      *lengthptr = this->getLength()+source.getLength();

      return *this;
}

Square::~Square(){
    delete lengthptr;
}


int main(){
    Square a;
    Square b = a;
    cout << b.getName() << endl;
    cout << b.getLength() << endl;
    Square c(a);
    Square d = a + b;
    cout << d.getName() << endl;
    cout << d.getLength() << endl;

    return 0;
}
