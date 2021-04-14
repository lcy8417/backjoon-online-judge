#include <iostream>
#include <vector>

using namespace std;

vector <int> dy(100001, 100001);

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++){
		dy[i] = i;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j*j <= i; j++){
			dy[i] = min(dy[i], dy[i-j*j]+1);
		}
	}
	cout << dy[n];
	
}
