#pragma once
class basescene
{
public:
	virtual void Init()=0;
	virtual int Update() = 0;
	virtual void Draw() = 0;
};

