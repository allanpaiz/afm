// Ball.cpp
#include "Ball.hpp" // Make sure this path is correct based on your project structure

Ball::Ball(float x, float y, float radius) {
    shape = sf::CircleShape(radius);
    shape.setPosition(x, y);
}

void Ball::update() {
    // Move the ball
    shape.move(xVelocity, yVelocity);

    // Get the ball's current position after moving
    sf::Vector2f pos = shape.getPosition();

    // Get the radius of the ball
    const float radius = shape.getRadius();

    // Assume window dimensions as constants, but these should ideally be passed to the function or accessed globally
    const float windowWidth = 800.0f;
    const float windowHeight = 600.0f;

    // Check collisions with window boundaries
    if ((pos.x <= 0 && xVelocity < 0) || (pos.x + 2 * radius >= windowWidth && xVelocity > 0)) {
        xVelocity = -xVelocity; // Reverse direction on X axis
    }
    if ((pos.y <= 0 && yVelocity < 0) || (pos.y + 2 * radius >= windowHeight && yVelocity > 0)) {
        yVelocity = -yVelocity; // Reverse direction on Y axis
    }
}