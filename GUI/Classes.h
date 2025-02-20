namespace gui{

    class text: public renderable::base{
    public:
        char* actual_string;
        std::string font;
        float size;
        bool fontLoaded = false;

        //sf::Text *native;

        text(){
            this->layer = 15;
            this->type = 3;
            this->size = 15;

            this->sizeRect.width = 100;
            this->sizeRect.height = 100;
            this->scale.x = 1;
            this->scale.y = 1;
            this->color = mental::color(255,255,255,255);

            mental::renderablesBuffer.push_back( this );
            //guiInit::texts.push_back(this);

            //this->native = new sf::Text("", *mental::loadFont("sansation.ttf"), 28);
            //guiInit::texts_native.push_back(this->native);

            //this->id = rand() % 99999999999;
        }

        text( std::string string ){
            this->layer = 15;
            this->type = 3;
            this->size = 15;

            this->actual_string = new char [string.length()+1];
            strcpy(this->actual_string, string.c_str());

            this->sizeRect.width = 100;
            this->sizeRect.height = 100;

            this->scale.x = 1;
            this->scale.y = 1;
            this->color = mental::color(255,255,255,255);

            mental::renderablesBuffer.push_back( this );
//            guiInit::texts.push_back(this);
//
//            this->native = new sf::Text("", *mental::loadFont("sansation.ttf"), 28);
//            this->native->setString( string );
//            guiInit::texts_native.push_back(this->native);
//
//            this->id = rand() % 99999999999;
        }

        text( std::string string, std::string font ){
            this->layer = 15;
            this->type = 3;
            this->size = 15;

            this->actual_string = new char [string.length()+1];
            strcpy(this->actual_string, string.c_str());

            this->font = mental::loadFont(font);

            this->sizeRect.width = 100;
            this->sizeRect.height = 100;
            this->fontLoaded = true;

            this->scale.x = 1;
            this->scale.y = 1;
            this->color = mental::color(255,255,255,255);

            mental::renderablesBuffer.push_back( this );
//            guiInit::texts.push_back(this);
//
//            this->native = new sf::Text("", *mental::loadFont(font), 28);
//            this->native->setString( string );
//            guiInit::texts_native.push_back(this->native);
//
//            this->id = rand() % 99999999999;
        }

        text( std::string string, std::string font, int size ){
            this->layer = 15;
            this->type = 3;
            this->size = size;

            this->actual_string = new char [string.length()+1];
            strcpy(this->actual_string, string.c_str());

            this->font = mental::loadFont(font);

            this->sizeRect.width = 100;
            this->sizeRect.height = 100;
            this->fontLoaded = true;

            this->scale.x = 1;
            this->scale.y = 1;
            this->color = mental::color(255,255,255,255);

            mental::renderablesBuffer.push_back( this );
//            guiInit::texts.push_back(this);
//
//            this->native = new sf::Text("", *mental::loadFont(font), size);
//            this->native->setString( string );
//            guiInit::texts_native.push_back(this->native);
//
//            this->id = rand() % 99999999999;
        }

        ~text(){
            for (int i = 0; i < mental::renderablesBuffer.size(); i++)
            {
                if( ((renderable::base*)mental::renderablesBuffer[i])->id == this->id ){
                    this->removed = true;
                    mental::renderablesBuffer.erase(mental::renderablesBuffer.begin() + i);
                    break;
                }
            }

//            for (int i = 0; i < guiInit::texts_native.size(); i++)
//            {
//                if( guiInit::texts_native[i] == this->native ){
//                    guiInit::texts_native.erase(guiInit::texts_native.begin() + i);
//                    break;
//                }
//            }
//
//            for (int i = 0; i < guiInit::texts.size(); i++)
//            {
//                if( ((text*)guiInit::texts[i])->id == this->id ){
//                    guiInit::texts.erase(guiInit::texts.begin() + i);
//                    break;
//                }
//            }
        }

        void screenCoords( bool onoff ){
            //this->screen = onoff;
        }

        void setString( std::string string ){
            this->actual_string = new char [string.length()+1];
            strcpy(this->actual_string, string.c_str());
            //this->bounds = amath::Vector2( this->native->getGlobalBounds() );
        }

        void setOutlineColor( mental::color rgba ){
            //this->native->setOutlineColor( rgba );
        }

        void setOutlineThickness( float thick ){
            //this->native->setOutlineThickness( thick );
        }

        void setScale( float scale ){
            this->scale.x = scale;
            this->scale.y = scale;

            //this->native->setScale( scale, scale );
            //this->bounds = amath::Vector2( this->native->getGlobalBounds() );
        }

        void setSize( float pixels ){
           this->size = pixels;
            //this->bounds = amath::Vector2( this->native->getGlobalBounds() );
        }

        void setFont( std::string path ){
            this->font = mental::loadFont(path);
            this->fontLoaded = true;
            //this->native->setFont( *mental::loadFont(path) );
            //this->bounds = amath::Vector2( this->native->getGlobalBounds() );
        }

        void draw( float time, int index ){
            if( !this->fontLoaded )
                return;

            rlPushMatrix();
                rlScalef(this->scale.x, this->scale.y, 1);
                //rlTranslatef(0,0, (this->depthLayer*15) - ((float)this->layer)*0.15f - 1);
                DrawTextPro(mental::fontBuffer[font], this->actual_string, this->position.raylib(), amath::Vector2(0,0).raylib(), this->renderAngle, this->size, 10, this->color.raylib() );
            rlPopMatrix();


        }
    };

}