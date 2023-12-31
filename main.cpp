#include "mathfunc.hpp"
#include <string.h>
int wdX = 1000, wdY=700;
int main()
{
    std::string inputStr;
    int n = 0;
    srand(static_cast<unsigned int>(time(NULL)));
    //constants
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return 0;
    }

    sinbutton.text.setFont(font);
    //window Height & Width
    sf::RenderWindow window(sf::VideoMode(wdX, wdY), "Graph builder");
    window.setVerticalSyncEnabled(true);
    sf::Vector2i mousePosition;
    /////////////////////////////////////////////////////
    sinbutton.init(150.d,100.d, "sin()", 750, 50, font);
    cosbutton.init(150.d,100.d, "cos()",750,200, font);
    tanbutton.init(150.d,100.d, "tan()", 750, 350, font);
    multiplierbutton.init(150.d,100.d, "n*x", 750, 600, font);
    //ok ---->get a string--->check number/ --- add number in string or multiplier--->
    //////////////////////////////////////////////////////
    Clock clickCooldown;
    CircleShape shape(1.f);
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
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= 48 && event.text.unicode <= 57) {
                    // If entered character is a digit (0-9)
                    inputStr += static_cast<char>(event.text.unicode);
                    n*=10;
                    n+=(static_cast<char>(event.text.unicode))-48;

                }
                if(event.text.unicode == 13)
                {
                    n=0;
                    inputStr.clear();
                }
            }
            std::cout<<inputStr<<"\n";
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //std::cout<<cosbutton.isPressed;
        if (Mouse::isButtonPressed(sf::Mouse::Left) && clickCooldown.getElapsedTime().asMilliseconds() > 200)  { //standby
        mousePosition = sf::Mouse::getPosition(window);
        sinbutton.checkCollision(mousePosition, clickCooldown);
        cosbutton.checkCollision(mousePosition, clickCooldown);
        tanbutton.checkCollision(mousePosition, clickCooldown);
        multiplierbutton.checkCollision(mousePosition,clickCooldown);
        clickCooldown.restart();
    }


        sinbutton.draw_line(window, sinfunc);
        cosbutton.draw_line(window,cosfunc);
        tanbutton.draw_line(window,tanfunc);
        multiplierbutton.draw_line(window,multiplierfunc, n);
        ///message to future me: please complete multiplier function by showing directly under the button the input and once the enter is pressed
        ///
        ///
        window.draw(ox);
        window.draw(oy);
        window.draw(bg);
        sinbutton.draw_button(window);
        cosbutton.draw_button(window);
        tanbutton.draw_button(window);
        multiplierbutton.draw_button(window);
        window.display();
        window.clear();

    }
    return 0;
}

