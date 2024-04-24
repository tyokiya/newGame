#include"DxLib.h"
#include"player.h"

Player::Player()
{
	//3Dモデルの読み込み
	modelHandle = MV1LoadModel("Model/Model.mv1");
	//3Dモデルの圧縮
	MV1SetScale(modelHandle, VGet(PlayerSizeScale, PlayerSizeScale, PlayerSizeScale));
	//座標のセット
	pos = VGet(0.0f, 0.0f, 0.0f);
	//プレイヤーの回転値をセット(0度)
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, 0.0f, 0.0f));
}

Player::~Player()
{
	// 3Dモデルの開放
}

/// <summary>
/// プレヤーの更新
/// </summary>
void Player::Updata()
{
	//復活フラグ
	//ply->displayFlg = true;

	//プレイヤーの座標設定
	MV1SetPosition(modelHandle, pos);

	// キーの入力に応じて移動処理
	if (CheckHitKey(KEY_INPUT_SPACE)) // ジャンプ処理
	{

	}
	
}

void Player::Draw()
{
	// プレイヤーの描画
	MV1DrawModel(modelHandle);
}
