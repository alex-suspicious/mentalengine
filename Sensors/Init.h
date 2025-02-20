namespace sensors{
	void enableAccelerometer(){
		//sf::Sensor::setEnabled(sf::Sensor::Accelerometer, true);
	}

	void enableGyroscope(){
		//sf::Sensor::setEnabled(sf::Sensor::Gyroscope, true);
	}

	void enableAcceleration(){
		//sf::Sensor::setEnabled(sf::Sensor::UserAcceleration, true);
	}

	void enableOrientation(){
		//sf::Sensor::setEnabled(sf::Sensor::Orientation, true);
	}

	void enableGravity(){
		//sf::Sensor::setEnabled(sf::Sensor::Gravity, true);
	}

	void disableAccelerometer(){
		//sf::Sensor::setEnabled(sf::Sensor::Accelerometer, false);
	}

	void disableGyroscope(){
		//sf::Sensor::setEnabled(sf::Sensor::Gyroscope, false);
	}

	void disableAcceleration(){
		//sf::Sensor::setEnabled(sf::Sensor::UserAcceleration, false);
	}

	void disableOrientation(){
		//sf::Sensor::setEnabled(sf::Sensor::Orientation, false);
	}

	void disableGravity(){
		//sf::Sensor::setEnabled(sf::Sensor::Gravity, false);
	}

	amath::Vector3 getAccelerometer(){
		//return amath::Vector3( sf::Sensor::getValue( sf::Sensor::Accelerometer ) );
	}

	amath::Vector3 getGyroscope(){
		//return amath::Vector3( sf::Sensor::getValue( sf::Sensor::Gyroscope ) );
	}

	amath::Vector3 getAcceleration(){
		//return amath::Vector3( sf::Sensor::getValue( sf::Sensor::UserAcceleration ) );
	}

	amath::Vector3 getOrientation(){
		//return amath::Vector3( sf::Sensor::getValue( sf::Sensor::Orientation ) );
	}

	amath::Vector3 getGravity(){
		//return amath::Vector3( sf::Sensor::getValue( sf::Sensor::Gravity ) );
	}
}