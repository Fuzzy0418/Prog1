#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	try{

		int sw = Fl::w();
		int sh = Fl::h();
		int ww = 800;
		int wh = 1000;

		Point tl = {(sw-ww)/2, (sh-wh)/2};
		Simple_window win { tl, ww, wh, "ch13"};

		int size[2] = {100, 100};

		Lines grid;
		for (int i = 0; i < 9; ++i)
		{
			grid.add(Point(i*size[0], 0), Point(i*size[0], 800));
		}
		for (int i = 0; i < 9; ++i)
		{
			grid.add(Point(0, i*size[1]), Point(800, i*size[1]));
		}
		win.attach(grid);

		Vector_ref<Rectangle> vr;

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (i==j){
					vr.push_back(new Rectangle(Point(i*size[0], j*size[1]), size[0], size[1]));
					vr[vr.size()-1].set_fill_color(Color::red);
					win.attach(vr[vr.size()-1]);
				}
			}
		}

		Image img1(Point(4*size[0], 0*size[1]), "picture.jpg");
		Image img2(Point(0*size[0], 4*size[1]), "picture.jpg");
		Image img3(Point(3*size[0], 6*size[1]), "picture.jpg");

		win.attach(img1);
		win.attach(img2);
		win.attach(img3);

		Image temp(Point(0*size[0], 0*size[1]), "picture002.jpg");
		temp.set_mask(Point(0*size[0], 0*size[1]), 100, 100);

		win.attach(temp);

		win.wait_for_button();
		int rows = 1;
		int columns = 1;
		while (true) {
			temp.move(100, 0);
			columns++;
			if (columns == 9) {
				temp.move(-800, 100);
				columns = 1;
				rows++;
			}
			if (rows == 8 && columns == 8) {
				break;
			}
			win.wait_for_button();
		}

		win.wait_for_button();

		return 0;
	} catch(exception& e) {
		return 1;
	} catch(...){
		return 2;
	}
}