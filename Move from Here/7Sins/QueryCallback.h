#ifndef QUERYCALLBACK_H
#define QUERYCALLBACK_H

#include "Dependencies\Include\Box2D\Box2D.h"

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