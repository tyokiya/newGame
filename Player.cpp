#include"DxLib.h"
#include"player.h"

Player::Player()
{
	//3Dモデルの読み込み
	modelHandle = MV1LoadModel("Model/Model.mv1");
	//3Dモデルの圧縮
	MV1SetScale(modelHandle, VGet(PlayerSizeScale, PlayerSizeScale, PlayerSizeScale));
	//座標のセット
	pos = VGet(-30.0f, 0.0f, 0.0f);
	vergePos = pos;
	//プレイヤーの回転値をセット(0度)
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, 89.5f, 0.0f));
}

Player::~Player()
{
	// 3Dモデルの開放
	MV1DeleteModel(modelHandle);
}

/// <summary>
/// プレヤーの更新
/// </summary>
void Player::Updata()
{
	// 1フレ前の座標更新
	vergePos = pos;

	// キーの入力に応じて移動処理
	if (CheckHitKey(KEY_INPUT_SPACE) && !isJump) // ジャンプ処理
	{
		isJump = true;               // フラグを立てる
		nowJumpForce = AddJumpForce; // 現在のジャン力を更新
	}

	// ジャンプ中の処理
	if (isJump)
	{
		pos.y += nowJumpForce;   // 座標の更新
		nowJumpForce -= Gravity; // 現在のジャンプ力を更新
		
		// プレイヤーが地面に埋まってないか確認
		if (pos.y < 0)
		{
			pos.y = 0;	      // 座標設定
			isJump = false;	  // フラグを下す
			nowJumpForce = 0; //現在のジャン力を初期化
		}
	}
	// 走り中の処理
	pos.x += RunSpeed;

	//プレイヤーの座標設定
	MV1SetPosition(modelHandle, pos);
}

void Player::Draw()
{
	// プレイヤーの描画
	MV1DrawModel(modelHandle);
}
