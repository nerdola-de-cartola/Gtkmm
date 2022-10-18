#include <gtkmm.h>

//Tree model columns:
class ModelColumns : public Gtk::TreeModel::ColumnRecord {
public:
   Gtk::TreeModelColumn<Gtk::PositionType> m_col_position_type;
   Gtk::TreeModelColumn<Glib::ustring> m_col_title;
   
public:
   ModelColumns();
};