#include "AI.hpp"
#include <vector>


AI::AI() {

}

AI::~AI() {
    
}

std::vector<int> AI::NextMove(std::vector<std::vector<int> > l_board) { 
    int bestMoveScore = 100; // -100 is arbitrary
    int new_board[3][3];

    for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
            new_board[i][j] = l_board[i][j];
        }
    }


	std::vector<int> bestMove = {0,0};

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(new_board[i][j] == 0) {
				new_board[i][j] = 2;
				int tempMoveScore = maxSearch(new_board);
				if(tempMoveScore <= bestMoveScore) {
					bestMoveScore = tempMoveScore;
					bestMove[0] = i;
					bestMove[1] = j;
				}
				new_board[i][j] = 0;
			}
		}
	}

	return bestMove;
}

int AI::maxSearch(int l_board[3][3]) {
	if(GameOver(l_board)) return Score(l_board);
	std::vector<int> bestMove;

	int bestMoveScore = -1000;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(l_board[i][j] == 0) {
				l_board[i][j] = 1;
				int tempMoveScore = minSearch(l_board);
				if(tempMoveScore >= bestMoveScore) {
					bestMoveScore = tempMoveScore;
					bestMove.push_back(i);
					bestMove.push_back(j);
				}
				l_board[i][j] = 0;
			}
		}
	}

	return bestMoveScore;
}

int AI::minSearch(int l_board[3][3]) {
	if(GameOver(l_board)) return Score(l_board);
    std::vector<int> bestMove;

	int bestMoveScore = 1000; 
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(l_board[i][j] == 0) {
				l_board[i][j] = 2;
				int tempMove = maxSearch(l_board);
				if(tempMove <= bestMoveScore) {
					bestMoveScore = tempMove;
					bestMove.push_back(i);
					bestMove.push_back(j);
				}
				l_board[i][j] = 0;
			}
		}
	}

	return bestMoveScore;
}

int AI::CheckWin(int l_board[3][3],int player){
    for(int i = 0; i < 3; i++) {
		// Check horizontals
		if(l_board[i][0] == player && l_board[i][1] == player
			&& l_board[i][2] == player)
			return true;

		// Check verticals
		if(l_board[0][i] == player && l_board[1][i] == player
			&& l_board[2][i] == player)
			return true;
	}

	// Check diagonals
	if (l_board[0][0] == player && l_board[1][1] == player 
		&& l_board[2][2] == player) {
		return true;
	} else if (l_board[0][2] == player && l_board[1][1] == player 
		&& l_board[2][0] == player) {
		return true;
	}

	return false;
}

int AI::Score(int l_board[3][3]) {
    if (CheckWin(l_board,1)) {
        return 10;
    } else if (CheckWin(l_board,2)) {
        return -10;
    } else {
        return 0;
    }
}

bool AI::GameOver(int l_board[3][3]){
    if (CheckWin(l_board,1)) { return true;}
    else if (CheckWin(l_board,2)) { return true;}
    bool result{true};
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            if (l_board[i][j] == 0) {
                result = false;
            }
        }
    }
    return result;
}