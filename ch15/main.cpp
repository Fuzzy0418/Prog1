#include "Simple_window.h"
#include "Graph.h"

double inline one(double x) { return 1; }
double inline sloop(double x) { return x/2; }
double inline square(double x) { return x*x; }
double inline cosinusSloop(double x) { return sloop(x) + cos(x); }

int main()
{
	using namespace Graph_lib;
	try {
		int sw = Fl::w();
		int sh = Fl::h();
		int ww = 600;
		int wh = 600;

		Point tl = {(sw-ww)/2, (sh-wh)/2};
		Simple_window win { tl, ww, wh, "Function graphs"};

		Axis x_tengely(Axis::x, Point(100, 300), 400, 20, "1==20 pixels");
		Axis y_tengely(Axis::y, Point(300, 500), 400, 20, "1==20 pixels");
		x_tengely.set_color(Color::red);
		y_tengely.set_color(Color::red);
		win.attach(x_tengely);
		win.attach(y_tengely);

		int range[2] = {-10, 11};
		Point origo = {ww/2, wh/2};
		int points = 400;
		int scaling[2] = {20, 20};

		Function one_draw(one, range[0], range[1], origo, points, scaling[0], scaling[1]);
		win.attach(one_draw);

		Function sloop_draw(sloop, range[0], range[1], origo, points, scaling[0], scaling[1]);
		win.attach(sloop_draw);
		Text sloopText_draw(Point(100, 420), "x/2");
		win.attach(sloopText_draw);

		Function square_draw(square, range[0], range[1], origo, points, scaling[0], scaling[1]);
		win.attach(square_draw);

		Function cosinus_draw([](double x) {return cos(x);}, range[0], range[1], origo, points, scaling[0], scaling[1]);
		cosinus_draw.set_color(Color::blue);
		win.attach(cosinus_draw);

		Function cosinusSloop_draw(cosinusSloop, range[0], range[1], origo, points, scaling[0], scaling[1]);
		win.attach(cosinusSloop_draw);

		win.wait_for_button();
		return 0;
	} catch(exception& e) {
		return 1;
	} catch(...){
		return 2;
	}
}