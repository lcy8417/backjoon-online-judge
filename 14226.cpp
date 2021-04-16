#include <iostream>
#include <queue>

using namespace std;
int res = 2147000000;
struct Emotion{
	int x;
	int clip;
	int time;
	Emotion(int a, int b, int c){
		x = a;
		clip = b;
		time = c;
	}
};

bool check[2001][2001];

int main(){
	ios_base::sync_with_stdio(false);
	int s;
	queue <Emotion> q;
	cin >> s;
	q.push(Emotion(1, 0, 0));
	check[1][0] = true;
	while(!q.empty()){
		int x = q.front().x;
		int clip = q.front().clip;
		int time = q.front().time;
		q.pop();
		if(x == s){
			cout << time << "\n";
			break;
		}
		if(!check[x][x]){
			check[x][x] = true;
			q.push(Emotion(x, x, time+1));
		}if(x-1 > 1 && !check[x-1][clip]){
			check[x-1][clip] = true;
			q.push(Emotion(x-1, clip, time+1));
		}if(x+clip <= 2000 && !check[x+clip][clip]){
			check[x+clip][clip] = true;
			q.push(Emotion(x+clip, clip, time+1));
		}
	}
}
