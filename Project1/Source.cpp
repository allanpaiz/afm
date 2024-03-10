#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp" // Make sure this is the correct path to your Ball header

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");
    std::vector<Ball> balls; // This will store all your balls

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse click event
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the click position and add a new ball at this position
                    sf::Vector2i clickPos = sf::Mouse::getPosition(window);
                    balls.emplace_back(clickPos.x, clickPos.y, 3.0f); // Adjust radius as needed
                }
            }
        }

        // Update and draw balls
        window.clear();
        for (auto& ball : balls) {
            ball.update();
            window.draw(ball.getShape());
        }
        window.display();
    }

    return 0;
}
