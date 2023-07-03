#include "../headers/ZombieArena.hpp"
#include <cstdlib>

int createBackGround(sf::VertexArray &vertexArray, sf::IntRect arena)
{
   // How big is each tile/texture
   /**The spritecheet is 50x200. Each square is 50 and theres four different ones so 50 x 4 = 200**/
   const int TILE_SIZE     { 50 };   // Each TILES in spritesheet are this big 0 - 50 pixels, each different tile.
   const int TILE_TYPES    { 3 };    // Theres four types of each different looking tile
   const int VERTS_IN_QUAD { 4 };    // its a square and SFML quads work well with rectangles

   // Let the function know precisely the size of the enlarging arena
   int worldWidth  { arena.width / TILE_SIZE };
   int worldHeight { arena.height / TILE_SIZE };

   // SFML quads work well with rectangular spritesheets
   vertexArray.setPrimitiveType(sf::Quads);

   // Size of Vertex Array
   // Multiply the width * height * Vertices in a quad(quad obviously means four)
   // vertexArray will change itself to constantly match the map dimensions
   // Having const VERTS_IN_QUAD provides less errors and confusion than just having '4'
   vertexArray.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

   // Start at the beginning of the vertexArray
   int currentVertex { 0 };

   for(int w{ 0 }; w < worldWidth; w++)
   {
      for(int h{ 0 }; h < worldHeight; h++)
      {
         // Position each vertex in the curent quad
         // (0 * TILE_SIZE, 0 * TILE_SIZE)
         vertexArray[currentVertex + 0].position =
            sf::Vector2f(w * TILE_SIZE, h * TILE_SIZE);

         // (w * TILE_SIZE, 0 * TILE_SIZE)
         vertexArray[currentVertex + 1].position =
            sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

         // (w * TILE_SIZE, h * TILE_SIZE)
         vertexArray[currentVertex + 2].position =
            sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

         // Practically gets the 4th TILE
         vertexArray[currentVertex + 3].position =
            sf::Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

         // Define the position in the texture for current quad
         // Either grass, stone, bush, or wall
         if(h == 0 || h == worldHeight - 1 ||
            w == 0 || w == worldWidth  - 1)
         {
            // Use the wall texture
            vertexArray[currentVertex + 0].texCoords =
               sf::Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

            vertexArray[currentVertex + 1].texCoords =
               sf::Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);

            vertexArray[currentVertex + 2].texCoords =
               sf::Vector2f(TILE_SIZE, TILE_SIZE + (TILE_TYPES * TILE_SIZE));

            vertexArray[currentVertex + 3].texCoords =
               sf::Vector2f(0, TILE_SIZE + (TILE_TYPES * TILE_SIZE));
         }else{
            // USe a random floor texture
            std::srand(static_cast<int>(time(0)) + (h * w) - h);
            int mudOrGrass{ (std::rand() % TILE_TYPES) }; // Modulus prevents it being 3
            int verticalOffset = mudOrGrass * TILE_SIZE;

            vertexArray[currentVertex + 0].texCoords =
               sf::Vector2f(0, 0 + verticalOffset);
            
            vertexArray[currentVertex + 1].texCoords =
               sf::Vector2f(TILE_SIZE, 0 + verticalOffset);

            vertexArray[currentVertex + 2].texCoords =
               sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

            vertexArray[currentVertex + 3].texCoords =
               sf::Vector2f(0, TILE_SIZE + verticalOffset);
            
         }

         // Position ready for the next for vertices
         currentVertex += VERTS_IN_QUAD;
      }
   }

   return TILE_SIZE;
}
