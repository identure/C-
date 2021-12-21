#include "Geometry.h"

// ============ Shape class =================

Shape::Shape() {} // REMOVE ME

Shape::Shape(int d) {
	// IMPLEMENT ME
	if (d<0) {
		throw std::invalid_argument("The input d value is a negative number");
	}
}

bool Shape::setDepth(int d) {
	// IMPLEMENT ME
	if (d<0) return false;
	depth_ = d;
	return true;
}

int Shape::getDepth() const {
	// IMPLEMENT ME
	return depth_;
}

int Shape::dim() const {
	// IMPLEMENT ME
	return dim_; 
}

void Shape::translate(float x, float y) {
	// IMPLEMENT ME
	cout << dim() << "dim" << endl;
	if (dim()==0) {
		pX_ = pX_ + x;
		pY_ = pY_ + y;
	}else if(dim()==1){
		lineXmin_ = lineXmin_ + x;
		lineXmax_ = lineXmax_ + x;
		lineYmin_ = lineYmin_ + y;
		lineYmax_ = lineYmax_ + y;
	}else if (dim()==2) {
		recXmin_ = recXmin_ + x;
		recXmax_ = recXmax_ + x;
		recYmin_ = recYmin_ + y;
		recYmax_ = recYmax_ + y;
		circleX_ = circleX_ + x;
		circleY_ = circleY_ + y;
	}
}

void Shape::rotate() {
	// IMPLEMENT ME
	if (dim()==1) { // line
		if (lineXmax_ == lineXmin_) {
			float len_ = lineYmax_ - lineYmin_;
			lineYmin_ = lineYmax_ = len_ / 2 + lineYmin_;
			lineXmax_ = len_ / 2 + lineXmin_;
			lineXmin_ = lineXmax_ - len_;
		}else {
			float len_ = lineXmax_ - lineXmin_;
			lineXmin_ = lineXmax_ = len_ / 2 + lineXmin_;
			lineYmax_ = len_ / 2 + lineYmin_;
			lineYmin_ = lineYmax_ - len_;
		}
	}else if(dim()==2){ // Rectangle
		float num1 = (recXmax_ - recXmin_) / 2;
		float num2 = (recYmax_ - recYmin_) / 2;
		float num3 = num1 + recXmin_ - num2;
		float num4 = num1 + recXmin_ + num2;
		float num5 = num2 + recYmin_ - num2;
		float num6 = num1 + recYmin_ + num2;
		recXmin_ = num3;
		recXmax_ = num4;
		recYmin_ = num5;
		recYmax_ = num6;
	}
}

void Shape::scale(float f) {
	// IMPLEMENT ME
	if (f <= 0) {
		throw std::invalid_argument("the f is 0 or negative");
	}
	if (dim()==1) {

	}else if(dim()==2){
		circleR_ = circleR_ * f;
	}
}

bool Shape::contains(const Point& p) const {
	// IMPLEMENT ME
	if (dim()==0) { // point
		if (p.getX() == pX_ && p.getY() == pY_) {
			return true;
		}else{
			return false;
		}
	}else if (dim()==1) {
	
	}
	return false;
}

// =============== Point class ================

Point::Point(float x, float y, int d) {
	// IMPLEMENT ME
	if (d < 0) {
		throw std::invalid_argument("The input d value is a negative number");
	}
	pX_ = x;
	pY_ = y; 
	depth_ = d;
}

float Point::getX() const {
	// IMPLEMENT ME
	return pX_; 
}

float Point::getY() const {
	// IMPLEMENT ME
	return pY_; 
}

// =========== LineSegment class ==============

LineSegment::LineSegment(const Point& p, const Point& q) {
	// IMPLEMENT ME
	if (p.getDepth()!=q.getDepth()) {
		throw std::invalid_argument("The two endpoints should have the same depth");
	}else if (p.getX() == q.getX() && p.getY() == q.getY()) {
		throw std::invalid_argument("the two endpoints coincide");
	}else if (p.getX()==q.getX() || p.getY()==q.getY()) {
		lineXmax_ = p.getX() >= q.getX() ? p.getX() : q.getX();
		lineXmin_ = p.getX() < q.getX() ? p.getX() : q.getX();
		lineYmax_ = p.getY() >= q.getY() ? p.getY() : q.getY();
		lineYmin_ = p.getY() < q.getY() ? p.getY() : q.getY();
	}
	//cout << lineXmin_ << " " << lineXmax_ << " " << lineYmax_ << " " << lineYmin_;
	depth_ = p.getDepth();
}

