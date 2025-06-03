#include <easyx.h>
#include<graphics.h>
#include <vector>
#include <string>
//#include<conio.h>//button
#include <iostream>
#include<windows.h>
#include<mmsystem.h>
#include<vector>
#pragma comment(lib,"winmm.lib")
constexpr float PI = 3.1415926535f;

using namespace std;

static IMAGE EarthImageMask;
static IMAGE EarthImageOrigin;
static IMAGE GrassImageMask;
static IMAGE GrassImageOrigin;
static IMAGE CloudImageMask;
static IMAGE CloudImageOrigin;
class Block
{
private:
    int X;
    int Y;
    int Width = 32;
    int Height = 32;

public:
    static void LoadBlockImage()
    {
        loadimage(&EarthImageMask, L"i wanna素材mask\\mask_土块.bmp", 32, 32);
        loadimage(&EarthImageOrigin, L"i wanna素材origin\\source_土块.bmp", 32, 32);
        loadimage(&GrassImageMask, L"i wanna素材mask\\mask_草方块.bmp", 32, 32);
        loadimage(&GrassImageOrigin, L"i wanna素材origin\\source_草方块.bmp", 32, 32);
        loadimage(&CloudImageMask, L"i wanna素材mask\\mask_Cloud.bmp", 32, 32);
        loadimage(&CloudImageOrigin, L"i wanna素材origin\\source_Cloud.bmp", 32, 32);

    }
    Block(int X, int Y) :X(X), Y(Y) {}

    void DrawEarth()
    {
        int LeftUpX = X - Width / 2;
        int LeftUpY = Y - Height / 2;


        putimage(LeftUpX, LeftUpY, &EarthImageMask, SRCAND);
        putimage(LeftUpX, LeftUpY, &EarthImageOrigin, SRCPAINT);
    }
    void DrawGrass()
    {
        int LeftUpX = X - Width / 2;
        int LeftUpY = Y - Height / 2;


        putimage(LeftUpX, LeftUpY, &GrassImageMask, SRCAND);
        putimage(LeftUpX, LeftUpY, &GrassImageOrigin, SRCPAINT);
    }
    void DrawCloud()
    {
        int LeftUpX = X - Width / 2;
        int LeftUpY = Y - Height / 2;


        putimage(LeftUpX, LeftUpY, &CloudImageMask, SRCAND);
        putimage(LeftUpX, LeftUpY, &CloudImageOrigin, SRCPAINT);
    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    int GetWidth()
    {
        return Width;
    }
    int GetHeight()
    {
        return Height;
    }

};

class BlockManager
{
private:
    vector<Block>MapEarthBlock1;
    vector<Block>MapEarthBlock2;
    vector<Block>MapEarthBlock3;

    vector<Block>MapGrassBlock1;
    vector<Block>MapGrassBlock2;
    vector<Block>MapGrassBlock3;

    vector<Block>MapCloudBlock1;
    vector<Block>MapCloudBlock2;
    vector<Block>MapCloudBlock3;


    int Shift = 1;
public:
    void InitializeMap()
    {
        Block Init(-1000, 1000);
        Init.LoadBlockImage();//初始化用的不用管他
        ///Map1 BasicPart
        for (int i = 0; i < 14; i++)
        {
            MapEarthBlock1.emplace_back(-496 + 32 * i, 496);//Map1 Last Ground (The Left part)

        }
        for (int i = 0; i < 14; i++)
        {
            MapEarthBlock1.emplace_back(496 - 32 * i, 496);//Map1 Last Ground (The right part)
        }
        for (int i = 0; i < 32; i++)
        {
            MapCloudBlock1.emplace_back(-496 + 32 * i, -496);//Map1 Ceiling CLoud
        }

        for (int i = 0; i < 30; i++)
        {
            MapEarthBlock1.emplace_back(-496, 464 - 32 * i);//Map1 Left Wall
        }
        for (int i = 0; i < 15; i++)
        {
            MapEarthBlock1.emplace_back(496, 464 - 32 * i);//Map1 right Wall (Lower one)
        }
        for (int i = 0; i < 12; i++)
        {
            MapEarthBlock1.emplace_back(496, -464 + 32 * i);//Map1 right Wall (Lower one)
        }
        //Map1 StretchPart
        for (int i = 0; i < 24; i++)
        {
            MapEarthBlock1.emplace_back(-368 + 32 * i, 336);//Map1floor2
        }
        for (int i = 0; i < 12; i++)
        {
            MapEarthBlock1.emplace_back(-368 + 32 * i, 16);//Map1floor3
        }
        for (int i = 0; i < 12; i++)
        {
            MapEarthBlock1.emplace_back(112 + 32 * i, 16);//Map1floor3
        }

        for (int i = 0; i < 12; i++)
        {
            MapEarthBlock1.emplace_back(-368, 80 - i * 32);// Map1floor4侧面墙体
        }

        for (int i = 0; i < 23; i++)
        {
            MapEarthBlock1.emplace_back(-368 + 32 * i, -304);//Map1floor4
        }
        for (int i = 0; i < 22; i++)
        {
            MapEarthBlock1.emplace_back(464 - 32 * i, -144);
        }

        MapEarthBlock1.emplace_back(-432, 208);
        MapEarthBlock1.emplace_back(-400, 112);
        MapEarthBlock1.emplace_back(-464, 48);
        MapEarthBlock1.emplace_back(-400, -48);
        MapEarthBlock1.emplace_back(-464, -144);


        //map2
        for (int i = 0; i < 15; i++)
        {
            MapGrassBlock2.emplace_back(-496, 464 - 32 * i);//左侧边界下半
        }
        for (int i = 0; i < 12; i++)
        {
            MapGrassBlock2.emplace_back(-496, -464 + 32 * i);//上半
        }
        for (int i = 0; i < 32; i++)
        {
            MapGrassBlock2.emplace_back(-496 + 32 * i, -496);//天花板
        }
        for (int i = 0; i < 8; i++)
        {
            MapGrassBlock2.emplace_back(-496 + 32 * i, 496);//地板左侧
        }
        for (int i = 0; i < 21; i++)
        {
            MapGrassBlock2.emplace_back(-144 + 32 * i, 496);//地板右侧
        }
        for (int i = 0; i < 5; i++)
        {
            MapGrassBlock2.emplace_back(-496 + 32 * i, 16);//地图入口平台

        }
        for (int i = 0; i < 29; i++)
        {
            MapGrassBlock2.emplace_back(496, 432 - 32 * i);//右侧边界
        }
        for (int i = 0; i < 12; i++)
        {
            MapGrassBlock2.emplace_back(-336, 16 - i * 32);//平台右侧墙壁
        }

        MapGrassBlock2.emplace_back(-368, -208);//草方块落脚点
        for (int i = 0; i < 12; i++)
        {
            MapGrassBlock2.emplace_back(-336 + i * 32, -336);//最上层平台
        }


        for (int i = 0; i < 12; i++)
        {
            MapGrassBlock2.emplace_back(16, -336 + i * 32);//U型通道左侧墙壁
        }
        for (int i = 0; i < 8; i++)
        {
            MapGrassBlock2.emplace_back(48 + i * 32, 16);//U型通道底部
        }
        for (int i = 0; i < 12; i++)
        {
            MapGrassBlock2.emplace_back(144, -464 + i * 32);//倒挂墙体
        }

        MapCloudBlock2.emplace_back(176, -112);

        MapCloudBlock2.emplace_back(176, -272);//云型落脚点


        for (int i = 0; i < 4; i++)
        {
            MapGrassBlock2.emplace_back(272 + i * 32, -368);//U型平台上侧平台
        }
        for (int i = 0; i < 16; i++)
        {
            MapGrassBlock2.emplace_back(368, -336 + i * 32);//下跳通道左侧墙体
        }
        for (int i = 0; i < 20; i++)
        {
            MapGrassBlock2.emplace_back(464 - i * 32, 272);//通道底部平台
        }

        //map3
        for (int i = 0; i < 32; i++)
        {
            MapCloudBlock3.emplace_back(-496 + 32 * i, 496);
        }
    }

