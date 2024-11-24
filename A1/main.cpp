#include <fstream>
#include <iostream>
#include <random>

struct Point {
  double x;
  double y;
};

struct Circle {
  Point center;
  double radius;
};

std::pair<Point, Point> findBoundingRectangle(const Circle& c1, const Circle& c2, const Circle& c3) {
  double minX = std::min({c1.center.x - c1.radius, c2.center.x - c2.radius, c3.center.x - c3.radius});
  double maxX = std::max({c1.center.x + c1.radius, c2.center.x + c2.radius, c3.center.x + c3.radius});
  double minY = std::min({c1.center.y - c1.radius, c2.center.y - c2.radius, c3.center.y - c3.radius});
  double maxY = std::max({c1.center.y + c1.radius, c2.center.y + c2.radius, c3.center.y + c3.radius});

  return {{minX, minY}, {maxX, maxY}};
}

Point generateRandomPoint(const Point& bottomLeft, const Point& topRight) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<> disX(bottomLeft.x, topRight.x);
  std::uniform_real_distribution<> disY(bottomLeft.y, topRight.y);

  return {disX(gen), disY(gen)};
}

bool isPointInsideCircle(const Point& point, const Circle& circle) {
  double dx = point.x - circle.center.x;
  double dy = point.y - circle.center.y;
  return dx * dx + dy * dy <= circle.radius * circle.radius;
}

double calculateIntersectionArea(const Circle& c1, const Circle& c2, const Circle& c3, int numPoints) {
  double pointsInside = 0;
  auto [bottomLeft, topRight] = findBoundingRectangle(c1, c2, c3);

  for (int i = 0; i < numPoints; ++i) {
    Point point = generateRandomPoint(bottomLeft, topRight);
    if (isPointInsideCircle(point, c1) &&
        isPointInsideCircle(point, c2) &&
        isPointInsideCircle(point, c3)) {
      pointsInside++;
        }
  }

  return pointsInside / numPoints * (topRight.x - bottomLeft.x) * (topRight.y - bottomLeft.y);
}

int main() {
  Circle
    c1(Point(1, 1), 1),
    c2(Point(1.5, 2), sqrt(5) / 2),
    c3(Point(2, 1.5), sqrt(5) / 2);

  std::ofstream out("A1.txt");
  if (!out.is_open()) {
    std::cerr << "Error opening file out.txt" << std::endl;
    return 1;
  }

  for (int i = 100; i < 100000; i += 500) {
    double area = 0;
    for (int j = 0; j < 10; ++j) {
      area += calculateIntersectionArea(c1, c2, c3, i);
    }
    area /= 10;

    out << i << " " << area << std::endl;
    std::cout << i << std::endl;
  }

  out.close();

  return 0;
}