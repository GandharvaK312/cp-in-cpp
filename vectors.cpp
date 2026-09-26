#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& vec){
	for(int x: vec) cout << x << "\t";
	cout << "\n";
}

// vector's growth is: allocate new bigger raw memory → construct new elements by copy/move from old → destroy old elements → free old block

int main(void) {

	vector<int> v;

	for(int i = 0; i < 5; i ++){
		v.push_back(i);
		cout << "i: " << i << "\nsize: " << v.size() << endl;
		cout << "capacity: " << v.capacity() << endl;
	}

	for(int x: v)
		cout << x << "\t";
	vector<int> v1;
	v1.reserve(10); // reserves 10 spaces instead of dynamically increasing on the go. so rn size = 0, capacity = 10
	
	cout << v1.size() << "\t" << v1.capacity() << endl;

	for(int i = 1; i <= 10; i ++){
		v1.push_back(i);
	}

	for(int x: v1)
		cout << x << "\t";
	cout << endl;
	cout << v1.size() << "\t" << v1.capacity() << endl;

	v1.push_back(11);
	cout << v1.size() << "\t" << v1.capacity() << endl;

	vector<int> v2 {10, 20, 30};
	for(int x: v2) cout << x << "\t";

	int *p = &v2[0];
	cout << *p;

	v2.push_back(40);
	cout << *p;
// any pointer, reference, or iterator obtained from a vector should be treated as invalid the moment you call anything that might grow the vector (push_back, insert, reserve if it needs to grow, etc.)

	vector<int> v3 {1, 3, 4, 5};

	v3.push_back(6);
	print(v3);

	// cout << *(v3.begin() + 1); // *(arr + i)
	v3.insert(v3.begin() + 1, 2);
	print(v3);

	cout << v3[3] <<"|"<< v3.at(3) << endl; // v3[3] at() first checks if the index passed is within bounds and hrows std::out_of_range if the index is invalid
	// v[i] accesses the elements without checking the bounds
	
	v3.pop_back();
	print(v3);

	v3.erase(find(v3.begin(), v3.end(), 3));
	print(v3);

	// for(int x : v3) v3.pop_back();

	cout << v3.empty();

	vector<vector<int>> matrix {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	vector<int> v4(3, 4); // vector_name(n, v); gives n elements with v being each element
	print(v4);

	for(const auto &row : matrix){
		// for(const auto &val : row){
		// 	cout << val << "\t";
		// }
		print(row);
		cout << endl;
	}

	vector<int> v5;
	v5.reserve(10);
	cout << "size: " << v5.size() << " capacity: " << v5.capacity() << endl;

	// for(int i = 1; i <= 10; ++ i){
	// 	v5.push_back(i);
	// }
	// print(v5);
	// cout << "size: " << v5.size() << " capacity: " << v5.capacity() << endl;

	v5.resize(5);
	print(v5);
	cout << "size: " << v5.size() << " capacity: " << v5.capacity() << endl;
	
	v5.resize(2);
	print(v5);
	cout << "size: " << v5.size() << " capacity: " << v5.capacity() << endl;
//  if you've only called reserve(), you cannot use indexed access to initialize elements.
//v.reserve(10);
// cout << v.capacity(); // >= 10
//
// v[0] = 42;            // ❌ invalid
	return 0;
}
