#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
  // Create an SFML window
  RenderWindow window(VideoMode(800, 600), "SFML Window");

  RectangleShape my_rectangle(Vector2f(700, 100));
  my_rectangle.setFillColor(Color::Red);

  CircleShape ball1(100), ball2(100), tip(50);
  ball1.setFillColor(Color::Red);
  ball2.setFillColor(Color::Red);
  tip.setFillColor(Color::Red);

  Vector2f position(100, 100);
  my_rectangle.setPosition(Vector2f(position.x + 100, 250));
  ball1.setPosition(position);
  ball2.setPosition(Vector2f(position.x, 300));
  tip.setPosition(Vector2f(position.x + 750, 250));

  // time.
  Clock clock;

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }

    // Get the elapsed time since the last frame
    Time deltaTime = clock.restart();
    // Move the circle based on the time elapsed
    position.x += 500 * deltaTime.asSeconds();

    if (position.x > 800) {
      position.x -= 1600;
    }

    // update position.
    my_rectangle.setPosition(Vector2f(position.x + 100, 250));
    ball1.setPosition(position);
    ball2.setPosition(Vector2f(position.x, 300));
    tip.setPosition(Vector2f(position.x + 750, 250));

    window.clear();
    window.draw(my_rectangle);
    window.draw(ball1);
    window.draw(ball2);
    window.draw(tip);
    window.display();
  }

  return 0;
}