
#include <string>
#include <set>
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    // ---------------------------------
    LinkedList<int> l;
    cout << "L: ";
    for(auto itr = l.begin(); itr != l.end(); ++itr)
        cout << *itr << "\t";
    cout << endl;
    l.add(1).add(2).add(3).add(4).add(5);
    cout << "L: ";
    for(auto itr = l.begin(); itr != l.end(); ++itr)
        cout << *itr << "\t";
    cout << endl;
    LinkedList<int>::iterator itri = l.begin();
    l.remove(itri);
    l.remove(++itri);
    cout << "L: ";
    for(const auto& x: l)
        cout << x << "\t";
    cout << endl;
    // ---------------------------------
    double Ad1[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
    double Ad2[] = { 3.1, 4.2, 5.3, 6.4, 7.5, 8.6 };
    LinkedList<double> ld1(Ad1, Ad1 + 5);
    decltype(ld1) ld2(Ad2, Ad2 + 6);
    cout << "L1: " << ld1 << endl;
    cout << "L2: " << ld2 << endl;
    ld1 = ld2;
    cout << "L1: " << ld1 << endl;
    cout << "L2: " << ld2 << endl;
    ld1.add(0.6).add(0.7).add(0.8);
    auto itrd2 = ld2.begin();
    ld2.remove(itrd2);
    ld2.remove(++itrd2);
    ld2.remove(++++itrd2);
    ld2.remove(++++++itrd2);
    cout << "L1: " << ld1 << endl;
    cout << "L2: " << ld2 << endl;
    // ---------------------------------
    std::set<std::string> v;
    v.insert("Stuart");
    v.insert("Kevin");
    v.insert("Bob");
    LinkedList<std::string> ls1(v.begin(), v.end()), ls2;
    for(const auto s: ls1)
        ls2.add(s);
    cout << "LS1: " << ls1 << endl;
    cout << "LS2: " << ls2 << endl;
    ls1.add("Dave").add("Jerry");
    ls2.add("Banana");
    cout << "LS1: " << ls1 << endl;
    cout << "LS2: " << ls2 << endl;
    ls1.remove(ls1.begin()).remove(ls1.begin());
    ls2.remove(ls2.begin());
    cout << "LS1: " << ls1 << endl;
    cout << "LS2: " << ls2 << endl;
    return 0; }
