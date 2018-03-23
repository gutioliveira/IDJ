#include "Music.h"

Music::Music(){
	music = nullptr;
}


// Music::Music(string file){
// 	Open(file);
// }

void Music::Play(int times){
	Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
	if ( Mix_LoadMUS(file.c_str()) == nullptr ){
		printf("%s\n", SDL_GetError());
		exit(-1);
	}
}

bool Music::IsOpen(){
	return music != nullptr;
}

Music::~Music(){
	Stop();
	Mix_FreeMusic(music);
}
