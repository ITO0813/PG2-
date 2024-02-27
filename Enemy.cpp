#include "Enemy.h"
#include<Novice.h>

void Enemy::Initalize() { 
	enemyX_ = 300;
	enemyY_ = 100;
	enemyR_ = 16;
	speed_ = 10;
	isAlive_ = 1;
	time_ = 50;
}

void Enemy::Update() { 
	if (isAlive_ == 1) {
		enemyX_ += speed_;
		if (enemyX_ <= enemyR_ || enemyX_ >= 1264 + enemyR_) {
			speed_ *= -1;
		}
	}if (isAlive_ == 0) {
		time_ -= 1;
	}
	if (time_ == 0) {
		isAlive_ = 1;
		time_ = 50;
		
	}
}

void Enemy::Draw() { 
	if (isAlive_ == 1) {
		Novice::DrawEllipse(enemyX_, enemyY_, enemyR_, enemyR_, 1.0, WHITE, kFillModeSolid);
	}
	
}

int Enemy::EnemyGetX()
{
	return enemyX_;
}

int Enemy::EnemyGetY()
{
	return enemyY_;
}

int Enemy::EnemyGetR()
{
	return enemyR_;
}

void Enemy::OnCollision(){
	isAlive_ = 0;
}