float LineSegment::getXmin() const {
	// IMPLEMENT ME
	cout << "123xx" << lineXmin_ << endl;
	return lineXmin_;
}

float LineSegment::getXmax() const {
	// IMPLEMENT ME
	return lineXmax_;
}

float LineSegment::getYmin() const {
	// IMPLEMENT ME
	return lineYmin_;
}

float LineSegment::getYmax() const {
	// IMPLEMENT ME
	return lineYmax_;
}

float LineSegment::length() const {
	// IMPLEMENT ME
	float lengthTmp = 0; // the length of the line
	//cout << lineXmin_ << " " << lineXmax_ << " " << lineYmax_ << " " << lineYmin_;
	if (lineXmin_ == lineXmax_) {
		lengthTmp = lineYmax_ - lineYmin_;
	}else {
		lengthTmp = lineXmax_ - lineXmin_;
	}
	//length_ = lengthTmp;
	return lengthTmp;
}

// ============ TwoDShape class ================

TwoDShape::TwoDShape(){} // REMOVE ME

TwoDShape::TwoDShape(int d) {
	// IMPLEMENT ME
	if (d < 0) {
		throw std::invalid_argument("The input d value is a negative number");
	}
}

float TwoDShape::area() const {
	// IMPLEMENT ME
	float s = 0;
	if (dim()==0 || dim()==1) { // Shape is point
		s = 0;
	}else if (dim()==2) { // Shape is circle
		//s = PI * r;
	}
	return -999; // dummy
}

// ============== Rectangle class ================

Rectangle::Rectangle(const Point& p, const Point& q) {
	// IMPLEMENT ME
	if (p.getDepth() != q.getDepth()) {
		throw std::invalid_argument("The two endpoints should have the same depth");
	}else if (p.getX() == q.getX() || p.getY() == q.getY()) {
		throw std::invalid_argument("the two endpoints coincide");
	}else if (p.getX() == q.getX() || p.getY() == q.getY()) {
		recXmax_ = p.getX() >= q.getX() ? p.getX() : q.getX();
		recXmin_ = q.getX() < q.getX() ? p.getX() : q.getX();
		recYmax_ = p.getY() >= q.getY() ? p.getY() : q.getY();
		recYmin_ = p.getY() < q.getY() ? p.getY() : q.getY();
	}
}

float Rectangle::getXmin() const {
	// IMPLEMENT ME
	return recXmin_;
}

float Rectangle::getYmin() const {
	// IMPLEMENT ME
	return recYmin_;
}

float Rectangle::getXmax() const {
	// IMPLEMENT ME
	return recXmax_;
}

float Rectangle::getYmax() const {
	// IMPLEMENT ME
	return recYmax_;
}

// ================== Circle class ===================

Circle::Circle(const Point& c, float r) {
	// IMPLEMENT ME
	if (r <= 0) {
		throw std::invalid_argument("the radius is 0 or negative");
	}else {
		circleX_ = c.getX();
		circleY_ = c.getY();
		circleR_ = r;
	}
}

float Circle::getX() const {
	// IMPLEMENT ME
	return circleX_; 
}

float Circle::getY() const {
	// IMPLEMENT ME
	return circleY_; 
}

float Circle::getR() const {
	// IMPLEMENT ME
	return circleR_;
}

// ================= Scene class ===================

Scene::Scene() {
	// IMPLEMENT ME
}

void Scene::addObject(std::shared_ptr<Shape> ptr) {
	// IMPLEMENT ME
}

void Scene::setDrawDepth(int depth) {
	// IMPLEMENT ME
}

std::ostream& operator<<(std::ostream& out, const Scene& s) {
	// IMPLEMENT ME
	return out;
}

