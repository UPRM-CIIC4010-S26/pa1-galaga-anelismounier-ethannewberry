#pragma once
#include "Enemy.hpp"

class DyEnemy : public Enemy {
    private: 
        float angle = 135;
        float aimAngle = 225;
        bool loop = false;
        //Adding variable to store chosen texture source
        Rectangle sourceRectangle;
    public:
        DyEnemy(float x, float y) : Enemy(x, y) { 
            this->cooldown = GetRandomValue(90, 300);
            this->health = 1; 
            this->scoreValue = 50; //Set DyEnemy specific score

            //Randomly assign one of two textures
             if (GetRandomValue(0, 1) == 0) {
                this->sourceRectangle = Rectangle{161, 103, 13, 13}; 
            } else {
                this->sourceRectangle = Rectangle{2, 147, 13, 13};   
            }
        }
        
        void draw() override;
        void update(std::pair<float, float> pos, HitBox target) override;
        void attack(HitBox target) override;
    };