#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace sf;
const double pi =3.1415926535;
double sinfunc(double x, double n)
{
    return 200*sin(x*pi/180);
}
double cosfunc(double x, double n)
{
    return 200*cos(x*pi/180);
}
double tanfunc(double x, double n)
{
    return 200*tan(x*pi/180);
}
double multiplierfunc(double x, double n=1)
{
    return x*n;
}
double powx(double x,double n =1)
{
    //dont use powers higher than 3
    return pow(x,n);
}
namespace sf {
    Color getRandomColor() {
        int r = rand() % 256 + 55;
        int g = rand() % 256 + 55;
        int b = rand() % 256 + 55;

        return sf::Color(r, g, b);
    }
}


class Buttons
{
    public:
    bool isPressed=false;
    RectangleShape shape,line;

    Text text;
    double titleX, titleY;
    Color color;
    void checkCollision(const sf::Vector2i& mousePos, sf::Clock& clock) {

            if (mousePos.x >= shape.getPosition().x &&
                mousePos.x <= shape.getPosition().x + shape.getSize().x &&
                mousePos.y >= shape.getPosition().y &&
                mousePos.y <= shape.getPosition().y + shape.getSize().y) {

                // Toggle button state
                isPressed = !isPressed;
                clock.restart();
            }

    }
    int draw_button(RenderWindow& window)
    {
        window.draw(shape);
        window.draw(text);
    }
    void init(double X, double Y, std::string title, double Xp, double Yp, Font &font)
    {
        shape.setSize(Vector2f(X, Y));
        shape.setPosition(sf::Vector2f(Xp, Yp));
        shape.setFillColor(Color::Blue);
    text.setString(title);
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(Color::Red);
    text.setPosition(Vector2f(Xp + X / 10, Yp + Y / 10));
    isPressed = false;
    color=getRandomColor();
    }
    int draw_line(RenderWindow &window,double (*func)(double, double), double n=1)
    {
        if(isPressed == true)
        {
           line.setSize(Vector2f(1,1));
        double j;
        line.setFillColor(color);
        for(double i = -400; i<=400; i+=0.1)
        {
            j=func(i, n);
            if(n==0)
            {
                break;
            }
            //std::cout<<j;
            line.setPosition(Vector2f(window.getSize().y/2+i,window.getSize().y/2-j));
            window.draw(line);
        }
        }

    }
};
Buttons sinbutton, cosbutton, tanbutton,multiplierbutton;

