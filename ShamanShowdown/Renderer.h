#pragma once
#include <vector>

class Texture;

using namespace std;

enum RENDER_PASS { RENDER_PASS_GROUND, RENDER_PASS_OBJECT, RENDER_PASS_ITEM, RENDER_PASS_CHARACTER, RENDER_PASS_ABOVE, RENDER_PASS_UI };

class Renderer
{
public:
	Renderer();
	~Renderer();
	void createQuad();
	void draw(int textureID, float x, float y, float size);
	void draw(int textureID, float x, float y, float sizex, float sizey);
	int loadTexture(char * fileName, char * name);
	vector<Texture *> textures;
	
	int getTexture(char * name);
	RENDER_PASS currentPass;
private:
	float * verticies;
	unsigned int * indicies;

};

