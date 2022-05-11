
! ---------------------------------------------------------------------------- !
!       HALLWAY. 6/5/17
!
  Room    hallwayHouse "Hallway"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = false;
              "This hallway is short and small, like the rest of the house. To the north, the
              living room. South the kitchen. West the rest of the place. With the door to the
              basement removed, the light comes up from below.";
          ],
          n_to [;
              <<Enter hallwayLivingRoom>>;
          ],
          s_to [;
              <<Enter hallwayKitchen>>;
          ],
          d_to [;
              <<Enter hallwayBasement>>;
          ],
          cant_go [;
              "You can go north to the living room. South to the kitchen or down into the basement.
              The rest of the house that is west is dark and uninviting.";
          ],
          before [;
              Exit:
                  <<Enter hallwayKitchen>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "The house is quiet but has an electrical hum of its own.";
              Smell:
                  "The place smells musty as you take mold into your lungs.";
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          lookFirstTime true;

! 6/5/17

  RoomObj -> hallwayRoomObj "hallway"
    with  name 'area' 'hallway' 'house' 'home' 'place',
          description [;
              <<Look hallwayHouse>>;
          ],
          before [;
              Search:
                  "You look around the hallway finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 6/5/17

  Object  -> hallwayDoor "doorway"
    with  name 'door' 'doorway',
          before [;
              Enter:
                  <<Enter hallwayBasement>>;
              Examine, Search, Close, Open:
                  "There are no doors, just doorways. All the doors have been removed.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the house.";
              Knock:
                  if (basement.firstTime) "You knock on it, trying to get someone's attention, but no one comes up from the basement.";
                  rfalse;
          ],
      has concealed static openable ~open;

! 6/5/17

  OutRch  -> hallwayLivingRoom "living room"
    with  name 'living' 'room',
          before [;
              Enter:
                  PlayerTo(livingRoom);
                  rtrue;
              Examine, Search, Close, Open:
                  "The door to the living room has been removed, leaving an opening between the rooms.";
          ];

! 6/5/17

  OutRch  -> hallwayKitchen "kitchen"
    with  name 'kitchen',
          before [;
              Enter:
                  PlayerTo(kitchenHouse);
                  rtrue;
              Examine, Search, Close, Open:
                  "The door to the kitchen has been removed, leaving an opening between the rooms.";
          ];

! 6/5/17

  OutRch  -> hallwayBasement "basement"
    with  name 'basement' 'cellar' 'light',
          before [;
              Enter:
                  PlayerTo(basement);
                  rtrue;
              Examine, Search:
                  print "Through the doorway, the light comes up from the basement";
                  if (basement.firstTime) " - a pulsating, living sort of thing.";
                  ".";
          ];
