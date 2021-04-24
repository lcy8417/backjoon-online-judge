#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
bool check[100001];
bool res[2000001];
void Go(const vector <int> &v, int L, int sum, int s){
	if(L > 0) res[sum] = true;
	for(int i = s; i < v.size(); i++){
		if(!check[i]){
			check[i] = true;
			Go(v, L+1, sum+v[i], i+1);
			check[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector <int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	Go(v, 0, 0, 0);
	for(int i = 1; i <= 2000000; i++){
		if(!res[i]){
			cout << i;
			break;
		}
	}
}
