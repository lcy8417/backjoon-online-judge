#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n;
vector <int> dy(MAX, MAX);

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	dy[n] = 0;
	for(int i = n; i >= 1; i--){
		if(i % 3 == 0 && dy[i] + 1 < dy[i/3]) dy[i/3] = dy[i] + 1;
		if(i % 2 == 0 && dy[i] + 1 < dy[i/2]) dy[i/2] = dy[i] + 1;
		if(i > 1 && dy[i-1] > dy[i] + 1) dy[i-1] = dy[i] + 1; 
	}
	cout << dy[1];
}
