#ifndef __OS__GUI__RAYCASTING_H
#define __OS__GUI__RAYCASTING_H


#include <common/types.h>
#include <drivers/vga.h>
#include <gui/widget.h>
#include <math.h>


namespace os {

	namespace gui {

		class RaycastSpace {
	
			public:
				const double w = 320.0;
				const double h = 200.0;
				int texW = 64.0;
				int texH = 64.0;
			
				//common::uint8_t textures[8][texW*texH];
				common::uint8_t textures[8][64*64];



				common::uint8_t worldMap[24][24];
				common::uint16_t spaceW = 24;
				common::uint16_t spaceH = 24;
		
				double posX = 22.0;
				double posY = 11.5;
				double dirX = -1.0;
				double dirY = 0.0;
				double planeX = 0.0;
				double planeY = 0.66;


				bool keyDown = false;
				bool mouseDown = false;
			public:
				RaycastSpace();
				~RaycastSpace();

				void ComputeSpace(common::GraphicsContext* gc, char keylog[16], common::uint8_t logIndex, 
						common::int32_t mouseX);
		};

		//int worldMap[mapWidth][mapHeight]=
		static int spaceMap[24][24] = {
		  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,1,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1},
		  {1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1},
		  {1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,1},
		  {1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,1},
		  {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,1},
		  {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};
	}
}

#endif
