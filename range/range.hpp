#ifndef GTKMM_EXAMPLE_RANGEWIDGETS_H
#define GTKMM_EXAMPLE_RANGEWIDGETS_H

#include <gtkmm.h>
#include "model_columns.hpp"

class ExampleWindow : public Gtk::Window {
protected:
  //Child widgets:
  Gtk::Box m_VBox_Top, m_VBox2, m_VBox_HScale;
  Gtk::Box m_HBox_Scales, m_HBox_Combo, m_HBox_Digits, m_HBox_PageSize;

  Glib::RefPtr<Gtk::Adjustment> m_adjustment, m_adjustment_digits, m_adjustment_pagesize;

  Gtk::Scale m_VScale;
  Gtk::Scale m_HScale, m_Scale_Digits, m_Scale_PageSize;

  Gtk::Separator m_Separator;

  Gtk::CheckButton m_Check_Button;

  Gtk::Scrollbar m_Scrollbar;

  ModelColumns m_Columns;

  //Child widgets:
  Gtk::ComboBox m_ComboBox_Position;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  Gtk::Button m_Button_Quit;

public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_check_button_toggled();
  void on_combo_position();
  void on_adjustment1_value_changed();
  void on_adjustment2_value_changed();
  void on_button_quit();
};

#endif //GTKMM_EXAMPLE_RANGEWIDGETS_H