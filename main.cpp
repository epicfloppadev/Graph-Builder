#include "Headers/mathfunc.hpp"
int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    //constants
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return 0;
    }
    sinbutton.text.setFont(font);
    int wdX = 1000, wdY=700;//window Height & Width
    sf::RenderWindow window(sf::VideoMode(wdX, wdY), "Graph builder");
    sf::Vector2i mousePosition;
    sinbutton.init(150.d,100.d, "sin()", 750, 50, font);
    cosbutton.init(150.d,100.d, "cos()",750,200, font);
    sf::Clock clickCooldown;
    sf::CircleShape shape(1.f);
    shape.setFillColor(getRandomColor());
    RectangleShape ox(Vector2f(2,wdX)),oy(Vector2f(wdX,2));
    RectangleShape bg(Vector2f(300.f,700.f));
    float y;
    ox.setPosition(wdY/2,0);
    oy.setPosition(0,wdY/2);
    bg.setPosition(700,0);
    bg.setFillColor(Color::Green);

while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout<<cosbutton.isPressed;
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
        mousePosition = sf::Mouse::getPosition(window);
        sinbutton.checkCollision(mousePosition, clickCooldown);
        cosbutton.checkCollision(mousePosition, clickCooldown);
    }

        window.draw(ox);
        window.draw(oy);
        sinbutton.draw_line(window, sinfunc);
        cosbutton.draw_line(window,cosfunc);
        window.draw(bg);
        sinbutton.draw_button(window);
        cosbutton.draw_button(window);
        window.display();
        window.clear();

    }
    return 0;
}

