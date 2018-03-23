#include "State.h"
#include "Sprite.h"

State::State(){

	background = new Sprite();
}

bool State::QuitRequested(){
	return QuitRequested;
}

void State::LoadAssets(){

	background->open("res/img/ocean.jpg");
}

void State::Update(float delta){
	if( SDL_QuitRequested() == SDL_TRUE ){
		QuitRequested = true;
	}
}

void State::render(){
	background->Render(0, 0);
}
