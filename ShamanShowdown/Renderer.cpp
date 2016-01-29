#include "Renderer.h"
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

// include the opengl and glu libraries
#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glu32.lib")

Renderer::Renderer()
{
	createQuad();
}


Renderer::~Renderer()
{
}

void Renderer::createQuad()
{
	verticies = new float[4*4];
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			verticies[(((x * 2) + y) * 4) + 0] = x - 0.5f;
			verticies[(((x * 2) + y) * 4) + 1] = y - 0.5f;
			verticies[(((x * 2) + y) * 4) + 2] = x;
			verticies[(((x * 2) + y) * 4) + 3] = y;
		}
	}
	indicies = new unsigned int[6];
	indicies[0] = 0;
	indicies[1] = 1;
	indicies[2] = 2;
	indicies[3] = 3;
	indicies[4] = 2;
	indicies[5] = 1;
}

void Renderer::draw(int textureID, float x, float y)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 4 * sizeof(float), verticies);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indicies);
	
	glPopMatrix();
	
	glDisableClientState(GL_VERTEX_ARRAY);

}
