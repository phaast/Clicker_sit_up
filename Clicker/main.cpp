#include "logic.h"
#include "draw.h"

int main() {

//--INIT--//
    logic game;
    draw visuals;

// creating a window
    sf::RenderWindow window(sf::VideoMode(1024, 640), "Sit Up!", 
        sf::Style::Close | sf::Style::Titlebar);

//--MAIN LOOP--//
// is working until the window gets closed
    while (window.isOpen()) {
        
        game._logic(&window);
        visuals.Draw(window, game.l_stat, game.l_upg, game.l_price);

        // window event processing
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {

            // sending a request to close the window
            case sf::Event::Closed:
                game.save();
                window.close();
                break;
            }
        }
    }
    return 0;
}