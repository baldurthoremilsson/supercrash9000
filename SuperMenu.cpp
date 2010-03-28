#include <string>
#include <vector>

class SuperMenu {
	private:
		int selected; 				// nr. hvað er valið
		vector<string> menuChoices; // valmöguleikar geymdir í vector
		bool hasChosen;				// búið er að velja menuChoices[selected]
	public:
		// public breytur hér

	SuperCrash() {
		// constructor
	}
	~SuperCrash() {
		// destructor
	}
	
	void addSelection(String s) {
		menuChoices.push_back(s);
	}
	int getSize() {
		return menuChoices.size();
	}
	
	void display() {
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		
		std::cout << "Menu!!1111\n";
	}
	void keyboard() {}

};
