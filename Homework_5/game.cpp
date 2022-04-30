#include "game.h"

//Game::Game(QGraphicsView *view, QGraphicsScene * scene, QGraphicsView *view_2, QGraphicsScene * scene_2 )
Game::Game()
{
    /*view_ = view;
    scene_ = scene;
    view_2_ = view_2;
    scene_2_ = scene_2;*/

    int x = 0;
    int y = 0;
    //Set the values for all tiles in each tile set
    for(int i = 0; i < 10; i++)
    {
        x = 0;
        y = y + 10;
        for(int j = 0; j < 10; j++)
        {
            x = x + 10;
            //set the types to empty
            tileset_one[i][j].type = empty;
            tileset_two[i][j].type = empty;
            //set the x and y positions
            tileset_one[i][j].x_pos = x;
            tileset_one[i][j].y_pos = y;

            tileset_two[i][j].x_pos = x;
            tileset_two[i][j].y_pos = y;
        }
    }
}

void Game::change_tile(Tiletype new_type, int set_num, int x_pos, int y_pos)
{
    if(set_num == 1)
    {
        for(int i = 0; i < 10; i++)
        {
            if(tileset_one[i][0].x_pos == x_pos)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(tileset_one[i][j].y_pos == y_pos)
                    {
                        tileset_one[i][j].type = new_type;
                        break;
                    }
                }
                break;
            }
        }
    }
    else if(set_num == 2)
    {
        for(int i = 0; i < 10; i++)
        {
            if(tileset_two[i][0].x_pos == x_pos)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(tileset_two[i][j].y_pos == y_pos)
                    {
                        tileset_two[i][j].type = new_type;
                        break;
                    }
                }
                break;
            }
        }

    }

}

Tile Game::get_tile(int set_num, int x_pos, int y_pos)
{
    if(set_num == 1)
    {
        for(int i = 0; i < 10; i++)
        {
            if(tileset_one[i][0].x_pos == x_pos)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(tileset_one[i][j].y_pos == y_pos)
                    {
                        return tileset_one[i][j];
                        break;
                    }
                }
                break;
            }
        }
    }
    else if(set_num == 2)
    {
        for(int i = 0; i < 10; i++)
        {
            if(tileset_two[i][0].x_pos == x_pos)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(tileset_two[i][j].y_pos == y_pos)
                    {
                        return tileset_two[i][j];
                        break;
                    }
                }
                break;
            }
        }

    }

}

void Game::next_turn()
{
    if(player_turn_ == 1)
    {
        player_turn_ = 2;
    }
    else
    {
        player_turn_ = 1;
    }
}
int Game::get_player_turn()
{
    return player_turn_;
}
/*
QRectF Game::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

// define the actual shape of the object
QPainterPath Game::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}
*/
