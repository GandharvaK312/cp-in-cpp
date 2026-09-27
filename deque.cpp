#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// deque: Double Ended Queue
// combines functionality of queue and vectors
// push_back is amortized O(1)
// deque<T>d; T: datatype
// can be used to implement both LIFO and FIFO functionalities

int main(void) {

	deque<int> d1; // empty

	deque<int> d2 = {10, 20, 30, 40, 50};

	for(int x : d2) cout << x << "\t" ;
	cout << endl;

	deque<int> d;

	for(int i = 1; i <= 7; i ++) d.push_back(i); // Time complexity: amortized O(1)
	for(int x : d) cout << x << "\t" ;
	cout << endl;

	for(int i = 90; i >= 85; i --) d.push_front(i); // Time complexity: amortized O(1)
	
	cout << "Before pop: \n";
	for(int x : d) cout << x << "\t" ;
	cout << endl;

	d.pop_back(); // Time complexity: O(1)
	cout << "After pop back: " << endl;
	for(int x : d) cout << x << "\t" ;
	cout << endl;

	d.pop_front(); // Time complexity: O(1)
	cout << "After pop front: " << endl;
	for(int x : d) cout << x << "\t" ;
	cout << endl;

	deque<int> d3 ={100, 200, 300};
	for(int x : d3) cout << x << "\t" ;
	cout << endl;
	cout << "front: " << d3.front() << " back: " << d3.back() << endl; // Time complexity: O(1)
	
	cout << d3.size() << endl;

	cout << boolalpha << (d3.empty()) << endl;
	d2.clear();
	cout << boolalpha << (d2.empty()) << endl;

	d3.erase(find(d3.begin(), d3.end(), 200)); // O(n) in worst case
	cout << d3.size() << endl;
	for(int x : d3) cout << x << "\t" ;
	cout << endl;


   return 0;
}
