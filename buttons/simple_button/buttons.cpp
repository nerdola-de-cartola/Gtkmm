#include "buttons.hpp"
#include <iostream>

Buttons::Buttons() {
  m_button.add_pixlabel("info.xpm", "cool button");
  m_button.set_alignment(0, 0);

  set_default_size(900, 720);
  set_title("Pixmap'd buttons!");
  set_border_width(200);

  m_button.signal_clicked().connect( sigc::mem_fun(*this,
    &Buttons::on_button_clicked) );

  add(m_button);

  show_all_children();
}

Buttons::~Buttons()
{
}

void Buttons::on_button_clicked() {
  std::cout << "The Button was clicked." << std::endl;
}