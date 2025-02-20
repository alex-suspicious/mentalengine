namespace mental{
    std::vector<void*> renderablesBuffer;
    std::vector<void*> modelsBuffer;
    //std::vector<sf::Shader*> spriteShadersBuffer;
    //std::vector<sf::Shader*> spriteShadersBufferDepth;
    std::vector<void*> dynamicsBuffer;
    std::vector<void*> collisionRectBuffer;
    std::vector<void*> lightsBuffer;
    std::vector<void*> brushBuffer;
    std::string consoleBuffer;
    amath::Vector2 camPos;
}