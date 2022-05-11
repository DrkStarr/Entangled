! ---------------------------------------------------------------------------- !
!       SHED. 02/02/18
!
  Room    shed "Shed"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = false;
              "This simple structure protects a lawnmower, a BMX, and some spare parts from the weather.
              In the corner are some gardening tools, forgotten and rusted.
              The door out is east.";
          ],
          e_to [;
              <<Enter shedDoor>>;
          ],
          cant_go [;
              "You can go east out the door.";
          ],
          before [;
              Exit:
                  <<Enter shedDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "You take a moment and listen. No one is outside.";
              Smell:
                  "Breathing in, you can tell the air is moldy.";
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          removeSparkPlug false;

! 02/02/18

  RoomObj -> shedObj "shed"
    with  name 'shed' 'building' 'place' 'area',
          description [;
              <<Look shed>>;
          ],
          before [;
              Search:
                  "You look around the shed, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Enter, Go:
                  <<Enter shedDoor>>;
              Open:
                  "That's already open.";
              Close:
                  "You don't need to do that.";
          ];

! 02/02/18

  Object  -> shedDoor "door"
    with  name 'door' 'trailer' 'park',
          before [;
              Close:
                  "You don't need to do that.";
              Enter, Go, Open:
                  PlayerTo(trailerPark);
                  rtrue;
              Examine, Search:
                  "The door leads back to the trailer park.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the shed.";
          ],
     has  concealed static open;

! 02/02/18

  Object  -> shedLawnMower "lawnmower"
    with  name 'lawnmower' 'mower' 'cylinder' 'cover',
          before [;
              Close:
                  "You might be able to close the cover, but there's no reason to fix it.";
              Open:
                  "The cover to the mower is already open.";
              Examine, Search:
                  "It's a small push mower that's being worked on. The cover is off and the spark plug is gone.";
              Fix:
                  "You don't need to. So you leave the mower alone.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The lawnmower isn't even working. It doesn't need to go anywhere.";
              SwitchOn, SwitchOff:
                  "The mower's being worked on. It won't operate.";
          ],
     has  concealed static container open;

! 05/14/18

  Object  -> shedBike "bmx"
    with  name 'bike' 'silver' 'bmx' 'chain',
          before [;
              Examine, Search:
                  "It's a BMX bike. Chain driven. It's smaller than a ten-speed and has no gears.";
              Take:
                  "The bike is in good shape, but there is no reason to tow it around.";
              Ride:
                  "It would be too uncomfortable. The bike is small, made for a young teen.";
              Remove, Turn, PushDir, Push, Pull:
                  "The bike doesn't need to go anywhere.";
          ],
     has  concealed static;

! 05/14/18

  Object  -> shedTools "tools"
    with  name 'tool' 'tools' 'simple' 'gardening',
          before [;
              Examine, Search:
                  "They're simple tools left behind to rust in the shed. Whoever used them must have forgotten they're here.";
              Take:
                  "The tools are in poor condition. There's no reason to take them.";
              Remove, Turn, PushDir, Push, Pull:
                  "The tools don't need to go anywhere.";
          ],
     has  concealed static pluralname;

! 02/02/18

  Object  -> shedShelf "shelf"
    with  name 'shelf',
          before [;
              Examine:
                  if (sparkPlugMower in self) "On the shelf are some spare parts and a nickel spark plug.";
                  "On the shelf are some spare parts.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The shelf doesn't need to go anywhere.";
          ],
     has  concealed static supporter;

! 02/02/18

  Object  shedParts "spare parts"
    with  name 'spare' 'part' 'parts' 'nut' 'nuts' 'bolt' 'bolts' 'pile',
          before [;
              Examine, Search:
                  if (sparkPlugMower in shedShelf)
                      "A spark plug sits in the middle of some leftover nuts and bolts on the shelf.";
                  "There are some leftover nuts and bolts on the shelf.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The spare parts don't need to go anywhere.";
          ],
     has  static pluralname;
