#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include "player.h"

#include "game.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{

    items_placed = 0;
    game_started = false;

    ui_->setupUi(this);
    view_ = ui_->plotGraphicsView;
    view_2_ = ui_ ->plotGraphicsView_2;
    view_3_ = ui_ ->ships_view;
    view_4_ = ui_ ->ships_view_2;
    board_1_hit_items = 0;
    board_2_hit_items = 0;
    scene_ = new QGraphicsScene;
    scene_2_ = new QGraphicsScene;
    scene_3_ = new QGraphicsScene;
    scene_4_ = new QGraphicsScene;
    ui_->status_label->setText("Player 1 turn to place tiles");
    ui_->place_ship_2->hide();
    ui_->enter_button->hide();
    view_->setScene(scene_);
    // make the scene the same size as the view containing it
    view_->setSceneRect(0,0,view_->frameSize().width(),view_->frameSize().height());
    view_2_->setScene(scene_2_);
    // make the scene the same size as the view containing it
    view_2_->setSceneRect(0,0,view_2_->frameSize().width(),view_2_->frameSize().height());
    view_3_->setScene(scene_3_);
    // make the scene the same size as the view containing it
    view_3_->setSceneRect(0,0,view_3_->frameSize().width(),view_3_->frameSize().height());
    view_4_->setScene(scene_4_);
    // make the scene the same size as the view containing it
    view_4_->setSceneRect(0,0,view_4_->frameSize().width(),view_4_->frameSize().height());

    for(int i = 0; i< 10; i++){
        scene_ ->addLine(0,29+i*29,view_->frameSize().width(),29+i*29);
        scene_ ->addLine(29+i*29,0,29+i*29,view_->frameSize().height());
    }
    for(int i = 0; i< 10; i++){
        scene_2_ ->addLine(0,29+i*29,view_->frameSize().width(),29+i*29);
        scene_2_ ->addLine(29+i*29,0,29+i*29,view_->frameSize().height());
    }
    std::string atoj = "ABCDEFGHIJ";
    for (int i = 1; i <=10; i++){
        QGraphicsTextItem* text = scene_->addText(QString(atoj[i-1]));
        //board[i*10+j] = new Tile(i*10+j+1);
        text->setPos(view_->frameSize().width()/11*i,0);
        //board[i*10+j]->set_x(view->frameSize().width()/10*j);
        //board[i*10+j]->set_y(view->frameSize().height()/10*(9-i));

    }
    for (int i = 1; i <=10; i++){
        QGraphicsTextItem* text = scene_2_->addText(QString(atoj[i-1]));
        //board[i*10+j] = new Tile(i*10+j+1);
        text->setPos(view_2_->frameSize().width()/11*i,0);
        //board[i*10+j]->set_x(view->frameSize().width()/10*j);
        //board[i*10+j]->set_y(view->frameSize().height()/10*(9-i));

    }
    for (int i = 1; i <=10; i++){
        QGraphicsTextItem* text = scene_->addText(QString::number(11-i));
        //board[i*10+j] = new Tile(i*10+j+1);
        text->setPos(0,view_->frameSize().height()/11*(11-i));
        //board[i*10+j]->set_x(view->frameSize().width()/10*j);
        //board[i*10+j]->set_y(view->frameSize().height()/10*(9-i));

    }
    for (int i = 1; i <=10; i++){
        QGraphicsTextItem* text = scene_2_->addText(QString::number(11-i));
        //board[i*10+j] = new Tile(i*10+j+1);
        text->setPos(0,view_2_->frameSize().height()/11*(11-i));
        //board[i*10+j]->set_x(view->frameSize().width()/10*j);
        //board[i*10+j]->set_y(view->frameSize().height()/10*(9-i));

    }
    //Intialize player 1 ships
    Item * ship_1 = new Item(ship, 1, 1, 29, 87);
    Item * ship_2 = new Item(ship, 39, 1, 87, 29);
    Item * ship_3 = new Item(ship, 39, 39, 58, 29);
    Item * ship_4 = new Item(ship, 136, 1, 29, 58);
    Item * ship_5 = new Item(ship, 102, 39, 29, 29);

    //Initialize player 1 chests
    Item * chest_1 = new Item(chest, 184, 1, 29, 29);
    Item * chest_2 = new Item(chest, 184, 39, 29, 29);

    //intialize player 2 ships
    Item * mine_1 = new Item(mine, 223, 1, 29, 29);
    Item * mine_2 = new Item(mine, 223, 39, 29, 29);
