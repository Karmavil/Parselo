#if !defined(PARSELO_LAYOUTS_ABOUT_HH)
#define PARSELO_LAYOUTS_ABOUT_HH

#include <gtkmm/frame.h>
#include <gtkmm/label.h>

namespace parselo
{
  class About : public Gtk::Frame
  {
  public:
    About ();
    virtual ~About ();

  protected:
    Gtk::Label m_Label;
  };

} // namespace parselo

#endif // PARSELO_LAYOUTS_ABOUT_HH
