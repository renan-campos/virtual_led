busctl introspect com.example.virtled /com/example/virtled/Manager
busctl get-property com.example.virtled /com/example/virtled/Manager com.example.virtled.Manager State
busctl call com.example.virtled /com/example/virtled/Manager com.example.virtled.Manager SetState s "com.example.virtled.Manager.Action.On"
busctl get-property com.example.virtled /com/example/virtled/Manager com.example.virtled.Manager State
busctl call com.example.virtled /com/example/virtled/Manager com.example.virtled.Manager SetState s "com.example.virtled.Manager.Action.Blink"
busctl get-property com.example.virtled /com/example/virtled/Manager com.example.virtled.Manager State
busctl call com.example.virtled /com/example/virtled/Manager com.example.virtled.Manager SetState s "com.example.virtled.Manager.Action.Off"
