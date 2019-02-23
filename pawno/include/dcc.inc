/*
	Daniel's Console Colours plugin v1.6
	© 2012-2013, Daniel_Cortez
*/

enum
{
	COLOR_TYPE_ALL = 0,
	COLOR_TYPE_TXT,
	COLOR_TYPE_BK,
	COLOR_TYPE_BG = COLOR_TYPE_BK
}

native SetConsoleColors(color, type = COLOR_TYPE_ALL);
native GetConsoleColors(type = COLOR_TYPE_ALL);

// базовые цвета
#define	TXT_BLACK		0x00
#define	TXT_BLUE		0x01
#define	TXT_GREEN		0x02
#define	TXT_RED			0x04
#define	TXT_LIGHT		0x08
// дополнительные цвета
#define	TXT_AQUA		TXT_GREEN|TXT_BLUE
#define	TXT_PURPLE		TXT_RED|TXT_BLUE
#define TXT_GOLD		TXT_RED|TXT_GREEN
#define	TXT_LIGHTGREY	TXT_RED|TXT_GREEN|TXT_BLUE
#define	TXT_LIGHTGRAY	TXT_RED|TXT_GREEN|TXT_BLUE
#define	TXT_GREY		TXT_LIGHT
#define	TXT_GRAY		TXT_LIGHT
#define TXT_LIGHTBLUE	TXT_LIGHT|TXT_BLUE
#define	TXT_LIGHTGREEN	TXT_LIGHT|TXT_GREEN
#define	TXT_LIGHTAQUA	TXT_LIGHT|TXT_AQUA
#define	TXT_LIGHTRED	TXT_LIGHT|TXT_RED
#define	TXT_MAGENTA		TXT_LIGHT|TXT_RED|TXT_BLUE
#define	TXT_YELLOW		TXT_LIGHT|TXT_RED|TXT_GREEN
#define	TXT_WHITE		TXT_LIGHT|TXT_RED|TXT_GREEN|TXT_BLUE

// базовые цвета
#define	BK_BLACK		0x00
#define	BK_BLUE			0x10
#define	BK_GREEN		0x20
#define	BK_RED			0x40
#define	BK_LIGHT		0x80
// дополнительные цвета
#define	BK_AQUA			BK_GREEN|BK_BLUE
#define	BK_PURPLE		BK_RED|BK_BLUE
#define BK_GOLD			BK_RED|BK_GREEN
#define	BK_LIGHTGRAY	BK_RED|BK_GREEN|BK_BLUE
#define	BK_LIGHTGREY	BK_LIGHTGRAY
#define	BK_GREY			BK_LIGHT
#define	BK_GRAY			BK_LIGHT
#define BK_LIGHTBLUE	BK_LIGHT|BK_BLUE
#define	BK_LIGHTGREEN	BK_LIGHT|BK_GREEN
#define	BK_LIGHTAQUA	BK_LIGHT|BK_AQUA
#define	BK_LIGHTRED		BK_LIGHT|BK_RED
#define	BK_MAGENTA		BK_LIGHT|BK_RED|BK_BLUE
#define	BK_YELLOW		BK_LIGHT|BK_RED|BK_GREEN
#define	BK_WHITE		BK_LIGHT|BK_RED|BK_GREEN|BK_BLUE

// redefinition
#define	BG_BLACK		BK_BLACK
#define	BG_BLUE			BK_BLUE
#define	BG_GREEN		BK_GREEN
#define	BG_RED			BK_RED
#define	BG_LIGHT		BK_LIGHT
#define	BG_AQUA			BK_AQUA
#define	BG_PURPLE		BK_PURPLE
#define	BG_GOLD			BK_GOLD
#define	BG_LIGHTGRAY	BK_LIGHTGRAY
#define	BG_LIGHTGREY	BK_LIGHTGREY
#define	BG_GREY			BK_GREY
#define	BG_GRAY			BK_GRAY
#define	BG_LIGHTBLUE	BK_LIGHTBLUE
#define	BG_LIGHTGREEN	BK_LIGHTGREEN
#define	BG_LIGHTAQUA	BK_LIGHTAQUA
#define	BG_LIGHTRED		BK_LIGHTRED
#define	BG_MAGENTA		BK_MAGENTA
#define	BG_YELLOW		BK_YELLOW
#define	BG_WHITE		BK_WHITE

stock ________dcc_prev_color;

#define	printc(%0,%1)\
		________dcc_prev_color = GetConsoleColors(),\
		SetConsoleColors(%0),\
		print(%1),\
		SetConsoleColors(________dcc_prev_color)

#define	printfc(%0,%1)\
		________dcc_prev_color = GetConsoleColors(),\
		SetConsoleColors(%0),\
		printf(%1),\
		SetConsoleColors(________dcc_prev_color)