    void SetShift(int NewMap)
    {
        Shift = NewMap;
    }

    int GetShift()
    {
        return Shift;
    }

    const vector<Block>& GetEarthBlocks()
    {
        if (Shift == 1)
        {
            return MapEarthBlock1;
        }
        else if (Shift == 2)
        {
            return MapEarthBlock2;
        }
        else if (Shift == 3)
        {
            return MapEarthBlock3;
        }
    }
    const vector<Block>& GetGrassBlocks()
    {
        if (Shift == 1)
        {
            return MapGrassBlock1;
        }
        else if (Shift == 2)
        {
            return MapGrassBlock2;
        }
        else if (Shift == 3)
        {
            return MapGrassBlock3;
        }
    }
    const vector<Block>& GetCloudBlocks()
    {
        if (Shift == 1)
        {
            return MapCloudBlock1;
        }
        else if (Shift == 2)
        {
            return MapCloudBlock2;
        }
        else if (Shift == 3)
        {
            return MapCloudBlock3;
        }
    }

    int GetEarthBlocksSize()
    {
        if (Shift == 1)
        {
            return static_cast<int>(MapEarthBlock1.size());
        }
        else if (Shift == 2)
        {
            return static_cast<int>(MapEarthBlock2.size());
        }
        else if (Shift == 3)
        {
            return static_cast<int>(MapEarthBlock3.size());
        }
    }

    int GetGrassBlocksSize()
    {
        if (Shift == 1)
        {
            return static_cast<int>(MapGrassBlock1.size());
        }
        else if (Shift == 2)
        {
            return static_cast<int>(MapGrassBlock2.size());
        }
        else if (Shift == 3)
        {
            return static_cast<int>(MapGrassBlock3.size());
        }
    }

    int GetCloudBlocksSize()
    {
        if (Shift == 1)
        {
            return static_cast<int>(MapCloudBlock1.size());
        }
        else if (Shift == 2)
        {
            return static_cast<int>(MapCloudBlock2.size());
        }
        else if (Shift == 3)
        {
            return static_cast<int>(MapCloudBlock3.size());
        }
    }

    void Update()
    {
        if (Shift == 1)
        {

            for (int i = 0; i < static_cast<int>(MapEarthBlock1.size()); i++)
            {
                MapEarthBlock1[i].DrawEarth();
            }
            for (int i = 0; i < static_cast<int>(MapGrassBlock1.size()); i++)
            {
                MapGrassBlock1[i].DrawGrass();
            }
            for (int i = 0; i < static_cast<int>(MapCloudBlock1.size()); i++)
            {
                MapCloudBlock1[i].DrawCloud();
            }
        }
        else if (Shift == 2)
        {

            for (int i = 0; i < static_cast<int>(MapEarthBlock2.size()); i++)
            {
                MapEarthBlock2[i].DrawEarth();
            }
            for (int i = 0; i < static_cast<int>(MapGrassBlock2.size()); i++)
            {
                MapGrassBlock2[i].DrawGrass();
            }
            for (int i = 0; i < static_cast<int>(MapCloudBlock2.size()); i++)
            {
                MapCloudBlock2[i].DrawCloud();
            }
        }
        else if (Shift == 3)
        {
            for (int i = 0; i < static_cast<int>(MapEarthBlock3.size()); i++)
            {
                MapEarthBlock3[i].DrawEarth();
            }
            for (int i = 0; i < static_cast<int>(MapGrassBlock3.size()); i++)
            {
                MapGrassBlock3[i].DrawGrass();
            }
            for (int i = 0; i < static_cast<int>(MapCloudBlock3.size()); i++)
            {
                MapCloudBlock3[i].DrawCloud();
            }
        }
    }

};
static IMAGE ThornTrapImageMaskUp;
static IMAGE ThornTrapImageOriginUp;

static IMAGE ThornTrapImageMaskDown;
static IMAGE ThornTrapImageOriginDown;

static IMAGE ThornTrapImageMaskLeft;
static IMAGE ThornTrapImageOriginLeft;

static IMAGE ThornTrapImageMaskRight;
static IMAGE ThornTrapImageOriginRight;

static IMAGE AppleImageMask;
static IMAGE AppleImageOrigin;
class Trap
{
private:
    int X;
    int Y;
    int Width = 32;
    int Height = 32;

public:
    Trap(int X, int Y)
    {
        this->X = X;
        this->Y = Y;

    }
    static void InitializeImage()
    {
        loadimage(&ThornTrapImageMaskUp, L"i wanna素材mask\\mask_刺.bmp", 32, 32);
        loadimage(&ThornTrapImageOriginUp, L"i wanna素材origin\\source_刺.bmp", 32, 32);

        loadimage(&ThornTrapImageMaskDown, L"i wanna素材mask\\mask_刺向下.bmp", 32, 32);
        loadimage(&ThornTrapImageOriginDown, L"i wanna素材origin\\source_刺向下.bmp", 32, 32);

        loadimage(&ThornTrapImageMaskLeft, L"i wanna素材mask\\mask_刺向左.bmp", 32, 32);
        loadimage(&ThornTrapImageOriginLeft, L"i wanna素材origin\\source_刺向左.bmp", 32, 32);

        loadimage(&ThornTrapImageMaskRight, L"i wanna素材mask\\mask_刺向右.bmp", 32, 32);
        loadimage(&ThornTrapImageOriginRight, L"i wanna素材origin\\source_刺向右.bmp", 32, 32);

        loadimage(&AppleImageMask, L"i wanna素材mask\\mask_苹果.bmp", 32, 32);
        loadimage(&AppleImageOrigin, L"i wanna素材origin\\source_苹果.bmp", 32, 32);

    }
    void DrawUp()
    {
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageMaskUp, SRCAND);
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageOriginUp, SRCPAINT);
    }
    void DrawDown()
    {
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageMaskDown, SRCAND);
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageOriginDown, SRCPAINT);
    }
    void DrawLeft()
    {
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageMaskLeft, SRCAND);
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageOriginLeft, SRCPAINT);
    }
    void DrawRight()
    {
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageMaskRight, SRCAND);
        putimage(X - Width / 2, Y - Height / 2, &ThornTrapImageOriginRight, SRCPAINT);
    }
    void DrawApple()
    {
        putimage(X - Width / 2, Y - Height / 2, &AppleImageMask, SRCAND);
        putimage(X - Width / 2, Y - Height / 2, &AppleImageOrigin, SRCPAINT);

    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    int GetWidth()
    {
        return Width;
    }
    int GetHeight()
    {
        return Height;
    }

};
class TrapManager
{
private:
    vector<Trap>TrapsOfMap1;
    vector<Trap>TrapsOfMap2;
    vector<Trap>TrapsOfMap3;
public:
    void InitializeTraps()
    {
        //Map1
          //向上的刺
        TrapsOfMap1.emplace_back(400, -176);
        for (int i = 0; i < 2; i++)
        {
            TrapsOfMap1.emplace_back(-368, 464);
        }
        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap1.emplace_back(16 + 32 * i, 16);
        }
        TrapsOfMap1.emplace_back(304, 464);
        TrapsOfMap1.emplace_back(240, 464);
        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap1.emplace_back(-464 + i * 32, 336);
        }
        TrapsOfMap1.emplace_back(304, -336);
        for (int i = 0; i < 4; i++)
        {
            TrapsOfMap1.emplace_back(-368 + 32 * i * 4, 304);
        }
        TrapsOfMap1.emplace_back(-304, -16);
        TrapsOfMap1.emplace_back(240, -176);
        //向下的刺
        TrapsOfMap1.emplace_back(304, -272);

        //向右的刺


        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap1.emplace_back(-464, 272 - i * 32 * 6);
        }
        TrapsOfMap1.emplace_back(-336, -144);
        //向左的刺
        for (int i = 0; i < 2; i++)
        {
            TrapsOfMap1.emplace_back(-400, -16 - i * 32 * 6);
        }



        //苹果
        TrapsOfMap1.emplace_back(336, 336);
        TrapsOfMap1.emplace_back(112, 272);
        TrapsOfMap1.emplace_back(144, -176);
        //Map2 
          //向上的刺
        TrapsOfMap2.emplace_back(432, 272);//下跳通道底部的刺
        for (int i = 0; i < 11; i++)
        {
            TrapsOfMap2.emplace_back(272, -16 - i * 32);//U型通道右侧刺墙
        }
        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap2.emplace_back(-304 + 32 * i * 3, -368);//最上层平台地刺
        }
        for (int i = 0; i < 2; i++)
        {
            TrapsOfMap2.emplace_back(-112 - 32 * i, 240);//下跳通道地面地刺
        }
        //向下的刺
        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap2.emplace_back(-256 + 32 * i * 3, -464);//最上层平台
        }
        for (int i = 0; i < 2; i++)
        {
            TrapsOfMap2.emplace_back(304 + 32 * i, -464);//下跳通道地面地刺
        }
        //向左的刺
        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap2.emplace_back(-368, -16 - i * 32);//入口平台墙刺
        }
        for (int i = 0; i < 8; i++)
        {
            TrapsOfMap2.emplace_back(112, -336 + 32 * i);//U型通道墙刺
        }
        for (int i = 0; i < 16; i++)
        {
            TrapsOfMap2.emplace_back(464, -368 + 32 * i);//下跳通道墙刺
        }
        //向右的刺
        for (int i = 0; i < 3; i++)
        {
            TrapsOfMap2.emplace_back(-464, -112 - i * 32);//入口平台墙刺
        }
        for (int i = 0; i < 8; i++)
        {
            TrapsOfMap2.emplace_back(48, -336 + 32 * i);//U型通道墙刺
        }
        ;       for (int i = 0; i < 16; i++)
        {
            TrapsOfMap2.emplace_back(400, -368 + 32 * i);//下跳通道墙刺
        }
        TrapsOfMap1[0].InitializeImage();
        TrapsOfMap2[0].InitializeImage();
    }
    const vector<Trap>& GetTraps(BlockManager& gm)
    {
        if (gm.GetShift() == 1)
        {
            return TrapsOfMap1;
        }
        else if (gm.GetShift() == 2)
        {
            return TrapsOfMap2;
        }
        else if (gm.GetShift() == 3)
        {
            return TrapsOfMap3;
        }
    }
    int GetTrapsOfMapSize(BlockManager& gm)
    {
        if (gm.GetShift() == 1)
        {
            return static_cast<int>(TrapsOfMap1.size());
        }
        else if (gm.GetShift() == 2)
        {
            return static_cast<int>(TrapsOfMap2.size());
        }
        else if (gm.GetShift() == 3)
        {
            return static_cast<int>(TrapsOfMap3.size());
        }
    }
    void Update(BlockManager& gm)
    {
        if (gm.GetShift() == 1)
        {
            for (int i = 0; i < 18; i++)
            {
                TrapsOfMap1[i].DrawUp();
            }
            for (int i = 18; i < 19; i++)
            {
                TrapsOfMap1[i].DrawDown();
            }
            for (int i = 19; i < 23; i++)
            {
                TrapsOfMap1[i].DrawRight();
            }
            for (int i = 23; i < 25; i++)
            {
                TrapsOfMap1[i].DrawLeft();
            }
            for (int i = 25; i < 28; i++)
            {
                TrapsOfMap1[i].DrawApple();
            }

        }
        else if (gm.GetShift() == 2)
        {

            for (int i = 0; i < 17; i++)
            {
                TrapsOfMap2[i].DrawUp();
            }
            for (int i = 17; i < 22; i++)
            {
                TrapsOfMap2[i].DrawDown();
            }
            for (int i = 22; i < 49; i++)
            {
                TrapsOfMap2[i].DrawLeft();
            }
            for (int i = 49; i < 76; i++)
            {
                TrapsOfMap2[i].DrawRight();
            }

        }

        else if (gm.GetShift() == 3)
        {


        }
    }
};
class Entity {
private:
    int X;
    int Y;
    int Width = 36;
    int Height = 36;
    int preX;
    int preY;

