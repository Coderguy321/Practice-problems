#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;
class Heap{
private:
	int capacity, heapsize;
	pair<int,pair<int, int> > arr[1005];

public:

	Heap(){
		// this->capacity = capacity;
		this->heapsize = 0;
		// arr = new int[capacity];
	}

	int parent_index(int index){
		return (index - 1)/2;
	}

	int left_index(int i){
		return 2*i +1;
	}

	int right_index(int i){
		return 2*i + 2;
	}

	void insert(pair <int, pair<int, int> > key){
		if (heapsize ==0){
			arr[heapsize] = key;
			heapsize++;
		}
		else{
		arr[heapsize] = key;
		heapsize++;

		int i = heapsize - 1;

		while(i!=0 && arr[parent_index(i)].first < arr[i].first){
			swap(arr[i], arr[parent_index(i)]);
			i = parent_index(i);
		}
		}
	}

	void heapify(int index){
		int largest = index;
		if (left_index(index)<heapsize && arr[left_index(index)].first>arr[index].first)
		{
			largest = left_index(index);
		}
		if (right_index(index)<heapsize && arr[right_index(index)].first > arr[largest].first)
		{
			largest = right_index(index);
		}

		swap(arr[largest], arr[index]);

		if(index!=largest){
			index = largest;
			heapify(index);
		}
	}

	int del_max_ret(){
		int max;
		if (heapsize == 0)
		{
			return -1;
		}
		else if(heapsize == 1){
			heapsize--;
			return arr[0].first;
		}
		else{
		max = arr[0].first;
		arr[0] = arr[heapsize - 1];
		heapsize --;
		heapify(0);
		}

		return max;
	}	

	int get_max_sum_left_array(){
		return arr[0].second.first;
	}

	int get_max_sum_right_array(){
		return arr[0].second.second;
	}

	void show_heap(){
		cout<<"\n";
		for (int i = 0; i < heapsize; ++i){
			cout<<arr[i].first<<" "; 
		}
		cout<<"\n";
	}
};



// vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

vector<int> solve(vector<int> A, vector<int> B) {
	Heap heap;
	std::vector<int> sum;
	map<pair<int, int> , bool> map;
	int size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = A.size() - 1, j = B.size() - 1;

    // cout<<A[i]+B[j]<<"\n";
    map[make_pair(i,j)] = true;
    heap.insert(make_pair(A[i] + B[j], make_pair(i,j)));
    // size--;

    while(size!=0){
    	i = heap.get_max_sum_left_array();
    	j = heap.get_max_sum_right_array();
    	sum.push_back(heap.del_max_ret());
    	size--;
    	if (i!=0 && map.find(make_pair(i-1,j)) == map.end()){
    		heap.insert(make_pair(A[i-1] + B[j], make_pair(i-1, j)));
    		map[make_pair(i-1, j)] = true;
    	}
    	if (j!=0 && map.find(make_pair(i, j-1)) == map.end()){
    		heap.insert(make_pair(A[i] + B[j-1], make_pair(i, j-1)));
    		map[make_pair(i, j-1)] = true;
    	}
   
  	}
  	return sum;
}  	 


int main(){
	std::vector<int> A, B;
	// int array[1] = {1}, count=0;
	int array[] = {1, 4, 2, 3};
	for(int i=0; i<sizeof(array)/sizeof(int); i++){
     	A.push_back(array[i]);
	}
    // int array2[1] = {2};
    int array2[] = {2, 5, 1, 6};
	for(int i=0; i<sizeof(array2)/sizeof(int); i++)
     	B.push_back(array2[i]);

	vector<int> result = solve(A, B);

	for (std::vector<int>::iterator it = result.begin(); it != result.end(); ++it)	{
		cout<<*it<<" ";
	}

	cout<<"\n";
}