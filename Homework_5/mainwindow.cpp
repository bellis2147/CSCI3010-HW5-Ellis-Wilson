#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include "player.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    view_ = ui_->plotGraphicsView;
    view_2_ = ui_ ->plotGraphicsView_2;
    view_3_ = ui_ ->ships_view;
    view_4_ = ui_ ->ships_view_2;

    scene_ = new QGraphicsScene;
    scene_2_ = new QGraphicsScene;
    scene_3_ = new QGraphicsScene;
    scene_4_ = new QGraphicsScene;
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
    QColor color(150,75,0);
    Item * ship_1 = new Item(color, 1, 1, 29, 87);
    Item * ship_2 = new Item(color, 39, 1, 87, 29);
    Item * ship_3 = new Item(color, 39, 39, 58, 29);
    Item * ship_4 = new Item(color, 136, 1, 29, 58);
    Item * ship_5 = new Item(color, 102, 39, 29, 29);

    QColor color_chest(255,215,0);
    Item * chest_1 = new Item(color_chest, 184, 1, 29, 29);
    Item * chest_2 = new Item(color_chest, 184, 39, 29, 29);

    QColor color_mine(0,0,0);
    Item * mine_1 = new Item(color_mine, 223, 1, 29, 29);
    Item * mine_2 = new Item(color_mine, 223, 39, 29, 29);

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

    Item * ship_6 = new Item(color, 1, 1, 29, 87);
    Item * ship_7 = new Item(color, 39, 1, 87, 29);
    Item * ship_8 = new Item(color, 39, 39, 58, 29);
    Item * ship_9 = new Item(color, 136, 1, 29, 58);
    Item * ship_10 = new Item(color, 102, 39, 29, 29);

    Item * chest_3 = new Item(color_chest, 184, 1, 29, 29);
    Item * chest_4 = new Item(color_chest, 184, 39, 29, 29);

    Item * mine_3 = new Item(color_mine, 223, 1, 29, 29);
    Item * mine_4 = new Item(color_mine, 223, 39, 29, 29);
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
    //game_ = new Game(view_,scene_,view_2_,scene_2_);

    connect(ui_->hide_board_1, &QAbstractButton::pressed, this, &MainWindow::HideBoard1Slot);
    connect(ui_->hide_board_2, &QAbstractButton::pressed, this, &MainWindow::HideBoard2Slot);
    connect(ui_->show_board_1, &QAbstractButton::pressed, this, &MainWindow::ShowBoard1Slot);
    connect(ui_->show_board_2, &QAbstractButton::pressed, this, &MainWindow::ShowBoard2Slot);
}

void MainWindow::ItemSelectedSlot(Item *p) {
    curr_item_ = p;

}
void MainWindow::HideBoard1Slot(){
    for (int i = 0; i < 9; i++)
    {
        scene_->removeItem(player_1_->get_items()[i]);
    }
}
void MainWindow::HideBoard2Slot(){
    for (int i = 0; i < 9; i++)
    {
        scene_2_->removeItem(player_2_->get_items()[i]);
    }
}
void MainWindow::ShowBoard1Slot(){
    for (int i = 0; i < 9; i++)
    {
        if (player_1_->get_items()[i]->get_x()%29 == 0)
            scene_->addItem(player_1_->get_items()[i]);
        else
            scene_3_->addItem(player_1_->get_items()[i]);
    }
}
void MainWindow::ShowBoard2Slot(){
    for (int i = 0; i < 9; i++)
    {
        if (player_2_->get_items()[i]->get_x()%29 == 0)
            scene_2_->addItem(player_2_->get_items()[i]);
        else
            scene_4_->addItem(player_2_->get_items()[i]);
    }
}
void MainWindow::PlaceItemSlot1() {
    if (curr_item_ != NULL)
    {
        std::string new_x = ui_->ship_input_x->text().toStdString();
        int new_y = (ui_->ship_input_y->text().toInt())*29;
        int new_x_int = 1;
        if(new_x == "A")
            new_x_int = 1;
        else if(new_x == "B")
            new_x_int = 2;
        else if(new_x == "C")
            new_x_int = 3;
        else if(new_x == "D")
            new_x_int = 4;
        else if(new_x == "E")
            new_x_int = 5;
        else if(new_x == "F")
            new_x_int = 6;
        else if(new_x == "G")
            new_x_int = 7;
        else if(new_x == "H")
            new_x_int = 8;
        else if(new_x == "I")
            new_x_int = 9;
        else if(new_x == "J")
            new_x_int = 10;
        else
            new_x_int = 1;
        new_x_int = new_x_int*29;
        curr_item_->set_y(new_y);
        curr_item_->set_x(new_x_int);
        QColor color(150,75,0);
        curr_item_->set_color(color);
        scene_3_->removeItem(curr_item_);
        scene_->addItem(curr_item_);
    }

}
void MainWindow::PlaceItemSlot2() {
    if (curr_item_ != NULL)
    {
        std::string new_x = ui_->ship_input_x->text().toStdString();
        int new_y = (ui_->ship_input_y->text().toInt())*29;
        int new_x_int = 1;
        if(new_x == "A")
            new_x_int = 1;
        else if(new_x == "B")
            new_x_int = 2;
        else if(new_x == "C")
            new_x_int = 3;
        else if(new_x == "D")
            new_x_int = 4;
        else if(new_x == "E")
            new_x_int = 5;
        else if(new_x == "F")
            new_x_int = 6;
        else if(new_x == "G")
            new_x_int = 7;
        else if(new_x == "H")
            new_x_int = 8;
        else if(new_x == "I")
            new_x_int = 9;
        else if(new_x == "J")
            new_x_int = 10;
        else
            new_x_int = 1;
        new_x_int = new_x_int*29;
        curr_item_->set_y(new_y);
        curr_item_->set_x(new_x_int);
        QColor color(150,75,0);
        curr_item_->set_color(color);
        scene_4_->removeItem(curr_item_);
        scene_2_->addItem(curr_item_);
    }

}
void MainWindow::QuitSlot() {
    quit_ = true;

}

MainWindow::~MainWindow()
{
    delete ui_;
}

