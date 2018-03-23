#include <SDL2/SDL.h>
#include <iostream>

class Sprite;
class Music;

class State{
	public:
		State();

		bool QuitRequested();
		void LoadAssets();
		void Update(float delta);
		void Render();

	private:
		Sprite * bg;
		Music * music;
		bool quitRequested = false;
};