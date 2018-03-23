#include <iostream>

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(string file){
    texture = nullptr;
    open(file);
}

Sprite::~Sprite(){
    if(texture){
        SDL_DestroyTexture(texture);
    }
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}

void Sprite::Open(string file){

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(texture == nullptr){
        printf("%s\n", SDL_GetError());
        exit(-1);
    }
    int query_texture = SDL_QueryTexture(texture, nullptr, nullptr, 
        &width, &height);
    if(query_texture){
        printf("%s\n", SDL_GetError());
        exit(-1);
    }
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect = SDL_Rect{x, y, w, h};
}

void Sprite::Render(int x, int y){
    SDL_Rect dstrect = SDL_Rect{x, y, clipRect.w, clipRect.h};
    int renderCopy = SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, 
        &clipRect, &dstrect);
    if(renderCopy){
        printf("%s\n", SDL_GetError());
        exit(-1);
    }
}
