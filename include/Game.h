#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        sf::RenderWindow *window;
        Player *player;
        vector<Enemy*> *enemy;
        vector<Bullet*> *bullet;

        Text *tScore;
        Text *tScorePoint;
        Text *tLost;
        Text *tLostPoint;
        Text *tTheEnd;

        double time;
        int scorePoint;
        int lostPoint;

    public:
        Game(sf::RenderWindow &window)
        {
            this->window = &window;

            player = new Player();
            enemy = new vector<Enemy*>();
            bullet = new vector<Bullet*>();

            for(int i = 0; i < ENEMY_COUNT; i++)
                enemy->push_back(new Enemy());

            time = 0.0;
            scorePoint = 0;
            lostPoint = 10;

            tScore = new Text("Score:", 2, 0);
            tScorePoint = new Text(scorePoint, 65, 0);
            tLost = new Text("Lost:", 2, 25);
            tLostPoint = new Text(lostPoint, 65, 25);
            tTheEnd = new Text("THE END", 500, 200, 150);
        }
        virtual ~Game()
        {
            NAME = "";
        }

        void Update(double FPS, double lastTime)
        {
            player->Movement(FPS);

            if(time >= 0.25)
            {
                player->Shooting(*bullet);
                time = 0.0;
            }
            time += lastTime;

            for(int i = 0; i < enemy->size(); i++)
            {
                enemy->operator[](i)->Movement(FPS);
                if(Collision::DetectingCollision(player, enemy->operator[](i)))
                {
                    game_state = MENU;
                    ofstream file("ranking.kz", fstream::app);
                    file << NAME << " " << scorePoint << endl;
                }

                if(enemy->operator[](i)->GetPosition().y > 800)
                {
                    enemy->operator[](i) = enemy->back();
                    enemy->pop_back();

                    lostPoint--;
                    tLostPoint->SetText(lostPoint);
                }

                for(int j = 0; j < bullet->size(); j++)
                {
                    bullet->operator[](j)->BulletMovement(FPS / enemy->size());

                    if(bullet->operator[](j)->GetPosition().y < 0)
                    {
                        bullet->operator[](j) = bullet->back();
                        bullet->pop_back();
                    }
                    if(Collision::DetectingCollision(bullet->operator[](j), enemy->operator[](i)))
                    {
                        enemy->operator[](i) = enemy->back();
                        enemy->pop_back();

                        bullet->operator[](j) = bullet->back();
                        bullet->pop_back();


                        Sound::PlaySound("explosion");

                        scorePoint++;
                        tScorePoint->SetText(scorePoint);
                    }
                }
            }

            if(enemy->size() <= 0)
            {
                for(int i = 0; i < ENEMY_COUNT; i++)
                {
                    enemy->push_back(new Enemy());
                    enemy->operator[](i)->SetSpeed(enemy->operator[](i)->GetSpeed() + 0.02);
                }
            }

            if(lostPoint == 0)
            {
                game_state = MENU;
                ofstream file("ranking.kz", fstream::app);
                file << NAME << " " << scorePoint << endl;
            }
        }

        void Draw()
        {
            window->clear();

            for(int i = 0; i < enemy->size(); i++)
                window->draw(enemy->operator[](i)->GetSprite());

            for(int i = 0; i < bullet->size(); i++)
                window->draw(bullet->operator[](i)->GetSprite());

            window->draw(player->GetSprite());

            window->draw(tScore->GetText());
            window->draw(tScorePoint->GetText());
            window->draw(tLost->GetText());
            window->draw(tLostPoint->GetText());

            if(game_state == MENU)
            {
                Sound::PlaySound("theend");
                window->draw(tTheEnd->GetText());


                window->display();
                sf::sleep(sf::seconds(2));
            }
            else
                window->display();
        }
};

#endif // GAME_H