/*
    Item * ship_1 = new Item(ship,color, 0, 0, 29, 87);
    Item * ship_2 = new Item(ship,color, 39, 0, 87, 29);
    Item * ship_3 = new Item(ship,color, 39, 39, 58, 29);
    Item * ship_4 = new Item(ship,color, 136, 0, 29, 58);
    Item * ship_5 = new Item(ship,color, 102, 39, 29, 29);

    QColor color_chest(255,215,0);
    Item * chest_1 = new Item(chest,color_chest, 184, 0, 29, 29);
    Item * chest_2 = new Item(chest,color_chest, 184, 39, 29, 29);

    QColor color_mine(0,0,0);
    Item * mine_1 = new Item(mine,color_mine, 223, 0, 29, 29);
    Item * mine_2 = new Item(mine,color_mine, 223, 39, 29, 29);
   */
    // add these to the scene for player 1
    scene_3_->addItem(ship_1);
    scene_3_->addItem(ship_2);
    scene_3_->addItem(ship_3);
    scene_3_->addItem(ship_4);
    scene_3_->addItem(ship_5);
    scene_3_->addItem(chest_1);
    scene_3_->addItem(chest_2);
    scene_3_->addItem(mine_1);
    scene_3_->addItem(mine_2);


    //initialize player 2 items
    Item * ship_6 = new Item(ship, 1, 1, 29, 87);
    Item * ship_7 = new Item(ship, 39, 1, 87, 29);
    Item * ship_8 = new Item(ship, 39, 39, 58, 29);
    Item * ship_9 = new Item(ship, 136, 1, 29, 58);
    Item * ship_10 = new Item(ship, 102, 39, 29, 29);

    Item * chest_3 = new Item(chest, 184, 1, 29, 29);
    Item * chest_4 = new Item(chest, 184, 39, 29, 29);

    Item * mine_3 = new Item(mine, 223, 1, 29, 29);
    Item * mine_4 = new Item(mine, 223, 39, 29, 29);
    /*
    Item * ship_6 = new Item(ship,color, 0, 0, 29, 87);
    Item * ship_7 = new Item(ship,color, 39, 0, 87, 29);
    Item * ship_8 = new Item(ship,color, 39, 39, 58, 29);
    Item * ship_9 = new Item(ship,color, 136, 0, 29, 58);
    Item * ship_10 = new Item(ship,color, 102, 39, 29, 29);

    Item * chest_3 = new Item(chest,color_chest, 184, 0, 29, 29);
    Item * chest_4 = new Item(chest,color_chest, 184, 39, 29, 29);

    Item * mine_3 = new Item(mine,color_mine, 223, 0, 29, 29);
    Item * mine_4 = new Item(mine, color_mine, 223, 39, 29, 29);
    */
    // add these to the scene for player 2
    scene_4_->addItem(ship_6);
    scene_4_->addItem(ship_7);
    scene_4_->addItem(ship_8);
    scene_4_->addItem(ship_9);
    scene_4_->addItem(ship_10);
    scene_4_->addItem(chest_3);
    scene_4_->addItem(chest_4);
    scene_4_->addItem(mine_3);
    scene_4_->addItem(mine_4);
    quit_ = false;

    connect(ship_1, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_2, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_3, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_4, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_5, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_6, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_7, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_8, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_9, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(ship_10, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(chest_1, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(mine_1, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(chest_2, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(mine_2, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(chest_3, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(mine_3, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(chest_4, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    connect(mine_4, &Item::ItemSelected, this, &MainWindow::ItemSelectedSlot);
    player_1_ = new Player({ship_1,ship_2,ship_3,ship_4,ship_5,mine_1,mine_2,chest_1,chest_2});
    player_2_ = new Player({ship_6,ship_7,ship_8,ship_9,ship_10,mine_3,mine_4,chest_3,chest_4});



    connect(ui_->place_ship_1, &QAbstractButton::pressed, this, &MainWindow::PlaceItemSlot1);
    connect(ui_->place_ship_2, &QAbstractButton::pressed, this, &MainWindow::PlaceItemSlot2);
    connect(ui_->Quit_Game, &QAbstractButton::pressed, this, &MainWindow::QuitSlot);
    //connect(ui_->Start_Game, &QAbstractButton::pressed, this, &MainWindow::start_game);
    //game_ = new Game(view_,scene_,view_2_,scene_2_);

    connect(ui_->hide_board_1, &QAbstractButton::pressed, this, &MainWindow::HideBoard1Slot);
    connect(ui_->hide_board_2, &QAbstractButton::pressed, this, &MainWindow::HideBoard2Slot);
    connect(ui_->show_board_1, &QAbstractButton::pressed, this, &MainWindow::ShowBoard1Slot);
    connect(ui_->show_board_2, &QAbstractButton::pressed, this, &MainWindow::ShowBoard2Slot);

    connect(ui_->start_game, &QAbstractButton::pressed, this, &MainWindow::StartGameSlot);
    connect(ui_->enter_button, &QAbstractButton::pressed, this, &MainWindow::AttackSlot);
}

int letterToNumber(std::string new_x)
{
    int new_x_int = 1;
    if(new_x == "A" || new_x == "a")
        new_x_int = 1;
    else if(new_x == "B"|| new_x == "b")
        new_x_int = 2;
    else if(new_x == "C" || new_x == "c")
        new_x_int = 3;
    else if(new_x == "D" || new_x == "d")
        new_x_int = 4;
    else if(new_x == "E" || new_x == "e")
        new_x_int = 5;
    else if(new_x == "F" || new_x == "f")
        new_x_int = 6;
    else if(new_x == "G" || new_x == "g")
        new_x_int = 7;
    else if(new_x == "H" || new_x == "h")
        new_x_int = 8;
    else if(new_x == "I" || new_x == "i")
        new_x_int = 9;
    else if(new_x == "J" || new_x == "j")
        new_x_int = 10;
    else
        new_x_int = 1;


    return new_x_int;
}
void MainWindow::ItemSelectedSlot(Item *p) {
    curr_item_ = p;
}
void MainWindow::HideBoard1Slot(){
    int get_items_size =  player_1_->get_items().size();
    for (int i = 0; i < get_items_size; i++)
    {
            scene_->removeItem(player_1_->get_items()[i]);
    }
}
void MainWindow::HideBoard2Slot(){
    int get_items_size = player_2_->get_items().size();
    for (int i = 0; i < get_items_size; i++)
    {
            scene_2_->removeItem(player_2_->get_items()[i]);
    }
}
void MainWindow::StartGameSlot(){
    /*
    ui_->status_label->setText("Game started");
    ui_->current_player_num->setText("1");
    game_started = true;
    */

    if(items_placed >= 18)
    {
        ui_->status_label->setText("Game started");
        ui_->current_player_num->setText("1");
        ui_->enter_button->show();
        ui_->show_board_1->show();
        game_started = true;

        delete scene_3_;
        delete scene_4_;
    }
    else
    {
        ui_->status_label->setText("place all items first");
    }


}
void MainWindow::AttackSlot(){
    if(game_started == false)
    {
        ui_->status_label->setText("place all items first");
        return;
    }
    if(ui_->current_player_num->text() == "1"){
        std::string new_x = ui_->attack_input_x->text().toStdString();
        ui_->show_board_2->show();
        ui_->show_board_1->hide();
        HideBoard1Slot();
        int new_y = (ui_->attack_input_y->text().toInt())*29;

        int new_x_int = letterToNumber(new_x);

        new_x_int = new_x_int*29;

        //variables to make the loops function properly
        int repeat = 0;
        int check_hit = 0;
        int shot_two_size = shot_two_.size();
        for(int j = 0; j < shot_two_size; j++)
        {
            if(new_y == shot_two_[j]->get_y() && new_x_int == shot_two_[j]->get_x())
            {
                ui_->status_label->setText("You have shot there. Shoot again!");
                repeat = 1;
                break;
            }
        }
        if(repeat == 0)
        {
            int get_items_size = player_2_->get_items().size();
            for(int i = 0; i < get_items_size; i++){
                if(player_2_->get_items()[i]->get_height() == 29 && player_2_->get_items()[i]->get_width() == 29){
                    if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                        if(player_2_->get_items()[i]->get_tiletype() == ship)
                        {
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            player_2_->remove_item(i);
                            shot_two_.push_back(hit_item);
                            scene_2_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            board_2_hit_items++;
                        }
                        else if(player_2_->get_items()[i]->get_tiletype() == chest)
                        {
                            //delete item within player class
                            delete player_2_->get_items()[i];
                            player_2_->remove_item(i);
                            //add new item within window
                            Item* hit_item = new Item(hit_chest, new_x_int, new_y, 29, 29);
                            shot_two_.push_back(hit_item);
                            scene_2_->addItem(hit_item);
                            ui_->status_label->setText("Found a Treasure Chest!");
                            board_2_hit_items++;
                        }
                        else if(player_2_->get_items()[i]->get_tiletype() == mine)
                        {
                            delete player_2_->get_items()[i];
                            player_2_->remove_item(i);
                            Item* hit_item = new Item(hit_mine, new_x_int, new_y, 29, 29);
                            shot_two_.push_back(hit_item);
                            scene_2_->addItem(hit_item);
                             ui_->status_label->setText("Hit a Mine!");
                             board_2_hit_items++;
                        }

                        check_hit++;
                        break;
                    }
                }
                else if (player_2_->get_items()[i]->get_height() == 58 && player_2_->get_items()[i]->get_width() == 29){
                    if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                    else if (new_y == player_2_->get_items()[i]->get_y()+29 && new_x_int == player_2_->get_items()[i]->get_x()){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                }
                else if (player_2_->get_items()[i]->get_height() == 87 && player_2_->get_items()[i]->get_width() == 29){
                    if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                    else if (new_y == player_2_->get_items()[i]->get_y()+29 && new_x_int == player_2_->get_items()[i]->get_x()){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        board_2_hit_items++;
                        check_hit++;
                        break;
                    }
                    else if (new_y == player_2_->get_items()[i]->get_y()+58 && new_x_int == player_2_->get_items()[i]->get_x()){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        board_2_hit_items++;
                        check_hit++;
                        break;
                    }
                }
                else if (player_2_->get_items()[i]->get_height() == 29 && player_2_->get_items()[i]->get_width() == 58){
                    if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                    else if (new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x()+29){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        board_2_hit_items++;
                        check_hit++;
                        break;
                    }
                }
                else {
                    if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                    else if (new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x()+29){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                    else if (new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x()+58){
                        Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                        shot_two_.push_back(hit_item);
                        scene_2_->addItem(hit_item);
                        ui_->status_label->setText("Hit a Ship!");
                        check_hit++;
                        board_2_hit_items++;
                        break;
                    }
                }
            }
            if (check_hit == 0){
                Item* missed_item = new Item(miss, new_x_int, new_y, 29, 29);
                scene_2_->addItem(missed_item);
                shot_two_.push_back(missed_item);
                ui_->status_label->setText("Miss!");
            }
            if(board_2_hit_items == 15){
                ui_->status_label->setText("Game won by Player 1!");
                ui_->enter_button->hide();
                ShowBoard1Slot();
                ShowBoard2Slot();
            }

            ui_->current_player_num->setText("2");
        }

    }
    else{
        std::string new_x = ui_->attack_input_x->text().toStdString();
        ui_->show_board_1->show();
        ui_->show_board_2->hide();
        HideBoard2Slot();
        int new_y = (ui_->attack_input_y->text().toInt())*29;

        int new_x_int = letterToNumber(new_x);

        new_x_int = new_x_int*29;

        int repeat = 0;
        int check_hit = 0;

        //first check if they have already shot there
        int shot_1_size = shot_one_.size();
            for(int j = 0; j < shot_1_size; j++)
            {
                if(new_y == shot_one_[j]->get_y() && new_x_int == shot_one_[j]->get_x())
                {
                    ui_->status_label->setText("You have shot there. Shoot again!");
                    repeat = 1;
                    break;
                }
            }
            if(repeat == 0)
            {
                int get_items_size = player_1_->get_items().size();
                for(int i = 0; i < get_items_size; i++){
                    if(player_1_->get_items()[i]->get_height() == 29 && player_1_->get_items()[i]->get_width() == 29){
                        if(new_y == player_1_->get_items()[i]->get_y() && new_x_int == player_1_->get_items()[i]->get_x() ){
                            if(player_1_->get_items()[i]->get_tiletype() == ship)
                            {
                                Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                                shot_one_.push_back(hit_item);
                                scene_->addItem(hit_item);
                                ui_->status_label->setText("Hit a Ship!");
                                board_1_hit_items++;
                            }
                            else if(player_1_->get_items()[i]->get_tiletype() == chest)
                            {
                                //delete item within player class
                                delete player_1_->get_items()[i];
                                player_1_->remove_item(i);
                                //add new item within window
                                Item* hit_item = new Item(hit_chest, new_x_int, new_y, 29, 29);
                                shot_one_.push_back(hit_item);
                                scene_->addItem(hit_item);
                                ui_->status_label->setText("Found a Treasure Chest!");
                                board_1_hit_items++;
                            }
                            else if(player_1_->get_items()[i]->get_tiletype() == mine)
                            {
                                delete player_1_->get_items()[i];
                                player_1_->remove_item(i);
                                Item* hit_item = new Item(hit_mine, new_x_int, new_y, 29, 29);
                                shot_one_.push_back(hit_item);
                                scene_->addItem(hit_item);
                                 ui_->status_label->setText("Hit a Mine!");
                                 board_1_hit_items++;
                            }

                            check_hit++;
                            break;
                        }
                    }
                    else if (player_1_->get_items()[i]->get_height() == 58 && player_1_->get_items()[i]->get_width() == 29){
                        if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                        else if (new_y == player_1_->get_items()[i]->get_y()+29 && new_x_int == player_1_->get_items()[i]->get_x()){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                    }
                    else if (player_1_->get_items()[i]->get_height() == 87 && player_1_->get_items()[i]->get_width() == 29){
                        if(new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x() ){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                        else if (new_y == player_1_->get_items()[i]->get_y()+29 && new_x_int == player_1_->get_items()[i]->get_x()){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                        else if (new_y == player_1_->get_items()[i]->get_y()+58 && new_x_int == player_1_->get_items()[i]->get_x()){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                    }
                    else if (player_1_->get_items()[i]->get_height() == 29 && player_1_->get_items()[i]->get_width() == 58){
                        if(new_y == player_1_->get_items()[i]->get_y() && new_x_int == player_1_->get_items()[i]->get_x() ){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                        else if (new_y == player_1_->get_items()[i]->get_y() && new_x_int == player_1_->get_items()[i]->get_x()+29){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                    }
                    else {
                        if(new_y == player_1_->get_items()[i]->get_y() && new_x_int == player_1_->get_items()[i]->get_x() ){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                        else if (new_y == player_1_->get_items()[i]->get_y() && new_x_int == player_1_->get_items()[i]->get_x()+29){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_two_.push_back(hit_item);
                            scene_2_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                        else if (new_y == player_2_->get_items()[i]->get_y() && new_x_int == player_2_->get_items()[i]->get_x()+58){
                            Item* hit_item = new Item(hit_ship, new_x_int, new_y, 29, 29);
                            shot_one_.push_back(hit_item);
                            scene_->addItem(hit_item);
                            ui_->status_label->setText("Hit a Ship!");
                            check_hit++;
                            board_1_hit_items++;
                            break;
                        }
                }
                if (check_hit == 0){
                    Item* missed_item = new Item(miss, new_x_int, new_y, 29, 29);
                    shot_one_.push_back(missed_item);
                    scene_->addItem(missed_item);
                     ui_->status_label->setText("Miss!");
                }
                ui_->current_player_num->setText("1");
                if (board_1_hit_items == 15){
                    ui_->status_label->setText("Game won by player 2!");
                    ui_->enter_button->hide();
                    ShowBoard1Slot();
                    ShowBoard2Slot();
                }

            }
        }
    }
}

void MainWindow::ShowBoard1Slot(){
    //first delete items from scene in window class
    //so they can show on top of items in player class
    int shot_one_size = shot_one_.size();
    for(int i = 0; i < shot_one_size; i++)
    {
        scene_->removeItem(shot_one_[i]);
    }
    int get_items_size = player_1_->get_items().size();
    for (int i = 0; i < get_items_size; i++)
    {
        if (player_1_->get_items()[i]->get_x()%29 == 0)
            scene_->addItem(player_1_->get_items()[i]);
        else
            scene_3_->addItem(player_1_->get_items()[i]);
    }
    //add items back after adding items from player
    for(int i = 0; i < shot_one_size; i++)
    {
        scene_->addItem(shot_one_[i]);
    }
}
void MainWindow::ShowBoard2Slot(){
    //remove
    int shot_two_size = shot_two_.size();
    for(int i = 0; i < shot_two_size; i++)
    {
        scene_2_->removeItem(shot_two_[i]);
    }
    //add player items
    int get_items_size = player_2_->get_items().size();
    for (int i = 0; i < get_items_size; i++)
    {
        if (player_2_->get_items()[i]->get_x()%29 == 0)
            scene_2_->addItem(player_2_->get_items()[i]);
        else
            scene_4_->addItem(player_2_->get_items()[i]);
    }
    //add shot items back
    for(int i = 0; i < shot_two_size; i++)
    {
        scene_2_->addItem(shot_two_[i]);
    }
}
void MainWindow::PlaceItemSlot1() {
    if (curr_item_ != NULL)
    {
        std::string new_x = ui_->ship_input_x->text().toStdString();
        int new_y = (ui_->ship_input_y->text().toInt())*29;

        int new_x_int = letterToNumber(new_x);

        new_x_int = new_x_int*29;
        curr_item_->set_y(new_y);
        curr_item_->set_x(new_x_int);
        curr_item_->set_tiletype(curr_item_->get_prev_tiletype());
        scene_3_->removeItem(curr_item_);
        scene_->addItem(curr_item_);

        items_placed++;
        if (items_placed == 9){
            ui_->status_label->setText("Player 2 turn to place tiles");
            ui_->place_ship_1->hide();
            ui_->place_ship_2->show();
            ui_->show_board_1->hide();
            HideBoard1Slot();
        }
    }

}
void MainWindow::PlaceItemSlot2() {
    if (curr_item_ != NULL)
    {
        std::string new_x = ui_->ship_input_x->text().toStdString();
        int new_y = (ui_->ship_input_y->text().toInt())*29;

        int new_x_int = letterToNumber(new_x);

        new_x_int = new_x_int*29;
        curr_item_->set_y(new_y);
        curr_item_->set_x(new_x_int);
        curr_item_->set_tiletype(curr_item_->get_prev_tiletype());
        scene_4_->removeItem(curr_item_);
        scene_2_->addItem(curr_item_);

        items_placed++;
        if (items_placed == 18){
            ui_->status_label->setText("Able to start game now");
            ui_->place_ship_2->hide();
            HideBoard2Slot();
            ui_->show_board_2->hide();
        }
    }

}

void MainWindow::QuitSlot() {
    quit_ = true;
}

MainWindow::~MainWindow()
{
    delete ui_;
}

