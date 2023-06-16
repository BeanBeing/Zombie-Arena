#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "../headers/Player.hpp"
#include "../headers/ZombieArena.hpp"


int main()
{

   // Game will always be in one of four states
   enum class State{ PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

   // Start iwth the GAME_OVER state
   State state = State::GAME_OVER;

   // Get screen resolution and create SFML Window
   sf::Vector2f resolution;
   resolution.x = sf::VideoMode::getDesktopMode().width;
   resolution.y = sf::VideoMode::getDesktopMode().height;

   sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Zombie Arena", sf::Style::Default);

   // Create an SFML View for the main action
   sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

   // Clock for timing everything
   sf::Clock clock;

   // How long has PLAYING state been active
   sf::Time gameTimeTotal;

   // Locate mouse in relation to world coordinates
   sf::Vector2f mouseWorldPosition;

   // Locate mouse in relation to screen coordinates
   sf::Vector2i mouseScreenPosition;

   // Create instance of Player class
   Player player;

   // Boundary of the arena
   sf::IntRect arena;

   // Create the background
   sf::VertexArray background;
   // Load texture for background vertex array
   sf::Texture textureBackGround;
   textureBackGround.loadFromFile("graphics/background_sheet.png");

   // Limit the framerate
   window.setFramerateLimit(60);
   
   // Event
   sf::Event event;

   /**GAME LOOP**/
   // Main Game Loop
   while (window.isOpen())
   {
      /**EVENTS**/
      // Start Event Polling
      while(window.pollEvent(event))
      {
         if(event.type == sf::Event::Closed)
         {
            window.close();
         }
         if(event.type == sf::Event::KeyPressed)
         {
            // Pause game while PLAYING state
            if(event.key.code == sf::Keyboard::Return && state == State::PLAYING)
            {
               state = State::PAUSED;
            }
            
            // Set PAUSED state to PLAYING state
            else if(event.key.code == sf::Keyboard::Return && state == State::PAUSED)
            {
               state = State::PLAYING;
               // Reset the clock so there isn't a frame jump
               clock.restart();
            }

            // Start a new game while in GAME_OVER state
            else if(event.key.code == sf::Keyboard::Return && state == State::GAME_OVER)
            {
               state = State::LEVELING_UP;
            }

            if(state == State::PLAYING)
            {
               
            }
         }
      }/**End of Event Polling**/

      /**INPUTS**/
      // Handle player quitting
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
         window.close();
      }

      // Handle WASD while playing
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
         player.moveUp();
      }else{
         player.stopUp();
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
         player.moveDown();
      }else{
         player.stopDown();
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      {
         player.moveLeft();
      }else{
         player.stopLeft();
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
         player.moveRight();
      }else{
         player.stopRight();
      }

      /**HANDLE LEVELING_UP state**/
      if(state == State::LEVELING_UP)
      {
         // Handle the player LEVELING_UP
         if(event.key.code == sf::Keyboard::Num1)
         {
            state = State::PLAYING;
         }

         if(event.key.code == sf::Keyboard::Num2)
         {
            state = State::PLAYING;
         }

         if(event.key.code == sf::Keyboard::Num3)
         {
            state = State::PLAYING;
         }

         if(event.key.code == sf::Keyboard::Num4)
         {
            state = State::PLAYING;
         }

         if(event.key.code == sf::Keyboard::Num5)
         {
            state = State::PLAYING;
         }

         if(event.key.code == sf::Keyboard::Num6)
         {
            state = State::PLAYING;
         }

         if(state == State::PLAYING)
         {
            // Prepare the level
            arena.width = 500;
            arena.height = 500;
            arena.left = 0;
            arena.top = 0;

            // Pass vertex array by reference to createBackground function

            int tileSize = createBackGround(background, arena);

            // Spawn the player in the middle of the arena
            player.spawn(arena, resolution, tileSize);

            // Reset the clock so there isn't a frame jump
            clock.restart();
         }
      }/**END OF LEVELING_UP**/

      /**UPDATE THE FRAME**/
      if(state == State::PLAYING)
      {
         // Update the delta time
         sf::Time dt = clock.restart();

         // Update the total game time
         gameTimeTotal += dt;

         // Make a decimal fraction of 1 from the delta time
         float dtAsSeconds = dt.asSeconds();

         // Locate mouse pointer
         mouseScreenPosition = sf::Mouse::getPosition();

         // Convert mouse position to world coordinates of mainView
         mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), mainView);

         // Update the player
         player.update(dtAsSeconds, sf::Mouse::getPosition());

         // Make a note of the players new position
         sf::Vector2f playerPosition(player.getCenter());

         // Make the view center around the player
         mainView.setCenter(player.getCenter());
      }/**END UPDATING THE SCENE**/

      /**DRAW THE SCENE**/
      
      if(state == State::PLAYING)
      {
         window.clear();
         
         // Set mainView to be displayed in window and draw everything to that view
         window.setView(mainView);

         // Draw background
         window.draw(background, &textureBackGround);
         // Draw player
         window.draw(player.getSprite());
      }
      if(state == State::LEVELING_UP)
      {
      }

      if(state == State::PAUSED)
      {
      }

      if(state == State::GAME_OVER)
      {
      }
      
      window.display();
      
   } /**Game of Game loop**/

   return 0;
}
