#pragma once

#include "variables.h"
#include <SDL2/SDL.h>
#include <array>

struct Cell
{
    int player = 0;
    SDL_Rect *rect = nullptr;
} typedef cell_t;

class Board
{
public:
    std::array<std::array<cell_t, N>, N> table;
    Board()
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                int posX = CELL_WIDTH * row;
                int posY = CELL_HEIGHT * col;
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
        // Diagonal
        if (table[0][2].player == table[1][1].player && table[0][2].player == table[2][0].player)
        {
            solution = table[0][2].player;
        }
        if (table[0][0].player == table[1][1].player && table[0][0].player == table[2][2].player)
        {
            solution = table[0][0].player;
        }

        return solution;
    }
};
