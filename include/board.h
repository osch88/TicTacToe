#pragma once

#include "variables.h"
#include <array>

struct Cell
{
    int player = 0;
} typedef cell_t;

class Board
{
public:
    std::array<std::array<cell_t, 3>, 3> table;
    Board()
    {
        for (size_t row = 0; row < N; row++)
        {
            for (size_t col = 0; col < N; col++)
            {
                table[row][col].player = 0;
            }
        }
    }
    int Solution()
    {
        int solution = 0;
        // Row && Col
        for (size_t i = 0; i < N; i++)
        {
            if (table[i][0].player == table[i][1].player && table[i][0].player == table[i][2].player && table[i][0].player != 0)
            {
                solution = table[i][0].player;
            }
            if (table[0][i].player == table[1][i].player && table[0][i].player == table[2][i].player && table[0][i].player != 0)
            {
                solution = table[0][i].player;
            }
        }

        return solution;
    }
};
