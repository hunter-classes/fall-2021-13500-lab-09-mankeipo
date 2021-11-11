#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

Coord3D pointA = {10,20,30};
Coord3D pointB = {40,50,60};
Coord3D pointC = {-20,21,-22};
Coord3D pos = {0, 0, 100.0};
Coord3D vel = {1, -5, 0.2};
TEST_CASE("TASK A") {
	CHECK(length(&pointA) == doctest::Approx(37.4166).epsilon(0.05));
	CHECK(length(&pointB) == doctest::Approx(87.7496).epsilon(0.05));
}

TEST_CASE("TASK B") {
	CHECK(fartherFromOrigin(&pointA, &pointC) == &pointA);
	CHECK(fartherFromOrigin(&pointA, &pointB) == &pointB);
}

TEST_CASE("TASK C") {
	move(&pos, &vel, 2.0);
	CHECK(pos.x == 2);
	CHECK(pos.y == -10);
	CHECK(pos.z == 100.4);

	move(&pointA, &vel, 2.0);
	CHECK(pointA.x == 12);
        CHECK(pointA.y == 10);
        CHECK(pointA.z == 30.4);
}

TEST_CASE("TASK E") {
	Coord3D *ppos = createCoord3D(10,20,30);
	Coord3D *pvel = createCoord3D(5.5,-1.4,7.77);
	move(ppos, pvel, 10.0);
	CHECK((*ppos).x == doctest::Approx(65).epsilon(0.05));
	CHECK((*ppos).y == doctest::Approx(6).epsilon(0.05));
	CHECK((*ppos).z == doctest::Approx(107.07).epsilon(0.05));
	deleteCoord3D(ppos); 
	deleteCoord3D(pvel);
	Coord3D *nppos = createCoord3D(20,30,40);
        Coord3D *npvel = createCoord3D(5.5,-1.4,7.77);
        move(nppos, npvel, 10.0);
	CHECK((*nppos).x == doctest::Approx(75).epsilon(0.05));
        CHECK((*nppos).y == doctest::Approx(16).epsilon(0.05));
        CHECK((*nppos).z == doctest::Approx(117.77).epsilon(0.05));
	deleteCoord3D(nppos); 
        deleteCoord3D(npvel);
}
