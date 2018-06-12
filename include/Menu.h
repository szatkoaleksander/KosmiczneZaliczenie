#ifndef MENU_H
#define MENU_H

class Menu
{
    private:
        sf::RenderWindow *window;
        Button *play;
        Button *ranking;
        Button *about;
        Button *exit;

        Text *inputName;

        RankingAbout *ra;
    public:
        Menu(sf::RenderWindow &window)
        {
            this->window = &window;

            play = new Button("Play", window, 70, 100);
            ranking = new Button("Ranking", window, 70, 160);
            about = new Button("About", window, 70, 220);
            exit = new Button("Exit", window, 70, 280);

            inputName = new Text("Input name:", 300, 100, 50);

            ra = new RankingAbout();
        }
        virtual ~Menu() {}

        void Draw()
        {
            window->clear();

            window->draw(play->GetText());
            window->draw(ranking->GetText());
            window->draw(about->GetText());
            window->draw(exit->GetText());

            if(menu_state == INPUT_NAME)
            {
                window->draw(inputName->GetText());
                window->draw(InputTxt::GetText());
            }
            else if(menu_state == RANKING)
            {
                ra = new RankingAbout();

                for(int i = 0; i < ra->GetRanking().size(); i++)
                    window->draw(ra->GetRanking()[i]);
            }
            else if(menu_state == ABOUT)
            {
                window->draw(ra->GetAbout());
            }

            window->display();
        }

        void Update()
        {
            if(play->ActionListener())
                menu_state = INPUT_NAME;
            else if(ranking->ActionListener())
                menu_state = RANKING;
            else if(about->ActionListener())
                menu_state = ABOUT;
            else if(exit->ActionListener())
                game_state = EXIT;
        }
};

#endif // MENU_H