    int VX;
    int VY;

    int AccelerationX;
    int AccelerationY;

    int JumpCount = 0;
    int MaxJumpCount = 2;


    bool isOnGround = false;
    bool isVerticalCollision = false;

    bool isDead = false;




public:

    Entity(int X, int Y, int VX, int VY, int AccelerationX, int AccelerationY)
    {
        this->X = X;
        this->Y = Y;

        this->preX = X;
        this->preY = Y;
        this->VX = VX;
        this->VY = VY;
        this->AccelerationX = AccelerationX;
        this->AccelerationY = AccelerationY;


    }


    void Move(int newX, int newY) {
        preX = X;
        preY = Y;
        X = newX;
        Y = newY;


    }

    void SetX(int X)
    {
        this->X = X;
    }
    void SetY(int Y)
    {
        this->Y = Y;
    }
    void SetVX(int VX)
    {
        this->VX = VX;
    }
    void SetVY(int VY)
    {
        this->VY = VY;
    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    int GetVX()
    {
        return VX;
    }
    int GetVY()
    {
        return VY;
    }
    int GetWidth()
    {
        return Width;
    }
    int GetHeight()
    {
        return Height;
    }
    bool GetIsOnGround()
    {
        return isOnGround;
    }

    void UpdatePhysics()
    {
        VY += AccelerationY;
        Y += VY;
        isOnGround = false;

    }
    void CheckMap(BlockManager& BM)
    {
        if (X <= -512)
        {
            if (BM.GetShift() > 1)
            {
                X = 511;
                BM.SetShift(BM.GetShift() - 1);
            }
            else
            {
                X = -511;
            }
        }
        else if (X >= 512)
        {
            if (BM.GetShift() <= 3)
            {
                X = -511;
                BM.SetShift(BM.GetShift() + 1);
            }
            else
            {
                X = 511;
            }
        }
    }
    void CheckCollisionWithBlocks(vector<Block>& blocks)
    {
        int SizeOfBlocks = blocks.size();
        for (int i = 0; i < SizeOfBlocks; i++)
        {

            int entityTop = Y - Height / 2;
            int entityBottom = Y + Height / 2;
            int entityLeft = X - Width / 2;
            int entityRight = X + Width / 2;

            // 计算实体上一帧的边界（关键改进）
            int prevTop = preY - Height / 2;
            int prevBottom = preY + Height / 2;
            int prevLeft = preX - Width / 2;
            int prevRight = preX + Width / 2;

            // 计算障碍物边界
            int blockLeft = blocks[i].GetX() - blocks[i].GetWidth() / 2;
            int blockRight = blocks[i].GetX() + blocks[i].GetWidth() / 2;
            int blockTop = blocks[i].GetY() - blocks[i].GetHeight() / 2;
            int blockBottom = blocks[i].GetY() + blocks[i].GetHeight() / 2;

            // 1. 垂直碰撞检测（上下）

                // 检测落地碰撞：上一帧底部在障碍物上方 + 当前帧底部进入障碍物 + 水平重叠
            if (prevBottom <= blockTop &&
                entityBottom >= blockTop &&
                entityRight > blockLeft &&
                entityLeft < blockRight)
            {
                VY = 0;
                Y = blockTop - Height / 2; // 对齐到障碍物顶部
                isOnGround = true;

                JumpCount = 0;
            }



            // 检测头顶碰撞：上一帧顶部在障碍物下方 + 当前帧顶部进入障碍物 + 水平重叠
            else if (prevTop >= blockBottom &&
                entityTop <= blockBottom &&
                entityRight > blockLeft &&
                entityLeft < blockRight)
            {
                isVerticalCollision = true;
                VY = 0;
                Y = blockBottom + Height / 2; // 对齐到障碍物底部
            }


            // 2. 水平碰撞检测（左右）
            else if (isVerticalCollision = false) // 确保水平方向有移动
            {
                // 检查垂直重叠（实体在障碍物的垂直范围内）
                bool isVerticalOverlap = X > blockTop && X < blockBottom;

                if (X > preX) // 向右移动
                {
                    // 检测右侧碰撞：上一帧右侧在障碍物左侧 + 当前帧右侧进入障碍物
                    if (prevRight <= blockLeft &&
                        entityRight >= blockLeft &&
                        isVerticalOverlap)
                    {

                        X = blockLeft - Width / 2; // 对齐到障碍物左侧
                    }
                }
                else if (X < preX) // 向左移动
                {
                    // 检测左侧碰撞：上一帧左侧在障碍物右侧 + 当前帧左侧进入障碍物
                    if (prevLeft >= blockRight &&
                        entityLeft <= blockRight &&
                        isVerticalOverlap)
                    {

                        X = blockRight + Width / 2; // 对齐到障碍物右侧
                    }
                }
            }

        }
    }

    void CheckCollision(BlockManager& BM)
    {
        vector<Block>TheMapEarthBlock = BM.GetEarthBlocks();
        int SizeOfTheMapEarthBlock = BM.GetEarthBlocksSize();

        vector<Block>TheMapGrassBlock = BM.GetGrassBlocks();
        int SizeOfTheMapGrassBlock = BM.GetGrassBlocksSize();

        vector<Block>TheMapCloudBlock = BM.GetCloudBlocks();
        int SizeOfTheMapCloudBlock = BM.GetCloudBlocksSize();

        /* ---------------------------- *
         * CheckCollisionWithEarthBlock *
         * ---------------------------- */
        for (int i = 0; i < SizeOfTheMapEarthBlock; i++)
        {
            Block earth = TheMapEarthBlock[i];
            int entityTop = Y - Height / 2;
            int entityBottom = Y + Height / 2;
            int entityLeft = X - Width / 2;
            int entityRight = X + Width / 2;

            // 计算实体上一帧的边界（关键改进）
            int prevTop = preY - Height / 2;
            int prevBottom = preY + Height / 2;
            int prevLeft = preX - Width / 2;
            int prevRight = preX + Width / 2;

            // 计算障碍物边界
            int earthLeft = earth.GetX() - earth.GetWidth() / 2;
            int earthRight = earth.GetX() + earth.GetWidth() / 2;
            int earthTop = earth.GetY() - earth.GetHeight() / 2;
            int earthBottom = earth.GetY() + earth.GetHeight() / 2;

            // 1. 垂直碰撞检测（上下）
            if (VY > 0) // 向下移动（下落）
            {
                // 检测落地碰撞：上一帧底部在障碍物上方 + 当前帧底部进入障碍物 + 水平重叠
                if (prevBottom <= earthTop &&
                    entityBottom >= earthTop &&
                    entityRight > earthLeft &&
                    entityLeft < earthRight)
                {
                    VY = 0;
                    Y = earthTop - Height / 2; // 对齐到障碍物顶部
                    isOnGround = true;
                    JumpCount = 0;
                }
            }
            else if (VY < 0) // 向上移动（跳跃）
            {
                // 检测头顶碰撞：上一帧顶部在障碍物下方 + 当前帧顶部进入障碍物 + 水平重叠
                if (prevTop >= earthBottom &&
                    entityTop <= earthBottom &&
                    entityRight > earthLeft &&
                    entityLeft < earthRight)
                {
                    isVerticalCollision = true;
                    VY = 0;
                    Y = earthBottom + Height / 2; // 对齐到障碍物底部
                }
            }

            // 2. 水平碰撞检测（左右）
            if (isVerticalCollision = false) // 确保水平方向有移动
            {
                // 检查垂直重叠（实体在障碍物的垂直范围内）
                bool isVerticalOverlap = X + 16 > earthTop && X - 16 < earthBottom;

                if (X > preX) // 向右移动
                {
                    // 检测右侧碰撞：上一帧右侧在障碍物左侧 + 当前帧右侧进入障碍物
                    if (prevRight <= earthLeft &&
                        entityRight >= earthLeft &&
                        isVerticalOverlap)
                    {

                        X = earthLeft - Width / 2; // 对齐到障碍物左侧
                    }
                }
                else if (X < preX) // 向左移动
                {
                    // 检测左侧碰撞：上一帧左侧在障碍物右侧 + 当前帧左侧进入障碍物
                    if (prevLeft >= earthRight &&
                        entityLeft <= earthRight &&
                        isVerticalOverlap)
                    {

                        X = earthRight + Width / 2; // 对齐到障碍物右侧
                    }
                }
            }

        }
        /* ---------------------------- *
         * CheckCollisionWithGrassBlock *
         * ---------------------------- */
        for (int i = 0; i < SizeOfTheMapGrassBlock; i++)
        {
            Block grass = TheMapGrassBlock[i];
            int entityTop = Y - Height / 2;
            int entityBottom = Y + Height / 2;
            int entityLeft = X - Width / 2;
            int entityRight = X + Width / 2;

            // 计算实体上一帧的边界（关键改进）
            int prevTop = preY - Height / 2;
            int prevBottom = preY + Height / 2;
            int prevLeft = preX - Width / 2;
            int prevRight = preX + Width / 2;

            // 计算障碍物边界
            int grassLeft = grass.GetX() - grass.GetWidth() / 2;
            int grassRight = grass.GetX() + grass.GetWidth() / 2;
            int grassTop = grass.GetY() - grass.GetHeight() / 2;
            int grassBottom = grass.GetY() + grass.GetHeight() / 2;

            // 1. 垂直碰撞检测（上下）
            if (VY > 0) // 向下移动（下落）
            {
                // 检测落地碰撞：上一帧底部在障碍物上方 + 当前帧底部进入障碍物 + 水平重叠
                if (prevBottom <= grassTop &&
                    entityBottom >= grassTop &&
                    entityRight > grassLeft &&
                    entityLeft < grassRight)
                {
                    VY = 0;
                    Y = grassTop - Height / 2; // 对齐到障碍物顶部
                    isOnGround = true;
                    JumpCount = 0;
                }
            }
            else if (VY < 0) // 向上移动（跳跃）
            {
                // 检测头顶碰撞：上一帧顶部在障碍物下方 + 当前帧顶部进入障碍物 + 水平重叠
                if (prevTop >= grassBottom &&
                    entityTop <= grassBottom &&
                    entityRight > grassLeft &&
                    entityLeft < grassRight)
                {
                    isVerticalCollision = true;
                    VY = 0;
                    Y = grassBottom + Height / 2; // 对齐到障碍物底部
                }
            }

            // 2. 水平碰撞检测（左右）
            if (isVerticalCollision = false) // 确保水平方向有移动
            {
                // 检查垂直重叠（实体在障碍物的垂直范围内）
                bool isVerticalOverlap = X + 16 > grassTop && X - 16 < grassBottom;

                if (X > preX) // 向右移动
                {
                    // 检测右侧碰撞：上一帧右侧在障碍物左侧 + 当前帧右侧进入障碍物
                    if (prevRight <= grassLeft &&
                        entityRight >= grassLeft &&
                        isVerticalOverlap)
                    {

                        X = grassLeft - Width / 2; // 对齐到障碍物左侧
                    }
                }
                else if (X < preX) // 向左移动
                {
                    // 检测左侧碰撞：上一帧左侧在障碍物右侧 + 当前帧左侧进入障碍物
                    if (prevLeft >= grassRight &&
                        entityLeft <= grassRight &&
                        isVerticalOverlap)
                    {

                        X = grassRight + Width / 2; // 对齐到障碍物右侧
                    }
                }
            }

        }



        /* ---------------------------- *
         * CheckCollisionWithCloudBlock *
         * ---------------------------- */
        for (int i = 0; i < SizeOfTheMapCloudBlock; i++)
        {
            Block cloud = TheMapCloudBlock[i];
            int entityTop = Y - Height / 2;
            int entityBottom = Y + Height / 2;
            int entityLeft = X - Width / 2;
            int entityRight = X + Width / 2;

            // 计算实体上一帧的边界（关键改进）
            int prevTop = preY - Height / 2;
            int prevBottom = preY + Height / 2;
            int prevLeft = preX - Width / 2;
            int prevRight = preX + Width / 2;

            // 计算障碍物边界
            int cloudLeft = cloud.GetX() - cloud.GetWidth() / 2;
            int cloudRight = cloud.GetX() + cloud.GetWidth() / 2;
            int cloudTop = cloud.GetY() - cloud.GetHeight() / 2;
            int cloudBottom = cloud.GetY() + cloud.GetHeight() / 2;

            // 1. 垂直碰撞检测（上下）
            if (VY > 0) // 向下移动（下落）
            {
                // 检测落地碰撞：上一帧底部在障碍物上方 + 当前帧底部进入障碍物 + 水平重叠
                if (prevBottom <= cloudTop &&
                    entityBottom >= cloudTop &&
                    entityRight > cloudLeft &&
                    entityLeft < cloudRight)
                {
                    VY = 0;
                    Y = cloudTop - Height / 2; // 对齐到障碍物顶部
                    isOnGround = true;
                    JumpCount = 0;
                }
            }
            else if (VY < 0) // 向上移动（跳跃）
            {
                // 检测头顶碰撞：上一帧顶部在障碍物下方 + 当前帧顶部进入障碍物 + 水平重叠
                if (prevTop >= cloudBottom &&
                    entityTop <= cloudBottom &&
                    entityRight > cloudLeft &&
                    entityLeft < cloudRight)
                {
                    isVerticalCollision = true;
                    VY = 0;
                    Y = cloudBottom + Height / 2; // 对齐到障碍物底部
                }
            }

            // 2. 水平碰撞检测（左右）
            if (isVerticalCollision = false) // 确保水平方向有移动
            {
                // 检查垂直重叠（实体在障碍物的垂直范围内）
                bool isVerticalOverlap = X + 16 > cloudTop && X - 16 < cloudBottom;

                if (X > preX) // 向右移动
                {
                    // 检测右侧碰撞：上一帧右侧在障碍物左侧 + 当前帧右侧进入障碍物
                    if (prevRight <= cloudLeft &&
                        entityRight >= cloudLeft &&
                        isVerticalOverlap)
                    {

                        X = cloudLeft - Width / 2; // 对齐到障碍物左侧
                    }
                }
                else if (X < preX) // 向左移动
                {
                    // 检测左侧碰撞：上一帧左侧在障碍物右侧 + 当前帧左侧进入障碍物
                    if (prevLeft >= cloudRight &&
                        entityLeft <= cloudRight &&
                        isVerticalOverlap)
                    {

                        X = cloudRight + Width / 2; // 对齐到障碍物右侧
                    }
                }
            }



        }
    }
    void CheckCollisionWithTrap(BlockManager& BM, TrapManager& TM)
    {
        vector<Trap>CurrentMapTraps = TM.GetTraps(BM);
        for (int i = 0; i < TM.GetTrapsOfMapSize(BM); i++)
        {
            Trap tp = CurrentMapTraps[i];
            int entityTop = Y - Height / 2;
            int entityBottom = Y + Height / 2;
            int entityLeft = X - Width / 2;
            int entityRight = X + Width / 2;

            int tpLeft = tp.GetX() - tp.GetWidth() / 2;
            int tpRight = tp.GetX() + tp.GetWidth() / 2;
            int tpTop = tp.GetY() - tp.GetHeight() / 2;
            int tpBottom = tp.GetY() + tp.GetHeight() / 2;

            if (X >= tpLeft && X <= tpRight && Y <= tpBottom && Y >= tpTop)
            {
                isDead = true;
            }
        }

    }
    void Jump()
    {
        if (GetAsyncKeyState('K'))
        {
            isVerticalCollision = false;
            if (JumpCount <= MaxJumpCount)
            {
                VY = -50;
                JumpCount++;
            }
        }
    }
    void CheckDeath()
    {
        if (Y >= 512)
        {
            isDead = true;
        }
    }
    bool GetisDead()
    {
        return isDead;
    }
    void SetAlive()
    {
        isDead = false;
    }

};



class Resource {
private:
    vector<IMAGE> playerUpmask, playerDownmask, playerLeftmask, playerRightmask;

