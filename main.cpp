#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;



void cn()
{
    setlocale(LC_ALL, "RUS");
    RenderWindow window(sf::VideoMode(900, 900), "SFML works!");

    Mouse::setPosition(Vector2i(450, 450), window);

    RectangleShape example(Vector2f(300, 300));
    RectangleShape kn[3][3];

    int x = 0, y = 0, step = 0;
    int win[4] = {0, 0, 0, 0}; // 0 - wbv, 1 - wbh, 2 - wrv, 3 - wrh;
    int windb1 = 0, windr1 = 0;
    int windb2 = 0, windr2 = 0;

    example.setOutlineThickness(15);
    example.setOutlineColor(Color::Black);
    example.setFillColor(Color::White);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            kn[i][j] = example;
            kn[i][j].setPosition(j * 300, i * 300);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                {
                    x = Mouse::getPosition(window).x/300;
                    y = Mouse::getPosition(window).y/300;
                    if (step % 2 == 0 && kn[y][x].getFillColor() == Color::White)
                    {
                        kn[y][x].setFillColor(Color::Blue);
                        step++;
                    }
                    else  if (step % 2 == 1 && kn[y][x].getFillColor() == Color::White)
                    {
                        kn[y][x].setFillColor(Color::Red);
                        step++;
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (kn[i][j].getFillColor() == Color::Blue)
                            {
                                win[1]++;
                            }
                            if (kn[i][j].getFillColor() == Color::Red)
                            {
                                win[3]++;
                            }
                        }
                        if (win[1] == 3 || win[3] == 3)
                        {
                            break;
                        }
                        else
                        {
                            win[1] = 0;
                            win[3] = 0;
                        }
                    }
                    for (int j = 0; j < 3; j++)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            if (kn[i][j].getFillColor() == Color::Blue)
                            {
                                win[0]++;
                            }
                            if (kn[i][j].getFillColor() == Color::Red)
                            {
                                win[2]++;
                            }
                        }
                        if (win[0] == 3 || win[2] == 3)
                        {
                            break;
                        }
                        else
                        {
                            win[0] = 0;
                            win[2] = 0;
                        }
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (kn[i][j].getFillColor() == Color::Blue)
                            {
                                windb1++;
                            }
                            if (kn[i][j].getFillColor() == Color::Red)
                            {
                                windr1++;
                            }
                            i++;
                        }
                        if (windb1 == 3 || windr1 == 3)
                        {
                            break;
                        }
                        else
                        {
                            windb1 = 0;
                            windr1 = 0;
                        }
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 2; j != -1; j--)
                        {
                            if (kn[i][j].getFillColor() == Color::Blue)
                            {
                                windb2++;
                            }
                            if (kn[i][j].getFillColor() == Color::Red)
                            {
                                windr2++;
                            }
                            i++;
                        }
                        if (windb2 == 3 || windr2 == 3)
                        {
                            break;
                        }
                        else
                        {
                            windb2 = 0;
                            windr2 = 0;
                        }
                    }
                    if (win[1] == 3 || win[0] == 3 || windb1 == 3 || windb2 == 3)
                    {
                        window.close();
                        cout << "Голубой победил\n";
                    }
                    if (win[3] == 3 || win[2] == 3 || windr1 == 3 || windr2 == 3)
                    {
                        window.close();
                        cout << "Красный победил\n";
                    }
                    if (step == 9)
                    {
                        window.close();
                        cout << "Ничья\n";
                    }
                }
            }
        }

        window.clear(Color::White);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                window.draw(kn[i][j]);
            }
        }
        window.display();
    }
}
int main()
{
    cn();
    system("pause");
    return 0;
}
