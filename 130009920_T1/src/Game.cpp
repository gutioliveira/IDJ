#include "Game.h"

Game * Game::instance = nullptr;

// public methods
Game::~Game(){
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer * Game::GetRenderer(){
	return renderer;
}

State & Game::GetState(){
	return *state;
}

Game & Game::GetInstance(){
	return *instance;
}

void Game::Run(){
	state->LoadAssets();
	while(state->QuitRequested() == false){
		state->Update(1);
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
// private methods
Game::Game(string title, int width, int height) : state(new State()){

	instance = instance? instance : this;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){

		printf("%s\n", SDL_GetError());
		exit(-1);
	}

	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;

	if ( flags != IMG_Init(flags) ){

		printf("%s\n", SDL_GetError());
		exit(-1);
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, width, height, 0);

	if ( window == nullptr ){

		printf("%s\n", SDL_GetError());
		exit(-1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if ( renderer == nullptr ){

		printf("%s\n", SDL_GetError());
		exit(-1);
	}
}
