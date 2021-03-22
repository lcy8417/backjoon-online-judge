#include <bits/stdc++.h>
using namespace std;

struct Info{
	int age;
	string name;
	int num;
	Info(int a, string b, int c){
		age = a;
		name = b;
		num = c;
	}
	bool operator<(const Info &b) const{
		if(age == b.age) return num < b.num;
		else return age < b.age;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <Info> people;
	for(int i = 0; i < n; i++){
		int a;
		string b;
		cin >> a >> b;
		people.push_back(Info(a, b, i));
	}
	sort(people.begin(), people.end());
	for(int i = 0; i < n; i++)
		cout << people[i].age << " " << people[i].name << "\n";
}
