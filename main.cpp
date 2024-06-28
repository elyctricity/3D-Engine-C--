#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Cube.h"
#include "Camera.h"
#include "Projection.h"

int main()
{
    const double WIDTH = 1280;
    const double HEIGHT = 720;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "3D Engine in C++");
    sf::View view(sf::Vector2f(1280.f, 720.f+100.f), sf::Vector2f(WIDTH+100, HEIGHT+100));
    window.setFramerateLimit(60);
    sf::Clock Clock;

    std::vector<std::vector<double>> init_cam_pos = {{0.5}, {1}, {-4}}; 
    Camera* camera = new Camera(init_cam_pos, HEIGHT, WIDTH);
    Projection* projection = new Projection(camera, HEIGHT, WIDTH);
    Cube* cube = new Cube(HEIGHT, WIDTH);
    cube->translate(0.2, 0.4, 0.2);
    cube->rotate_y(M_PI / 6);

    double angle = 0;

    while (window.isOpen())
    {
        sf::Time elapsed = Clock.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();

        camera->control();

        window.setView(view);

        window.clear();

        angle += 0.01;

        cube->screen_projection(camera, projection, window);
        window.display();
    }

    return 0;
}