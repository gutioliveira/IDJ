#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <State.h>

using std::string;

class Game{
    public:
        // methods
        ~Game();
        void Run();
        SDL_Renderer * GetRenderer();
        State & GetState();
        static Game & GetInstance();
        Game(string title, int width, int height);

    private:

        // attributes
        static Game * instance;
        SDL_Window * window;
        SDL_Renderer * renderer = nullptr;
        State * state;
};