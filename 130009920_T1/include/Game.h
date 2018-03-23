#include "SDL_include.h"

#include <State.h>

class Game{
    public:
        // methods
        ~Game();
        void run();
        SDL_Renderer * GetRenderer();
        State & GetState();
        static GetInstance() & Game;

    private:
        // methods
        Game(string title, int width, int height);

        // attributes
        static Game * instance;
        SDL_Window * window;
        SDL_Renderer * renderer = nullptr;
        State * state;
}