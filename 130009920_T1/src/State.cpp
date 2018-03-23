#include "State.h"
#include "Sprite.h"

State::State(){

	background = new Sprite();
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::LoadAssets(){

	background->Open("res/img/ocean.jpg");
}

void State::Update(float delta){
	if( SDL_QuitRequested() == SDL_TRUE ){
		quitRequested = true;
	}
}

void State::Render(){
	background->Render(0, 0);
}
