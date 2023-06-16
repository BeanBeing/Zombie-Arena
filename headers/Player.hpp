#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
   Player();

   ~Player() = default;

   void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);

   // Call this at the end of every game
   void resetPlayerStats();

   // Handle player getting hit by a zombie
   bool hit(sf::Time timeHit);

   // How long ago was player last hit
   sf::Time getLastHitTime();

   // Get location of player
   sf::FloatRect getPosition();

   // Where is the center of Player
   sf::Vector2f getCenter();

   // Angle Player is facing
   float getRotation();

   // Send copy of the sprite to main function
   sf::Sprite getSprite();

   // Gets the info of player's current health
   int getHealth();

   // Player Movement
   void moveUp();
   void moveDown();
   void moveLeft();
   void moveRight();

   // Stops player moving in a specific direction
   void stopUp();
   void stopDown();
   void stopLeft();
   void stopRight();

   // Called once every frame
   void update(float elapsedTime, sf::Vector2i mousePosition);

   // Increase the player speed
   void upgradeSpeed();

   // Increase the player health
   void upgradeHealth();
   
   // Give the player health
   void healing(int amount);

   
   
private:
   const float START_SPEED = 200;
   const float START_HEALTH = 100;

   // Player Position
   sf::Vector2f m_Position;

   // Player Sprite
   sf::Sprite m_Sprite;

   // Player Texture
   sf::Texture m_Texture;

   // Screen resolution
   sf::Vector2f m_Resolution;

   // Size of current arena
   sf::IntRect m_Arena;

   // How big is each tile of arena
   int m_TileSize;

   // Which direction is player currently moving in
   bool m_UpPressed;
   bool m_DownPressed;
   bool m_LeftPressed;
   bool m_RightPressed;

   // How much health does player currently have
   int m_Health;

   // Maximum health player can have
   int m_MaxHealth;

   // When was player last hit
   sf::Time m_LastHit;

   // Speed in pixels per second

   float m_Speed;
};
