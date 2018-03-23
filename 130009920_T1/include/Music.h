#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string>

using std::string;

class Music{
    public:
        // methods
        Music();
        ~Music();
        Music(string file);
        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(string file);
        bool IsOpen();

    private:
        Mix_Music * music;  
};