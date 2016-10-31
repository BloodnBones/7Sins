#include "Animation.h"


/*
* @brief	:
* @param	:
* @return	:
*/
Animation::Animation()
{
	m_currentFrame = 0;
	m_maxFrames = 0;
	m_frameInc = 1;
	m_frameRate = 150; //Milliseconds
}

/*
* @brief	:
* @param	:
* @return	:
*/
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

/*
* @brief	:
* @param	:
* @return	:
*/
void Animation::SetFrameRate(int Rate)
{
	m_frameRate = Rate;
}

/*
* @brief	:
* @param	:
* @return	:
*/
void Animation::SetCurrentFrame(int Frame)
{
	if (Frame < 0 || Frame >= m_maxFrames) return;
	m_currentFrame = Frame;
}

/*
* @brief	:
* @param	:
* @return	:
*/
int Animation::GetCurrentFrame()
{
	return m_currentFrame;
}

/*
* @brief	:
* @param	:
* @return	:
*/
void Animation::DrawSprite(sf::RenderWindow & Window)
{
	Window.draw(*m_sprite);
}

/*
* @brief	:
* @param	:
* @return	:
*/
void Animation::SetAnim(int StartFrame, int TotalFrames)
{
	SetCurrentFrame(StartFrame);
	Animation::m_maxFrames = TotalFrames;
}

/*
* @brief	:
* @param	:
* @return	:
*/
void Animation::DrawSpriteAnim(sf::RenderWindow & Window, int x, int y, int w, int h)
{
	m_sprite->setTextureRect(sf::IntRect(x*w, y*h, w, h));
	Window.draw(*m_sprite);
}

/*
* @brief	:
* @param	:
* @return	:
*/
sf::Sprite * Animation::GetSprite()
{
	return m_sprite;
}

/*
* @brief	:
* @param	:
* @return	:
*/
void Animation::setSprite(sf::Sprite * sprite)
{
	m_sprite = sprite;
}

/*
* @brief	:
* @param	:
* @return	:
*/
Animation::~Animation()
{
}