    vector<IMAGE> playerUporigin, playerDownorigin, playerLeftorigin, playerRightorigin;

    IMAGE BackGroundEarth;
    IMAGE BackGroundGrass;
    IMAGE BackGroundCloud;



    int LastDirection = 4;
    int FrameIndex = 0;


public:
    void SetLastDirection(int NewLastDirection)
    {
        LastDirection = NewLastDirection;
    }
    int GetFrameIndex()
    {
        return FrameIndex;
    }
    void SetFrameIndex(int NewFrameIndex)
    {
        FrameIndex = NewFrameIndex;
    }

    int GetTheLastDirection()
    {
        return LastDirection;
    }
    void LoadFrames(vector<IMAGE>& frames, const wstring& path, int count) {
        for (int i = 1; i <= count; ++i) {
            IMAGE img;
            wstring fullPath = path + to_wstring(i) + L".bmp";
            loadimage(&img, fullPath.c_str(), 48, 48);
            frames.push_back(img);
        }
    }

    Resource() {

        LoadFrames(playerUpmask, L"mask\\mask_manbo_run_back_", 4);
        LoadFrames(playerDownmask, L"mask\\mask_manbo_run_front_", 4);
        LoadFrames(playerLeftmask, L"mask\\mask_manbo_run_left_", 4);
        LoadFrames(playerRightmask, L"mask\\mask_manbo_run_right_", 4);

        LoadFrames(playerUporigin, L"origin\\source_manbo_run_back_", 4);
        LoadFrames(playerDownorigin, L"origin\\source_manbo_run_front_", 4);
        LoadFrames(playerLeftorigin, L"origin\\source_manbo_run_left_", 4);
        LoadFrames(playerRightorigin, L"origin\\source_manbo_run_right_", 4);

        loadimage(&BackGroundEarth, L"BackGroundEarth.jpg", 1024, 1024);
        loadimage(&BackGroundGrass, L"BackGroundGrass.jpg", 1024, 1024);
        loadimage(&BackGroundCloud, L"BackGroundCloud.jpg", 1024, 1024);

    }

