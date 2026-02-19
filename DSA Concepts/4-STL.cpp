#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

/* STL is of four parts :-
   1) Containers
   2) Iterators
   3) Algorithms
   4) Functors*/

/* 1) Containers
    i)Vector is a container.
    ii) Vector is a dynamic container.
    ii) All the things about vectors is in vectors file.*/

/* 2) Iterators
    i) Vector are also present in iterators.
    ii) functions => vec.begin() and vector.end().
    iii) begin() => points to first element.
    iv) end() => points to last nth space not last element.*/

bool comparator(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    if (p1.first < p2.second)
        return true;
    else
        return false;
}

int main()
{
    /* Sequential containers */

    // 1) Vector iterator
    cout << "Vector iterator\n"
         << endl;
    vector<int> arr = {1, 2, 3, 4, 5}; // {1,2,3,4,5,_} => _ => end element
    cout << "First element of arr : " << *(arr.begin()) << endl;
    cout << "last element of arr : " << *(arr.end()) << endl; // returns garbage value
    vector<int>::iterator it;                                 // store address of vector like pointer
    cout << "Printing a vector using iterator : ";
    for (it = arr.begin(); it != arr.end(); it++)
        cout << *(it) << " ";
    cout << endl;
    // backward loop
    // rbegin() , rend() are used.
    cout << "Reverse a vector using iterator : ";
    vector<int>::reverse_iterator it0;
    for (it0 = arr.rbegin(); it0 != arr.rend(); it0++)
        cout << *(it0) << " ";
    cout << endl;
    // (or)
    cout << "Printing a vector using auto keyword : ";
    for (auto it = arr.rbegin(); it != arr.rend(); it++)
        cout << *(it) << " ";
    cout << endl;

    // 2) LIST (doubly listed list) //
    // random access of element is not possible.
    cout << "\nLIST\n"
         << endl;
    // intializing a list
    list<int> List = {1, 2, 3, 4, 5};
    cout << "Elements of List : ";
    for (int val : List)
        cout << val << " ";
    cout << endl;
    list<int> l;
    // list functions
    l.push_back(19);
    l.emplace_back(25);
    l.push_back(29);
    l.push_front(3);
    l.push_front(2); // 2 3 19 25 29
    l.pop_back();    // 2 3 19 25
    l.pop_front();   // 3 19 25
    cout << "Elements of 'l' : ";
    for (int val : l) // o/p => 3 19 25
        cout << val << " ";
    cout << endl;
    // other functions we can perform are :-
    // size,erase,clear,begin,end,rbegin,rend,front,back
    // same as vectors

    // 3) DEQUE (Double Ended Queue) //
    // Similar to list but,random access of element is possible.
    cout << "\nDEQUE\n"
         << endl;
    // intializing a deque
    deque<int> Deque = {1, 2, 3, 4, 5};
    cout << "Elements of deque : ";
    for (int val : Deque)
        cout << val << " ";
    cout << endl;
    // random access
    cout << Deque[2] << endl;
    deque<int> d;
    // deque functions
    d.push_back(21);
    d.emplace_back(45);
    d.push_back(56);
    d.push_front(9);
    d.push_front(8); // 8 9 21 45 56
    d.pop_back();    // 8 9 21 45
    d.pop_front();   //  9 21 45
    cout << "Elements of 'd' : ";
    for (int val : d) // o/p => 9 21 45
        cout << val << " ";
    cout << endl;
    // other functions we can perform are :-
    // size,erase,clear,begin,end,rbegin,rend,front,back
    // same as vectors,lists.

    // 4) PAIR //
    cout << "\nPAIR\n"
         << endl;
    // intializing a pair
    // i) single pair
    pair<int, int> p = {10, 20};
    cout << "Elements of p : ";
    cout << p.first << " " << p.second << endl;
    pair<string, int> p1 = {"Tharun", 699};
    cout << "Elements of p1 : ";
    cout << p1.first << " " << p1.second << endl;
    // ii) nested pair
    pair<int, pair<char, int>> p2 = {2, {'s', 8}};
    cout << "Elements of p2 : ";
    cout << p2.first << " ";
    cout << p2.second.first << " " << p2.second.second << endl;
    // iii) Vector pair
    vector<pair<int, int>> vecPair = {{1, 2}, {2, 3}, {3, 4}};
    vecPair.push_back({4, 5});  // insert
    vecPair.emplace_back(5, 6); // creates in-place objects
    cout << "Elements of vecPair : \n";
    for (auto p : vecPair)
        cout << p.first << " " << p.second << endl;
    cout << endl;
    // output working :-
    // 1) {1,2} => p.first = 1, p.second = 2
    // 2) {2,3} => p.first = 2, p.second = 3
    // 3) {3,4} => p.first = 3, p.second = 4
    // so on....

    /* Non-sequential containers */

    // 1) Stack //
    // Last in First out structure
    cout << "\nSTACK\n"
         << endl;
    stack<int> Stack;

    Stack.push(1);
    Stack.push(2);
    Stack.emplace(3);

    cout << "Top = " << Stack.top() << endl; // tracks the top el in stack
    cout << "Order of Top in Stack : ";
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;

    stack<int> s1;
    s1.push(20);
    s1.push(30);
    s1.push(40);
    stack<int> s2;
    cout << "Before Swapping : \n";
    cout << "Size of s1 = " << s1.size() << endl;
    cout << "Size of s2 = " << s2.size() << endl;
    s2.swap(s1);
    cout << "After Swapping : \n";
    cout << "Size of s1 = " << s1.size() << endl;
    cout << "Size of s2 = " << s2.size() << endl;

    // top,pop,emplace,push => O(1)

    // 2) Queue (same as stack but no top function) //
    // First in First out
    cout << "\nQUEUE\n"
         << endl;
    queue<int> q;
    q.push(11);
    q.push(22);
    q.push(33);
    q.emplace(44);
    cout << "first element in q = " << q.front() << endl;
    cout << "Order of Pop in Queue : ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    queue<int> q1;
    q1.push(18);
    q1.push(19);
    q1.push(29);
    q1.push(39);
    queue<int> q2;
    cout << "Before Swapping : \n";
    cout << "Size of s1 = " << q1.size() << endl;
    cout << "Size of s2 = " << q2.size() << endl;
    q2.swap(q1);
    cout << "After Swapping : \n";
    cout << "Size of s1 = " << q1.size() << endl;
    cout << "Size of s2 = " << q2.size() << endl;

    // front,pop,emplace,push => O(1)

    // 3) Priority Queue //
    cout << "\nPRIORITY QUEUE\n"
         << endl;
    priority_queue<int> pq;
    pq.push(4);
    pq.push(5);
    pq.push(10);
    pq.emplace(3);
    cout << "Order of Top in Priority queue : ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // reverse priority queue
    priority_queue<int, vector<int>, greater<int>> pq1; // greater => functor used to give greater order
    pq1.push(5);
    pq1.push(14);
    pq1.push(12);
    pq1.emplace(33);
    cout << "Size of pq1 before = " << pq1.size() << endl;
    cout << "Elements of pq1 : ";
    while (!pq1.empty())
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;
    cout << "Size of pq1 after = " << pq1.size() << endl;

    // top => O(1) , pop,push,emplace => O(log n)

    // 4) Map //
    // Map have (key,value) pairs.
    // Data inside map is sorted in ascending order.
    // Key is unique.
    // Key value can be inserted and changed.
    cout << "\nMAP\n"
         << endl;
    map<string, int> m;
    m["TV"] = 190000;
    m["Laptop"] = 60000;
    m["Headphones"] = 500;
    m["Bike"] = 300000;
    m["Watch"] = 2000;
    m["Laptop"] = 70000; // updated the value

    m.insert({"Pen", 10}); // O(log n) => insert
    m.emplace("Book", 60); // O(log n) => emplace
    m.erase("TV");         // O(log n) => erase

    for (auto p : m)
        cout << "Price of " << p.first << " is " << p.second << endl;

    cout << "Count of Laptops in m = " << m.count("Laptop") << endl;
    cout << "Value of Pen : " << m["Pen"] << endl;

    if (m.find("Watch") != m.end())
        cout << "Watch found." << endl;
    else
        cout << "Item not found." << endl;

    if (m.find("Pencil") != m.end())
        cout << "Pencil found." << endl;
    else
        cout << "Pencil not found." << endl;

    cout << "Size of m = " << m.size() << endl;
    m.empty(); // just empty the map
    cout << "Size of m after emptying = " << m.size() << endl;
    m.clear(); // clear the space of map
    cout << "Size of m after clearing = " << m.size() << endl;
    // Multi maps
    multimap<string, int> mm;
    mm.emplace("tv", 100);
    mm.emplace("tv", 100);
    mm.emplace("tv", 100);
    mm.emplace("Pen", 10);

    mm.erase("tv"); // erase all tv

    mm.emplace("Car", 2000);
    mm.emplace("Car", 2000);
    mm.emplace("Car", 2000);

    mm.erase(mm.find("Car")); // erase only one item
    cout << "Elements of mm : ";
    for (auto p : mm)
        cout << p.first << " " << p.second << endl;

    // Unordered Map
    // There are in random order (unsorted)
    // functions time complexity is O(1)
    cout << "\nUNORDERED MAPS\n"
         << endl;
    unordered_map<string, int> unM;
    unM.emplace("tv", 100); // no duplicates
    unM.emplace("tv", 100);
    unM.emplace("tv", 100);
    unM.emplace("laptop", 300);
    unM.emplace("fridge", 190);
    unM.emplace("printer", 150);
    cout << "Elements of unordered map : \n";
    for (auto p : unM)
        cout << p.first << " " << p.second << endl;

    // 5) Set //
    // unique values stored in a sorted order.
    cout << "\nSET\n"
         << endl;
    set<int> s;
    s.emplace(1);
    s.emplace(2);
    s.emplace(3);
    // s.emplace(4);
    s.insert(5);
    // no duplicates are allowed
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(6);

    s.erase(6);
    cout << "Elements of set s : ";
    for (auto val : s)
        cout << val << " ";
    cout << endl;
    cout << "Lower bound of 2 = " << *(s.lower_bound(2)) << endl;
    cout << "Lower bound of 4 = " << *(s.lower_bound(4)) << endl;
    if (s.lower_bound(10) != s.end())
        cout << "Lower bound of 10 = " << *it0 << endl;
    else
        cout << "Lower bound of 10 doesn't exist." << endl;
    cout << "Upper bound of 2 = " << *(s.upper_bound(2)) << endl;
    cout << "Size of s : " << s.size() << endl;
    cout << "Count of 5 = " << s.count(5) << endl;

    if (s.find(2) != s.end())
        cout << "2 found." << endl;
    else
        cout << "2 not found." << endl;

    // Multi Set

    multiset<int> sm;
    sm.emplace(1);
    sm.emplace(2);
    sm.emplace(3);
    sm.emplace(4);
    sm.insert(5);
    // now duplicates are allowed
    sm.insert(1);
    sm.insert(2);
    sm.insert(3);
    sm.insert(6);
    cout << "Elements of set sm : \n";
    for (auto val : sm)
        cout << val << " ";
    cout << endl;

    // Unordered Set
    // unsorted order storing of elements.
    unordered_set<int> unS;
    cout << "Elements of set unS : \n";
    unS.insert(10);
    unS.insert(20);
    unS.insert(30);
    unS.insert(40);
    unS.insert(50);

    for (auto val : unS)
        cout << val << " ";
    cout << endl;

    /* Algorithms */

    // 1) Sorting //
    // Ex-1)
    cout << "\nSORTING\n"
         << endl;
    int Arr[5] = {3, 8, 9, 2, 5};
    sort(Arr, Arr + 5);
    cout << "Elements of arr = ";
    for (int i = 0; i < 5; i++)
        cout << Arr[i] << " ";
    cout << endl;
    // Ex-2)
    vector<int> vec = {87, 78, 67, 91, 97};
    sort(vec.begin(), vec.end());
    cout << "Elements of vec (ascending) = ";
    for (int val : vec)
        cout << val << " ";
    cout << endl;
    sort(vec.begin(), vec.end(), greater<int>()); // descending order
    cout << "Elements of vec (descending) = ";
    for (int val : vec)
        cout << val << " ";
    cout << endl;
    // Ex-3)
    vector<pair<int, int>> Vecpair = {{5, 2}, {6, 1}, {1, 2}, {4, 2}};
    sort(Vecpair.begin(), Vecpair.end());
    cout << "Vecpair elements after sorting (first el) : \n";
    for (auto p : Vecpair) // sorted accoring to first value of pair
        cout << p.first << " " << p.second << endl;
    // using custom comparator
    cout << "Vecpair elements after sorting (second el) : \n";
    sort(Vecpair.begin(), Vecpair.end(), comparator);
    for (auto p : Vecpair)
        cout << p.first << " " << p.second << endl;

    // 2) Reverse //
    cout << "\nREVERSE\n"
         << endl;
    // Ex-1)
    vector<int> revVec = {1, 6, 8, 11, 13, 15};
    reverse(revVec.begin(), revVec.end());
    cout << "Elements of reverse Vector : ";
    for (int val : revVec)
        cout << val << " ";
    cout << endl;
    // Ex-2)
    vector<int> Vec = {1, 2, 3, 4, 5};
    reverse(Vec.begin() + 1, Vec.begin() + 3); // Vec[1] and Vec[3-1]
    cout << "Elements of Vec : ";
    for (int val : Vec)
        cout << val << " ";
    cout << endl;

    // 3) Next Permutation
    cout << "\nNext Permutation\n"
         << endl;
    string str = "abc";
    // All possible permutations are :-
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba
    next_permutation(str.begin(), str.end());
    cout << "Next permuatation of str = " << str << endl;

    string str1 = "cab";
    prev_permutation(str1.begin(), str1.end());
    cout << "Previous permutation of str1 = " << str1 << endl;

    // 4) Swap,min,max
    cout << "\nSWAP,MIN AND MAX\n"
         << endl;
    int a = 10, b = 20;
    cout << "Before Swapping : ";
    cout << "a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "After Swapping : ";
    cout << "a = " << a << " b = " << b << endl;
    cout << "Max value in a and b = " << max(a, b) << endl;
    cout << "Min value in a and b = " << min(a, b) << endl;

    // 5) Max and Min element
    cout << "\nMax and Min element\n"
         << endl;
    vector<int> vec1 = {1, 2, 3, 4, 5};
    cout << "Max element = " << *(max_element(vec1.begin(), vec1.end())) << endl;
    cout << "Min element = " << *(min_element(vec1.begin(), vec1.end())) << endl;

    // 6) Binary Search
    cout << "\nBinary Search\n"
         << endl;
    cout << "Target is found if output is 1 else 0.\n";
    cout << "Target 4 is found : " << binary_search(vec1.begin(), vec1.end(), 4) << endl;
    cout << "Target 10 is found : " << binary_search(vec1.begin(), vec1.end(), 10) << endl;

    // 7) Count Set Bits
    cout << "\nCount Set Bits\n"
         << endl;
    int n1 = 15;
    long int n2 = 25;
    long long int n3 = 30;
    cout << __builtin_popcount(n1) << endl;
    cout << __builtin_popcountl(n2) << endl;
    cout << __builtin_popcountll(n3) << endl;

    return 0;
}