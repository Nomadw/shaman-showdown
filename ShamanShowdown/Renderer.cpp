#include "Renderer.h"
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "Texture.h"
#include <fstream>
using namespace std;

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
	glBindTexture(GL_TEXTURE_2D, textures[textureID]->ID);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glVertexPointer(2, GL_FLOAT, 4 * sizeof(float), verticies);
	glTexCoordPointer(2, GL_FLOAT, 4 * sizeof(float), verticies + 2);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indicies);
	
	glPopMatrix();
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
}

int Renderer::loadTexture(char * fileName, char * name)
{
	char * data;
	ifstream file; 
	file.open(fileName, fstream::in | fstream::binary);
	file.seekg(0, std::ios::end);
	int size = file.tellg();
	data = new char[size];
	file.seekg(0, std::ios::beg);
	file.read(data, size);
	short int width = *(short int*)(data + 12);
	short int height = *(short int*)(data + 14);
	Texture * texture = new Texture();
	char * colourData = data + 18;
	for (int i = 0; i < width * height; i++)
	{
		char temp = colourData[i * 4];
		colourData[i * 4] = colourData[(i * 4) + 2];
		colourData[(i * 4) + 2] = temp;
	}
	glGenTextures(1, &(texture->ID));
	glBindTexture(GL_TEXTURE_2D, texture->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, colourData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	textures.push_back(texture);
	glBindTexture(GL_TEXTURE_2D,0);
	return texture->ID;
}
