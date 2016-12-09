#pragma once
#include <vector>
#include <algorithm>

enum class Direction {

	NORTH=1,
	EAST,
	SOUTH,
	WEST
};

class Node {

	int x;
	int y;
	int imgIndex;

public:

	int getX()const { return x; }
	int getY()const { return y; }
	
	int getImgIndex()const { return imgIndex; }
	void moveTo(int nx, int ny) {

		x = nx;
		y = ny;
	}

	Node(int _x, int _y, int _ii): x(_x), y(_y), imgIndex(_ii){}
	Node(const Node& other) {

		x = other.x;
		y = other.y;
		imgIndex = other.imgIndex;
	}
	Node& operator=(const Node& other) {

		if (this == &other) {
			return *this;
		}
		x = other.x;
		y = other.y;
		imgIndex = other.imgIndex;
		return *this;
	}
};

class Snake {

public:

	std::vector<Node> nodes;
	Direction dir;

	Snake() {
	
		dir = static_cast<Direction>(1);
		nodes.push_back(Node(10, 10, 2));
	}
	void eat(int x, int y, int imgIndex) {

		nodes.push_back(Node(0, 0, 0));
		for (int i = nodes.size()-1; i>0; i--) {

			nodes[i] = nodes[i-1];
		}
		nodes[0] = Node(x, y, imgIndex);
	}
	void setDirection(int nd) {

		dir = static_cast<Direction>(nd);
	}
	void move() {

		for (int i = nodes.size() - 1; i > 0; i--) {

			nodes[i].moveTo(nodes[i - 1].getX(), nodes[i - 1].getY());
		}
		if (dir == Direction::NORTH) {

			nodes[0].moveTo(nodes[0].getX(), nodes[0].getY() - 1);
		}
		if (dir == Direction::EAST) {

			nodes[0].moveTo(nodes[0].getX()+1, nodes[0].getY());
		}
		if (dir == Direction::SOUTH) {

			nodes[0].moveTo(nodes[0].getX(), nodes[0].getY() + 1);
		}
		if (dir == Direction::WEST) {

			nodes[0].moveTo(nodes[0].getX()-1, nodes[0].getY());
		}
	}
};

Snake snake;
Snake snake2;