#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
}

Player::Player(string name, Color color){
	this->name = name;
	this->color = color;
}
string Player::getName()const{
	return name;
}
Color Player::getColor()const {
	return color;
}
