#if !defined(PARSELO_LAYOUTS_PREFERENCES_HH)
#define PARSELO_LAYOUTS_PREFERENCES_HH

#include <gtkmm/frame.h>
#include <gtkmm/label.h>

namespace parselo
{
  class Preferences : public Gtk::Frame
  {
  public:
    Preferences ();
    virtual ~Preferences ();

  protected:
    Gtk::Label m_Label;
  };

} // namespace parselo

#endif // PARSELO_LAYOUTS_PREFERENCES_HH
