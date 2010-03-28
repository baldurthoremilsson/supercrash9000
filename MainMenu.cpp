#include "SuperMenu.h"
#include "SuperCrash.h"
#include <string>
#include <vector>


SuperMenu::SuperMenu(SuperCrash *p) {
	s = p;

	menuChoices.push_back("Hello");
	menuChoices.push_back("This is a test");
	menuChoices.push_back("If this works, I will be very happy");
	menuChoices.push_back("Here's some longer text just so it can be tested whether the thingy breaks down or not. Not that it's important to support overly long menu items");
}
SuperMenu::~SuperMenu() {
	// delete teh stuffz!11
}
	
void makeSelection(int i) {
	// ath. hvað er valið og keyra rétt thingy eftir því
	// í bili ætlum við bara að gera eitthvað bleh
	s.test();
}
void display() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		
	std::cout << "Menu!!1111\n";
}
