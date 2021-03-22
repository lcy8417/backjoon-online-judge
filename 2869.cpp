#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int up, down, h, day = 0;
	cin >> up >> down >> h;
	if(down < up && up <= h){
		if((h-up)%(up-down) == 0) day = (h - up) / (up - down) + 1;
		else day = (h - down) / (up - down) + 1;
	}
	cout << day;
}
