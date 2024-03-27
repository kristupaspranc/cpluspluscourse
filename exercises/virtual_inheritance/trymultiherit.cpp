#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox text("Text for textbox", 1, 2, 3);
    // text.draw();

    // Fix the code to call both draws by using types
    // Rectangle& viaRectangle{text};
    // viaRectangle.draw();

    // Text& viaText{text};
    // viaText.draw();

    // try with virtual inheritance
    text.draw();



}
