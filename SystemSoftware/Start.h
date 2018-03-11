#ifndef GTKMM_START_H
#define GTKMM_START_H

#include "Attr.h"

#include <gtkmm.h>

class Start : public Gtk::Window
{
public:
	Start();
  virtual ~Start();

private:
  // Signal handlers:
	void on_button_clicked();
	void on_assistant_apply();
  // Child widgets:
	Gtk::Button m_button;
	Gtk::Label m_label1, m_label2;
	Gtk::Box m_boxv;
	Attributes a;
    	Asif m_assistant;
};

#endif /* GTKMM_EXAMPLEWINDOW_H */
