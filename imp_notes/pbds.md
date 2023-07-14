multi-ordered set
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
int main() {
multi_ordered_set <int> a;
    a.insert(1);
    a.insert(10);
    a.insert(10);
    a.insert(10);
    a.insert(10);
    a.insert(7);
    a.insert(5);
    cout << *a.find_by_order(2) << endl; //output is 7
    cout << *a.find_by_order(5) << endl; //output is 10
    cout << (a.order_of_key(10)) << endl; //output is 3
    cout << (a.order_of_key(11)) << endl; //output is 7
}
```
ordered set
```cpp

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ordered_set <int> a;
    a.insert(2);
    a.insert(4);
    a.insert(3);
    a.insert(7);
    a.insert(5);
    cout << *a.find_by_order(3) << endl; //output is 5
    cout << (a.order_of_key(10)) << endl; //output is 5
}
```
