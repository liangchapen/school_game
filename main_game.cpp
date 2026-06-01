#include "./game_funcs.cpp"
#include <raylib.h>
#include<cstring>
int main()
{
    int num;
    // 初始化全局游戏数据
    g_game.Init();
    InitAudioDevice();
    g_player.Init();
    memset(g_game.dialpt,0,sizeof(g_game.dialpt));
    memset(g_game.dialpt,false,sizeof(g_game.dialpt));
    g_pointAnims[0] = {{0, 0}, {0, 0}, 0.0f};
    InitWindow(800, 800, "title");
    g_game.monitorID = GetCurrentMonitor();
    g_game.screenW  = GetMonitorWidth(g_game.monitorID);
    g_game.screenH  = GetMonitorHeight(g_game.monitorID);
    SetWindowSize(g_game.screenW, g_game.screenH);
    ToggleFullscreen();
    float screenScale = fminf((float)g_game.screenW / BASE_GAME_W, (float)g_game.screenH / BASE_GAME_H);
    g_game.renderScale = screenScale;
    g_game.renderViewportW = (int)(BASE_GAME_W * screenScale);
    g_game.renderViewportH = (int)(BASE_GAME_H * screenScale);
    g_game.renderOffsetX = (g_game.screenW - g_game.renderViewportW) / 2;
    
    g_game.renderOffsetY = (g_game.screenH - g_game.renderViewportH) / 2;
    g_game.renderTarget = LoadRenderTexture(BASE_GAME_W, BASE_GAME_H);
    loadply();
    const char* fontPath = "res/ZLabsBitmap_12px_CN.ttf";
    Font chFont = LoadFontEx(fontPath, 12, NULL, 50000);
    SetTargetFPS(120);
    //g_game.curScene=outdoor1;(不要管这个)
    readwhere();
    loadtxt("main_chara",sceneTex[g_game.curScene]);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginTextureMode(g_game.renderTarget);
        ClearBackground(WHITE);

        switch(g_game.curScene)
        {
            case welcome_scene:
            {
                float playerW = g_player.width;
                float playerH = g_player.height;
                drawbg(sceneTex[welcome_scene].tex, BASE_GAME_W, BASE_GAME_H);
                //DrawRectangle(g_player.pos.x, g_player.pos.y, playerW, playerH, GREEN);
                DrawText(TextFormat("x: %d, y: %d", (int)g_player.pos.x, (int)g_player.pos.y), 0, 0, 30, BLUE);
                
                if(IsKeyPressed(KEY_Q)){
                    g_game.dialbl[2]=false;
                }
                playdia(sceneTex[g_game.curScene].dialg[1],chFont,1);
                if(g_player.pos.x + playerW <= 1684.0f && g_player.pos.x >= 1513.0f && g_player.pos.y <= 370.0f && IsKeyDown(KEY_E))
                {
                    g_game.dialbl[2]=true;
                }
                if(g_game.dialbl[2]){
                    playdia(sceneTex[g_game.curScene].dialg[2],chFont,2);
                }
                if(g_player.pos.x==670&&g_player.pos.y==553&&IsKeyPressed(KEY_ENTER)){
                    writewhere(g_game.curScene,g_player.pos);
                }
                drawani(g_pointAnims[0], {610,601}, "savepoint");
                tstcordobj(g_player.pos, 613, 666, 605, 648,playerW, playerH);
                drawani(g_pointAnims[1], {1550.0f, 120.0f},"pointer");
                if(g_game.indial){
                    movply(g_player);
                    
                }
                draw_animated_item(8.0f,"anime",{8,8},8);
                showply(g_player);
                if(add_item(g_player.pos, 613, 666, 605, 648,playerW, playerH)){
                    show_item_to("yes","save",chFont);
                }
                tstcordbound(g_player.pos, 0.0f, (float)BASE_GAME_W, 350.0f, (float)BASE_GAME_H, playerW, playerH);
                break;
            }
            case nexts:
            {
                
                float playerW = g_player.width;
                float playerH = g_player.height;
                drawbg(sceneTex[g_game.curScene].tex, BASE_GAME_W, BASE_GAME_H);
                
                DrawText(TextFormat("x: %d, y: %d", (int)g_player.pos.x, (int)g_player.pos.y), 0, 0, 30, BLUE);
                {//添加碰撞
                    tstcordobj(g_player.pos, 107.0f, 197.0f, 692.0f, 792.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 342.0f, 432.0f, 692.0f, 792.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 582.0f, 672.0f, 692.0f, 792.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 821.0f, 911.0f, 692.0f, 792.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 1046.0f, 1136.0f, 692.0f, 792.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 1290.0f, 1380.0f, 692.0f, 792.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 109.0f, 199.0f, 889.0f, 989.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 337.0f, 427.0f, 889.0f, 989.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 589.0f, 679.0f, 889.0f, 989.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 829.0f, 919.0f, 889.0f, 989.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 1057.0f, 1147.0f, 889.0f, 989.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 1297.0f, 1387.0f, 907.0f, 1007.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 769.0f, 952.0f, 452.0f, 620.0f, playerW, playerH);
                }
                drawani(g_pointAnims[0], {1800.0f, 120.0f},"pointer");
                if(g_player.pos.x + playerW <= (float)BASE_GAME_W && g_player.pos.x >= 1766.0f && g_player.pos.y >= 350.0f && IsKeyDown(KEY_E))
                {
                    g_game.curScene = outdoor1;
                }
                //DrawRectangle(g_player.pos.x, g_player.pos.y, playerW, playerH, GREEN);
                tstcordbound(g_player.pos, 0.0f, (float)BASE_GAME_W, 350.0f, (float)BASE_GAME_H, playerW, playerH);
                tstshade(sceneTex[g_game.curScene], g_player.pos, playerW, playerH);
                break;
            }
            case outdoor1:
            {
                float playerW = g_player.width;
                float playerH = g_player.height;
                drawbg(sceneTex[g_game.curScene].tex, BASE_GAME_W, BASE_GAME_H);
                movply(g_player);
                {//添加碰撞
                    tstcordobj(g_player.pos, 252.0f, 346.0f, 807.0f, 831.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 1537.0f, 1610.0f, 815.0f, 885.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 116.0f, 1068.0f, 74.0f, 539.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 1094.0f, 1447.0f, 40.0f, 570.0f, playerW, playerH);
                    tstcordobj(g_player.pos, 373, 391, 880, 885, playerW, playerH);
                    tstcordobj(g_player.pos, 221, 227, 880, 885, playerW, playerH);
                }
                tstcordbound(g_player.pos, 0.0f, (float)BASE_GAME_W, 350.0f, (float)BASE_GAME_H, playerW, playerH);
                //DrawRectangle(g_player.pos.x, g_player.pos.y, playerW, playerH, GREEN);
                if(g_player.pos.y+playerH<=810||g_player.pos.y+playerH<=882){
                }
                showply(g_player);
                tstshade(sceneTex[g_game.curScene], g_player.pos, playerW, playerH);
                //drawbg(items["outdoor1_tree"], BASE_GAME_W, BASE_GAME_H);
                DrawText(TextFormat("x: %d, y: %d", (int)g_player.pos.x, (int)g_player.pos.y), 0, 0, 30, BLUE);
                
                break;
            }
        }
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            g_player.pos.x=GetMouseX();
            g_player.pos.y=GetMouseY();
        }
        EndTextureMode();

        DrawTexturePro(
            g_game.renderTarget.texture,
            {0.0f, 0.0f, (float)g_game.renderTarget.texture.width, -(float)g_game.renderTarget.texture.height},
            {(float)g_game.renderOffsetX, (float)g_game.renderOffsetY, (float)g_game.renderViewportW, (float)g_game.renderViewportH},
            {0,0},
            0.0f,
            WHITE
        );

        EndDrawing();
    }
    UnloadRenderTexture(g_game.renderTarget);
    UnloadFont(chFont);
    unloadply();
    CloseWindow();
    return 0;
}
