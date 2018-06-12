#ifndef BUTTON_H
#define BUTTON_H

class Button
{
    private:
        sf::RenderWindow *window;
        sf::Mouse mouse;
        sf::Vector2i positionMouseTermsWindow; //pozycja myszko wzgledem okna
        sf::Vector2f positionMouseOnScene; //pozycja myszki na scenie

        sf::FloatRect boundingBox;

        sf::Text text;

        int xButton;
        int yButton;

    public:
        Button(string name, sf::RenderWindow &window, int x, int y)
        {
            this->window = &window;

            text.setString(name);
            text.setCharacterSize(50);
            text.setFont(font);
            text.setColor(sf::Color::White);
            text.setPosition(x, y);
        }
        virtual ~Button() {}

        bool ActionListener()
        {
            positionMouseTermsWindow = mouse.getPosition(*window);
            positionMouseOnScene = window->mapPixelToCoords(positionMouseTermsWindow);

            boundingBox = text.getGlobalBounds();

            if(boundingBox.contains(positionMouseOnScene))
            {
                text.setColor(sf::Color::Blue);

                if( sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    text.setColor(sf::Color::Red);

                    return true;
                }
            }
            else
            {
                text.setColor(sf::Color::White);
            }

            return false;
        } //actionListener

        sf::Text GetText()
        {
            return text;
        }
};

#endif // BUTTON_H
