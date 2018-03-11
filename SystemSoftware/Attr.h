#ifndef GTKMM_ATTR_H
#define GTKMM_ATTR_H

#include <gtkmm.h>
#include "Attributes.cc"

class Asif : public Gtk::Assistant
{
public:
	Asif();
  virtual ~Asif();

  void get_result();
  void select_type1();
  void select_type2();
  void select_type3();
  Attributes getattributes();

private:
  // Signal handlers:
  void on_assistant_apply();
  void on_assistant_cancel();
  void on_assistant_close();
  void on_assistant_prepare(Gtk::Widget* widget);
  void on_entry_changed();
  void on_title();
  void on_xlabel();
  void on_ylabel();
  void on_xrange0();
  void on_yrange0();
  void on_xrange1();
  void on_yrange1();

  // Member functions:
  static bool state;

  // Child widgets:
  Gtk::Box m_boxh1,m_boxh2,m_boxv1;
  Gtk::Box m1_boxh1,m1_boxh2,m1_boxh3,m1_boxh4,m1_boxh5,m1_boxv2;
  Gtk::Box m2_boxv3,m2_boxh1,m2_boxh2;
 
  Gtk::Separator Sep1,Sep2,Sep3,Sep4;

  Gtk::Label m_label1, m_label2,m_label3,m_label4,m_label5,m_label6;
  Gtk::Label m_label7,m_label8,m_label9,m_label10,m_label11,m_label12;
  Gtk::Label m_label13,m_label14,m_label15,m_label16,m_label17,m_label18;
  Gtk::Label m_label19,m_label20;

  Gtk::Entry FileName,Title,xlabel,ylabel;
  Gtk::SpinButton xrange0,xrange1,yrange0,yrange1;
  Gtk::RadioButton type1,type2,type3;
  Gtk::Image IconA;

  Attributes a;
};
bool Asif::state;
#endif /* GTKMM_EXAMPLEASSISTANT_H */


