#include "draw.h"

draw::draw() {
	//TEXTURES
	b_situp_tx.loadFromFile("img/character.png");
	b_situp_rect.setPosition(sf::Vector2f(140.0f, 160.0f));
	b_situp_rect.setTexture(&b_situp_tx);

	//couldnt initialize this object without preprecessing
	draw_b_situp temp{ &b_situp_tx, sf::Vector2u(2, 1) };
	b_situp = temp;

	background_tx.loadFromFile("img/background1.png");
	background_rect.setTexture(&background_tx);

	// font initializing
	/* license: SIL Open Font License (OFL)
	link: https://www.fontspace.com/pixeloid-font-f69232 */
	if (!font.loadFromFile("PixeloidSans.ttf")) {
		printf("Failed to load font file.\n");
	}
	else {
		printf("Font loaded successfully.\n");
	}
	//points info
	text_situps.setFont(font);
	text_situps.setCharacterSize(28);
	text_situps.setOutlineColor(sf::Color::Black);
	text_situps.setOutlineThickness(1.0);
	text_situps.setFillColor(sf::Color::White);
	text_situps.setPosition(sf::Vector2f(40.0f, 600.0f));

	//stamina info
	text_stamina.setFont(font);
	text_stamina.setCharacterSize(28);
	text_stamina.setOutlineColor(sf::Color::Black);
	text_stamina.setOutlineThickness(1.0);
	text_stamina.setFillColor(sf::Color::Green);
	text_stamina.setPosition(sf::Vector2f(180.0f, 115.0f));

	//upgrade 0 info
	text_upg0_x.setFont(font);
	text_upg0_x.setCharacterSize(15);
	text_upg0_x.setFillColor(sf::Color::White);
	text_upg0_x.setPosition(sf::Vector2f(605.0f, 145.0f));

	text_upg0_p.setFont(font);
	text_upg0_p.setCharacterSize(15);
	text_upg0_p.setFillColor(sf::Color::White);
	text_upg0_p.setPosition(sf::Vector2f(840.0f, 145.0f));

	//upgrade 1 info
	text_upg1_x.setFont(font);
	text_upg1_x.setCharacterSize(15);
	text_upg1_x.setFillColor(sf::Color::White);
	text_upg1_x.setPosition(sf::Vector2f(605.0f, 251.0f));

	text_upg1_p.setFont(font);
	text_upg1_p.setCharacterSize(15);
	text_upg1_p.setFillColor(sf::Color::White);
	text_upg1_p.setPosition(sf::Vector2f(840.0f, 251.0f));
	//upgrade 2 info
	text_upg2_x.setFont(font);
	text_upg2_x.setCharacterSize(15);
	text_upg2_x.setFillColor(sf::Color::White);
	text_upg2_x.setPosition(sf::Vector2f(605.0f, 357.0f));

	text_upg2_p.setFont(font);
	text_upg2_p.setCharacterSize(15);
	text_upg2_p.setFillColor(sf::Color::White);
	text_upg2_p.setPosition(sf::Vector2f(840.0f, 357.0f));
	//upgrade 3 info
	text_upg3_x.setFont(font);
	text_upg3_x.setCharacterSize(15);
	text_upg3_x.setFillColor(sf::Color::White);
	text_upg3_x.setPosition(sf::Vector2f(605.0f, 463.0f));

	text_upg3_p.setFont(font);
	text_upg3_p.setCharacterSize(15);
	text_upg3_p.setFillColor(sf::Color::White);
	text_upg3_p.setPosition(sf::Vector2f(840.0f, 463.0f));
	//upgrade 4 info
	text_upg4_x.setFont(font);
	text_upg4_x.setCharacterSize(15);
	text_upg4_x.setFillColor(sf::Color::White);
	text_upg4_x.setPosition(sf::Vector2f(605.0f, 569.0f));

	text_upg4_p.setFont(font);
	text_upg4_p.setCharacterSize(15);
	text_upg4_p.setFillColor(sf::Color::White);
	text_upg4_p.setPosition(sf::Vector2f(840.0f, 569.0f));
}


void draw::Draw(sf::RenderWindow& window, std::vector<double>& l_stat, 
	std::vector<int>& l_upg, std::vector<double>& l_price) {
	//character animation
	b_situp.perform(&window, 0, l_stat);
	b_situp_rect.setTextureRect(b_situp.uvRect);

	//situps counter updating
	conv = std::to_string(std::ceil(l_stat[0]*100)/100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);
	text_situps.setString("Sit-ups: " + conv);

	//stamina counter updating
	conv = std::to_string((int)l_stat[4]);

	conv2 = conv + "/";
	conv = std::to_string(std::ceil(l_stat[3] * 100) / 100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);

	text_stamina.setString(conv2 + conv);
	

	//upgrade 0 updating
	conv = std::to_string(l_upg[0]);
	text_upg0_x.setString(conv);

	conv = std::to_string(std::ceil(l_price[0] * 100) / 100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);
	text_upg0_p.setString(conv);

	//upgrade 1 updating
	conv = std::to_string(l_upg[1]);
	text_upg1_x.setString(conv);

	conv = std::to_string(std::ceil(l_price[1] * 100) / 100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);
	text_upg1_p.setString(conv);

	//upgrade 2 updating
	conv = std::to_string(l_upg[2]);
	text_upg2_x.setString(conv);

	conv = std::to_string(std::ceil(l_price[2] * 100) / 100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);
	text_upg2_p.setString(conv);

	//upgrade 3 updating
	conv = std::to_string(l_upg[3]);
	text_upg3_x.setString(conv);

	conv = std::to_string(std::ceil(l_price[3] * 100) / 100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);
	text_upg3_p.setString(conv);

	//upgrade 4 updating
	conv = std::to_string(l_upg[4]);
	text_upg4_x.setString(conv);

	conv = std::to_string(std::ceil(l_price[4] * 100) / 100);
	conv.erase(conv.find_last_not_of('0') + 1, std::string::npos);
	conv.erase(conv.find_last_not_of('.') + 1, std::string::npos);
	text_upg4_p.setString(conv);

	//actual drawing
	window.clear();
	window.draw(background_rect);
	window.draw(b_situp_rect);
	window.draw(text_upg0_p);
	window.draw(text_upg0_x);
	window.draw(text_upg1_p);
	window.draw(text_upg1_x);
	window.draw(text_upg2_p);
	window.draw(text_upg2_x);
	window.draw(text_upg3_p);
	window.draw(text_upg3_x);
	window.draw(text_upg4_p);
	window.draw(text_upg4_x);
	window.draw(text_situps);
	window.draw(text_stamina);
	window.display();
}
