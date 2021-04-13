#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int> > dy(1001, make_pair(1, 0));
int lis[1001];
int n, a, b, maxlen=1, maxidx=1;

void go(int idx){
	if(dy[idx].second == 0){ // 더이상 경로가 없을때 
		cout << lis[idx] << " ";
		return;
	}else{
		go(dy[idx].second);
		cout << lis[idx] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> lis[i];
	}
	for(int i = 1; i <= n-1; i++){
		for(int j = i+1; j <= n; j++){
			if(lis[i] < lis[j]){
				if(dy[j].first < dy[i].first+1){
					dy[j].first = dy[i].first+1;
					dy[j].second = i; // 온 경로 저장 
				}
				if(maxlen < dy[j].first){
					maxlen = dy[j].first;
					maxidx = j;
				}
			}
		}
	}
	cout << maxlen << "\n";
	go(maxidx);
}
