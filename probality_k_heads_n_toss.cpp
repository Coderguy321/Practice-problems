#include <iostream>
#include <cmath>
using namespace std;

float p(int n, int k, float ph){
	if (n<k){
		return 0;
	}
	else if (n==k){
		return pow(ph,n);
	}
	else if (k==0){
		return 1-ph;
	}

	return p(n-1,k, ph)*(1-ph) + p(n-1,k-1, ph)*ph;
}
int main(){
	int n, k;
	float ph;
	// ph in the probability of head 
	cin>>n>>k>>ph;
	if (n==1&&k==1)
	{
		cout<<ph;
	}
	else
		cout<<p(n-1,k, ph)*(1-ph) + p(n-1,k-1, ph)*ph;


}