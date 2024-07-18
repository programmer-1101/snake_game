#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define board_size 18

char grid[board_size][board_size];

void initialize_board()
{
    srand(time(NULL));
    int snake_head_position_x = (rand() % 16) + 1;
    int snake_head_position_y = (rand() % 16) + 1;

    int food_position_x;
    int food_position_y;

     do {
        food_position_x = (rand() % 16) + 1;
        food_position_y = (rand() % 16) + 1;
    } while (food_position_x == snake_head_position_x && food_position_y == snake_head_position_y);

    grid[snake_head_position_x][snake_head_position_y] = 'S';
    grid[food_position_x][food_position_y] = 'F';

    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (i == board_size - board_size || i == board_size - 1 || j == board_size - board_size || j == board_size - 1)
            {
                grid[i][j] = '=';
            }
            else if (grid[i][j] != 'S' && grid[i][j] != 'F')
            {
                grid[i][j] = ' ';
            }
        }
    }
}

void print_board()
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            printf(" %c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    initialize_board();
    print_board();
    return 0;
}