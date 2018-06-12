#ifndef TEXT_H
#define TEXT_H


class Text
{
    private:
        sf::Text text;


    public:
        Text(int content, int x, int y, int charSize = 24)
        {
            text.setFont(font);
            text.setString(to_string(content));
            text.setCharacterSize(charSize);
            text.setPosition(x, y);
        }

        Text(string content, int x, int y, int charSize = 24)
        {
            text.setFont(font);
            text.setString(content);
            text.setCharacterSize(charSize);
            text.setPosition(x, y);
        }

        Text(string content, int x, int y, int charSize, sf::Color color)
        {
            text.setFont(font);
            text.setString(content);
            text.setCharacterSize(charSize);
            text.setPosition(x, y);
            text.setColor(color);
        }


        virtual ~Text() {}

        void SetText(int content)
        {
            text.setString(to_string(content));
        }

        void SetText(string content)
        {
            text.setString(content);
        }

        sf::Text GetText()
        {
            return text;
        }
};

#endif // TEXT_H
