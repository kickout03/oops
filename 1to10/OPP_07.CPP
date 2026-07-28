#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_set>
#define ll long long
#define vll vector<long long>
#define pll pair<ll, ll>
#define omp map<ll, ll>
#define ump unordered_map<ll, ll>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rep0(i, n) for (ll i = 0; i < n; i++)
#define print(arr) \
    for (int i = 0; i < arr.size(); i++) \
        cout << arr[i] << ' ';
#define input(arr, n) \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
using namespace std;

class A{
    private:
    int a;
    static int g;
    public:
    int x;

    A(int a,int x){
        this->x=x;
        this->a=a;
    }

    void showall();


};
void A::showall(){
    cout<<"it is a member fun so it can asses all private or public"<<endl;
    cout<<"a="<<a<<" x="<<x<<" g="<<g<<endl;
}
int A::g=4;



class complex
{
private:
    int a,b;
    public:
    static int p;
    complex(int x,int y){// parameterize const
        cout<<"built it"<<endl;
        a=x;
        b=y;
    }
    complex(){//deafualt constructor
        cout<<"built it"<<endl;
    }

    // there is bydeafult ccopy const
    // we can also make it
    complex(complex &c){
        cout<<"called"<<endl;
        a=c.a;
        b=c.b;
    }

    ~complex(){}
   
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }

    complex add(complex c){// when you call it called prints as vale of c1 copes;
        complex temp(0,0);
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }

    void helloData();

    friend void helloData2(complex);

    static void changeP(int x){
        cout<<"update valure of p through static func"<<endl;
        p=x;
    }
};



void func(){
    int x=6;
    static int y=6;
    cout<<x<<" "<<y<<endl;
}

int complex::p=3;//static variable has to define outside func

int main()
{

    complex c1(2,3);
    complex c2;
    // c1.showData();
    // c2.showData();// garbage value come as no value passes

    complex c3(2,6);
    // c3.showData();

    c2=c3.add(c1);
    c2.showData();

    complex c4=c1;// copy constructor works
    // complex c5
    c4.showData();

    return 0;
}