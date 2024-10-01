//Write a C++ class that is derived from the Progression class to produce a progression where each value is the square root of the
//previous value. (Note that you can no longer represent each value with an integer.) You should include a default constructor that 
//starts with 65,536 as the first value and a parametric constructor that starts with a specified (double) number as the first value.  
#include<iostream>
using namespace std;
class progretion{
    public:
    progretion(){
        a=65536;
    }

};
class FinalProgression : public Progression{
    public:
    FinalProgression(){
        a=x;
    }
};
int main(){
    FinalProgression p;
    cout<<p.a<<endl;
    return 0;
}