#include <raylib.h>
#include <raymath.h>
#include <map>
#include <string>
#include <vector>
// 场景枚举
enum SceneType
{
    welcome_scene = 1,
    nexts = 2,
    outdoor1 = 3,
}sd;
//对话
struct dia
{
    std::string who;
    std::string txt;
    Color colour;
    int size;
    float timeper;
};
// 玩家结构体 收纳所有玩家相关数据
struct Player
{
    Vector2 pos;
    int frame;
    float frameTimer;
    int facing;
    int normState;
    unsigned int height;
    unsigned int width;

    // 初始化
    void Init()
    {
        height=180;
        width=100;
        pos = {18.0f, 532.0f};
        frame = 0;
        frameTimer = 0.0f;
        facing = 1;
        normState = 0;
    }
};
// 游戏核心全局状态
struct GameCore
{
    SceneType curScene;
    int monitorID;
    int screenW;
    int screenH;
    bool indial;
    float diatimer;
    int which=0;
    int word=0;
    int dialpt[30];//存储对话位置
    int dialbl[30];//对话是否显示
    float renderScale;
    int renderOffsetX;
    int renderOffsetY;
    int renderViewportW;
    int renderViewportH;
    RenderTexture2D renderTarget;
    void Init()
    {
        curScene = welcome_scene;
        monitorID = 0;
        screenW = 0;
        screenH = 0;
        renderScale = 1.0f;
        renderOffsetX = 0;
        renderOffsetY = 0;
        renderViewportW = 0;
        renderViewportH = 0;
        renderTarget = { 0 };
    }
};
//存储场景信息
struct sceneinfo{
    std::map<int,std::vector<dia>>dialg;
    bool newscene=false;
    int shadenums=0;
    struct {
    Texture shadetex;
    Vector2 rightdown;
    Vector2 leftup;
    } shades[100];
    Texture tex;
    void addshade(Texture shadetex,Vector2 rightdown,Vector2 leftup){
        shades[shadenums].shadetex=shadetex;
        shades[shadenums].rightdown=rightdown;
        shades[shadenums].leftup=leftup;
        shadenums++;
    }
};
struct animation
{
    int cur_stt=0;
    std::vector<Texture> tex;
    float timer;
};
// 指针浮动动画数据
struct PointAnim
{
    Vector2 nowPos;
    Vector2 targetPos;
    float timer;
};
//存储动画物品
struct pointer{
    Vector2 pos;
    Texture tex;
};
// 全局变量
GameCore     g_game;
Player       g_player,liudoujiang;
PointAnim g_pointAnims[10];
// 全局资源纹理
std::map<std::string,animation>animated_items;
std::map<std::string,pointer>pt;
Texture savepointTex;
std::map<std::string, Texture> items;
sceneinfo sceneTex[100];
Texture playerTex[10];
Texture friendliu[10];
static const int BASE_GAME_W = 1920;
static const int BASE_GAME_H = 1200;
void cnt(){
    static int num;
    num++;
}
