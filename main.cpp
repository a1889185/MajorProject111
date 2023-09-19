// JUST TO TEST SFML.

#include <SFML/Graphics.hpp>

int u = 42;
int window_size = 20 * u;
using namespace sf;

int main() {
  RenderWindow window(VideoMode(window_size, window_size), "SFML works!");
  RectangleShape shape(Vector2f(u, u));
  shape.setFillColor(Color::Green);

  shape.setPosition(Vector2f(0, 0));

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}