    void DrawStillEntity(Entity& entity)//与checkLast绑定检查上个方向实现待机朝向
    {
        vector<IMAGE>* LastFrameMask = &playerRightmask;
        vector<IMAGE>* LastFrameOrigin = &playerRightorigin;

        switch (LastDirection)
        {
        case 1:  LastFrameMask = &playerUpmask;
            LastFrameOrigin = &playerUporigin;
            break;
        case 2:  LastFrameMask = &playerDownmask;
            LastFrameOrigin = &playerDownorigin;
            break;
        case 3:  LastFrameMask = &playerLeftmask;
            LastFrameOrigin = &playerLeftorigin;
            break;
        case 4:  LastFrameMask = &playerRightmask;
            LastFrameOrigin = &playerRightorigin;
            break;
        }


        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*LastFrameMask)[0], SRCAND);
        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*LastFrameOrigin)[0], SRCPAINT);

    }

    void DrawEntityMoveUp(Entity& entity, int frameIndex) {
        vector<IMAGE>* frames1 = &playerUpmask;
        vector<IMAGE>* frames2 = &playerUporigin;

        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames1)[frameIndex], SRCAND);
        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames2)[frameIndex], SRCPAINT);
    }
    void DrawEntityMoveDown(Entity& entity, int frameIndex) {
        vector<IMAGE>* frames1 = &playerDownmask;
        vector<IMAGE>* frames2 = &playerDownorigin;

        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames1)[frameIndex], SRCAND);
        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames2)[frameIndex], SRCPAINT);
    }
    void DrawEntityMoveLeft(Entity& entity, int frameIndex) {
        vector<IMAGE>* frames1 = &playerLeftmask;
        vector<IMAGE>* frames2 = &playerLeftorigin;

        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames1)[frameIndex], SRCAND);
        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames2)[frameIndex], SRCPAINT);
    }
    void DrawEntityMoveRight(Entity& entity, int frameIndex) {
        vector<IMAGE>* frames1 = &playerRightmask;
        vector<IMAGE>* frames2 = &playerRightorigin;

        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames1)[frameIndex], SRCAND);
        putimage(entity.GetX() - entity.GetWidth() / 2, entity.GetY() - entity.GetHeight() / 2, &(*frames2)[frameIndex], SRCPAINT);
    }

    void DrawBackGround(BlockManager& BM)
    {
        if (BM.GetShift() == 1)
        {
            putimage(-512, -512, &BackGroundEarth);
        }
        else if (BM.GetShift() == 2)
        {
            putimage(-512, -512, &BackGroundGrass);
        }
        else if (BM.GetShift() == 3)
        {
            putimage(-512, -512, &BackGroundCloud);
        }

    }
};



