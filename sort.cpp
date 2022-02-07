#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

void printVector(vector<int>& a) {
	vector<int>::const_iterator i;
	for(i = a.begin(); i < a.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}

void insertionSort(vector<int>& a) {
	vector<int>::iterator i,j;
	int tmp;
	for(i = a.begin(); i < a.end(); i++) {
		for(j = i; j > a.begin() && *(j-1) > *j; j--) {
			tmp = *j;
			*j = *(j-1);
			*(j-1) = tmp;	
		}
		printVector(a);
		cout << endl;
	}
}

void revInsertionSort(vector<int>& a) {
	vector<int>::iterator i,j;
	int tmp;
	for(i = a.begin(); i < a.end(); i++) {
		for(j = i; j > a.begin() && *(j-1) < *j; j--) {
			tmp = *j;
			*j = *(j-1);
			*(j-1) = tmp;	
		}
		printVector(a);
		cout << endl;
	}
}

void mergeSort(vector<int>& x) {
	vector<int>::const_iterator i,j;
	vector<int>::iterator mid, k; 
	vector<int> a, b;
	mid = x.begin() + x.size()/2;

	/* Split array x into  arrays a and b if x has two or more elements */
	cout << "Splitting arrays..." << endl;
	if(x.size() > 1) {
		a.insert(a.begin(),x.begin(),mid);
		b.insert(b.begin(),mid,x.end());
		cout << "Recursive call (a)" << endl;
		mergeSort(a);
		cout << "Recursive call (b)" << endl;
		mergeSort(b);
	}

	/* Merge elements of a and b into x */
	cout << "Merging elements..." << endl;
	k = x.begin();
	i = a.begin();
	j = b.begin();
	while(i < a.end() && j < b.end()) {
		if(*i <= *j) {
			*k = *i;
			i++;
		} else {
			*k = *j;
			j++;
		}
		k++;
	}
	while(i < a.end()) {
		*k = *i;
		k++;
		i++;
	}
	while(j < b.end()) {
		*k = *j;
		k++;
		j++;
	}
	cout << "Merge complete..." << endl;
	printVector(x);
	cout << endl;
	cout << endl;
}

int main() {
	vector<int> v = {6,30000,9,10,12,21,32765,15,3,14,9,3,22,1};
	printVector(v);
	//auto mid = v.begin() + v.size()/2;
	//cout << *(v.begin()) << endl;
	//cout << *(v.end() - 1) << endl;
	//insertionSort(v);
	//cout << endl;
	//revInsertionSort(v);
	//cout << endl;
	mergeSort(v);
	cout << "Here we go..." << endl;
	printVector(v);
	//cout << v.size() << endl;
	//cout << typeid(mid).name() << endl;
	return 0;
}
