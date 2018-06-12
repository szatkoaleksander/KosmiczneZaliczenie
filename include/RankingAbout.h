#ifndef RANKINGABOUT_H
#define RANKINGABOUT_H


class RankingAbout
{
    private:
        sf::Text text;
        vector<pair<string, int> > v;

    public:
        RankingAbout()
        {
            text.setCharacterSize(25);
            text.setFont(font);

            ifstream file("ranking.kz");
            string text = "";
            int point = 0;
            int it = 1;

            while(file >> text >> point)
            {
                v.push_back(make_pair(text, point));
                it++;
            }

            sort(this->v.begin(), this->v.end(), PairComparison);
        }
        virtual ~RankingAbout() {}


        static bool PairComparison(const pair<string,int> &a, const pair<string,int> &b)
        {
            return a.second > b.second;
        }

        vector<sf::Text> GetRanking()
        {
            vector<sf::Text> r;

            //first place
            text.setPosition(450, 100);
            text.setColor(sf::Color::Red);
            text.setString(to_string(1) +  ". " + v[0].first + " _____ " + to_string(v[0].second));

            r.push_back(text);

            for(int i = 1; i < v.size(); i++)
            {
                text.setPosition(450, 100 + (27 * i));
                text.setColor(sf::Color::Yellow);
                text.setString(to_string(i + 1) +  ". " + v[i].first + " _____ " + to_string(v[i].second));

                r.push_back(text);
            }

            return r;
        }

        sf::Text GetAbout()
        {
            sf::Text about("AUTHOR: Aleksander Szatko", font, 25);
            about.setPosition(450, 100);

            return about;
        }
};

#endif // RANKINGABOUT_H
