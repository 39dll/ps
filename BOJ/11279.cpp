#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<int> a;
	unsigned int N, x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (x != 0) {
			a.push(x);
		}
		else {
			if (a.empty()) cout << "0\n";
			else {
				cout << a.top() << "\n";
				a.pop();
			}
		}
	}
}