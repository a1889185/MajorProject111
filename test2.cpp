#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
  // Create an SFML window
  RenderWindow window(VideoMode(800, 600), "SFML Window");

  RectangleShape my_rectangle(Vector2f(100, 100));
  my_rectangle.setFillColor(Color::Red);

  Vector2f position(100, 100);
  my_rectangle.setPosition(position);

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
    position.x += 200 * deltaTime.asSeconds();

    // update position.
    my_rectangle.setPosition(position);

    window.clear();
    window.draw(my_rectangle);
    window.display();
  }

  return 0;
}
