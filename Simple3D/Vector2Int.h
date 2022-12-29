#pragma once

struct Vector2Int
{
	int x;
	int y;

	inline Vector2Int()
	{
		x = 0;
		y = 0;
	}

	inline Vector2Int(int new_x, int new_y)
	{
		x = new_x;
		y = new_y;
	}

	inline Vector2Int(const Vector2Int& vec) : Vector2Int(vec.x, vec.y)
	{
	}

	friend Vector2Int operator+(Vector2Int l, Vector2Int r)
	{
		return Vector2Int(l.x + r.x, l.y + r.y);
	}

	friend Vector2Int operator-(Vector2Int l, Vector2Int r)
	{
		return Vector2Int(l.x - r.x, l.y - r.y);
	}

	friend bool operator==(Vector2Int l, Vector2Int r)
	{
		return l.x == r.x && l.y == r.y;
	}

	friend bool operator!=(Vector2Int l, Vector2Int r)
	{
		return !(l == r);
	}

	friend bool operator>(Vector2Int l, Vector2Int r)
	{
		return l.x > r.x && l.y > r.y;
	}

	friend bool operator<(Vector2Int l, Vector2Int r)
	{
		return r > l;
	}

	friend bool operator>=(Vector2Int l, Vector2Int r)
	{
		return l.x >= r.x && l.y >= r.y;
	}

	friend bool operator<=(Vector2Int l, Vector2Int r)
	{
		return r >= l;
	}
};
