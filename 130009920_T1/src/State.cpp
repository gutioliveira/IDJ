#include "State.h"
#include "Sprite.h"
#include "Music.h"

State::State(){

	bg = new Sprite();
	music = new Music();
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::LoadAssets(){

	bg->Open("assets/img/ocean.jpg");
	music->Open("assets/audio/stageState.ogg");
}

void State::Update(float delta){
	if( SDL_QuitRequested() == SDL_TRUE ){
		quitRequested = true;
	}
}

void State::Render(){
	bg->Render(0, 0);
}
