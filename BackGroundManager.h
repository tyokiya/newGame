#pragma once
#include "DxLib.h"
#include "vector"
#include "BackGroundObject.h"

class BackGroundObject;
using namespace std;

const float HouseSizeScale = 0.2f;   // 家オブジェクトの圧縮値
const float House2SizeScale = 0.1f; // 家オブジェクト2の圧縮値

/// <summary>
/// 背景管理クラス
/// </summary>
class BackGroundManager
{
public:
	BackGroundManager();                       // コンストラクタ
	~BackGroundManager();                      // デストラクタ
	void CreateBackGroudObj(float cameraPosX); // 背景オブジェクト生成処理
	void Update(float cameraPosX);             // 更新処理
	void Draw();                               // 描画処理
private:
	vector<BackGroundObj*> backGoundObjects; // 背景オブジェクトのコンテナ
	int BackImgHandle;                       // 背景画像のハンドル
};
