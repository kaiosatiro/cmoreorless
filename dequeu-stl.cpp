#include <iostream>
#include <deque> 
using namespace std;

// 2
// 5 2
// 3 4 6 3 4
// 7 4
// 3 4 5 8 1 4 10

// 4 6 6 4
// 8 8 8 10

void printKMax(int arr[], int n, int k){
	deque <int> dq(0);
	deque <int> out(0);

	int idx{0};
	int max{0};

	do {
		if (idx >= k){
			for (int sub_idx{0}; sub_idx < k; sub_idx++){
				if (dq[sub_idx] > max) 
					max = dq[sub_idx];
			}
			out.push_back(max);
			max = 0;
			dq.push_back(arr[idx]);
			dq.pop_front();
			idx++;
		}
		else {
			dq.push_back(arr[idx]);
			idx++;
		}

	} while (idx <= n);

	for (auto i: out){
		cout << i << " ";
	}
	cout << '\n';
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}