#include <stdio.h>

#ifdef DEBUG
#define myprint printf
#else
#define myprint
#endif

constexpr int gridSize = 4;
constexpr int maxFish = 1000000;
constexpr int nDirections = 8;
constexpr int directions[nDirections][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
const char* const directionsStr[nDirections] = { "left", "top-left", "top", "top-right", "right", "bottom-right", "bottom", "bottom-left" };
constexpr int nSharkDirections = 4;
constexpr int sharkDirections[nSharkDirections][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

constexpr int nMovements = 3;
int nRounds;
int maxScore;
int score;
int bestMovements[nMovements];
int movements[nMovements];

struct Shark {
	int row;
	int col;
};

struct Unit {
	int nFish;
	int fishDirection[maxFish];
	int smellStatus;
};

Shark shark;
Unit map[gridSize][gridSize];
Unit map2[gridSize][gridSize];

void backupMap(void) {
	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			map2[r][c].nFish = map[r][c].nFish;
			for (int fishNo = 0; fishNo < map[r][c].nFish; fishNo++) {
				map2[r][c].fishDirection[fishNo] = map[r][c].fishDirection[fishNo];
			}
		}
	}
}

void duplicateFish(void) {
	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			int startNo = map[r][c].nFish;
			for (int fishNo = 0; fishNo < map2[r][c].nFish; fishNo++) {
				map[r][c].fishDirection[startNo + fishNo] = map2[r][c].fishDirection[fishNo];
			}
			map[r][c].nFish += map2[r][c].nFish;
		}
	}
}

int getNextDir(int curDir) {
	return (curDir - 1 + nDirections) % nDirections;
}

bool isBound(int r, int c) {
	if ((r < 0) || (r >= gridSize) || (c < 0) || (c >= gridSize)) {
		return false;
	}
	return true;
}

bool availableSpace(int r, int c) {
	if ((shark.row == r) && (shark.col == c)) {
		return false;
	}
	if ((r < 0) || (r >= gridSize) || (c < 0) || (c >= gridSize)) {
		return false;
	}
	if (map[r][c].smellStatus > 0) {
		return false;
	}
	return true;
}

void moveFish(void) {
	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			map[r][c].nFish = 0;
		}
	}

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			int numFishesToMove = map2[r][c].nFish;

			for (int fishNo = 0; fishNo < numFishesToMove; fishNo++) {
				int curFishDir = map2[r][c].fishDirection[fishNo];

				for (int numAttemps = 0; numAttemps < nDirections; numAttemps++) {
					int nextRow = r + directions[curFishDir][0];
					int nextCol = c + directions[curFishDir][1];

					if (availableSpace(nextRow, nextCol)) {
						map[nextRow][nextCol].fishDirection[map[nextRow][nextCol].nFish++] = curFishDir;
						break;
					}
					else {
						curFishDir = getNextDir(curFishDir);
					}
					if (numAttemps == (nDirections - 1)) {
						map[r][c].fishDirection[map[r][c].nFish++] = curFishDir;
					}
				}
			}
		}
	}
}


void getSharkPlan(int movementNo, int r, int c) {
	if (movementNo == nMovements) {
		if (score > maxScore) {
			maxScore = score;
			for (int i = 0; i < nMovements; i++) {
				bestMovements[i] = movements[i];
			}
		}
		return;
	}

	for (int i = 0; i < nSharkDirections; i++) {
		int nextRow = r + sharkDirections[i][0];
		int nextCol = c + sharkDirections[i][1];

		if (!isBound(nextRow, nextCol)) {
			continue;
		}

		movements[movementNo] = i;

		int fishBackup = map[nextRow][nextCol].nFish;
		score += fishBackup;

		map[nextRow][nextCol].nFish = 0;

		getSharkPlan(movementNo + 1, nextRow, nextCol);

		map[nextRow][nextCol].nFish = fishBackup;

		score -= map[nextRow][nextCol].nFish;
	}
}

void moveShark(void) {
	for (int i = 0; i < nMovements; i++) {
		shark.row += sharkDirections[bestMovements[i]][0];
		shark.col += sharkDirections[bestMovements[i]][1];

		if (map[shark.row][shark.col].nFish > 0) {
			map[shark.row][shark.col].smellStatus = 3;
		}
		map[shark.row][shark.col].nFish = 0;

		myprint("shark moved %d %d \n", shark.row, shark.col);
	}
}

void changeSmellStatus(void) {
	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			if (map[r][c].smellStatus > 0) {
				map[r][c].smellStatus--;
			}
		}
	}
}


void input(void) {
	int numFishes;

	scanf("%d %d", &numFishes, &nRounds);

	myprint("Input Start===================================\n");
	myprint("numFishes : %d nRounds: %d \n", numFishes, nRounds);

	for (int i = 0; i < numFishes; i++) {
		int r;
		int c;
		int direction;

		scanf("%d %d %d", &r, &c, &direction);
		r--, c--, direction--;

		map[r][c].fishDirection[map[r][c].nFish++] = direction;
		myprint("r : %d c: %d direction: %s nFish %d \n", r, c, directionsStr[direction], map[r][c].nFish);
	}

	scanf("%d %d", &shark.row, &shark.col);
	shark.row--, shark.col--;
	myprint("shark r: %d c: %d \n", shark.row, shark.col);

	myprint("Input End===================================\n");
}

int countFish(void) {
	int count = 0;

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			count += map[r][c].nFish;
		}
	}
	return count;
}

void printStatus(void) {
	myprint("%s Start===================================\n", __FUNCTION__);

	for (int r = 0; r < gridSize; r++) {
		for (int c = 0; c < gridSize; c++) {
			myprint("[%d][%d] : smell %s nFishes %d : ", r, c, map[r][c].smellStatus > 0 ? "yes" : "no", map[r][c].nFish);
			for (int i = 0; i < map[r][c].nFish; i++) {
				myprint("%s ", directionsStr[map[r][c].fishDirection[i]]);
			}
			myprint("\n");
		}
		myprint("\n");
	}
	myprint("Shark %d %d \n", shark.row, shark.col);

	myprint("%s End===================================\n", __FUNCTION__);
}

void solve(void) {
	myprint("%s Start===================================\n", __FUNCTION__);

	input();

	for (int round = 0; round < nRounds; round++) {
		myprint("backupMap Start===================================\n");
		backupMap();
		myprint("backupMap End===================================\n");

		myprint("moveFish Start===================================\n");
		moveFish();
		myprint("moveFish End===================================\n");
		printStatus();

		maxScore = -1;
		score = 0;
		myprint("getSharkPlan Start===================================\n");
		getSharkPlan(0, shark.row, shark.col);
		myprint("getSharkPlan End===================================\n");
		myprint("moveShark Start===================================\n");
		moveShark();
		myprint("moveShark End===================================\n");

		myprint("changeSmellStatus Start===================================\n");
		changeSmellStatus();
		myprint("changeSmellStatus End===================================\n");

		myprint("duplicateFish Start===================================\n");
		duplicateFish();
		myprint("duplicateFish End===================================\n");

		printStatus();
	}

	printf("%d \n", countFish());

	myprint("%s End===================================\n", __FUNCTION__);
}

int main(void) {
	solve();

	return 0;
}
