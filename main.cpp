#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;
using namespace sf;

//Assets
Texture texturaBall;
Sprite spriteBall;
Texture paleta1;
Sprite spriteP1;
Texture paleta2;
Sprite spriteP2;
Font fuente;
Text contP1, contP2;
//Variables globales(velocidades y contadores)
float speedX = 2;
float speedY = 2;
int contJ1 = 0;
int contJ2 = 0;





int main()
{
    //Cargamos todos los assets que vamos a usar para cada objeto
    if (!texturaBall.loadFromFile("textures/ball.png"))
    {
        cout << "Error al cargar textura de la bola" << endl;
    }
    if (!paleta1.loadFromFile("textures/paddle1.png"))
    {
        cout << "Error al cargar textura de la paleta" << endl;
    }

    if (!paleta2.loadFromFile("textures/paddle2.png"))
    {
        cout << "Error al cargar textura de la paleta" << endl;
    }

    if (!fuente.loadFromFile("font/pixelart.ttf"))
    {
        cout << "Error al cargar fuentes" << endl;
    }

    //Les asignamos las texturas,ajustamos tamaño y ubicacion
    spriteBall.setTexture(texturaBall);
    spriteBall.setOrigin((float)texturaBall.getSize().x/2, (float)texturaBall.getSize().y / 2);
    spriteBall.setPosition(400, 300);
    spriteBall.setScale(0.17f, 0.17f);

    spriteP1.setTexture(paleta1);
    spriteP1.setOrigin((float)paleta1.getSize().x / 2, (float)paleta1.getSize().y / 2);
    spriteP1.setPosition(10, 300);

    spriteP2.setTexture(paleta2);
    spriteP2.setOrigin((float)paleta2.getSize().x / 2, (float)paleta2.getSize().y / 2);
    spriteP2.setPosition(790, 300);

    contP1.setFont(fuente);
    contP1.setCharacterSize(40);
    contP1.setPosition(350, 25);
    contP1.setString(to_string(contJ1));

    contP2.setFont(fuente);
    contP2.setCharacterSize(40);
    contP2.setPosition(450, 25);
    contP2.setString(to_string(contJ2));


    //Creamos la ventana de juego
    RenderWindow gameWindow(VideoMode(800, 600), "Pong");
    gameWindow.setFramerateLimit(160);//Limitamos los frames para que sea estable y las velocidades de la pelota no se descontrolen
    while (gameWindow.isOpen())
    {
        Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                gameWindow.close();
            }
        }

        //Creamos la logica de la pelota y como se mueve
        spriteBall.move(speedX, speedY);
        if (spriteP1.getGlobalBounds().contains((float)spriteBall.getPosition().x, (float)spriteBall.getPosition().y) ||
            spriteP2.getGlobalBounds().contains((float)spriteBall.getPosition().x, (float)spriteBall.getPosition().y))
        {
            //Si la pelota golpea con alguna de las paletas rebota y aumenta su velocidad
            speedX *= -1.02;
        }

        if (spriteBall.getPosition().x > 800)
        {
            //punto jugador 1;
            contJ1++;
            speedX = -2;
            spriteBall.setPosition(400, 300);
            contP1.setString(to_string(contJ1));
        }

        if (spriteBall.getPosition().x < 0)
        {
            //punto jugador 2;
            contJ2++;
            speedX = 2;
            spriteBall.setPosition(400, 300);
            contP2.setString(to_string(contJ2));
        }

        if (spriteBall.getPosition().y > 600 || spriteBall.getPosition().y < 0)
        {
            //Si la pelota pega en alguno de los techos rebota y aumenta la velocidad
            speedY *= -1.02;
        }

        //Asignamos las teclas para mover a las paletas
        if (Keyboard::isKeyPressed(Keyboard::W) && spriteP1.getPosition().y > 0)
        {
            spriteP1.move(0, -4);
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && spriteP1.getPosition().y < 600)
        {
            spriteP1.move(0, 4);
        }

        if (Keyboard::isKeyPressed(Keyboard::Up) && spriteP2.getPosition().y > 0)
        {
            spriteP2.move(0, -4);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && spriteP2.getPosition().y < 600)
        {
            spriteP2.move(0, 4);
        }

        //Dibujamos cada parte de nuestro juego en la ventana
        gameWindow.clear();
        gameWindow.draw(spriteBall);
        gameWindow.draw(spriteP1);
        gameWindow.draw(spriteP2);
        gameWindow.draw(contP1);
        gameWindow.draw(contP2);
        gameWindow.display();
    }
   
	
	return 0;
}