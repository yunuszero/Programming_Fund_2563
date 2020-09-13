#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Result {
	char name[21];
	int score[4];
	int total = 0;
	int shoot = 0, raw = 0;
};

void checkScore(struct Result* Board) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Board[i].score[j] > Board[j].score[i] && i != j) Board[i].total += 3;
			else if (Board[i].score[j] == Board[j].score[i] && i != j) Board[i].total++;
		}
	}
}

void sort(struct Result* Board) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Board[i].total > Board[j].total) {
				struct Result temp = Board[i];
				Board[i] = Board[j];
				Board[j] = temp;
			}
			if (Board[i].total == Board[j].total) {
				if (Board[i].raw > Board[j].raw) {
					struct Result temp = Board[i];
					Board[i] = Board[j];
					Board[j] = temp;
				}
				if (Board[i].raw == Board[j].raw) {
					if (Board[i].shoot > Board[j].shoot) {
						struct Result temp = Board[i];
						Board[i] = Board[j];
						Board[j] = temp;
					}
				}
			}
		}
	}
}

void printBoard(struct Result* Board) {
	for (int i = 0; i < 4; i++) {
		printf("%s %d\n", Board[i].name, Board[i].total);
	}
}

int main() {
	struct Result Team[4];
	for (int i = 0; i < 4; i++) {
		scanf("%s", Team[i].name);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &Team[i].score[j]);
			Team[i].shoot += Team[i].score[j];
		}
		Team[i].raw = Team[i].shoot;
	}
	checkScore(Team);
	int max = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Team[i].raw -= Team[j].score[i];
		}
		if (max < Team[i].total) {
			max = Team[i].total;
		}
	}
	sort(Team);
	printBoard(Team);

	return 0;
}