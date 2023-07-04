#if !defined(PARSELO_LAYOUTS_INQUIRY_HH)
#define PARSELO_LAYOUTS_INQUIRY_HH

#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>

namespace parselo
{
  class Inquiry : public Gtk::Frame
  {
  public:
    Inquiry ();
    virtual ~Inquiry ();

  protected:
    Gtk::Label m_Label;
  };

} // namespace parselo

#endif // PARSELO_LAYOUTS_INQUIRY_HH
