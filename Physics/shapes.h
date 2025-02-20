namespace body{
	void* removing = nullptr;
	std::vector<std::vector<amath::Vector2>> traces;

	b2PolygonShape box(amath::Vector2 size){
		b2PolygonShape shape;
		shape.SetAsBox(size.x/physics::worldSize, size.y/physics::worldSize);
		return shape;
	}

	b2CircleShape circle(float radius){
		//b2PolygonShape shape;
		//shape.SetAsBox(size.x/physics::worldSize, size.y/physics::worldSize);

		b2CircleShape shape;
		shape.m_radius = radius/physics::worldSize;
		return shape;
	}

	b2PolygonShape convex(luabridge::LuaRef coords){
		b2PolygonShape shape;

		b2Vec2 vertices[coords.length()];
		for (int i = 1; i <= coords.length(); i++)
		{
			amath::Vector2 tempCoords = coords[i].cast<amath::Vector2>().valueOr(amath::Vector2(0,0));
			vertices[i-1].Set( tempCoords.x/physics::worldSize, tempCoords.y/physics::worldSize);
		}


		shape.Set(vertices, coords.length());
		return shape;
	}

	class rigidbody
	{
		static int count;
	public:
		b2Body* body;
		int ID = 0;
		luaClasses::FlexibleClass* owner;
		std::vector<rigidbody*> collided;
		bool ownerSet = false;
		bool removing = false;
		bool touching = false;
		std::vector<rigidbody*> filtered;
		std::string hitSound = "fall.wav";


		rigidbody(b2CircleShape shape){
			this->ID = rand() % 999999;
			b2BodyDef newBodyDef;
			
			newBodyDef.type = b2_dynamicBody;
			this->body = physics::world->CreateBody(&newBodyDef);


			b2FixtureDef fixtureDef;
			fixtureDef.shape = &shape;
			fixtureDef.density = 2.0f;
			fixtureDef.restitution = 0.5f;
			fixtureDef.friction = 0.3f;

			this->body->CreateFixture(&fixtureDef);
			this->body->GetUserData().pointer = (uintptr_t)this;
			

			physics::bodies.push_back( this->body );
		};
		
		rigidbody(b2PolygonShape shape){
			this->ID = rand() % 999999;
			b2BodyDef newBodyDef;
			
			newBodyDef.type = b2_dynamicBody;
			this->body = physics::world->CreateBody(&newBodyDef);


			b2FixtureDef fixtureDef;
			fixtureDef.shape = &shape;
			fixtureDef.density = 2.0f;
			fixtureDef.restitution = 0.5f;
			fixtureDef.friction = 0.3f;

			this->body->CreateFixture(&fixtureDef);
			this->body->GetUserData().pointer = (uintptr_t)this;
			

			physics::bodies.push_back( this->body );
		};

		rigidbody(b2ChainShape* shape){
			this->ID = rand() % 999999;
			b2BodyDef newBodyDef;
			
			newBodyDef.type = b2_dynamicBody;
			this->body = physics::world->CreateBody(&newBodyDef);


			b2FixtureDef fixtureDef;
			fixtureDef.shape = shape;
			fixtureDef.density = 2.0f;
			fixtureDef.restitution = 0.0f;
			fixtureDef.friction = 0.3f;

			this->body->CreateFixture(&fixtureDef);
			this->body->GetUserData().pointer = (uintptr_t)this;

			physics::bodies.push_back( this->body );
		};


		~rigidbody(){
//			for (int i = 0; i < this->collided.size(); i++)
//			{
//				for (int e = 0; e < this->collided[i]->collided.size(); e++)
//				{
//					this->collided[i]->collided[e]->endContact( this->collided[i] );
//				}
//			}

			for (int i = 0; i < this->collided.size(); i++)
			{
				if( this != this->collided[i] && this->collided[i] != nullptr ){
					this->collided[i]->endContact( this );
//					//this->endContact( collided[i] );
//					//this->collided[i] = nullptr;
//					//this->collided.erase(this->collided.begin() + i);
//					//this->endContact( collided[i] );
				}
			}

//			for (int i = 0; i < this->collided.size(); i++)
//			{
//				this->collided[i] = nullptr;
//			}

			this->body->GetUserData().pointer = removing;
			//this->owner = 0;
			this->collided.clear();
			this->filtered.clear();
//			this->ownerSet = false;
			
//            for (int i = 0; i < physics::bodies.size(); i++)
//            {
//                if( physics::bodies[i] == this->body ){
//                    physics::bodies.erase(physics::bodies.begin() + i);
//                    break;
//                }
//            }
//            physics::world->DestroyBody(this->body);
		};

		void addFilter( rigidbody* rb ){
			this->filtered.push_back(rb);
		}

		void hookContact(){
            for (int e = 0; e < this->owner->hooks["collide"].size(); e++)
            {
                auto physics = luaClasses::allHooks.find(this->owner->hooks["collide"][e]);

                if (physics == luaClasses::allHooks.end())
                    continue;

                //thread::run_lua([&, this](){
				for (int i = 0; i < this->collided.size(); i++)
				{

//					lua_State* L_thread = lua_newthread(luaInit::luaState);
//					physics->second.push(L_thread);
//
//				    //luabridge::Stack<luabridge::LuaRef>::push(L_thread, this->owner);
//				    luabridge::push(L_thread, &this->owner);
//				    luabridge::push(L_thread, &this->collided[i]->owner);
				    //
//				    int nresults = 0;
//					if (lua_resume(L_thread, nullptr, 2, &nresults) != LUA_OK) {
//						// Handle errors if lua_resume fails
//						const char* errorMessage = lua_tostring(L_thread, -1);
//						std::cerr << "Error: " << errorMessage << std::endl;
//					}

                    physics->second(this->owner, this->collided[i]->owner);
                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
				}
                //});
            }
		}

		bool isTouching(){
			return this->touching;
		}

		bool isColliding(){
			return this->collided.size();
		}

		int collidersCount(){
			return this->collided.size();
		}

		void startContact( rigidbody* collidedEnt ) {
            auto tent = std::find(this->filtered.begin(), this->filtered.end(), collidedEnt);
            if( tent != this->filtered.end() )
            	return;

//			bool found = false;
//			for (int i = 0; i < this->collided.size(); i++)
//			{
//				if( this->collided[i]->ID == collidedEnt->ID )
//					found = true;
//			}

            //auto ent = std::find(this->collided.begin(), this->collided.end(), collidedEnt);
            //if ( ent == this->collided.end() )

    
			auto ent = find_if(this->collided.begin(), this->collided.end(),
    			[collidedEnt](rigidbody *r) { return r->ID == collidedEnt->ID; });

			//if( ent != this->collided.end() )
			//	this->collided.erase(ent);

            this->collided.push_back(collidedEnt);


			if( !collidedEnt->ownerSet || !this->ownerSet )
				return;

            for (int e = 0; e < this->owner->hooks["collide_start"].size(); e++)
            {
                auto physics = luaClasses::allHooks.find(this->owner->hooks["collide_start"][e]);
                if (physics == luaClasses::allHooks.end())
                    continue;

//				lua_State* L_thread = lua_newthread(luaInit::luaState);
//				physics->second.push(L_thread);
//
//			    //luabridge::Stack<luabridge::LuaRef>::push(L_thread, this->owner);
//			    luabridge::push(L_thread, &this->owner);
//			    luabridge::push(L_thread, &collidedEnt->owner);
			    //
//			    int nresults = 0;
//				if (lua_resume(L_thread, nullptr, 2, &nresults) != LUA_OK) {
//					// Handle errors if lua_resume fails
//					const char* errorMessage = lua_tostring(L_thread, -1);
//					std::cerr << "Error: " << errorMessage << std::endl;
//				}

                //thread::run_lua([&, this](){
                physics->second(this->owner, collidedEnt->owner);
				//lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                //});
            }

		}

		void endContact( rigidbody* collidedEnt ) {
            auto tent = std::find(this->filtered.begin(), this->filtered.end(), collidedEnt);
            if( tent != this->filtered.end() )
            	return;

			//bool found = false;


			//for (int i = 0; i < this->collided.size(); i++)
			//{
			//	if( this->collided[i]->ID == collidedEnt->ID ){
			//		this->collided.erase(this->collided.begin() + i);
					//found = true;
			//	}
			//}

			auto ent = find_if(this->collided.begin(), this->collided.end(),
				[collidedEnt](rigidbody *r) { return r->ID == collidedEnt->ID; });

			if( ent != this->collided.end() )
				this->collided.erase(ent);

			//if( !found )
			//	return;

			if( !collidedEnt->ownerSet || !this->ownerSet )
				return;

            for (int e = 0; e < this->owner->hooks["collide_end"].size(); e++)
            {
                auto physics = luaClasses::allHooks.find(this->owner->hooks["collide_end"][e]);
                if (physics == luaClasses::allHooks.end())
                    continue;


//				lua_State* L_thread = lua_newthread(luaInit::luaState);
//				physics->second.push(L_thread);
//
//			    //luabridge::Stack<luabridge::LuaRef>::push(L_thread, this->owner);
//			    luabridge::push(L_thread, &this->owner);
//			    luabridge::push(L_thread, &collidedEnt->owner);
			    //
//			    int nresults = 0;
//				if (lua_resume(L_thread, nullptr, 2, &nresults) != LUA_OK) {
//					// Handle errors if lua_resume fails
//					const char* errorMessage = lua_tostring(L_thread, -1);
//					std::cerr << "Error: " << errorMessage << std::endl;
//				}

                //thread::run_lua([&, this](){
                physics->second(this->owner, collidedEnt->owner);
                    //lua_gc(luaInit::luaState, LUA_GCCOLLECT, 0);
                //});
            }
		}

		void setOwner( luaClasses::FlexibleClass* newOwner ){
			this->owner = newOwner;
			this->ownerSet = true;
		}

		void setGravityFactor( float value ){
			this->body->SetGravityScale(value);
		}

		void setType( std::string Type ){
			if( Type == "kinematic" )
				this->body->SetType( b2_kinematicBody );
			else if( Type == "dynamic" )
				this->body->SetType( b2_dynamicBody );
			else if( Type == "static" )
				this->body->SetType( b2_staticBody );
		}

		void setSensor( bool flag ){
			if( flag ){
				this->body->SetSleepingAllowed(false);
				this->body->SetAwake(true);
			}
			else
				this->body->SetSleepingAllowed(true);

			for (b2Fixture* fixture = this->body->GetFixtureList(); fixture; fixture = fixture->GetNext()) 
            {
               fixture->SetSensor( flag );
            }
		}

		void setFriction( float amount ){
			for (b2Fixture* fixture = this->body->GetFixtureList(); fixture; fixture = fixture->GetNext()) 
            {
               fixture->SetFriction( amount );
            }
		}

		void setBouncy( float amount ){
			for (b2Fixture* fixture = this->body->GetFixtureList(); fixture; fixture = fixture->GetNext()) 
            {
               fixture->SetRestitution(amount);
            }
		}

		void setFixedRotation( bool flag ){
			this->body->SetFixedRotation( flag );
		}

		bool getFixedRotation(){
			return this->body->IsFixedRotation();
		}

		void setAngularVelocity( float angle ){
			this->body->SetAngularVelocity( angle );
		}

		float getAngularVelocity(){
			return this->body->GetAngularVelocity();
		}

		void applyAngularVelocity( float angle ){
			this->body->ApplyTorque( angle, true );
		}

		void applyVelocity( amath::Vector2 vec ){
			this->body->ApplyForceToCenter( b2Vec2(vec.x/physics::worldSize,vec.y/physics::worldSize), true );
		}

		void setVelocity( amath::Vector2 vec ){
			this->body->SetLinearVelocity( b2Vec2(vec.x/physics::worldSize,vec.y/physics::worldSize) );
		}

		amath::Vector2 getVelocity(){
			auto vel = this->body->GetLinearVelocity();
			return amath::Vector2(vel.x*physics::worldSize,vel.y*physics::worldSize);
		}

		void setPosition( amath::Vector2 pos ){
			this->body->SetTransform( b2Vec2(pos.x/physics::worldSize,pos.y/physics::worldSize) , this->body->GetAngle());
			this->body->SetAwake(true);
		}

		void setRotation( float angle ){
			this->body->SetTransform( this->body->GetPosition() , angle/amath::r2d);
			this->body->SetAwake(true);
		}

		void setLinearDamping( float value ){
			this->body->SetLinearDamping( value );
		}

		void setBullet( bool flag ){
			this->body->SetBullet( flag );
		}

		bool getBullet(){
			return this->body->IsBullet();
		}

		float getLinearDamping(){
			return this->body->GetLinearDamping();
		}

		void setAngularDamping( float value ){
			this->body->SetAngularDamping( value );
		}

		float getAngularDamping(){
			return this->body->GetAngularDamping();
		}

		amath::Vector2 getPosition(){
			b2Vec2 position = this->body->GetPosition();
			return amath::Vector2(position.x*physics::worldSize,position.y*physics::worldSize);
		}

		float getRotation(){
			return this->body->GetAngle()*amath::r2d;
		}

		void remove(){
			this->body->GetUserData().pointer = removing;
			//this->removing = true;
		}
	};

	class callBackLua : public b2ContactListener {
	public:
	    void BeginContact(b2Contact* contact) override {
	    	auto bodyA = contact->GetFixtureA();
	    	auto bodyB = contact->GetFixtureB();

        	if( bodyA->IsSensor() && bodyB->IsSensor() )
    			return;

	        void* bodyUserDataA = reinterpret_cast<void*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	        void* bodyUserDataB = reinterpret_cast<void*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	        if (bodyUserDataA && bodyUserDataB ) {
	            auto* rbA = static_cast<rigidbody*>(bodyUserDataA);
	            auto* rbB = static_cast<rigidbody*>(bodyUserDataB);

	            rbA->startContact(rbB);
	            rbB->startContact(rbA);
	        }
	    }

	    void EndContact(b2Contact* contact) override {
	    	auto bodyA = contact->GetFixtureA();
	    	auto bodyB = contact->GetFixtureB();

        	if( bodyA->IsSensor() && bodyB->IsSensor() )
    			return;

	        void* bodyUserDataA = reinterpret_cast<void*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	        void* bodyUserDataB = reinterpret_cast<void*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	        if (bodyUserDataA && bodyUserDataB ) {
	            auto* rbA = static_cast<rigidbody*>(bodyUserDataA);
	            auto* rbB = static_cast<rigidbody*>(bodyUserDataB);

	            rbA->endContact(rbB);
	            rbB->endContact(rbA);
	        }
	    }
	};


	callBackLua LuaCallbacker;

	void init(){
		physics::world->SetContactListener(&LuaCallbacker);
	}

	class rayOutput: public b2RayCastCallback{
	public:
		amath::Vector2 normal;
		amath::Vector2 point;
		float distance;
		bool hit;
		b2Fixture* filterFixture;

		rayOutput(){
		};

		rayOutput(amath::Vector2 normal, amath::Vector2 point, float distance){
			this->normal = normal;
			this->distance = distance;
			this->point = point;
		};

	    float ReportFixture(b2Fixture* fixture, const b2Vec2& point,
	                          const b2Vec2& normal, float fraction) override {
			this->normal = amath::Vector2(normal.x,normal.y);
			//this->distance = fraction*physics::worldSize;
			this->point = amath::Vector2(point.x*physics::worldSize,point.y*physics::worldSize);

			if( this->filterFixture == fixture )
				return -1.0f;

	        if (fixture->IsSensor())
	            return -1.0f;

	        return fraction;
	    }
	};	


	rayOutput trace( amath::Vector2 posA, amath::Vector2 posB){
		b2Vec2 intersectionNormal(0,0);
		rayOutput callback;
		physics::world->RayCast(&callback, b2Vec2(posA.x/physics::worldSize,posA.y/physics::worldSize), b2Vec2(posB.x/physics::worldSize,posB.y/physics::worldSize));

		callback.distance = callback.point.distance(posA);

		if( callback.distance >= posA.distance(posB) )
			traces.push_back({posA,posB});
		else
			traces.push_back({posA,callback.point});

		return callback;
	}

	rayOutput trace( amath::Vector2 posA, amath::Vector2 posB, rigidbody* filterBody){
		b2Vec2 intersectionNormal(0,0);
		rayOutput callback = rayOutput();

		for (b2Fixture* fixture = filterBody->body->GetFixtureList(); fixture; fixture = fixture->GetNext()){
			callback.filterFixture = fixture;
		}

		physics::world->RayCast(&callback, b2Vec2(posA.x/physics::worldSize,posA.y/physics::worldSize), b2Vec2(posB.x/physics::worldSize,posB.y/physics::worldSize));
		callback.distance = callback.point.distance(posA);

		if( callback.distance >= posA.distance(posB) )
			traces.push_back({posA,posB});
		else
			traces.push_back({posA,callback.point});

		return callback;
	}
//
//	rayOutput trace( amath::Vector2 pos, amath::Vector2 normal){
		//
//	}
}