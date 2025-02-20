namespace console{
	static char luaInput[512] = "";
	std::string tempBuffer;
//
//	void draw(sf::RenderWindow& buffer, sf::Clock* deltaClockImgui){
//        std::vector<std::string> lines = m_str::split(mental::consoleBuffer,'\n');
//
//        ImGui::SetNextWindowSize(ImVec2(600, 300), ImGuiCond_FirstUseEver);
//        ImGui::Begin("Mental Console");
//        ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.75f); // Dark gray
//
//        ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
//        for (int n = 1; n < lines.size(); n++){
//            if( lines[n][0] == '!' )
//                ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255,0,0,255));
//            if( lines[n][0] == '~' )
//                ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255,255,0,255));
//            if( lines[n][0] == '+' )
//                ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0,255,0,255));
//
//            ImGui::Text("%s", lines[n].c_str());
//
//            if( lines[n][0] == '!' || lines[n][0] == '+' || lines[n][0] == '~' )
//                ImGui::PopStyleColor();
//        }
//
//        if( tempBuffer != mental::consoleBuffer ){
//        	ImGui::SetScrollHereY(1.0f);
//    		tempBuffer = mental::consoleBuffer;
//    	}
//
//        //ImGui::SetScrollHereY(1.0f);
//
//        ImGui::EndChild();
//        ImGui::Separator();
//
//
//		if (ImGui::InputText("Command", luaInput, IM_ARRAYSIZE(luaInput), ImGuiInputTextFlags_EnterReturnsTrue)) {
//			luaFunctions::print( "~" + std::string(luaInput) );
//			luaFunctions::loadStringSchedule( luaInput );
//
//			luaInput[0] = '\0';
//		}
//
//        ImGui::End();
//
//	}

}