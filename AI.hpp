#pragma once

#include <vector>
class AI {
public:
    AI();
    ~AI();
    std::vector<int> NextMove(std::vector<std::vector<int> > l_board);
    
    int maxSearch(int l_board[3][3]);

    int minSearch(int l_board[3][3]);

    int Score(int l_board[3][3]);

    int CheckWin(int l_board[3][3], int player);

    bool GameOver(int l_board[3][3]);
};