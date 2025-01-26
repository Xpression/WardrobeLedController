# WardrobeLedController
A project for controlling LED strips in sliding door wardrobes. Using Arduino Nano, cheap LED strips, and magnetic reed switches to turn lights on when doors are open.

# BOM
1x Arduino Nano - programmed with sketch included in repo

1x 470 Ohm resistor

1z 1000uF electrolytic capacitor

1x LED strip with WS2811 chipset (others should work but will require sketch to be changed)

1x Box housing (3d printed, STL included in repo)

1x Box lid (3d printed, STL included in repo)

1x 12V DC power supply

1x DC Power jack

Nx reed switches, N == the number of doors in the wardrobe.

Nx Elfa Vista magnetic reed switch brackets (3d printed, STL included in repo), N == the number of doors in the wardrobe.

Misc suitable wires and heat shrink.



The number of doors (i.e., magnetic reed switches) to use is configurable in the Arduino sketch. By default, magnetic switches are wired from pin 5 and out consequtively. Pin 4 is used to control the LED strip.
