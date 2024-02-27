#include "Player.h"
#include<Novice.h>


void Player::Initalize() {
	x = 300;
	y = 500;
	posX_ = x;
	posY_ = y;
	speedX_ = 10;
	speedY_ = 10;
	posR_ = 20;
	bulletX_ = posX_;
	bulletY_ = posY_;
	bulletR_ = posR_ / 2;
	is_shot_ = 0;
	is_Alive_ = 1;
	postime_ = 50;
}

void Player::Update() {

	if (is_Alive_ == 1) {
		if (keys_[DIK_W] && preKeys_[DIK_W]) {
			posY_ -= speedY_;
		}
		if (keys_[DIK_S] && preKeys_[DIK_S]) {
			posY_ += speedY_;
		}
		if (keys_[DIK_A] && preKeys_[DIK_A]) {
			posX_ -= speedX_;
		}
		if (keys_[DIK_D] && preKeys_[DIK_D]) {
			posX_ += speedX_;
		}

		if (is_shot_ == 0) {
			if (keys_[DIK_Z] && preKeys_[DIK_Z]) {
				bulletX_ = posX_;
				bulletY_ = posY_;
				is_shot_ = 1;
			}
		}
		if (is_shot_ == 1) {
			bulletY_ -= speedY_;
		}
		if (bulletY_ <= 0) {
			is_shot_ = 0;
		}
	}

	if (is_Alive_ == 0) {
		postime_ -= 1;
	}
	if (postime_ == 0) {
		is_Alive_ = 1;
		postime_ = 50;

	}

}

void Player::Draw() {
	if (is_Alive_ == 1) {
		Novice::DrawEllipse(posX_, posY_, posR_, posR_, 0, WHITE, kFillModeSolid);
	}
	
	if (is_shot_ == 1) {
		Novice::DrawEllipse(bulletX_, bulletY_, bulletR_, bulletR_, 0, RED, kFillModeSolid);
	}
	
}

void Player::Setkeys(char keys[], char prekeys[]) {
	memcpy(keys_, keys, 256);
	memcpy(preKeys_, prekeys, 256);

}

int Player::BulletGetX()
{
	return bulletX_;
}

int Player::BulletGetY()
{
	return bulletY_;
}

int Player::BulletGetR()
{
	return bulletR_;
}

int Player::PlayerGetX()
{
	return posX_;
}

int Player::PlayerGetY()
{
	return posY_;
}

int Player::PlayerGetR()
{
	return posR_;
}

void Player::OnCollision(){
	is_Alive_ = 0;
}
