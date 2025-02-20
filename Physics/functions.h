namespace physics{
	void setGravity( amath::Vector2 dir ){
		physics::world->SetGravity(b2Vec2(dir.x, dir.y));
	}

	void setSpeed( float speed ){
		physics::speed = speed;
	}
}