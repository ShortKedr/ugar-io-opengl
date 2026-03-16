#ifndef COLOR_H
#define COLOR_H
class Color
{
	public:
	
		float r, g, b;
	
		Color();
		Color(float _r, float _g, float _b);
		~Color();

		void setRGB(float _r, float _g, float _b);
		Color normalized(float normalize = 1.0f) const;

		
};
#endif


