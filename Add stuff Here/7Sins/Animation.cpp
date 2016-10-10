#include "Animation.h"



Animation::Animation()
{
	m_currentFrame = 0;
	m_maxFrames = 0;
	m_frameInc = 1;
	m_frameRate = 150; //Milliseconds
}

void Animation::Animate()
{
	sf::Time elapsed = clock.getElapsedTime();

	if (elapsed.asMilliseconds() >= m_frameRate) {
		m_currentFrame += m_frameInc;

		if (m_frameInc > 0) {
			if (m_currentFrame >= m_maxFrames) {
				m_currentFrame = m_frameInc;
			}
		}

		clock.restart();
	}
}

void Animation::SetFrameRate(int Rate)
{
	m_frameRate = Rate;
}

void Animation::SetCurrentFrame(int Frame)
{
	if (Frame < 0 || Frame >= m_maxFrames) return;
	m_currentFrame = Frame;
}

int Animation::GetCurrentFrame()
{
	return m_currentFrame;
}

void Animation::DrawSprite(sf::RenderWindow & Window)
{
	Window.draw(*m_sprite);
}

void Animation::SetAnim(int StartFrame, int TotalFrames)
{
	SetCurrentFrame(StartFrame);
	Animation::m_maxFrames = TotalFrames;
}

void Animation::DrawSpriteAnim(sf::RenderWindow & Window, int x, int y, int w, int h)
{
	m_sprite->setTextureRect(sf::IntRect(x*w, y*h, w, h));
	Window.draw(*m_sprite);
}

sf::Sprite * Animation::GetSprite()
{
	return m_sprite;
}

void Animation::setSprite(sf::Sprite * sprite)
{
	m_sprite = sprite;
}


Animation::~Animation()
{
}
