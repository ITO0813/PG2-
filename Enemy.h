#pragma once

class Enemy {

private:
	int enemyX_;
	int enemyY_;
	int speed_;
	int enemyR_;
	int isAlive_;
	int time_;

public:
	void Initalize();
	void Update();
	void Draw();
	int EnemyGetX();
	int EnemyGetY();
	int EnemyGetR();
	void OnCollision();
};