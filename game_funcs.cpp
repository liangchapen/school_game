#include "./game_util.cpp"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <raylib.h>
#include <utility>
#include <vector>
Color chs_color_str(std::string str){//将string转换为颜色
    if(str=="red"){
        return RED;
    }
    if(str=="white"){
        return WHITE;
    }
    if(str=="blue"){
        return BLUE;
    }
    if(str=="green"){
        return GREEN;
    }
    if(str=="black"){
        return BLACK;
    }
    if(str=="purple"){
        return PURPLE;
    }
    if(str=="skyblue"){
        return SKYBLUE;
    }
    if(str=="gray"){
        return GRAY;
    }
    if(str=="darkgreen"){
        return DARKGREEN;
    }
    if(str=="darkgray"){
        return DARKGRAY;
    }
    if(str=="darkblue"){
        return DARKBLUE;
    }
    if(str=="brown"){
        return BROWN;
    }
    if(str=="darkbrown"){
        return DARKBROWN;
    }
    else{
        return WHITE;
    }
}
Color chs_color_rgb(unsigned char r,unsigned char g,unsigned char b){
    Color temp = {r,g,b};
    return temp;
}
void loadply()//加载
{
    {playerTex[0] = LoadTexture("res/main_chara/main_chara_0001.png");
    playerTex[1] = LoadTexture("res/main_chara/main_chara_0002.png");
    playerTex[2] = LoadTexture("res/main_chara/main_chara_0003.png");
    playerTex[3] = LoadTexture("res/main_chara/main_chara_0004.png");
    playerTex[4] = LoadTexture("res/main_chara/main_chara_0005.png");
    playerTex[5] = LoadTexture("res/main_chara/main_chara_0006.png");
    playerTex[6] = LoadTexture("res/main_chara/main_chara_0007.png");
    playerTex[7] = LoadTexture("res/main_chara/main_chara_0008.png");
    playerTex[8] = LoadTexture("res/main_chara/main_chara_0009.png");
    playerTex[9] = LoadTexture("res/main_chara/main_chara_0010.png");}//玩家图片
    {friendliu[0] = LoadTexture("res/friend/friend_0001.png");
    friendliu[1] = LoadTexture("res/friend/friend_0002.png");
    friendliu[2] = LoadTexture("res/friend/friend_0003.png");
    friendliu[3] = LoadTexture("res/friend/friend_0004.png");
    friendliu[4] = LoadTexture("res/friend/friend_0005.png");
    friendliu[5] = LoadTexture("res/friend/friend_0006.png");
    friendliu[6] = LoadTexture("res/friend/friend_0007.png");
    friendliu[7] = LoadTexture("res/friend/friend_0008.png");
    friendliu[8] = LoadTexture("res/friend/friend_0009.png");
    friendliu[9] = LoadTexture("res/friend/friend_0010.png");}// liudoujiang
    sceneTex[1].tex = LoadTexture("res/scene/school_hall.png");
    {sceneTex[2].tex = LoadTexture("res/scene/class.png");
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0023.png"), {207,785}, {110,689});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0022.png"), {436,785}, {342,689});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0021.png"), {680,785}, {582,690});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0020.png"), {922,783}, {824,685});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0019.png"), {1146,788}, {1047,687});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0018.png"), {1387,788}, {1288,688});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0017.png"), {207,986}, {110,887});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0016.png"), {438,990}, {341,894});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0015.png"), {687,988}, {587,891});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0014.png"), {924,988}, {828,891});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0013.png"), {1152,993}, {1055,891});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0012.png"), {1393,1001}, {1295,903});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0011.png"), {207,1154}, {110,1054});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0010.png"), {439,1151}, {342,1054});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0009.png"), {686,1151}, {587,1054});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0008.png"), {938,1146}, {838,1052});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0007.png"), {1174,1143}, {1076,1040});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0006.png"), {1473,1167}, {1372,1072});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0001.png"),{958,621}, {769,458});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0002.png"),{1649,990}, {1597,897});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0003.png"),{1644,818}, {1590,723});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0005.png"),{1626,650}, {1574,558});
    sceneTex[2].addshade(LoadTexture("res/shade/classs_0004.png"),{1626,650}, {1574,558});}//添加场景
    {sceneTex[3].tex = LoadTexture("res/scene/outdoor1.png");
    sceneTex[3].addshade(LoadTexture("res/shade/outdoorchair.png"), {344,810},{253,763});
    sceneTex[3].addshade(LoadTexture("res/shade/outdoortree.png"), {1900,842},{1294,233});
    sceneTex[3].addshade(LoadTexture("res/shade/outdoorshel.png"), {392,887},{174,544});}//scene outdoor1
    savepointTex = LoadTexture("res/g_u_i/savepoint.png");
    items.insert(std::make_pair("sword", LoadTexture("res/items/sword.png")));
    pt["pointer"].tex=LoadTexture("res/g_u_i/pointer.png");
    pt["savepoint"].tex=LoadTexture("res/g_u_i/savepoint.png");
    
}
void unloadply()
{
    for (int i = 0; i < 10; ++i)
    {
        UnloadTexture(playerTex[i]);
        UnloadTexture(friendliu[i]);
    }

    UnloadTexture(sceneTex[1].tex);

    UnloadTexture(sceneTex[2].tex);
    for (int i = 0; i < sceneTex[2].shadenums; ++i)
    {
        UnloadTexture(sceneTex[2].shades[i].shadetex);
    }

    UnloadTexture(sceneTex[3].tex);
    for (int i = 0; i < sceneTex[3].shadenums; ++i)
    {
        UnloadTexture(sceneTex[3].shades[i].shadetex);
    }

    UnloadTexture(savepointTex);

    auto swordIt = items.find("sword");
    if (swordIt != items.end())
    {
        UnloadTexture(swordIt->second);
    }
    items.clear();

    auto pointerIt = pt.find("pointer");
    if (pointerIt != pt.end())
    {
        UnloadTexture(pointerIt->second.tex);
    }
    pt.clear();
}
void playdia(std::vector<dia> dial, Font font, int where){//显示对话
    Color opa = {0, 0, 0, 200};
    if(g_game.dialpt[where] < dial.size()){
        g_game.indial = false;
        std::string temp = dial[g_game.dialpt[where]].txt;
        std::vector<std::string> show;
        while(temp.length() > 50){
            std::string cmp = temp.substr(0, 50);  // 每行50字
            temp = temp.substr(50);                // 从第50字开始
            show.push_back(cmp);
        }
        if(!temp.empty()) {
            show.push_back(temp);
        }
        DrawRectangle(0, 2*(BASE_GAME_H/3), BASE_GAME_W, BASE_GAME_H/3, opa);
        DrawTextEx(font, "按下Q继续", 
                  {BASE_GAME_W - 200.0f, BASE_GAME_H - 100.0f}, 20, 1, WHITE);
        if(!dial[g_game.dialpt[where]].who.empty()) {
            DrawTextEx(font, (dial[g_game.dialpt[where]].who + ":").c_str(), 
                      {20, (float)2*BASE_GAME_H/3 + 20}, 
                      48, 1, 
                      dial[g_game.dialpt[where]].colour);
        }
        float startY = (float)2*BASE_GAME_H/3 + 20+48;
        float lineHeight = dial[g_game.dialpt[where]].size+5;
        
        for(int i = 0; i < show.size(); i++){
            DrawTextEx(font, show[i].c_str(), 
                      {20, startY + i * lineHeight}, 
                      dial[g_game.dialpt[where]].size, 1, 
                      dial[g_game.dialpt[where]].colour);
        }
        if(IsKeyPressed(KEY_Q)){
            g_game.dialpt[where]++;
        }
    }else{
        g_game.indial=true;
    }
    if(g_game.dialbl[where] && g_game.dialpt[where] >= dial.size()){
        g_game.dialpt[where] = 0;
        g_game.indial=false;
    }
}
void refresh(){//重置
    memset(g_game.dialpt, 0, sizeof(g_game.dialpt));
}
void movply(Player& p)//移动玩家
{
    float playerW = p.width;
    float playerH = p.height;
    float moveSpeed = 3.0f;
    float diagSpeed = sqrt(4.5f);

    DrawEllipse(
        (int)p.pos.x + playerW / 2,
        (int)p.pos.y + playerH,
        playerW * 0.4f,
        10.0f,
        (Color){ 0, 0, 0, 80 }
    );
    p.frameTimer += GetFrameTime();

    if(IsKeyDown(KEY_D))
    {
        if(IsKeyDown(KEY_W))
        {
            if(p.normState != 7) p.frame = 6;
            p.facing = 1;
            p.pos.y -= diagSpeed;
            p.pos.x += diagSpeed;
            p.normState = 7;
            if(p.frameTimer >= 0.3f)
            {
                p.frame = (p.frame == 5) ? 6 : 5;
                p.frameTimer = 0.0f;
            }
        }
        else if(IsKeyDown(KEY_S))
        {
            if(p.normState != 0) p.frame = 3;
            p.facing = 1;
            p.pos.y += diagSpeed;
            p.pos.x += diagSpeed;
            p.normState = 0;
            if(p.frameTimer >= 0.3f)
            {
                p.frame = (p.frame == 3) ? 4 : 3;
                p.frameTimer = 0.0f;
            }
        }
        else
        {
            if(p.normState != 9) p.frame = 9;
            p.normState = 9;
            p.pos.x += moveSpeed;
            p.facing = 1;
            if(p.frameTimer >= 0.2f)
            {
                p.frame = (p.frame == 8) ? 9 : 8;
                p.frameTimer = 0.0f;
            }
        }
    }
    else if(IsKeyDown(KEY_A))
    {
        if(IsKeyDown(KEY_W))
        {
            if(p.normState != 7) p.frame = 6;
            p.facing = 1;
            p.pos.y -= diagSpeed;
            p.pos.x -= diagSpeed;
            p.normState = 7;
            if(p.frameTimer >= 0.3f)
            {
                p.frame = (p.frame == 5) ? 6 : 5;
                p.frameTimer = 0.0f;
            }
        }
        else if(IsKeyDown(KEY_S))
        {
            if(p.normState != 0) p.frame = 3;
            p.facing = 1;
            p.pos.y += diagSpeed;
            p.pos.x -= diagSpeed;
            p.normState = 0;
            if(p.frameTimer >= 0.3f)
            {
                p.frame = (p.frame == 3) ? 4 : 3;
                p.frameTimer = 0.0f;
            }
        }
        else
        {
            if(p.normState != 9) p.frame = 9;
            p.normState = 9;
            p.facing = -1;
            p.pos.x -= moveSpeed;
            if(p.frameTimer >= 0.2f)
            {
                p.frame = (p.frame == 8) ? 9 : 8;
                p.frameTimer = 0.0f;
            }
        }
    }
    else if(IsKeyDown(KEY_W))
    {
        if(p.normState != 7) p.frame = 6;
        p.facing = 1;
        p.pos.y -= moveSpeed;
        p.normState = 7;
        if(p.frameTimer >= 0.3f)
        {
            p.frame = (p.frame == 5) ? 6 : 5;
            p.frameTimer = 0.0f;
        }
    }
    else if(IsKeyDown(KEY_S))
    {
        if(p.normState != 0) p.frame = 3;
        p.facing = 1;
        p.pos.y += moveSpeed;
        p.normState = 0;
        if(p.frameTimer >= 0.3f)
        {
            p.frame = (p.frame == 3) ? 4 : 3;
            p.frameTimer = 0.0f;
        }
    }
    else
    {
        p.frame = p.normState;
    }
}
void showply(Player p){
    float playerH = p.height;
    Texture2D curTex = playerTex[p.frame];
    Rectangle srcRect;
    if(p.facing == -1)
        srcRect = {0,0,-(float)curTex.width,(float)curTex.height};
    else
        srcRect = {0,0,(float)curTex.width,(float)curTex.height};

    float spriteScale = playerH / curTex.height;
    Rectangle dstRect = {p.pos.x, p.pos.y, curTex.width * spriteScale, curTex.height * spriteScale};
    DrawTexturePro(curTex, srcRect, dstRect, {0,0}, 0.0f, WHITE);
}
void addanimation(int nums,std::string file_name){
    for(int i =1;i<=nums;i++){
        std::string temp;
        if(i<10){
            temp="000";
            temp+=(char)'0'+i;
        }
        else if(i>10){
            temp="00";
            temp+=(char)'0'+1;
        }
        std::string filedir=file_name+'_'+temp+".png";
        animated_items[file_name].push_back(LoadTexture(filedir.c_str()));
    }
}

