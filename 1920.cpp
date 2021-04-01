#include <bits/stdc++.h>
using namespace std;

int a[100001];
int b[100001];

int main(){
	ios_base::sync_with_stdio(false);
	int N, M, lt = 1, rt = 0, mid = 0;
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a+1, a+N+1);
	cin >> M;
	for(int i = 1; i <= M; i++){
		 cin >> b[i];
	}
	
	for(int i = 1; i <= M; i++){
		bool search = false;
		int key = b[i];
		lt = 1; rt = N;
		if(key < a[1] || key > a[N]) {
			cout << 0 << "\n";
			continue;
		}
		while(lt <= rt){
			mid = (lt + rt)	/ 2;
			if(a[mid] == key){
				search = !search;
				break;
			}else if(a[mid] > key) rt = mid-1;
			else if(a[mid] < key) lt = mid+1;
		}
		if(search) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}
