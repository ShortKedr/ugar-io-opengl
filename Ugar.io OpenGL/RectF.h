#ifndef RECT_F_H
#define RECT_F_H

class RectF {
	float x = 0.0f;
	float y = 0.0f;
	float w = 0.0f;
	float h = 0.0f;

	public:
		RectF();
		RectF(float _x, float _y, float _w, float _h);
		~RectF();

		void setX(float _x);
		void setY(float _y);
		void setW(float _w);
		void setH(float _h);

		float getX() const;
		float getY() const;
		float getW() const;
		float getH() const;
};
#endif
