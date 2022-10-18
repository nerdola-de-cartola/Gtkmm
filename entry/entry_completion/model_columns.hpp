#include <gtkmm.h>

//Tree model columns, for the EntryCompletion's filter model:
class ModelColumns : public Gtk::TreeModel::ColumnRecord {
  public:
    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;

  public:
    ModelColumns();
};