class Boss
{
    int X;
    int Y;
    int Width;
    int Height;
    int Hp;
    IMAGE BossImageMask;
    IMAGE BossImageOrigin;
    int Direction = -1;
    int Speed = 10;
public:
    int GetWidth()
    {
        return Width;
    }
    int GetHeight()
    {
        return Height;
    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
    int GetHp()
    {
        return Hp;
    }
    Boss(int X, int Y, int Width, int Height, int Hp) :X(X), Y(Y), Width(Width), Height(Height), Hp(Hp)
    {

        loadimage(&BossImageMask, L"i wanna素材mask\\mask_PC Computer - I Wanna be the Justice Guy KOR - Becket D Perfectman.bmp", 638, 131);
        loadimage(&BossImageOrigin, L"i wanna素材origin\\source_PC Computer - I Wanna be the Justice Guy KOR - Becket D Perfectman.bmp", 638, 131);

    }

    void SetHp(int NewHp)
    {
        Hp = NewHp;
    }

    bool CheckHp()
    {
        return Hp > 0;
    }

    void Draw()
    {

        putimage(X - Width / 2, Y - Height / 2, &BossImageMask, SRCAND);
        putimage(X - Width / 2, Y - Height / 2, &BossImageOrigin, SRCPAINT);

    }

    void AutoMove()
    {
        if (X - Width / 2 < -500)
        {

            X = -500 + Width / 2;
            Speed = 0;
            Direction = 1;
            int Count = 0;
            for (int i = 0; i < 20; i++)
            {
                Count++;
            }
            if (Count == 20)
            {
                Speed = 10;
            }
        }
        else if (X + Width / 2 > 500)
        {

            X = 500 - Width / 2;
            Direction = -1;

        }
        X += Speed * Direction;


    }
};

class BossManager
{
private:
    vector<Boss>Bosses;
public:


    void AddBosses()
    {
        Boss bs(0, -300, 638, 131, 10);
        Bosses.push_back(bs);

    }
    Boss* GetBoss()
    {
        if (HasBosses())
        {
            return &Bosses.front();
        }
        else
        {
            return nullptr;
        }

    }
    void Update()
    {


        if (!Bosses.empty())
        {
            Boss& currentBoss = Bosses.front();

            if (currentBoss.CheckHp() == true)
            {
                currentBoss.Draw();
            }
            else
            {

                Bosses.clear();

            }
            currentBoss.AutoMove();
        }
    }
    bool HasBosses()const
    {
        return !Bosses.empty();
    }

    Boss& GetCurrentBoss()
    {
        if (this->HasBosses())
        {
            return Bosses.front();
        }
    }

};

class BulletOfBoss
{
private:
    float X;
    float Y;
    float Angle;
    float Speed;
    float Radius;

public:
    BulletOfBoss(float X, float Y, float Angle, float Speed, float Radius) :X(X), Y(Y), Angle(Angle), Speed(Speed), Radius(Radius) {}

    float GetX()
    {
        return X;
    }

    float GetY()
    {
        return Y;
    }

    float GetSpeed()
    {
        return Speed;
    }
    float GetAngle()
    {
        return Angle;
    }

    void SetX(float NewX)
    {
        X = NewX;
    }
    void SetY(float NewY)
    {
        Y = NewY;
    }

    bool JudgeOutOfMap()
    {
        if (X - Radius >= 400)
        {
            return true;
        }
        else if (X + Radius <= -400)
        {
            return true;
        }
        else if (Y - Radius >= 400)
        {
            return true;
        }
        else if (Y + Radius <= -400)
        {
            return true;
        }
        return false;
    }

    bool CollisionWithEntity(Entity& entity)
    {
        if (X + Radius >= entity.GetX() - entity.GetWidth() / 2 && X - Radius <= entity.GetX() + entity.GetWidth() / 2 && Y - Radius <= entity.GetY() + entity.GetHeight() / 2 && Y + Radius >= entity.GetY() - entity.GetHeight() / 2)
        {

            return true;

        }
        else
        {
            return false;
        }
    }
};
class BulletOfBossManager
{
private:
    vector<BulletOfBoss>Bullets;

public:
    void AddBullets(BossManager& bsm) {
        if (bsm.HasBosses())
        {
            Boss* currentBoss = bsm.GetBoss();
            if (currentBoss != nullptr)
            {
                const float COUNT = 36.0f;
                const float SPEED = 5.0f;

                for (int i = 0; i < static_cast<int>(COUNT); ++i)
                {
                    float angle = 2.0f * PI * static_cast<float>(i) / COUNT;
                    Bullets.emplace_back(static_cast<float>(currentBoss->GetX()), static_cast<float>(currentBoss->GetY()), angle, SPEED, 4.0f);
                }
            }
        }
    }

