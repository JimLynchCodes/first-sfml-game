#include "Platform/Platform.hpp"

void handleKeyboardInput(sf::Keyboard::Key key, sf::CircleShape shape)
{
	sf::Vector2f playerPosition = shape.getPosition();

	int speed = 100;

	if (key == 73)
	{
		shape.setPosition(playerPosition.x, playerPosition.y + speed);
		std::cout << "pressed Up" << std::endl;
	}

	if (key == 74)
		std::cout << "pressed Down" << std::endl;

	if (key == 72)
		std::cout << "pressed Right" << std::endl;

	if (key == 71)
		std::cout << "pressed Left" << std::endl;
}

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());

	sf::CircleShape shape(window.getSize().x / 2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				handleKeyboardInput(event.key.code, shape);
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
