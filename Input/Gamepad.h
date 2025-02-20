namespace Input{
	namespace axis{
		amath::Vector2 leftStick;
		amath::Vector2 rightStick;
		int gamepad = 0;

		void process(){
			if (!IsGamepadAvailable(gamepad))
				return;

            float leftStickX = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X);
            float leftStickY = GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y);

            if( abs( leftStickX ) > 0.01 )
            	leftStick.x = leftStickX;
            
            if( abs( leftStickY ) > 0.01 )
            	leftStick.y = leftStickY;
		}
	}
}