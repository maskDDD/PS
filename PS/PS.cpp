#include <iostream>
#include <cmath>
using namespace std;
#define CASE_NUM 10000
#define STELLA_NUM 50

int stp[CASE_NUM][2];
int dtp[CASE_NUM][2];
int stella[CASE_NUM][STELLA_NUM][3];

int path_of_galaxy(int i, int n) {
	int x=0, y=0, z=0;
	for (int j = 0; j < n; j++) {
		float stp_to_stella = sqrt(pow(stella[i][j][0] - stp[i][0], 2) + pow(stella[i][j][1] - stp[i][1], 2));
		float dtp_to_stella = sqrt(pow(stella[i][j][0] - dtp[i][0], 2) + pow(stella[i][j][1] - dtp[i][1], 2));
		if (stp_to_stella < stella[i][j][2]) {
			x++;
		}
		if (dtp_to_stella < stella[i][j][2]) {
			y++;
		}
		if (stp_to_stella < stella[i][j][2] && dtp_to_stella < stella[i][j][2]) {
			z++;
		}
	}
	return x + y - 2*z;
}

int main() {
	int T;
	cin >> T;

	int* n = new int[T];	// 행성계의 갯수
	for (int i = 0; i < T; i++) {
		cin >> stp[i][0] >> stp[i][1] >> dtp[i][0] >> dtp[i][1];

		cin >> n[i];
		for (int j = 0; j < n[i]; j++) {
			cin >> stella[i][j][0] >> stella[i][j][1] >> stella[i][j][2];

		}
	}

	for (int i = 0; i < T; i++) {
		cout << path_of_galaxy(i, n[i]) << '\n';
	}

	return 0;
}
