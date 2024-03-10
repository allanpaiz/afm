// Ball.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float x, float y, float radius);

    void update(); // Update the ball's state
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
    sf::CircleShape& getShape() {
		return shape;
	}

private:
    sf::CircleShape shape;
    float xVelocity{ 0.2f }; // Example velocity in the x direction
    float yVelocity{ 0.2f }; // Example velocity in the y direction
};
