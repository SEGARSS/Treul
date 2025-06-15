#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <random>

#include <vector>
#include <iostream>
#include <chrono>

using namespace sf;
using namespace std;

/*Сделай сначала один прямоугольник и выведи его*/
//--------------------------------------------------------------------------
RectangleShape getRectangleShape(float x, float y, int v, int b)
{
    RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(v, b));
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);
    rectangle.setPosition({ x, y });

    return rectangle;
}
//--------------------------------------------------------------------------
int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 500);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");

    // храним или только вектор прямоугольников, или вектор чисел
    // потому что одновременно и то и другое нам не нужно
    vector<RectangleShape> rectangle;

    //Вектор
    //vector<int> chisla; //Получается, вектор с интами та и не нужен был?

    for (int i = 0; i < 10; i++)
    {
        int tpm = distrib(gen);
        rectangle.push_back(getRectangleShape((10 + i) * 30, 100, 10, tpm));
    }

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }        

        // Очистка окна.
        window.clear();

        for (int i = 0; i < rectangle.size(); i++)
        {
            // выводим уже созданные до game loop прямоугольники
            window.draw(rectangle[i]);
        }

        //Обновить окно
        window.display();
    }
    return 0;
}