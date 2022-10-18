#include "lines.hpp"
#include <cairomm/context.h>

MyArea::MyArea()
{
}

MyArea::~MyArea()
{
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // coordinates for the center of the window
  int xc, yc;
  xc = width / 2;
  yc = height / 2;

  cr->set_line_width(5.0);
  cr->set_source_rgb(0.8, 0.0, 0.0);

	cr->set_line_cap(Cairo::LINE_CAP_ROUND);
	cr->set_line_join(Cairo::LINE_JOIN_BEVEL);

  cr->move_to(50, 50);
  cr->line_to(200, 200);

  cr->move_to(0, height);
  cr->line_to(width, 0);

  cr->move_to(xc, 0);
  cr->line_to(xc, height);

  cr->move_to(0, yc);
  cr->line_to(width, yc);

  cr->stroke();

  return true;
}