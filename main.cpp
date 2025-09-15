#include <SFML/Graphics.cpp>

void init() {
	// initialise all the objects needed for the game. 
}

float playerSpeed = 10.0f;
void Update(double dt) {
	//bad!
	if (moveButton.pressed) {
		player.move(playerSpeed);
	}
	//Good!
	if (moveButton.pressed) {
		player.move(playerSpeed * dt);
	}
}

void render(sf::RenderWindow& window) {
	// Draw Everything
	window.display();
	window.setVerticalSyncEnabled(true / false);
}

void clean() {
	//free up the memory if necessary.
}

int main() {
	//create the window
	sf::RenderWindow window(sf::VideoMode({ game_width, game_height }), "PONG");
	//initialise and load
	init();
	while (!window.isOpen()) {
		static sf::Clock clock;
		const float dt = clock.restart().asSeconds();
		//Calculate dt
		...
			window.clear();
		update(dt);
		render(window);
		//wait for the time_step to finish before displaying the next frame.
		sf::sleep(time_step);
		//Wait for Vsync
		window.display()
	}
	//Unload and shutdown
	clean();
}