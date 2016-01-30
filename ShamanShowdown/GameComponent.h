#pragma once
class GameComponent
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
};

/*
COMPONENT IDS
-------------
0	Transform
1	Render
2	Physics
3	Input
4	Health
5	Inventory
6	
7
8
9
10
11
12
13
14
15
16
17
18
19

*/