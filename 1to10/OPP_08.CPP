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
        cout<<"built it class A"<<endl;;
        this->x=x;
        this->a=a;
    }
    ~A(){// after program complete , it auto matically call destrut , ad object destroyed
        cout<<"destroy it class A"<<endl;
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
    A *x;
    static int p;
    complex(int x,int y) : x(new A(0,0)) {// parameterize const
        cout<<"built it"<<endl;
        a=x;
        b=y;
    }
    complex() : x(new A(0,0)) {//deafualt constructor
        cout<<"built it"<<endl;
        x->showall();
    }

    // there is bydeafult ccopy const
    // we can also make it
    complex(complex &c) : x(new A(*c.x)) {//copy constructor
        cout<<"called"<<endl;
        a=c.a;
        b=c.b;
    }

    ~complex(){// after program complete , it auto matically call destrut , ad object destroyed
        cout<<"destroy it"<<endl;
         // we can also delete the object of class A which is created in constructor
        delete x;
    }
   
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }

    complex add(complex c){// when you call it called prints as vale of c1 copes;
        complex temp(0,0);
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }
};
void func(){
    complex c1(2,3);
    A *a = new A(2,3);
    c1.showData();
    a->showall();
    delete a; // if we do not delete it , then destructor will not be called for dynamically allocated object
}

int main()
{
    int t;
    // complex c1(2,4);
    complex c2;
    complex c3 = c2;
    c3.x->showall();
    // c1.showData();
    // func();
    // cin>>t;
    // A b (2,3);
    // b.showall();
    // cout<<t<<endl;

    return 0;
}

// this is the output of this program

// built it
// a=2 b=4
// built it
// built it class A
// a=2 b=3
// it is a member fun so it can asses all private or public
// a=2 x=3 g=4
// destroy it
// 5
// built it class A
// it is a member fun so it can asses all private or public
// a=2 x=3 g=4
// 5
// destroy it class A
// destroy it

// we can clearly see that the destructor is called when the object goes out of scope,
//  and for dynamically allocated objects, we need to manually delete them to call the destructor.