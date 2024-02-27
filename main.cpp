#include <Novice.h>
#include<math.h>
#include"Enemy.h"
#include"Player.h"

const char kWindowTitle[] = "GC1D_01_イトウヒビキ_タイトル";

enum scene {
	title,
	main,
	clear,
	gameover
};

bool BulletCollision(Player* player, Enemy* enemy) {

	float bulletX = (float)enemy->EnemyGetX() - (float)player->BulletGetX();
	float bulletY = (float)enemy->EnemyGetY() - (float)player->BulletGetY();
	float bulletZ = sqrtf(bulletX * bulletX + bulletY * bulletY);
	int bulletR = player->BulletGetR();
	int enemyR = enemy->EnemyGetR();

	if (bulletZ <= bulletR + enemyR) {
		return true;
	}
	else {
		return false;
	}
}

bool Collision(Player* player, Enemy* enemy) {
	float X = (float)enemy->EnemyGetX() - (float)player->PlayerGetX();
	float Y = (float)enemy->EnemyGetY() - (float)player->PlayerGetY();
	float Z = sqrtf(X * X + Y * Y);
	int R = player->PlayerGetR();
	int enemyR = enemy->EnemyGetR();

	if (Z <= R + enemyR) {
		return true;
	}
	else {
		return false;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	scene scene = title;
	Player* player = new Player();
	Enemy* enemy = new Enemy();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Setkeys(keys, preKeys);

		switch (scene) {
		case title:
			if (keys[DIK_SPACE]) { 
				scene = main;
				player->Initalize();
				enemy->Initalize();
			}
			break;
		case main:
			player->Update();
			enemy->Update();
			if (BulletCollision(player, enemy) == true) {
				enemy->OnCollision();
			}
			if (Collision(player, enemy) == true) {
				player->OnCollision();
			}
			if (keys[DIK_R]) {
				scene = title;
				player->Initalize();
				enemy->Initalize();
			}
			break;
		default:
			title;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (scene) {
		case title:

			Novice::ScreenPrintf(600, 360, "TITLE  Please SPACE\n");

			break;
		case main:
			player->Draw();
			enemy->Draw();

			Novice::ScreenPrintf(1100, 600, "W = UP\n");
			Novice::ScreenPrintf(1100, 620, "S = DAWN\n");
			Novice::ScreenPrintf(1100, 640, "A = LEFT\n");
			Novice::ScreenPrintf(1100, 660, "D = RIGHT\n");
			Novice::ScreenPrintf(1100, 680, "Z = Bullet\n");
			Novice::ScreenPrintf(1100, 700, "R = RESET\n");

			break;
		default:
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