void tstcordbound(Vector2& pos, float xb1, float xb2, float yb1, float yb2, float wid, float hi)//设置边界
{
    if(pos.x <= xb1) pos.x = xb1;
    if(pos.x + wid >= xb2) pos.x = xb2 - wid;
    if(pos.y <= yb1) pos.y = yb1;
    if(pos.y + hi >= yb2) pos.y = yb2 - hi;
}

void tstcordobj(Vector2& pos, float xb1, float xb2, float yb1, float yb2, float wid, float hi)//设置物品碰撞
{
    float feetHeight = 8.0f;
    float playerFeetTop = pos.y + hi - feetHeight;
    float playerFeetBottom = pos.y + hi;

    float overlapX = (pos.x+wid>xb1 && pos.x<xb2) ? fminf(pos.x+wid-xb1, xb2-pos.x) : 0.0f;
    float overlapY = (playerFeetBottom>yb1 && playerFeetTop<yb2) ? fminf(playerFeetBottom-yb1, yb2-playerFeetTop) : 0.0f;

    if(overlapX <= 0.0f || overlapY <= 0.0f) return;

    if(overlapX < overlapY)
    {
        pos.x += (pos.x + wid*0.5f < (xb1+xb2)*0.5f) ? -overlapX : overlapX;
    }
    else
    {
        pos.y += (playerFeetTop + feetHeight*0.5f < (yb1+yb2)*0.5f) ? -overlapY : overlapY;
    }
}

