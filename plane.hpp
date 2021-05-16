
#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>
#include <iostream>

struct Move
{
	int k; // kolumna
	int w; // wiersz
	char color; // player_color
	double value; // evaluated value of this particular move? not sure if it's required
	
	Move(int k, int w, char color, double value); 
	Move(const Move& ob);
	Move(const Move&& ob);
};

class Plane
{
	public:
		// Data Processing
		unsigned int size() const; // Get size of plane - it is square, so one value is enough
		char at(int k, int w) const; // Access given element of plane - read-only!
		std::vector<Move> evaluate(char player_color) const; // evaluate
		bool finished() const; // check if game has finished on this plane
		// Data Manipulation
		Plane(unsigned int size); // Create plane with given size
		bool apply(const Move& m); // apply move to the plane, return 'false' if failed, otherwise 'true'
		
		// those two should be made, but default ones probably work as well
		Plane(const Plane& ob); // Copy existing plane
		Plane(const Plane&& ob); // Return-val constructor
		Plane& operator = (const Plane& ob); // Similar to constructor above
	private:
		std::vector<std::vector<char>> data; // data[kolumna][wiersz] 
		unsigned int s; // vassal for size
};

std::ostream& operator << (std::ostream& stream, const Plane& plane);

#endif