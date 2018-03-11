#include <iostream>

using namespace std;

#include "Attr.h"

Asif::Asif()
: m_boxh1(Gtk::ORIENTATION_HORIZONTAL,10),
  m_boxh2(Gtk::ORIENTATION_HORIZONTAL,10),
  m_boxv1(Gtk::ORIENTATION_VERTICAL,12),

  m1_boxh1(Gtk::ORIENTATION_HORIZONTAL, 18),
  m1_boxh2(Gtk::ORIENTATION_HORIZONTAL, 18),
  m1_boxh3(Gtk::ORIENTATION_HORIZONTAL, 18),
  m1_boxh4(Gtk::ORIENTATION_HORIZONTAL, 18),
  m1_boxh5(Gtk::ORIENTATION_HORIZONTAL, 18),
  m1_boxv2(Gtk::ORIENTATION_VERTICAL,18),

  m2_boxv3(Gtk::ORIENTATION_VERTICAL,22),
  m2_boxh1(Gtk::ORIENTATION_HORIZONTAL,30),
  m2_boxh2(Gtk::ORIENTATION_HORIZONTAL,8),

  IconA("/home/asif/SystemSoftware/table.gif"),

  m_label1("Type File Path: "),
  m_label4("Select Chart Type: "),
  m_label10("To"),
  m_label11("To")
{
  set_title("RAPA Graph Editor");
  set_border_width(8);
  set_default_size(600, 400);
  set_position(Gtk::WIN_POS_CENTER);

  m_label6.set_markup("<b>Title    : </b>"),
  m_label2.set_markup("<b>X-Range: </b>");
  m_label3.set_markup("<b>Y-Range: </b>");
  m_label7.set_markup("<b>X-Label: </b>");
  m_label8.set_markup("<b>Y-Label: </b>");

  m_label5.set_markup("Click <b> Continue </b> to Proceed ");
  
  type1.add_pixlabel("/home/asif/SystemSoftware/Bar.jpeg","");
  type2.add_pixlabel("/home/asif/SystemSoftware/Pie.jpeg","");
  type3.add_pixlabel("/home/asif/SystemSoftware/Line.jpeg","");

  type1.set_border_width(6);
  type2.set_border_width(6);
  type3.set_border_width(6);

//Grouping radio buttons
  Gtk::RadioButton::Group G= type1.get_group();
  type2.set_group(G);
  type3.set_group(G);

  type3.set_active(true);
  type2.set_active(true);
  type1.set_active(true);

//Setting wrap on spinbutton
	xrange0.set_digits(2);
	xrange0.set_increments(10.0,100.0);
	xrange0.set_range(-1000000.0,1000000.0);
	xrange0.set_value(100.0);
	xrange0.set_numeric(true);

	yrange0.set_digits(2);
	yrange0.set_increments(10.0,100.0);
	yrange0.set_range(-1000000.0,1000000.0);
	yrange0.set_value(100.0);
	yrange0.set_numeric(true);

  xrange0.set_wrap();
  xrange1.set_wrap();
  yrange0.set_wrap();
  yrange1.set_wrap();

//Box 1 asking Chart Type
  m_boxh1.pack_start(type1,Gtk::PACK_SHRINK);
  m_boxh1.pack_start(type2,Gtk::PACK_SHRINK);
  m_boxh1.pack_start(type3,Gtk::PACK_SHRINK);
//Select Type Chart on click
  type1.signal_clicked().connect(sigc::mem_fun(*this,
    &Asif::select_type1));
  type2.signal_clicked().connect(sigc::mem_fun(*this,
    &Asif::select_type2));
  type3.signal_clicked().connect(sigc::mem_fun(*this,
    &Asif::select_type3));

//Box 2 asking File name
  m_label1.set_justify(Gtk::JUSTIFY_LEFT);
  m_boxh2.pack_start(m_label1,Gtk::PACK_SHRINK);
  m_boxh2.pack_start(FileName);
  FileName.signal_changed().connect(sigc::mem_fun(*this,
    &Asif::on_entry_changed));
  m_boxh2.pack_start(IconA,Gtk::PACK_SHRINK);

//Main Packing of Box in Window 1
  m_label4.set_justify(Gtk::JUSTIFY_LEFT);
  m_label4.set_line_wrap();
  m_boxv1.pack_start(m_label4);

  m_boxv1.pack_start(m_boxh1);
  m_boxv1.pack_start(Sep1);
  m_boxv1.pack_start(m_boxh2);
  m_boxv1.pack_start(Sep2);

  m_label5.set_justify(Gtk::JUSTIFY_LEFT);
  m_boxv1.pack_start(m_label5);

//Box 1 asking Title in window 2
  m_label6.set_alignment(0.0,0.5);
  m1_boxh1.pack_start(m_label6,Gtk::PACK_SHRINK);
  m1_boxh1.pack_start(Title);
  Title.signal_changed().connect(sigc::mem_fun(*this,
    &Asif::on_title));

//Box 2 asking x  label in window 2
  m_label7.set_alignment(0.0,0.5);
  m1_boxh2.pack_start(m_label7,Gtk::PACK_SHRINK);
  m1_boxh2.pack_start(xlabel);
  xlabel.signal_changed().connect(sigc::mem_fun(*this,
    &Asif::on_xlabel));

//Box 3 asking y label
  m_label8.set_alignment(0.0,0.5);
  m1_boxh3.pack_start(m_label8,Gtk::PACK_SHRINK);
  m1_boxh3.pack_start(ylabel);
  ylabel.signal_changed().connect(sigc::mem_fun(*this,
    &Asif::on_ylabel));

//Box 4 x range
  m_label2.set_alignment(0.0,0.5);
  m1_boxh4.pack_start(m_label2,Gtk::PACK_SHRINK);
  m1_boxh4.pack_start(xrange0);
  xrange0.signal_value_changed().connect(sigc::mem_fun(*this,
	&Asif::on_xrange0));		//Just for time being
  m1_boxh4.pack_start(m_label10,Gtk::PACK_SHRINK); 
  m1_boxh4.pack_start(xrange1);
  xrange1.signal_value_changed().connect(sigc::mem_fun(*this,
	&Asif::on_xrange1));		//Just for time being 

//Box 5 y range
  m1_boxh5.pack_start(m_label3,Gtk::PACK_SHRINK);
  m1_boxh5.pack_start(yrange0);
  yrange0.signal_value_changed().connect(sigc::mem_fun(*this,
	&Asif::on_yrange0));		//Just for time being 
  m1_boxh5.pack_start(m_label11,Gtk::PACK_SHRINK); 
  m1_boxh5.pack_start(yrange1);
  yrange1.signal_value_changed().connect(sigc::mem_fun(*this,
	&Asif::on_yrange1));		//Just for time being 

//Main Packing of Box in Window 2
  m1_boxv2.pack_start(m1_boxh1);
  m1_boxv2.pack_start(Sep3);
  m1_boxv2.pack_start(m1_boxh2);
  m1_boxv2.pack_start(m1_boxh3);
  m1_boxv2.pack_start(Sep4);
  m1_boxv2.pack_start(m1_boxh4);
  m1_boxv2.pack_start(m1_boxh5);

//page 3

  m_label12.set_markup("<u><b>Attributes To Be Sent:</b></u>");
  m_label12.set_alignment(0.0,0.0);
  m_label13.set_markup("\n\n<b>Type\t\t:</b>\t Bar Chart");
  m_label13.set_alignment(0.0,0.0);

  m2_boxv3.pack_start(m_label12,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label13,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label14,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label15,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label16,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label19,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label17,Gtk::PACK_SHRINK);
  m2_boxv3.pack_start(m_label18,Gtk::PACK_SHRINK);

  m2_boxh1.pack_start(m2_boxv3);

//Appending Pages
  append_page(m_boxv1);
  append_page(m1_boxv2);
  append_page(m2_boxh1);

  set_page_title(*get_nth_page(0), "Chart Type and File Path");
  set_page_title(*get_nth_page(1), "Attributes");
  set_page_title(*get_nth_page(2), "Confirmation");

  set_page_complete(m1_boxv2, true);
  set_page_complete(m2_boxh1, true);

  set_page_type(m_boxv1, Gtk::ASSISTANT_PAGE_INTRO);
  set_page_type(m2_boxh1, Gtk::ASSISTANT_PAGE_CONFIRM);

  signal_apply().connect(sigc::mem_fun(*this,
    &Asif::on_assistant_apply));
  signal_cancel().connect(sigc::mem_fun(*this,
    &Asif::on_assistant_cancel));
  signal_close().connect(sigc::mem_fun(*this,
    &Asif::on_assistant_close));
  signal_prepare().connect(sigc::mem_fun(*this,
    &Asif::on_assistant_prepare));
  
//functions  

  show_all_children();
}

