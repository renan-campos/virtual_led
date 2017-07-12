import dbus.glib # This import is needed for main loop to work. (Is this a bug?)
import dbus
import gobject

SERVICE = "com.example.virtled"
OBJECT  = "/com/example/virtled/Manager"
IFACE   = "com.example.virtled.Manager"

bus = dbus.SystemBus()

def led_status(*args, **kwargs):

  led = bus.get_object(SERVICE, OBJECT)

  props_iface = dbus.Interface(led, 'org.freedesktop.DBus.Properties')
  properties = props_iface.GetAll(IFACE)

  print "*** LED STATE: ***"
  for k,v in properties.iteritems():
    print "%s: %s" % (k,v)
  print

if __name__ == '__main__':
  loop = gobject.MainLoop()
  led_status()
  bus.add_signal_receiver(led_status,
                          dbus_interface=IFACE,
                          signal_name='StateChange')
  loop.run()
