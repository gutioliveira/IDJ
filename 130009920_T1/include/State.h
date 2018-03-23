#include <SDL2/SDL.h>
#include <iostream>

class Sprite;

class State{
	public:
		State();

		bool QuitRequested();
		void LoadAssets();
		void Update(float delta);
		void Render();

	private:
		Sprite * background;
		bool quitRequested = false;
};