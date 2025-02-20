namespace physics{
	float timeStep = 1.0f / 55.0f;
	float speed = 1.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	float worldSize = 30.0f;
	float vectorSize = 20.0f;


	b2World* world;
	b2Vec2 gravity(0.0f, 15.0f);

	std::vector<b2Body*> bodies;

	void init(){
		physics::world = new b2World( physics::gravity );
	}
}