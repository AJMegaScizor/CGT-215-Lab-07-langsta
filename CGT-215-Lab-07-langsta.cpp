// CGT-215-Lab-07-langsta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
using namespace std;
using namespace sf;
using namespace sfp;
int main()
{
	// Create our window and world with gravity 0,1
	RenderWindow window(VideoMode(800, 600), "Bounce");
	World world(Vector2f(0, 1));
	// Create the ball
	PhysicsCircle ball;
	ball.setCenter(Vector2f(50, 100));
	ball.setRadius(20);
	world.AddPhysicsBody(ball);
	ball.applyImpulse(Vector2f(2.f, 0.f)); //applies an impulse variable to push the ball
	// Create the floor
	PhysicsRectangle floor;
	floor.setSize(Vector2f(800, 50));
	floor.setCenter(Vector2f(400, 590));
	floor.setStatic(true);
	world.AddPhysicsBody(floor);
	//create right wall
	PhysicsRectangle wall_right;
	wall_right.setSize(Vector2f(50, 800));
	wall_right.setCenter(Vector2f(790, 200));
	wall_right.setStatic(true);
	world.AddPhysicsBody(wall_right);
	//create left wall
	PhysicsRectangle wall_left;
	wall_left.setSize(Vector2f(50, 800));
	wall_left.setCenter(Vector2f(10, 200));
	wall_left.setStatic(true);
	world.AddPhysicsBody(wall_left);
	//create ceiling
	PhysicsRectangle ceiling;
	ceiling.setSize(Vector2f(800, 50));
	ceiling.setCenter(Vector2f(400, 10));
	ceiling.setStatic(true);
	world.AddPhysicsBody(ceiling);
	//create center rectangle
	PhysicsRectangle center;
	center.setSize(Vector2f(100, 100));
	center.setCenter(Vector2f(400, 300));
	center.setStatic(true);
	world.AddPhysicsBody(center);
	// thud counts 
	int thudCount(0);
	
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	wall_right.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	wall_left.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	ceiling.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	//bang counts
	int bangCount(0);
	center.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << " bang " << bangCount << endl;
		bangCount++;
		};
	
	
	Clock clock;
	Time lastTime(clock.getElapsedTime());
	while (true) {

		// calculate MS since last frame
		Time currentTime(clock.getElapsedTime());
		Time deltaTime(currentTime - lastTime);
		int deltaTimeMS(deltaTime.asMilliseconds());
		if (deltaTimeMS > 0) {
			world.UpdatePhysics(deltaTimeMS);
			lastTime = currentTime;
		}
		window.clear(Color(0, 0, 0));
		window.draw(ball);
		window.draw(floor);
		window.draw(wall_right);
		window.draw(wall_left);
		window.draw(ceiling);
		window.draw(center);
		window.display();
		if (bangCount == 3) {
			exit(0);
		}
		
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