Asif::~Asif()
{
}

Attributes Asif::getattributes()
{
	return a;
}

void Asif::get_result()
{
  
}

void Asif::on_title()
{
	char temp[40];
	strcpy(temp,(Title.get_text()).c_str());
	a.ReadTitle(temp);
	m_label14.set_markup(Glib::ustring::compose("<b>Title\t  :</b>\t %1",temp));

  m_label14.set_alignment(0.0,0.0);
}

void Asif::on_xlabel()
{
	char temp[40];
	strcpy(temp,(xlabel.get_text()).c_str());
	a.ReadLabelX(temp);
	m_label15.set_markup(Glib::ustring::compose("<b>X Label\t  :</b>\t %1",temp));
  m_label15.set_alignment(0.0,0.0);
}

void Asif::on_ylabel()
{
	char temp[40];
	strcpy(temp,(ylabel.get_text()).c_str());
	a.ReadLabelY(temp);
	a.ShowLabels();
	m_label16.set_markup(Glib::ustring::compose("<b>Y Label\t  :</b>\t %1",temp));
  m_label16.set_alignment(0.0,0.0);
}

void Asif::select_type1()
{
	bool state3=type1.get_active();
	if(state3)
	std::cout<<"Type: "<<a.SelectType(1)<<endl;
	xrange0.set_sensitive(true);
	xrange1.set_sensitive(true);
	yrange0.set_sensitive(true);
	yrange1.set_sensitive(true);
	m_label13.set_markup("\n\n<b>Type\t\t:</b>\t Bar Chart");
  m_label13.set_alignment(0.0,0.0);
}

