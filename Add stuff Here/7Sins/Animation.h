#ifndef ANIMATION_H
#define ANIMATION_H
#pragma once

#include "Utils.h"
class Animation
{
private:

	int 	m_currentFrame;
	int		m_frameInc;
	int		m_frameRate;
	sf::Clock	clock;
	sf::Sprite *m_sprite;

public:
	Animation();
	~Animation();
	void	Animate();
	void 	SetFrameRate(int Rate);
	void 	SetCurrentFrame(int Frame);
	int 	GetCurrentFrame();
	int		m_maxFrames;
	void DrawSprite(sf::RenderWindow &Window);
	void SetAnim(int StartFrame, int TotalFrames);
	void DrawSpriteAnim(sf::RenderWindow &Window, int x, int y, int w, int h);
	sf::Sprite *GetSprite();
	void setSprite(sf::Sprite *sprite);
};

#endif