void drawbg(Texture bg, int w, int h)//图画背景
{
    DrawTexturePro(
        bg,
        {0.0f, 0.0f, (float)bg.width, (float)bg.height},
        {0.0f, 0.0f, (float)w, (float)h},
        {0,0},
        0.0f,
        WHITE
    );
}

void drawani(PointAnim& anim, Vector2 target,std::string which)//添加指针
{
    if(anim.targetPos.x != target.x || anim.targetPos.y != target.y)
    {
        anim.targetPos = target;
        anim.timer = 0.0f;
    }
    anim.timer += GetFrameTime();
    float pointerShift = 6.0f;
    float pointerScale = 5.0f;
    float cycle = fmod(anim.timer, 2.0f);
    anim.nowPos = (cycle < 1.0f) ? Vector2{target.x, target.y + pointerShift} : target;
    DrawTextureEx(pt[which].tex, anim.nowPos, 0.0f, pointerScale, WHITE);
}
void loadtxt(std::string path,sceneinfo & scn){//加载文本
    std::string filepath = "res/dialogue/"+path+".txt";
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open dialogue file: " << filepath << "\n";
        return;
    }
    int num;
    int unum=0;
    std::string lstwho="";
    std::string clr;
    std::string who="";
    std::string str;
    int sz;
    while(1){
        file>>num;
        if(num==114514){
            break;
        }
        file>>who>>clr>>str>>sz;
        if(who!=lstwho) unum++;
        dia temp={who,str,chs_color_str(clr),sz};
        scn.dialg[unum].push_back(temp);
        lstwho=who;
    }
}
void tstshade(sceneinfo info,Vector2 pos, float wid, float hi){
    for(int i =0;i<info.shadenums;i++){
        if(pos.y+hi<=info.shades[i].rightdown.y){
            drawbg(info.shades[i].shadetex, BASE_GAME_W, BASE_GAME_H);
        }
    }
}
void readwhere()
{
    std::ifstream file("res/where.txt");
    if (!file.is_open())
    {
        std::cerr << "Warning: No save file found at res/where.txt, using default spawn position\n";
        // 使用默认出生点
        g_player.pos = {18.0f, 532.0f};
        g_game.curScene = welcome_scene;
        return;
    }
    
    int where = 0;
    Vector2 pos = {0, 0};  // 初始化为0，防止读取失败时使用垃圾值
    
    // 一次性读取三个值，并检查是否全部成功
    if (file >> where >> pos.x >> pos.y)
    {
        g_player.pos = pos;
        g_game.curScene = static_cast<SceneType>(where);
        std::cout << "Save loaded: scene=" << where << " pos=(" << pos.x << "," << pos.y << ")\n";
    }
    else
    {
        std::cerr << "Error: Save file corrupted, using default spawn position\n";
        // 文件损坏时使用默认值
        g_player.pos = {18.0f, 532.0f};
        g_game.curScene = welcome_scene;
    }
    
    file.close();  // 可选，析构时会自动调用，但显式写出来更清晰
}
void writewhere(int where,Vector2 pos)
{
    std::ofstream file("res/where.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open res/where.txt for writing\n";
        return;
    }
    file << where;
    file <<" " << pos.x << " " <<pos.y;
}
void savept(Vector2 pos){
    writewhere(g_game.curScene,g_player.pos);
}
//这期神了
