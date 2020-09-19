//BUG!!!
#include<iostream>
using namespace std;

void playReversi(char[8][9], int, int , char);

int main() {
	char grid[8][9] = { "........",
						"........",
						"........",
						"...OX...",
						"...XO...",
						"........",
						"........",
						"........"};
	int k,posy;
	cin >> k;
	char posx;
	for (int i = 0; i < k; i++) {
		cin >> posx >> posy;
		playReversi(grid, posx - 'a', posy - 1, (i%2==0)? 'X' : 'O');
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}

void playReversi(char grid[8][9], int posx, int posy, char change) {
	for (int i = 1; i < 8; i++) {
		// check upper
		if (grid[posy - i][posx] == change && posy - i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posy - i + 1;
			while (j != posy) {
				if (grid[j][posx] == '.') break;
				grid[j++][posx] = change;
			}
		}
		//check lower
		if (grid[posy + i][posx] == change && posy + i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posy + i - 1;
			while (j != posy) {
				if (grid[j][posx] == '.') break;
				grid[j--][posx] = change;
			}
		}
		//check left
		if (grid[posy][posx - i] == change && posx - i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posx - i + 1;
			while (j != posx) {
				if (grid[posy][j] == '.') break;
				grid[posy][j++] = change;
			}
		}
		//check right
		if (grid[posy][posx + i] == change && posx + i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posx + i - 1;
			while (j != posx) {
				if (grid[posy][j] == '.') break;
				grid[posy][j--] = change;
			}
		}
		//check down right
		if (grid[posy + i][posx + i] == change && posx + i >= 0 && posy + i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posx + i - 1, k = posy + i - 1;
			while (j != posx && k != posy) {
				if (grid[k][j] == '.') break;
				grid[k--][j--] = change;
			}
		}
		if (grid[posy - i][posx - i] == change && posx - i >= 0 && posy - i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posx - (i - 1), k = posy - (i - 1);
			while (j != posx && k != posy) {
				if (grid[k][j] == '.') break;
				grid[k++][j++] = change;
			}
		}
		if (grid[posy - i][posx + i] == change && posx + i >= 0 && posy - i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posx + (i - 1), k = posy - (i - 1);
			while (j != posx && k != posy) {
				if (grid[k][j] == '.') break;
				grid[k++][j--] = change;
			}
		}
		if (grid[posy + i][posx - i] == change && posx - i >= 0 && posy + i >= 0 && i != 1) {
			grid[posy][posx] = change;
			int j = posx - (i - 1), k = posy + (i - 1);
			while (j != posx && k != posy) {
				if (grid[k][j] == '.') break;
				grid[k--][j++] = change;
			}
		}
	}
}