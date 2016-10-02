/*
Bachelor of Software Engineering
Media Design School
Auckland
NewZealand

(c) 2005 - 2016 Media Design School

File Name	:
Description	:
Authors		:	Tyrone Mills, Gabriel Mugadza, Mun Hou Yong, Dylan Ridgeway
mail		:	tyrone.mill6438@mediadesign.school.nz
*/


#ifndef QUERYCALLBACK_H
#define QUERYCALLBACK_H

#include "include\Box2D\Box2D.h"

class QueryCallback : public b2QueryCallback
{
public:
	QueryCallback(const b2Vec2& point);
	~QueryCallback();
	b2Vec2 m_point;
	b2Fixture* m_fixture;
	bool ReportFixture(b2Fixture* fixture);
};

#endif