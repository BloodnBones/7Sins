#include "QueryCallback.h"

/*
* @brief
* @param
* @return
*/
QueryCallback::QueryCallback(const b2Vec2& point)
{
	m_point = point;
	m_fixture = NULL;
}

/*
* @brief
* @param
* @return
*/
QueryCallback::~QueryCallback()
{
}

/*
* @brief
* @param
* @return
*/
bool QueryCallback::ReportFixture(b2Fixture* fixture)
{
	b2Body* body = fixture->GetBody();
	if (body->GetType() == b2_dynamicBody)
	{
		bool inside = fixture->TestPoint(m_point);
		if (inside)
		{
			m_fixture = fixture;

			// We are done, terminate the query.
			return false;
		}
	}

	// Continue the query.
	return true;
}