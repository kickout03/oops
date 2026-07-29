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
class complex;
class A{
    private:
    static int g;
    int a;
    public:
    int x;
    
    A(int a,int x){
        this->x=x;
        this->a=a;
    }
    
    
    friend void showp(complex,A);
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
    complex(/* args */){
        cout<<"built it"<<endl;;
    }
    ~complex(){}
    void setdata(int x,int y){
        a=x;
        b=y;
    }
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
        cout<<"p="<<p<<endl;
    }

    complex add(complex c){
        complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }

    void helloData();
    friend void helloData2(complex);
    //A friend function has no this pointer because it is not a member of the class. So it doesn't know which object's data it should access.

    friend void showp(complex,A);

    static void changeP(int x){
        // cout<<a<<endl; // we cannot access non static member variable in static member function
        cout<<"update valure of p through static func to p = " << x<<endl;
        p=x;
    }
};
void complex::helloData(){
    cout<<"p value "<<p<<endl;
    cout<<a<<" "<<b<<endl;;//here it got acces of member variable of object
}
void helloData2(complex c){
    //cout<<"p value "<<p<<endl; so in friend fun static member notf assec
    cout<<c.a<<" "<<c.b<<endl;
    cout<<"p="<<c.p<<endl;// since p is public so it can be call herwe
}

void showp(complex c,A a){
    cout<<"it is friend function of both class so it can access all private and public member of both class"<<endl;
    cout<<"complex class a="<<c.a<<" b="<<c.b<<" p="<<c.p<<endl;
    cout<<"A class a="<<a.x<<" g="<<a.g<<endl;
}

void func(){
    int x=6;
    static int y=6;
    cout<<x<<" "<<y<<endl;
}

int complex::p=3;//static variable has to define outside func , else it will give error

int main()
{
    complex c1,c2;
    // complex c3 = complex(); 
    
    c1.setdata(3,4);
    // c1.showData();
    // c3.setdata(1,2);
    // c3.showData();
    // c1.helloData();
    // c2=c1.add(c3);
    // c2.showData();
    complex::p = 4; // means we can change the value of static variable through static member function
    cout<<"this statis variable  directly can call with out any object p = "<<complex::p<<endl;
    // cout<<y<<endl; // we can not access static variable directly without class name
    func();
    complex::changeP(5);// means we can change the value of static variable through static member function
    // cout<<"p = "<<complex::p<<endl;
    helloData2(c1);
    // cout<<<<endl;
    // cout<<y<<endl;  // we connot print y it still exsit , but it is in scope of fuc
    cout<<endl;
  
    A a(2,3);
    //cout<<A::g<<endl; // we cannot access static private member directly with class name
    cout<<a.x<<endl;
    // cout<<a.g<<endl;// static public
    // cout<<a.a<<endl;// private
    a.showall();

    showp(c1,a);

    return 0;
}