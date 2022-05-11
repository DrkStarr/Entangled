! Like the rest of the upstairs it seems abandoned.
! ---------------------------------------------------------------------------- !
!       LIVING ROOM. 12/16/16
!
  Room    livingRoom "Living Room"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = false;
              print "A pillow sits in the corner on top of an old phonebook
              with other pieces of junk scattered around the room - the front
              door's nailed shut. ";
              if (livingRoomWindow.settingSun) {
                  print "The setting sun shines through a boarded-up window barely illuminating";
              } else {
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || SelfPlayer.earlyEvening) print "The light coming in from the boarded-up window barely illuminates";
                  else print "Sunlight tries to come through a boarded-up window and illuminates";
              }
              " the room. You can go south back to the hallway.";
          ],
          s_to [;
              <<Enter livingRoomBasement>>;
          ],
          cant_go [;
              "You can go south to the hallway.";
          ],
          before [;
              Exit:
                  <<Enter livingRoomBasement>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "The house is quiet but has an electrical hum of its own.";
              Smell:
                  "The place smells musty as you take mold into your lungs.";
              Sleep:
                  return roomSleep();
                  !if (iAMPM == 0) "You have too much to do even though it's getting late.";
                  !"You have too much to do, and it's too early to sleep.";
          ],
          firstTime true,
          lookFirstTime true;

! 12/16/16

  RoomObj -> livingRoomObj "room"
    with  name 'room' 'area' 'house' 'home' 'place',
          description [;
              <<Look livingRoom>>;
          ],
          before [;
              Search:
                  "You look around the room, pushing around some of the junk but finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 12/16/16

  Object  -> livingRoomDoor "door"
    with  name 'front' 'door' 'doorway' 'nail' 'nails' 'wood' 'frame' 'metal' 'rot',
          before [;
              Attack, Kick:
                  "Be careful. It's old and rotted, and you could put your foot through it.";
              Close:
                  "The door's already closed. It's nailed shut.";
              Enter, Open, Go, Turn, PushDir, Push, Pull:
                  "The door's nailed shut.";
              Examine, Search:
                  "The wood is old, having rotted over time, though metal sticks through the frame and wood splinters away with the door nailed shut.";
              Take, Remove:
                  "You can't do that. It's part of the house.";
          ],
      has concealed static openable ~open;

! 12/19/16

  Object  -> livingRoomWindow "window"
    with  name 'light' 'window' 'sun' 'sky' 'boarded-up' 'boarded',
          before [;
              Open, Close, Turn, PushDir, Push, Pull, Take, Remove:
                  "The window is boarded up. You can't do that.";
              Examine, Search:
                  if (self.settingSun) "Through a boarded-up window, you catch the last rays of the sun burning across the sky.";
                  if (SelfPlayer.eveningTime) "Through a boarded-up window, the entire sky is burnt orange.";
                  if (SelfPlayer.earlyEvening) "Through a boarded-up window, the entire sky is a dark shade of purple.";
                  if (SelfPlayer.nightTime)
                      "Through a boarded-up window, the sky is black as midnight. A bit of light does make it
                      into the room. There must be a lamp post outside.";
                  "Through a boarded-up window, the sun comes in lighting the room.";
          ],
          settingSun true,
    has   concealed static openable ~open;

! 12/19/16

  OutRch  -> livingRoomBasement "hallway"
    with  name 'hallway' 'hall',
          before [;
              Enter, Go:
                  PlayerTo(hallwayHouse);
                  rtrue;
              Examine:
                  if (livingRoomWindow.settingSun) "Light comes in from the hallway even though the setting sun shines through the window.";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || SelfPlayer.earlyEvening) "Light is coming in from the hallway.";
                  "Sunlight through the window is lighting the room, but a bit of light can be seen in the hallway.";
          ];

! 05/15/18

  Object  -> livingRoomPhoneBook "phonebook"
    with  name 'phonebook' 'book' 'old',
          before [;
              Examine, Search:
                  "Underneath the pillow, you see the book is for the northeast part of the county and it's old. The spine says July 1977 - 1978.";
              Open, Take, Remove, Read, Consult:
                  "The book is old and the information is worthless.";
              Close, Turn, PushDir, Push, Pull:
                  "You don't need to do that.";
          ],
    has   concealed static openable ~open;

! 10/24/18

  Object  -> livingRoomBoards "boards"
    with  name 'board' 'boards',
          before [;
              Examine, Search:
                  "Boards cover the window, arranged in random order, and made out of different types of wood.";
              Take, Remove, Pull:
                  "You tug on them for a bit, but flesh gives way to wood. They won't budge.";
              PushDir, Push, Turn:
                  "You try to push them. They won't budge.";
          ],
     has  concealed static pluralname;

! 03/05/19

  Object  -> livingRoomJunk "junk"
    with  name 'junk' 'wrapper' 'wrappers' 'beer' 'bottle' 'bottles',
          before [;
              Examine, Search:
                  "The junk consists mostly of old wrappers along with a few empty beer bottles.";
              Take, Remove, Pull:
                  "It's all worthless. You don't need any of it.";
              Kick:
                  "You kick at one of them, connecting with a wrapper that bounces off the wall.";
              PushDir, Push, Turn:
                  "You push one of them around a bit. Nothing comes of it.";
          ],
     has  concealed static;

! 03/05/19

  Object  -> livingRoomPillow "pillow"
    with  name 'pillow' 'cushion' 'pad' 'headrest' 'dirt' 'dirty',
          before [;
              Examine, Search:
                  "A pillow has been tucked away, placed on top of the old phonebook.
                  It's missing a cover. The dirt is worn in.";
              Take, Remove, Pull:
                  "It's used and dirty. You don't need it.";
              Kick:
                  "You think about it, but there's no need to add to the dirt.";
              PushDir, Push, Turn:
                  "There's no need to do that.";
              Rub:
                  "You're not going to be able to clean it. The dirt's rub in. It's permanently stained.";
          ],
     has  concealed static;
