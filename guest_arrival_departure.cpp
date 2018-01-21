#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std; 

int main(){
	int n, a[1000000] = {0}, temp1, temp2, max_guests = -1;
	 vector< pair<int,int> >  arr;

	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>temp1>>temp2;
		arr.push_back(make_pair(temp1, 0));
		arr.push_back(make_pair(temp2,1));
	}

	sort(arr.begin(), arr.end());
	int count = 0;

	for (int i = 0; i < n; ++i){
		if (arr[i].second == 0) {
			count++;

			if(count>=max_guests){
				max_guests = count;
			}
		}
		else{
			count--;
		}
	}


	cout<<max_guests;
}