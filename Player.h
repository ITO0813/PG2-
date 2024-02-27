#pragma once

class Player {
public:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int posR_;
	int x;
	int y;
	int bulletX_;
	int bulletY_;
	int bulletR_;
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
	bool is_shot_;
	bool is_Alive_;
	int postime_;


public:
	void Initalize();
	void Update();
	void Draw();
	void Setkeys(char keys[], char prekeys[]);
	int BulletGetX();
	int BulletGetY();
	int BulletGetR();
	int PlayerGetX();
	int PlayerGetY();
	int PlayerGetR();
	void OnCollision();
};