    void UpdateBullets(Entity& entity)
    {


        for (int i = 0; i < Bullets.size(); i++)
        {

            float dx = static_cast<float>(Bullets[i].GetSpeed() * cos(static_cast<double>(Bullets[i].GetAngle())));
            float dy = static_cast<float>(-Bullets[i].GetSpeed() * sin(static_cast<double>(Bullets[i].GetAngle())));
            Bullets[i].SetX(Bullets[i].GetX() + dx);
            Bullets[i].SetY(Bullets[i].GetY() + dy);
        }

        for (int i = static_cast<int>(Bullets.size()) - 1; i >= 0; i--)
        {

            if (Bullets[i].GetX() < -500 || Bullets[i].GetX() > 500 || Bullets[i].GetY() < -500 || Bullets[i].GetY() > 500 || Bullets[i].CollisionWithEntity(entity))
            {
                Bullets.erase(Bullets.begin() + i);
            }
            else
            {
                setfillcolor(RED);  // 改用红色

                fillcircle(static_cast<int>(Bullets[i].GetX()), static_cast<int>(Bullets[i].GetY()), 5);  // 子弹尺寸

            }
        }


    }
};



class Bullet
{
private:
    int X;
    int Y;
    int Speed;
    int Radius;
    int TheLastDirection;
    IMAGE Bulletmask;
    IMAGE Bulletorigin;

public:
    Bullet(int X, int Y, int Speed, int Radius, Resource& res) :X(X), Y(Y), Speed(Speed), Radius(Radius), TheLastDirection(res.GetTheLastDirection())
    {
        loadimage(&Bulletmask, L"i wanna素材mask\\mask_子弹（白色）.bmp", 8, 8);
        loadimage(&Bulletorigin, L"i wanna素材origin\\source_子弹（白色）.bmp", 8, 8);
    }


    void Shoot()
    {

        if (TheLastDirection == 1)
        {
            Y -= Speed;
        }
        if (TheLastDirection == 2)
        {
            Y += Speed;
        }
        if (TheLastDirection == 3)
        {
            X -= Speed;
        }
        if (TheLastDirection == 4)
        {
            X += Speed;
        }
    }

    void Draw()
    {
        putimage(X, Y, &Bulletmask, SRCAND);
        putimage(X, Y, &Bulletorigin, SRCPAINT);

    }

    bool JudgeOutOfMap()
    {
        if (X - Radius >= 500)
        {
            return true;
        }
        else if (X + Radius <= -500)
        {
            return true;
        }
        else if (Y - Radius >= 500)
        {
            return true;
        }
        else if (Y + Radius <= -500)
        {
            return true;
        }
        return false;
    }

    bool CollisionWithBoss(Boss& boss)
    {
        if (X + Radius >= boss.GetX() - boss.GetWidth() / 2 && X - Radius <= boss.GetX() + boss.GetWidth() / 2 && Y - Radius <= boss.GetY() + boss.GetHeight() / 2 && Y + Radius >= boss.GetY() - boss.GetHeight() / 2)
        {
            cout << boss.GetHp() << endl;
            return true;

        }
        else
        {
            return false;
        }
    }
};

class BulletManager
{
private:
    vector<Bullet>Bullets;

public:
    void AddBullets(int X, int Y, Resource& res)
    {
        Bullets.emplace_back(X, Y, 10, 4, res);

    }
    void UpdateBullets(BossManager& bsm)
    {

        for (int i = 0; i < Bullets.size(); i++)
        {


            Bullets[i].Shoot();
            Bullets[i].Draw();

            if (bsm.HasBosses())
            {
                Boss& currentboss = bsm.GetCurrentBoss();

                if (Bullets[i].CollisionWithBoss(currentboss))
                {
                    currentboss.SetHp(currentboss.GetHp() - 1);
                    Bullets.erase(Bullets.begin() + i);

                }
            }
            else if (Bullets[i].JudgeOutOfMap())
            {
                Bullets.erase(Bullets.begin() + i);

            }


        }

    }


};

bool HandleInput(Entity& entity, Resource& res) {
    int newX = entity.GetX();
    int newY = entity.GetY();
    int SpeedX = entity.GetVX();
    int SpeedY = entity.GetVY();

    bool hasinput = false;
    if (GetAsyncKeyState('W'))
    {
        res.SetLastDirection(1);
        res.DrawEntityMoveUp(entity, res.GetFrameIndex());
        hasinput = true;
    }
    else if (GetAsyncKeyState('S'))
    {
        res.SetLastDirection(2);
        res.DrawEntityMoveDown(entity, res.GetFrameIndex());
        hasinput = true;
    }
    else if (GetAsyncKeyState('A'))
    {

        res.SetLastDirection(3);
        newX -= SpeedX;
        res.DrawEntityMoveLeft(entity, res.GetFrameIndex());
        entity.Move(newX, newY);
        hasinput = true;
    }
    else if (GetAsyncKeyState('D'))
    {

        res.SetLastDirection(4);
        newX += SpeedX;
        res.DrawEntityMoveRight(entity, res.GetFrameIndex());
        entity.Move(newX, newY);
        hasinput = true;
    }
    else if (!hasinput)
    {
        entity.Move(newX, newY);
    }

    return hasinput;

}

class Button
{
private:
    int X;
    int Y;
    int Width;
    int Height;
    LPCWSTR text;
    COLORREF color;

public:
    Button(int X, int Y, int Width, int Height, LPCWSTR text, COLORREF color) :X(X), Y(Y), Width(Width), Height(Height), text(text), color(color) {}
    void Draw()
    {

        setfillcolor(color);
        solidrectangle(X - Width / 2, Y - Height / 2, X + Width / 2, Y + Height / 2);
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        outtextxy(X - Width / 3, Y - Height / 3, text);
    }
    bool IsClicked(int mx, int my)
    {
        return mx >= X - Width / 2 && mx <= X + Width / 2 && my >= Y - Height / 2 && my <= Y + Height / 2;

    }
};

void ShowStartScreen(bool& running) {
    IMAGE StartBackGround;
    loadimage(&StartBackGround, L"帝皇.jpg", 1024, 1024);
    putimage(-512, -512, &StartBackGround);

    setbkmode(TRANSPARENT);
    settextstyle(40, 0, L"楷体");
    settextcolor(YELLOW);
    outtextxy(-150, -100, L"I Wanna But Manbo");


    Button StartButton(0, -250, 200, 60, L"开始游戏", BLUE);
    StartButton.Draw();

    // 等待点击按钮
    while (true) {

        ExMessage msg;
        peekmessage(&msg, EX_MOUSE);
        int mx = msg.x - 500;
        int my = msg.y - 500;//因为他是按照左上角为00点，所以为了和我设定的一致我要改一下；
        if (msg.message == WM_LBUTTONDOWN && StartButton.IsClicked(mx, my)) {


            running = true;
            cleardevice();
            break; // 进入游戏

        }


    }
}
static IMAGE ALRePointImageMask;
static IMAGE ALRePointImageOrigin;
static IMAGE WARePointImageMask;
static IMAGE WARePointImageOrigin;
class RebirthPoint
{
private:

    int X;
    int Y;
    int Width = 32;
    int Height = 32;
    int Trigger = 0;
public:
    RebirthPoint() :X(-420), Y(420) {}

    static void InitializeImage()
    {
        loadimage(&ALRePointImageMask, L"i wanna素材mask\\mask_存档（已存）.bmp", 32, 32);
        loadimage(&ALRePointImageOrigin, L"i wanna素材origin\\source_存档（已存）.bmp", 32, 32);
        loadimage(&WARePointImageMask, L"i wanna素材mask\\mask_存档（未存）.bmp", 32, 32);
        loadimage(&WARePointImageOrigin, L"i wanna素材origin\\source_存档（未存）.bmp", 32, 32);
    }

    RebirthPoint(int X, int Y) :X(X), Y(Y) {}

    void DrawRePoint()
    {
        if (Trigger == 0)
        {
            putimage(X - Width / 2, Y - Height / 2, &WARePointImageMask, SRCAND);
            putimage(X - Width / 2, Y - Height / 2, &WARePointImageOrigin, SRCPAINT);

        }
        else if (Trigger == 1)
        {
            putimage(X - Width / 2, Y - Height / 2, &ALRePointImageMask, SRCAND);
            putimage(X - Width / 2, Y - Height / 2, &ALRePointImageOrigin, SRCPAINT);

        }
    }
    int GetX()
    {
        return X;
    }

