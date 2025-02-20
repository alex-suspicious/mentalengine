namespace Input{
	namespace keyboard{
		std::vector<KeyboardKey> downKeys;
		bool computer = true;
		bool anyPressed = false;
		amath::Vector2 virtualStick(0,0);
//
		bool KeyReleaseRegister( KeyboardKey key ){
			computer = true;
			auto index = std::find(downKeys.begin(), downKeys.end(), key);
			if( index != downKeys.end()) {
				downKeys.erase(index);
				return true;
			}
			return false;
		}
//
		bool KeyDownRegister( KeyboardKey key ){
			computer = true;
			auto index = std::find(downKeys.begin(), downKeys.end(), key);
			if( index == downKeys.end()) {
				downKeys.push_back( key );
				return true;
			}
			return false;
		}

		bool isDown( KeyboardKey key ){
			auto index = std::find(downKeys.begin(), downKeys.end(), key);
			return index != downKeys.end();
		}

//		sf::Keyboard::Key getKeyNameBackward(const std::string& keyName) {
//			if (keyName == "Unknown") return sf::Keyboard::Unknown;
//			else if (keyName == "A") return sf::Keyboard::A;
//			else if (keyName == "B") return sf::Keyboard::B;
//			else if (keyName == "C") return sf::Keyboard::C;
//			else if (keyName == "D") return sf::Keyboard::D;
//			else if (keyName == "E") return sf::Keyboard::E;
//			else if (keyName == "F") return sf::Keyboard::F;
//			else if (keyName == "G") return sf::Keyboard::G;
//			else if (keyName == "H") return sf::Keyboard::H;
//			else if (keyName == "I") return sf::Keyboard::I;
//			else if (keyName == "J") return sf::Keyboard::J;
//			else if (keyName == "K") return sf::Keyboard::K;
//			else if (keyName == "L") return sf::Keyboard::L;
//			else if (keyName == "M") return sf::Keyboard::M;
//			else if (keyName == "N") return sf::Keyboard::N;
//			else if (keyName == "O") return sf::Keyboard::O;
//			else if (keyName == "P") return sf::Keyboard::P;
//			else if (keyName == "Q") return sf::Keyboard::Q;
//			else if (keyName == "R") return sf::Keyboard::R;
//			else if (keyName == "S") return sf::Keyboard::S;
//			else if (keyName == "T") return sf::Keyboard::T;
//			else if (keyName == "U") return sf::Keyboard::U;
//			else if (keyName == "V") return sf::Keyboard::V;
//			else if (keyName == "W") return sf::Keyboard::W;
//			else if (keyName == "X") return sf::Keyboard::X;
//			else if (keyName == "Y") return sf::Keyboard::Y;
//			else if (keyName == "Z") return sf::Keyboard::Z;
//			else if (keyName == "Num0") return sf::Keyboard::Num0;
//			else if (keyName == "Num1") return sf::Keyboard::Num1;
//			else if (keyName == "Num2") return sf::Keyboard::Num2;
//			else if (keyName == "Num3") return sf::Keyboard::Num3;
//			else if (keyName == "Num4") return sf::Keyboard::Num4;
//			else if (keyName == "Num5") return sf::Keyboard::Num5;
//			else if (keyName == "Num6") return sf::Keyboard::Num6;
//			else if (keyName == "Num7") return sf::Keyboard::Num7;
//			else if (keyName == "Num8") return sf::Keyboard::Num8;
//			else if (keyName == "Num9") return sf::Keyboard::Num9;
//			else if (keyName == "Escape") return sf::Keyboard::Escape;
//			else if (keyName == "LControl") return sf::Keyboard::LControl;
//			else if (keyName == "LShift") return sf::Keyboard::LShift;
//			else if (keyName == "LAlt") return sf::Keyboard::LAlt;
//			else if (keyName == "LSystem") return sf::Keyboard::LSystem;
//			else if (keyName == "RControl") return sf::Keyboard::RControl;
//			else if (keyName == "RShift") return sf::Keyboard::RShift;
//			else if (keyName == "RAlt") return sf::Keyboard::RAlt;
//			else if (keyName == "RSystem") return sf::Keyboard::RSystem;
//			else if (keyName == "Menu") return sf::Keyboard::Menu;
//			else if (keyName == "LBracket") return sf::Keyboard::LBracket;
//			else if (keyName == "RBracket") return sf::Keyboard::RBracket;
//			else if (keyName == "SemiColon") return sf::Keyboard::SemiColon;
//			else if (keyName == "Comma") return sf::Keyboard::Comma;
//			else if (keyName == "Period") return sf::Keyboard::Period;
//			else if (keyName == "Quote") return sf::Keyboard::Quote;
//			else if (keyName == "Slash") return sf::Keyboard::Slash;
//			else if (keyName == "BackSlash") return sf::Keyboard::BackSlash;
//			else if (keyName == "Tilde") return sf::Keyboard::Tilde;
//			else if (keyName == "Equal") return sf::Keyboard::Equal;
//			else if (keyName == "Dash") return sf::Keyboard::Dash;
//			else if (keyName == "Space") return sf::Keyboard::Space;
//			else if (keyName == "Return") return sf::Keyboard::Return;
//			else if (keyName == "BackSpace") return sf::Keyboard::BackSpace;
//			else if (keyName == "Tab") return sf::Keyboard::Tab;
//			else if (keyName == "PageUp") return sf::Keyboard::PageUp;
//			else if (keyName == "PageDown") return sf::Keyboard::PageDown;
//			else if (keyName == "End") return sf::Keyboard::End;
//			else if (keyName == "Home") return sf::Keyboard::Home;
//			else if (keyName == "Insert") return sf::Keyboard::Insert;
//			else if (keyName == "Delete") return sf::Keyboard::Delete;
//			else if (keyName == "Add") return sf::Keyboard::Add;
//			else if (keyName == "Subtract") return sf::Keyboard::Subtract;
//			else if (keyName == "Multiply") return sf::Keyboard::Multiply;
//			else if (keyName == "Divide") return sf::Keyboard::Divide;
//			else if (keyName == "Left") return sf::Keyboard::Left;
//			else if (keyName == "Right") return sf::Keyboard::Right;
//			else if (keyName == "Up") return sf::Keyboard::Up;
//			else if (keyName == "Down") return sf::Keyboard::Down;
//			else if (keyName == "Numpad0") return sf::Keyboard::Numpad0;
//			else if (keyName == "Numpad1") return sf::Keyboard::Numpad1;
//			else if (keyName == "Numpad2") return sf::Keyboard::Numpad2;
//			else if (keyName == "Numpad3") return sf::Keyboard::Numpad3;
//			else if (keyName == "Numpad4") return sf::Keyboard::Numpad4;
//			else if (keyName == "Numpad5") return sf::Keyboard::Numpad5;
//			else if (keyName == "Numpad6") return sf::Keyboard::Numpad6;
//			else if (keyName == "Numpad7") return sf::Keyboard::Numpad7;
//			else if (keyName == "Numpad8") return sf::Keyboard::Numpad8;
//			else if (keyName == "Numpad9") return sf::Keyboard::Numpad9;
//			else if (keyName == "F1") return sf::Keyboard::F1;
//			else if (keyName == "F2") return sf::Keyboard::F2;
//			else if (keyName == "F3") return sf::Keyboard::F3;
//			else if (keyName == "F4") return sf::Keyboard::F4;
//			else if (keyName == "F5") return sf::Keyboard::F5;
//			else if (keyName == "F6") return sf::Keyboard::F6;
//			else if (keyName == "F7") return sf::Keyboard::F7;
//			else if (keyName == "F8") return sf::Keyboard::F8;
//			else if (keyName == "F9") return sf::Keyboard::F9;
//			else if (keyName == "F10") return sf::Keyboard::F10;
//			else if (keyName == "F11") return sf::Keyboard::F11;
//			else if (keyName == "F12") return sf::Keyboard::F12;
//			else if (keyName == "F13") return sf::Keyboard::F13;
//			else if (keyName == "F14") return sf::Keyboard::F14;
//			else if (keyName == "F15") return sf::Keyboard::F15;
//			else if (keyName == "Pause") return sf::Keyboard::Pause;
//			else return sf::Keyboard::Unknown;
//		}

		bool isDownLua( std::string key ){
			//return sf::Keyboard::isKeyPressed( getKeyNameBackward(key) );
		}

		const char *getKeyName( int key ) {

			switch (key) {
				case KEY_APOSTROPHE:
					return ",";
				case KEY_COMMA:
					return "Comma";
				case KEY_MINUS:
					return "Minus";
				case KEY_PERIOD:
					return "Period";
				case KEY_SLASH:
					return "Slash";
				case KEY_ZERO:
					return "0";
				case KEY_ONE:
					return "1";
				case KEY_TWO:
					return "2";
				case KEY_THREE:
					return "3";
				case KEY_FOUR:
					return "4";
				case KEY_FIVE:
					return "5";
				case KEY_SIX:
					return "6";
				case KEY_SEVEN:
					return "7";
				case KEY_EIGHT:
					return "8";
				case KEY_NINE:
					return "9";
				case KEY_SEMICOLON:
					return "SemiColon";
				case KEY_EQUAL:
					return "Equal";
				case KEY_A:
					return "A";
				case KEY_B:
					return "B";
				case KEY_C:
					return "C";
				case KEY_D:
					return "D";
				case KEY_E:
					return "E";
				case KEY_F:
					return "F";
				case KEY_G:
					return "G";
				case KEY_H:
					return "H";
				case KEY_I:
					return "I";
				case KEY_J:
					return "J";
				case KEY_K:
					return "K";
				case KEY_L:
					return "L";
				case KEY_M:
					return "M";
				case KEY_N:
					return "N";
				case KEY_O:
					return "O";
				case KEY_P:
					return "P";
				case KEY_Q:
					return "Q";
				case KEY_R:
					return "R";
				case KEY_S:
					return "S";
				case KEY_T:
					return "T";
				case KEY_U:
					return "U";
				case KEY_V:
					return "V";
				case KEY_W:
					return "W";
				case KEY_X:
					return "X";
				case KEY_Y:
					return "Y";
				case KEY_Z:
					return "Z";
				case KEY_LEFT_BRACKET:
					return "LBracket";
				case KEY_BACKSLASH:
					return "BackSlash";
				case KEY_RIGHT_BRACKET:
					return "RBracket";
				case KEY_GRAVE:
					return "Tilde";
				case KEY_SPACE:
					return "Space";
				case KEY_ESCAPE:
					return "Escape";
				case KEY_ENTER:
					return "Return";
				case KEY_TAB:
					return "Tab";
				case KEY_BACKSPACE:
					return "BackSpace";
				case KEY_INSERT:
					return "Insert";
				case KEY_DELETE:
					return "Delete";
				case KEY_RIGHT:
					return "Right";
				case KEY_LEFT:
					return "Left";
				case KEY_DOWN:
					return "Down";
				case KEY_UP:
					return "Up";
				case KEY_PAGE_UP:
					return "PageUp";
				case KEY_PAGE_DOWN:
					return "PageDown";
				case KEY_HOME:
					return "Home";
				case KEY_END:
					return "End";
				case KEY_CAPS_LOCK:
					return "CapsLock";
				case KEY_SCROLL_LOCK:
					return "ScrollLock";
				case KEY_NUM_LOCK:
					return "NumLock";
				case KEY_PRINT_SCREEN:
					return "PrintScreen";
				case KEY_PAUSE:
					return "Pause";
				case KEY_F1:
					return "F1";
				case KEY_F2:
					return "F2";
				case KEY_F3:
					return "F3";
				case KEY_F4:
					return "F4";
				case KEY_F5:
					return "F5";
				case KEY_F6:
					return "F6";
				case KEY_F7:
					return "F7";
				case KEY_F8:
					return "F8";
				case KEY_F9:
					return "F9";
				case KEY_F10:
					return "F10";
				case KEY_F11:
					return "F11";
				case KEY_F12:
					return "F12";
				case KEY_LEFT_SHIFT:
					return "LShift";
				case KEY_LEFT_CONTROL:
					return "LControl";
				case KEY_LEFT_ALT:
					return "LAlt";
				case KEY_LEFT_SUPER:
					return "LSystem";
				case KEY_RIGHT_SHIFT:
					return "RShift";
				case KEY_RIGHT_CONTROL:
					return "RControl";
				case KEY_RIGHT_ALT:
					return "RAlt";
				case KEY_RIGHT_SUPER:
					return "RSystem";
				case KEY_KB_MENU:
					return "Menu";
				case KEY_KP_0:
					return "Num0";
				case KEY_KP_1:
					return "Num1";
				case KEY_KP_2:
					return "Num2";
				case KEY_KP_3:
					return "Num3";
				case KEY_KP_4:
					return "Num4";
				case KEY_KP_5:
					return "Num5";
				case KEY_KP_6:
					return "Num6";
				case KEY_KP_7:
					return "Num7";
				case KEY_KP_8:
					return "Num8";
				case KEY_KP_9:
					return "Num9";
				case KEY_KP_DECIMAL:
					return "KPDECIMAL";
				case KEY_KP_DIVIDE:
					return "KPDIVIDE";
				case KEY_KP_MULTIPLY:
					return "KPMULTIPLY";
				case KEY_KP_SUBTRACT:
					return "KPSUBTRACT";
				case KEY_KP_ADD:
					return "KPADD";
				case KEY_KP_ENTER:
					return "KPENTER";
				case KEY_KP_EQUAL:
					return "KPEQUAL";
				case KEY_BACK:
					return "BACK";
				// TODO(wolfen): Not sure if we should keep this in.
				// case KEY_MENU:
				//	 return "MENU";
				case KEY_VOLUME_UP:
					return "VOLUMEUP";
				case KEY_VOLUME_DOWN:
					return "VOLUMEDOWN";
				default:
					return "Unknown";
			}
		}

		void process(){
			if( !computer )
				return;
			
			anyPressed = false;

			if( IsKeyDown( KEY_UP ) )
				if( virtualStick.y > -1 ){
					virtualStick.y -= 0.1;
					anyPressed = true;
				}

			if( IsKeyDown( KEY_DOWN ) )
				if( virtualStick.y < 1 ){
					virtualStick.y += 0.1;
					anyPressed = true;
				}

			if( IsKeyDown( KEY_LEFT ) )
				if( virtualStick.x > -1 ){
					virtualStick.x -= 0.1;
					anyPressed = true;
				}

			if( IsKeyDown( KEY_RIGHT ) )
				if( virtualStick.x < 1 ){
					virtualStick.x += 0.1;
					anyPressed = true;
				}

			if( !anyPressed ){
				virtualStick.x *= 0.8;
				virtualStick.y *= 0.8;
			}

			if( virtualStick.distance( amath::Vector2(0,0) ) > 1 )
				Input::axis::leftStick = virtualStick.normalize();
			else
				Input::axis::leftStick = virtualStick;
		}
	}
}