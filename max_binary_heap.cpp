#include <iostream>
using namespace std;
class Heap{
private:
	long long capacity, heapsize, *arr;

public:

	Heap(int capacity){
		this->capacity = capacity;
		this->heapsize = 0;
		arr = new long long[capacity];
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

	void insert(int key){
		if (heapsize ==0)
		{
			arr[heapsize] = key;
			heapsize++;
		}
		else if(heapsize<capacity){
			arr[heapsize] = key;
			heapsize++;

			int i = heapsize - 1;

			while(i!=0 && arr[parent_index(i)] < arr[i]){
				swap(arr[i], arr[parent_index(i)]);
				i = parent_index(i);
			}
		}
	}

	void heapify(int index){
		int largest = index;
		if (left_index(index)<heapsize && arr[left_index(index)]>arr[index])
		{
			largest = left_index(index);
		}
		if (right_index(index)<heapsize && arr[right_index(index)] > arr[largest])
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
		if (heapsize == 0)
		{
			return -1;
		}
		else if(heapsize == 1){
			heapsize--;
			return arr[0];
		}
		int max = arr[0];
		arr[0] = arr[heapsize - 1];
		heapsize --;
		heapify(0);

		return max;
	}	

	void show_heap(){
		for (int i = 0; i < heapsize; ++i){
			cout<<arr[i]<<" "; 
		}
		cout<<"\n";
	}
};
int main(){
	long long t, i, j;
	Heap heap(10);
	heap.insert(3);
	heap.insert(7);
	heap.insert(4);
	heap.insert(10);
	// cout<<heap.del_max_ret()<<"\n";
	heap.show_heap();
}