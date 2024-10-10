#include "raylib.h"

Texture2D mimico;
Texture2D mimico_virado;
Texture2D fundo;

typedef struct Imagem{
   float posX;
   float posY;
}imagem;

imagem img[4]= {{0, 0}, {20, 350}};
float speed = 2.0;
float scrollingBack = 0.0f;
bool DirecaoFundo = true;

void Fundo (Texture2D texture);
void Mimic (Texture2D texture);
void Movimenta_fundo (Texture2D texture);

int main()
{   
    InitWindow(800, 550, "ASSASSINIC");
    
    mimico = LoadTexture("mimico.png");
    mimico_virado = LoadTexture("mimico_virado.png");
    fundo = LoadTexture("fundo_2.png");
    
    SetTargetFPS(60);    
    
    while(!WindowShouldClose()){
        
        Movimenta_fundo(fundo);
        
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            Fundo(fundo);
            Mimic(mimico);
           
            if(IsKeyDown(KEY_D)){
                Fundo(fundo);
                Mimic(mimico);
                img[1].posX+=speed;
            }
            if(IsKeyDown(KEY_A)){
                Fundo(fundo);
                Mimic(mimico_virado);
                img[1].posX-=speed;;
            }
            
        EndDrawing();
    }
    CloseWindow();
    return 0;
}


void Fundo(Texture2D texture)
{
    ClearBackground(RAYWHITE); 
    DrawTextureEx(texture, (Vector2){ scrollingBack, img[0].posY }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(texture, (Vector2){ texture.width*2 + scrollingBack, img[0].posY }, 0.0f, 2.0f, WHITE);
}

void Mimic (Texture2D texture)
{
    DrawTextureEx(texture, (Vector2){ img[1].posX, img[1].posY }, 0.0f, 5.0f, WHITE);
}

void Movimenta_fundo (Texture2D texture)
{
    if (IsKeyDown(KEY_D)) {
            scrollingBack -= speed; //nesha p/ direita -> fundo p/ esquerda
            DirecaoFundo = true;
        }
        else if (IsKeyDown(KEY_A)) {
            scrollingBack += speed; // nesha p/ esquerda -> fundo p/ direita
            DirecaoFundo = false;
        }
        
        if (scrollingBack <= -texture.width * 2) {
            scrollingBack = 0;
        }
        else if (scrollingBack >= texture.width * 2) {
            scrollingBack = 0;
        }
}