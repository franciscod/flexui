#pragma once

#include <algorithm> // for min, max

namespace flexui {

	struct Vec2 {
		Vec2(float x, float y) : x(x), y(y) { };
		Vec2() : x(0), y(0) { };

		float x, y;

		inline bool operator==(const Vec2& b) const { return x == b.x && y == b.y; }
		inline bool operator!=(const Vec2& b) const { return x != b.x || y != b.y; }
		inline Vec2 operator+(const Vec2& b) const { return { x + b.x, y + b.y }; };
		inline Vec2 operator-(const Vec2& b) const { return { x - b.x, y - b.y }; };
		inline Vec2 operator*(const Vec2& b) const { return { x * b.x, y * b.y }; };
		inline Vec2 operator*(const float& k) const { return { x * k, y * k }; };

		inline Vec2& operator+=(const Vec2& b) {
			this->x += b.x;
			this->y += b.y;
			return *this;
		}

		static inline Vec2 Min(const Vec2& a, const Vec2& b) { return { std::min(a.x, b.x), std::min(a.y, b.y) }; }
	};

	struct Rect {
		Rect(float x, float y, float w, float h) : x(x), y(y), width(w), height(h) { };
		Rect() : x(0), y(0), width(0), height(0) { };

		union {
			struct {
				Vec2 position;
				Vec2 size;
			};
			struct {
				float x, y, width, height;
			};
		};

		inline bool operator==(const Rect& b) const { return x == b.x && y == b.y && width == b.width && height == b.height; }
		inline bool operator!=(const Rect& b) const { return x != b.x || y != b.y || width != b.width || height != b.height; }
	};

	typedef uint32_t Color;
}