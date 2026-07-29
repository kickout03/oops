#include <iostream>
using namespace std;


class complex
{
private:
    int a,b;
    public:
    complex(){}// default constructor
    complex(int x,int y){// parameterize const
        cout<<"built it"<<endl;
        a=x;
        b=y;
    }
   
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    
    // friend void func(complex);
    friend ostream& operator<<(ostream& ,complex& );
    friend istream& operator>>(istream&,complex&);
};
ostream& operator<<(ostream& os, complex& c) {
    os << "a=" << c.a << " b=" << c.b <<endl;;
    return os;
}

istream& operator>>(istream& is, complex& c) {
    is >> c.a >> c.b;
    return is;
}



int main()
{
    complex c1(2,4);
    complex c2;
    cin>>c2;
    cout<<c2;
    c1.showData();    return 0;
}

