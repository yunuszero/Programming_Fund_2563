// Not Done
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int start, end;
	cin >> start >> end;
	int nWeakness, nEffective;
	cin >> nWeakness >> nEffective;
	int cntW[20] = { 0 }, cntE[20] = { 0 };
	vector<vector<int>> x;

	for (int i = 0; i < end; i++) {
		
		for (int j = 0; j < end; j++) {
			if (cntE[j] < nEffective) {
				cntE[j]++;
			}
		}
	}

	return 0;
}