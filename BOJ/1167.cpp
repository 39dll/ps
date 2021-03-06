#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> p; //연결된 노드, 거리
vector<p> edge[100001];//index번째 노드에서 vector값 안의 노드에 연결됨
int dis[100001];
int mx = 0, mxind = 0;
int V, N, temp1, temp2;
void find(int ind) { //ind의 자식을 찾아 dis[ind]를 업데이트
	for (int i = 0; i < edge[ind].size(); i++) {
		int next = edge[ind][i].first;
		int cost = edge[ind][i].second;
		if (dis[next] == -1) {
			dis[next] = dis[ind] + cost;
			if (dis[next] > mx) {
				mx = dis[next];
				mxind = next;
			}
			find(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> V;
	for(int i=1;i<=V;i++){
		dis[i] = -1;
		cin >> N;
		cin >> temp1;
		while (temp1 != -1) {
			cin >> temp2;
			edge[N].push_back({ temp1, temp2 });
			//edge[temp1].push_back({ N, temp2 });
			cin >> temp1;
		}
	}
	dis[1] = 0;
	find(1);
	for (int i = 1; i <= V; i++) {
		dis[i] = -1;
	}
	mx = 0;
	dis[mxind] = 0;
	find(mxind);
	cout << mx;
}