#include "text.hpp"

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

  const int rectangle_width = width;
  const int rectangle_height = height / 2;

  // Draw a black rectangle
  cr->set_source_rgb(0.0, 0.0, 0.0);
  draw_rectangle(cr, rectangle_width, rectangle_height);

  // and some white text
  cr->set_source_rgb(1.0, 1.0, 1.0);
  draw_text(cr, rectangle_width, rectangle_height);

  // flip the image vertically
  // see http://www.cairographics.org/documentation/cairomm/reference/classCairo_1_1Matrix.html
  // the -1 corresponds to the yy part (the flipping part)
  // the height part is a translation (we could have just called cr->translate(0, height) instead)
  // it's height and not height / 2, since we want this to be on the second part of our drawing
  // (otherwise, it would draw over the previous part)
  Cairo::Matrix matrix(1.0, 0.0, 0.0, -1.0, 0.0, height);

  // apply the matrix
  cr->transform(matrix);

  // white rectangle
  cr->set_source_rgb(1.0, 1.0, 1.0);
  draw_rectangle(cr, rectangle_width, rectangle_height);

  // black text
  cr->set_source_rgb(0.0, 0.0, 0.0);
  draw_text(cr, rectangle_width, rectangle_height);

  return true;
}

void MyArea::draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  cr->rectangle(0, 0, width, height);
  cr->fill();
}

void MyArea::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height)
{
  // http://developer.gnome.org/pangomm/unstable/classPango_1_1FontDescription.html
  Pango::FontDescription font;

  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);

  // http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
  auto layout = create_pango_layout("Hi there!");

  layout->set_font_description(font);

  int text_width;
  int text_height;

  //get the text dimensions (it updates the variables -- by reference)
  layout->get_pixel_size(text_width, text_height);

  // Position the text in the middle
  cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);

  layout->show_in_cairo_context(cr);
}