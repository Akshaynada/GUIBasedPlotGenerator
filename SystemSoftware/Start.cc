#include "Start.h"
#include "Attr.h"
#include "Attr.cc"

Start::Start()
: m_button("Start"),
  m_boxv(Gtk::ORIENTATION_VERTICAL,25)
{
  set_title("RAPA Graph Editor");
  set_border_width(2);
  set_default_size(600,400);
  set_position(Gtk::WIN_POS_CENTER);
  Gtk::Separator Sep;

  m_button.set_border_width(70);  

  m_label1.set_markup("<u><b> System Software Project </b></u>\n\n");
  m_label2.set_markup("<b> RAPA Graph Editor </b>");
  
  m_boxv.pack_start(m_label1);
  m_boxv.pack_start(Sep);
  m_boxv.pack_start(m_label2);
  m_boxv.pack_start(m_button);
  
  add(m_boxv);

  m_button.signal_clicked().connect(sigc::mem_fun(*this,
    &Start::on_button_clicked));
  
  m_assistant.signal_apply().connect(sigc::mem_fun(*this,
    &Start::on_assistant_apply));

  show_all_children();
}

Start::~Start()
{

}

void Start::on_button_clicked()
{
  m_assistant.show();
}

void Start::on_assistant_apply()
{
	hide();
	cout<<"Start Closing"<<endl;
	cout<<"Attributes and file is copying.... "<<endl;
	bool check_state;
	a=m_assistant.getattributes();
	a.Store();
	a.CopyFile();
}
