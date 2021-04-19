#include <iostream>
#include <algorithm>
using namespace std;

int a[50];
int b[50];
int p[50];
bool ch[50];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b+n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[i] == a[j] && !ch[j]){
				ch[j] = true;
				p[j] = i;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++) cout << p[i] << " ";
}
