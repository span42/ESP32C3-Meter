
#ifndef BUTTON_H
#define BUTTON_H

#include <OneButton.h>

class Button
{
private:
public:
	static void init();
	static void monitor();

	static void click1();
	static void click2();
	static void doubleClick1();
	static void longPressStop1();
};

extern Button button;
#endif
