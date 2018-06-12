#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


enum GAME_STATE
{
    MENU = 1,
    PLAY = 2,
    NEW_GAME = 3,
    EXIT = 4
};

enum MENU_STATE
{
    RANKING = 1,
    ABOUT = 2,
    INPUT_NAME = 3,
    NEUTRAL = 4
};

GAME_STATE game_state;
MENU_STATE menu_state;

sf::Font font;
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 720;
int ENEMY_COUNT = 20;
string NAME = "";

#include <Text.h>
#include <InputTxt.h>
#include <RankingAbout.h>
#include <Button.h>
#include <Menu.h>
#include <Object.h>
#include <Sound.h>
#include <Bullet.h>
#include <Player.h>
#include <Enemy.h>
#include <Collision.h>
#include <Game.h>

///---------TO_DO-----------------
/*
    - NULL
*/

int main()
{
///-----INIT-----
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "KosmiczneZaliczenie");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    srand (time(NULL));

    font.loadFromFile("font/munro.ttf");

    game_state = MENU;

    Menu *menu = new Menu(window);
    Game *game;

    sf::Clock clock;
    double lastTime = 0.0;

///-----MAIN_LOOP-----
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(menu_state == INPUT_NAME)
                InputTxt::Input(event);
        }

        float curTime = clock.restart().asSeconds();
        float FPS = 1.0 / curTime;
        lastTime = curTime;
        window.setTitle("KosmiczneZaliczenie   FPS:" + to_string(FPS));

        switch(game_state)
        {
            case MENU:
                menu->Update();
                menu->Draw();

                break;
            case PLAY:
                game->Update(FPS, lastTime);
                game->Draw();

                break;
            case NEW_GAME:
                game = new Game(window);
                game_state = PLAY;
                menu_state = NEUTRAL;

                break;
            case EXIT:
                window.close();

                break;
        }
    }

    delete game;
    delete menu;
    return 0;
}
