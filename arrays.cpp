#include <iostream>
#include <cstring>
#include <algorithm>
#include <array>
#include <string>
using namespace std;

void print(const array<int, 5> &a){
    for(int x : a) cout << x << "\t";
    cout << "\n";
}
void print_2(const array<int, 4> &a){
    for(int x : a) cout << x << "\t";
    cout << "\n";
}
void print_str(const array<string, 2> &a){
    for(string x : a) cout << x << "\t";
    cout << "\n";
}

int main(void) {
    // // array is a 2 argument template array<datatype, size> array_name
    array<int, 5> arr {{3, 4, 5, 1, 2}};
    array<int, 4> arr2 = {10, 20, 30, 40};
    array<string, 2> ar3 = {"a", "b"};
    array<string, 2> ar4 = {{string("a"), "b"}}; //  verbose method. refer to above line for more modern approach
    array<int, 8> ar5;
    ar5.fill(67);

    print(arr);
    print_2(arr2);
    print_str(ar3);
    print_str(ar4);

    cout << "arr: " << arr.size() << " arr2: " << arr2.size() <<  " ar3: " << ar3.size() <<  " ar4: " << ar4.size() << endl;

    sort(arr.begin(), arr.end());
    cout << "after sort of arr: " << endl;
    print(arr);

    arr2.fill(10);
    for(auto i : arr2) cout << i << "\t";
    cout << endl;
    for(auto i : ar5) cout << i << "\t";
    cout << endl;
    for (string s : ar3)
    cout << s << ' ';

    array<char, 3> a = {'G', 'f', 'G'};
    cout << a[0] << ' ' << a[2] << endl;

    array<int, 3> a2 = {'G', 'f', 'G'};
    cout << a2.front() << ' ' << a2.back() << endl; // front and back return references
    array <int , 3> arrr={'G','f','G'};  // ASCII val of 'G' =71 
    array <int , 3> arr1={'M','M','P'}; // ASCII val of 'M' = 77 and 'P' = 80
    arrr.swap(arr1);  // now arr = {M,M,P}
    cout<<arrr.front() <<" "<<arrr.back() << endl;

    bool x = arr.empty();
    cout <<boolalpha << (x) << endl;

    // cout << arr.at(3) << endl; // performs bound checking
    // cout << arr[3] << endl; // does not

    cout << arrr.size() << " " << arrr.max_size() << " " << sizeof(arr) << endl;// arr.max_size is the same as size since it cannot grow/shrink
    const char* str = "GeeksforGeeks";
    array<char,14> arr6;
    memcpy (arr6.data(),str,14);
    cout << arr6.data() << '\n';
// begin(), end() functions return iterators to the beginning and end of the array. cbegin(), cend() return constant iterators that provide read-only access to the elements and are commonly used with STL algorithms and range-based traversals.
    return 0;
}
