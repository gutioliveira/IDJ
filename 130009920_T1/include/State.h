#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.h"

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
		bool QuitRequested = false;
}