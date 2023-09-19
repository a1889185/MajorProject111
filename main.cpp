// The Main Game file.
#include <SFML/Graphics.hpp>

using namespace sf;

// units.
int u = 42;
int windowSize = 20 * u;

int main() {
  Clock clock;
  // Create The SFML window
  RenderWindow window(VideoMode(windowSize, windowSize),
                      "ROUGE, by Kosta, James, and Ben");

  // MAIN GAME WINDOW LOOP.
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }
    // Get the elapsed time since the last frame
    Time deltaTime = clock.restart();

    // DO GAME SHIT

    //
  }

  return 0;
}