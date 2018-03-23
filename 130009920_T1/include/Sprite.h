#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using std::string;

class Sprite{
    public:
        Sprite();
        Sprite(string file);
        ~Sprite();
        int GetWidth();
        int GetHeight();
        bool IsOpen();
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y);

    private:
        SDL_Texture * texture = nullptr;
        int width;
        int height;
        SDL_Rect clipRect;
};