    int GetY()
    {
        return Y;
    }
    int GetWidth()
    {
        return Width;
    }
    int GetHeight()
    {
        return Height;
    }
    void SetTrigger()
    {
        Trigger = 1;
    }
};

class RebirthPointManager
{
private:
    vector<RebirthPoint>RePointsOfMap1;
    vector<RebirthPoint>RePointsOfMap2;
    vector<RebirthPoint>RePointsOfMap3;
    RebirthPoint CurrentPoint;

public:

    void AddRePoints()
    {
        RebirthPoint rb11(-420, 420);
        rb11.InitializeImage();//只用初始化一次因为static
        RebirthPoint rb12(-48, 256);
        RebirthPoint rb13(-352, -356);
        RePointsOfMap1.push_back(rb11);
        RePointsOfMap1.push_back(rb12);
        RePointsOfMap1.push_back(rb13);


        RebirthPoint rb31(-496, -16);
        RebirthPoint rb32(16, -368);
        RePointsOfMap2.push_back(rb31);
        RePointsOfMap2.push_back(rb32);

        RebirthPoint rb4(-420, 420);
        RePointsOfMap3.push_back(rb4);
    }

    void DrawRePoints(BlockManager& BM)
    {
        if (BM.GetShift() == 1)
        {
            for (int i = 0; i < RePointsOfMap1.size(); i++)
            {

                RePointsOfMap1[i].DrawRePoint();
            }
        }
        else if (BM.GetShift() == 2)
        {
            for (int i = 0; i < RePointsOfMap2.size(); i++)
            {

                RePointsOfMap2[i].DrawRePoint();
            }
        }
        else if (BM.GetShift() == 3)
        {
            for (int i = 0; i < RePointsOfMap3.size(); i++)
            {

                RePointsOfMap3[i].DrawRePoint();
            }
        }
    }

    void CheckCollision(Entity& entity, BlockManager& BM)
    {
        int entityLeft = entity.GetX() - entity.GetWidth() / 2;
        int entityRight = entity.GetX() + entity.GetWidth() / 2;
        int entityUp = entity.GetY() - entity.GetHeight() / 2;
        int entityDown = entity.GetY() + entity.GetHeight() / 2;

        if (BM.GetShift() == 1)
        {
            for (int i = 0; i < RePointsOfMap1.size(); i++)
            {

                int ThePointLeft = RePointsOfMap1[i].GetX() - RePointsOfMap1[i].GetWidth() / 2;
                int ThePointRight = RePointsOfMap1[i].GetX() + RePointsOfMap1[i].GetWidth() / 2;
                int ThePointUp = RePointsOfMap1[i].GetY() - RePointsOfMap1[i].GetHeight() / 2;
                int ThePointDown = RePointsOfMap1[i].GetY() + RePointsOfMap1[i].GetHeight() / 2;

                if (entity.GetX() >= ThePointLeft && entity.GetX() <= ThePointRight && entity.GetY() <= ThePointDown && entity.GetY() >= ThePointUp)
                {
                    RePointsOfMap1[i].SetTrigger();
                    CurrentPoint = RePointsOfMap1[i];
                }
            }

        }
        else if (BM.GetShift() == 2)
        {
            for (int i = 0; i < RePointsOfMap2.size(); i++)
            {

                int ThePointLeft = RePointsOfMap2[i].GetX() - RePointsOfMap2[i].GetWidth() / 2;
                int ThePointRight = RePointsOfMap2[i].GetX() + RePointsOfMap2[i].GetWidth() / 2;
                int ThePointUp = RePointsOfMap2[i].GetY() - RePointsOfMap2[i].GetHeight() / 2;
                int ThePointDown = RePointsOfMap2[i].GetY() + RePointsOfMap2[i].GetHeight() / 2;

                if (entity.GetX() >= ThePointLeft && entity.GetX() <= ThePointRight && entity.GetY() <= ThePointDown && entity.GetY() >= ThePointUp)
                {
                    RePointsOfMap2[i].SetTrigger();
                    CurrentPoint = RePointsOfMap2[i];
                }
            }
        }

        else if (BM.GetShift() == 3)
        {
            for (int i = 0; i < RePointsOfMap3.size(); i++)
            {

                int ThePointLeft = RePointsOfMap3[i].GetX() - RePointsOfMap3[i].GetWidth() / 2;
                int ThePointRight = RePointsOfMap3[i].GetX() + RePointsOfMap3[i].GetWidth() / 2;
                int ThePointUp = RePointsOfMap3[i].GetY() - RePointsOfMap3[i].GetHeight() / 2;
                int ThePointDown = RePointsOfMap3[i].GetY() + RePointsOfMap3[i].GetHeight() / 2;

                if (entity.GetX() >= ThePointLeft && entity.GetX() <= ThePointRight && entity.GetY() <= ThePointDown && entity.GetY() >= ThePointUp)
                {
                    RePointsOfMap3[i].SetTrigger();
                    CurrentPoint = RePointsOfMap3[i];
                }
            }
        }


    }

    void Reborn(Entity& entity)
    {
        if (entity.GetisDead() == true)
        {
            entity.SetX(CurrentPoint.GetX());
            entity.SetY(CurrentPoint.GetY());
            entity.SetAlive();
            entity.SetVY(0);
        }
    }
};


int main()
{
    initgraph(1024, 1024);
    setorigin(512, 512);

    TrapManager TM;


    BulletOfBossManager BOBM;

    RebirthPointManager RPM;
    RPM.AddRePoints();

    Entity entity(-440, 428, 10, 0, 10, 10);

    Resource Res;

    BulletManager BTM;

    BossManager bsm;


    bsm.AddBosses();



    bool running = false;


    ShowStartScreen(running);

    if (running)
    {
        PlaySound(L"老人と海.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }

    BeginBatchDraw();
    BlockManager BM; //地面管理待补充
    BM.InitializeMap();//地面管理待补充


    while (running) {
        cleardevice();
        Res.DrawBackGround(BM);

        TM.InitializeTraps();
        TM.Update(BM);
        entity.CheckCollisionWithTrap(BM, TM);

        entity.CheckMap(BM);



        BOBM.UpdateBullets(entity);



        RPM.CheckCollision(entity, BM);
        RPM.Reborn(entity);
        RPM.DrawRePoints(BM);
        entity.CheckDeath();

        if (BM.GetShift() == 3)
        {
            bsm.Update();
            Boss* currentBoss = bsm.GetBoss();
            if (currentBoss != nullptr &&
                (currentBoss->GetX() == -81 || currentBoss->GetX() == 81))
            {
                BOBM.AddBullets(bsm);
            }
        }


        BM.Update();//地面管理待补充





        entity.UpdatePhysics();



        entity.CheckCollision(BM);

        entity.Jump();



        if (GetAsyncKeyState('J'))
        {
            BTM.AddBullets(entity.GetX(), entity.GetY(), Res);
        }


        BTM.UpdateBullets(bsm);


        bool hasKeyinput = HandleInput(entity, Res);



        if (!hasKeyinput)
        {
            Res.DrawStillEntity(entity);
        }

        Res.SetFrameIndex((Res.GetFrameIndex() + 1) % 4);


        if (GetAsyncKeyState(VK_ESCAPE))
        {
            saveimage(_T("D:\\test.bmp"));
            running = false;
        }
        FlushBatchDraw();
        Sleep(50);



    }
    EndBatchDraw();
    PlaySound(NULL, NULL, 0);
    closegraph();
    return 0;
}

