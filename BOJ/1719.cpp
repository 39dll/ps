﻿#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, M, dist[201][201], firstnode[201][201];
int main() { //Floyd-Warshall로 100개의 도시의 이동 최소 비용 알아내기
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		dist[in1][in2] = min(dist[in1][in2], in3);
		dist[in2][in1] = min(dist[in2][in1], in3);
		firstnode[in1][in2] = in2;
		firstnode[in2][in1] = in1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])firstnode[i][j] = firstnode[i][k];
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << "- ";
			else cout << firstnode[i][j] << " ";
		}
		cout << "\n";
	}
}