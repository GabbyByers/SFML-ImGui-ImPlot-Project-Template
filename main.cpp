#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "implot.h"
#include "SFML/Graphics.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(700, 700), "Hello SFML", sf::Style::Close);
	sf::Event event;
	ImGui::SFML::Init(window);
	ImGui::GetIO().IniFilename = NULL;
	ImPlot::CreateContext(); // ImPlot Create Context

	int dummy_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	sf::Clock deltaClock;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("my pretty window!");
		ImGui::Text("some text!");

		if (ImPlot::BeginPlot("the dolls will go nuts for this plot uwu")) {
			ImPlot::PlotLine("line1", dummy_data, 10);
			ImPlot::PlotLine("line2", dummy_data, 10);
			ImPlot::EndPlot();
		}

		ImGui::End();

		window.clear(sf::Color(0, 0, 0));
		ImGui::SFML::Render(window);
		window.display();
	}

	ImPlot::DestroyContext(); // ImPlot Destroy
	ImGui::SFML::Shutdown();
	return 0;
}