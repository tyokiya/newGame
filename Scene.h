#pragma once
#include "DxLib.h"

// シーン列挙隊
enum SeceList
{
    Tittle,
    Game,
    Result,
};

class Scene
{
public:
    Scene();
    ~Scene();
    void ChangeNextScene(); // 次のシーンへ切り替え
    SeceList GetNowScene() const { return nowScene; };
private:
    SeceList nowScene; // 現在のシーン
};
