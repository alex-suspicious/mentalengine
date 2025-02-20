namespace debug{
	void SetNextWindowSize( amath::Vector2 size ){
		ImGui::SetNextWindowSize(ImVec2(size.x, size.y), ImGuiCond_FirstUseEver);
	}

	void Begin( std::string name ){
		ImGui::Begin(name.c_str());
	}

	void End(){
		ImGui::End();
	}
}