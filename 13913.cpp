#include <iostream>
#include <queue>
using namespace std;

int n, k;
vector <pair<int, int> > check(200001, make_pair(0, -1));
queue <int> q;

void go(int x){
	if(check[x].second == -1){
		cout << x << " ";
	}else{
		go(check[x].second);
		cout << x << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	q.push(n);
	check[n].first = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == k){
			cout << check[x].first-1 << "\n";
			go(x);
			break;
		} 
		if(x*2 <= 200000 && !check[x*2].first){
			check[x*2].first = check[x].first+1;
			check[x*2].second = x; // ¿Â °æ·Î »ðÀÔ 
			q.push(x*2);
		}if(x-1 >= 0 && !check[x-1].first){
			check[x-1].first = check[x].first+1;
			check[x-1].second = x;
			q.push(x-1);
		}if(x+1 <= 200000 && !check[x+1].first ){
			check[x+1].first = check[x].first+1;
			check[x+1].second = x;
			q.push(x+1);
		}
	}
}