void Asif::select_type2()
{
	bool state1=type2.get_active();
	if(state1)
	std::cout<<"Type: "<<a.SelectType(2)<<endl;
	xrange0.set_sensitive(false);
	xrange1.set_sensitive(false);
	yrange0.set_sensitive(false);
	yrange1.set_sensitive(false);
	m_label13.set_markup("\n\n<b>Type\t\t:</b>\t Pie Chart");
  m_label13.set_alignment(0.0,0.0);
}

void Asif::select_type3()
{
	bool state2=type3.get_active();
	if(state2)
	std::cout<<"Type: "<<a.SelectType(3)<<endl;
	xrange0.set_sensitive(true);
	xrange1.set_sensitive(true);
	yrange0.set_sensitive(true);
	yrange1.set_sensitive(true);
	m_label13.set_markup("\n\n<b>Type\t\t:</b>\t Line Chart");
  m_label13.set_alignment(0.0,0.0);
}

void Asif::on_assistant_apply()
{
  std::cout << "Apply was clicked";
  get_result();
hide();
}

void Asif::on_assistant_cancel()
{
//  std::cout << "Cancel was clicked";
  hide();
}

void Asif::on_assistant_close()
{
//  std::cout << "Assistant was closed";
  hide();
}

 void Asif::on_assistant_prepare(Gtk::Widget* /* widget */)
{
  set_title(Glib::ustring::compose("RAPA Graph Editor (Page %1 of %2)",
    get_current_page() + 1, get_n_pages()));
} 

void Asif::on_entry_changed()
{
  char temp[40];
  strcpy(temp,(FileName.get_text()).c_str());
  state=a.ReadFile(temp);
  if(state)
  {
	std::cout<<"File Path: "<<a.ShowFile()<<endl;
	set_page_complete(m_boxv1, true); 
	m_label19.set_markup(Glib::ustring::compose("<b>File Path  :</b>\t %1",temp));
  m_label19.set_alignment(0.0,0.0);
  }
  else
  {
    set_page_complete(m_boxv1, false);
  }
}

void Asif::on_xrange0()
{
  double x1=xrange0.get_value_as_int( );
	xrange1.set_digits(2);
	xrange1.set_increments(10.0,100.0);
	xrange1.set_range(x1,1000000.0);
	xrange1.set_value(x1+100.0);
	xrange1.set_numeric(true);
  a.ReadX1(x1);
}

void Asif::on_xrange1()
{
  double x2=xrange1.get_value_as_int( );
  a.ReadX2(x2);
  m_label17.set_markup(Glib::ustring::compose("<b>X Range\t  :</b>\t %1 to %2",
    xrange0.get_value_as_int(),xrange1.get_value_as_int()));
  m_label17.set_alignment(0.0,0.0);
}

void Asif::on_yrange0()
{
  double y1=yrange0.get_value_as_int( );
	yrange1.set_digits(2);
	yrange1.set_increments(10.0,100.0);
	yrange1.set_range(y1,1000000.0);
	yrange1.set_value(y1+100.0);
	yrange1.set_numeric(true);
  a.ReadY1(y1);
}

void Asif::on_yrange1()
{
  double y2=yrange1.get_value_as_int( );
  a.ReadY2(y2);
  m_label18.set_markup(Glib::ustring::compose("<b>Y Range\t  :</b>\t %1 to %2",
    yrange0.get_value_as_int(),yrange1.get_value_as_int()));
  m_label18.set_alignment(0.0,0.0);
}
