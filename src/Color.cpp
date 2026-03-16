#include "ugar_io_opengl/Color.h"


Color::Color() {
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
}

Color::Color(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}


Color::~Color()
{
}

void Color::setRGB(float _r, float _g, float _b)
{
	r = _r;
	g = _g;
	b = _b;
}

Color Color::normalized(float normalize) const
{
	float max = 255.0f;
	return Color((r / max)*normalize, (g / max)*normalize, (b / max)*normalize);
}

