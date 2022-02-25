#pragma once

#include "variables.h"
#include <SDL2/SDL.h>
#include <array>

enum STATE
{
    EMPTY = 0,
    PLAYER1,
    PLAYER2
};
struct Cell
{
    int player = 0;
    SDL_Rect rect;
    SDL_Rect *pRect = nullptr;
} typedef cell_t;

class Game
{
public:
    Game()
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                int posX = CELL_WIDTH * row;
                int posY = CELL_HEIGHT * col;

                table[row][col].rect = {
                    .x = CELL_WIDTH * col,
                    .y = CELL_HEIGHT * row,
                    .w = CELL_WIDTH,
                    .h = CELL_HEIGHT};
                table[row][col].pRect = &table[row][col].rect;
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
        // Draw
        int counter = 0;
        if (solution == 0)
        {
            for (int row = 0; row < N; row++)
            {
                for (int col = 0; col < N; col++)
                {
                    if (table[row][col].player != 0)
                    {
                        counter++;
                    }
                }
            }
            if (counter == N*N)
            {
                solution = -1;
            }
        }

        return solution;
    }

    STATE getPlayer(const int row, const int col)
    {
        if (table[row][col].player == 1)
        {
            return STATE::PLAYER1;
        }
        else if (table[row][col].player == 2)
        {
            return STATE::PLAYER2;
        }
        else
        {
            return STATE::EMPTY;
        }
    }

    SDL_Rect *getRect(const int row, const int col)
    {
        return table[row][col].pRect;
    }

    void UpdateBoard(const SDL_Point _MousePos)
    {
        if (table[_MousePos.y / CELL_HEIGHT][_MousePos.x / CELL_WIDTH].player == 0)
        {
            table[_MousePos.y / CELL_HEIGHT][_MousePos.x / CELL_WIDTH].player = m_Player;
            if (m_Player == 1)
            {
                m_Player = 2;
            }
            else
            {
                m_Player = 1;
            }
        }
    }

    void resetBoard()
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                table[row][col].player = 0;
            }
        }
        std::cout << "Board has been reseted" << std::endl;
    }

public:
    std::array<std::array<cell_t, N>, N>
        table;

private:
    int m_Player = 1;
};
