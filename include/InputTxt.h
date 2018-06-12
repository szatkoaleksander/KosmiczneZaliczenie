#ifndef INPUTTXT_H
#define INPUTTXT_H


class InputTxt
{
    private:

    public:
        static Text *name;

        static void Input(sf::Event event)
        {
            if(menu_state == INPUT_NAME)
            {
                if(event.type == sf::Event::TextEntered)
                {
                    if(event.text.unicode == 13)
                    {
                        game_state = NEW_GAME;
                    }
                    else if(event.text.unicode == 8 && NAME.size() > 0)
                    {
                        NAME.pop_back();
                        name->SetText(NAME);
                    }
                    else if(event.text.unicode < 128 && event.text.unicode != 8 && NAME.size() < 17)
                    {
                        NAME += (char)(event.text.unicode);
                        name->SetText(NAME);
                    }
                }
            }
        }

        static sf::Text GetText()
        {
            return name->GetText();
        }
};
Text *InputTxt::name = new Text("", 550, 100, 50, sf::Color::Green);

#endif // INPUTTXT_H
