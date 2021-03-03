#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	try{
		//draw window
		int sw = Fl::w(); //main screen width
		int sh = Fl::h(); //main screen height
		int ww = 600; // window width
		int wh = 400; // window height

		Point tl = {(sw-ww)/2, (sh-wh)/2};
		Simple_window win { tl, ww, wh, "My"};
		//

		//axis
		Axis xa {Axis::x, Point{20, 150}, 300, 10, "x axis"};
		Axis ya {Axis::y, Point{180, 290}, 280, 10, "y axis"};
		//
		
		//function
		Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
		//

		//polygons
		Polygon poly;
		poly.add(Point{300, 200});
		poly.add(Point{350, 100});
		poly.add(Point{400, 200});

		poly.set_style(Line_style(Line_style::dash, 4));
		//

		//rectangle
		Rectangle r {Point{200, 200}, 100, 50};

		r.set_fill_color(Color::red);
		//

		//text
		Text t {Point{150, 150}, "Hello"};
		
		t.set_font(Font::times_bold);
		t.set_font_size(12);
		//

		//circle
		Circle c {Point{100, 200}, 50};
		//

		win.attach(xa);
		win.attach(ya);
		win.attach(sine);
		win.attach(poly);
		win.attach(r);
		win.attach(t);
		win.attach(c);

		win.wait_for_button();
		return 0;
	} catch(exception& e) {
		return 1;
	} catch(...){
		return 2;
	}
}