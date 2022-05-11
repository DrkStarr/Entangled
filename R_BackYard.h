
! ---------------------------------------------------------------------------- !
!       BACK YARD. 08/16/16
!
  Room    backYard "Back Yard"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              print "Paint peels away from the house like dry, flaky skin falling off a dead
              body. The windows are boarded up. There's also a bit of light coming
              from inside - through the backdoor that's ";
              if (basement.firstTime) print "cracked ";
              "open to the north. The bowling alley lies southeast.";
          ],
          n_to [;
              <<Enter backYardDoor>>;
          ],
          se_to [;
              if (basement.firstTime) "There's something about this building. You can't explain it. The thing has a hold on you, drawing you inside.";
              <<Enter backYardBowlingAlley>>;
          ],
          u_to [;
              <<Climb backYardHouse>>;
          ],
          cant_go [;
              if (basement.firstTime) "There's something about this building. You can't explain it. The thing has a hold on you, drawing you inside.";
              "You can go southeast to the bowling alley or north into the house.";
          ],
          before [;
              Exit:

              GoIn:
                  <<Enter backYardDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
        ],
        firstTime true;

! 08/16/16

  RoomObj -> backYardObj "yard"
    with  name 'back' 'yard' 'lawn' 'area',
          description [;
              <<Look backYard>>;
          ],
          before [;
              Search:
                  "You look around the yard a bit, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 12/16/16

  Object  -> backYardHouse "house"
    with  name 'brick' 'house' 'home' 'building' 'paint' 'wood' 'brick' 'rot' 'rotting',
          before [;
              Climb:
                  "I wouldn't try that. The wood has rotted, and the roof could collapse.";
              Enter, Go:
                  <<Enter backYardDoor>>;
              Search:
                  "There's a bit of light coming from inside the house.";
              Examine:
                  "The sun has beaten on this house for ages. The wood rotting away. Though the brick is solid and the foundation strong. But out here on the edge of town, it looks abandoned with all the windows boarded up.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The house is falling apart. You don't need to help it.";
              Knock:
                  <<Knock backYardDoor>>;
          ],
     has  concealed static;

! 12/16/16

  Object  -> backYardDoor "backdoor"
    with  name 'back' 'door' 'backdoor' 'light',
          before [;
              Climb:
                  "You're supposed to enter it.";
              Close:
                  "You don't need to do that.";
              Enter, Go:
                  self.doorIsOpen = true;
                  PlayerTo(kitchenHouse);
                  rtrue;
              Open:
                  print "You open the door entering the house.^";
                  self.doorIsOpen = true;
                  PlayerTo(kitchenHouse);
                  rtrue;
              Examine, Search:
                  if (self.doorIsOpen) "The backdoor to the house is open, light from the inside spilling out.";
                  "The backdoor to the house is ajar, light from the inside spilling out.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The house is falling apart. You don't need to help it.";
              Knock:
                  "You knock on it, trying to get someone's attention, but no one answers the door.";
          ],
          doorIsOpen false,
     has  concealed static openable ~open;

! 12/19/16

  OutRch  -> backYardBowlingAlley "bowling alley"
    with  name 'bowling' 'alley' 'lowry' 'lanes' 'lot' 'dumpster' 'wall' 'backlot',
          before [;
              Enter, Go:
                  if (basement.firstTime) "There's something about this building. You can't explain it. The thing has a hold on you, drawing you inside.";
                  PlayerTo(backLot);
                  rtrue;
              Examine:
                  "The backlot to the bowling alley is empty. Only a dumpster sits up against the wall.";
          ];

! 10/26/18

  Object  -> backyardWindows "windows"
    with  name 'window' 'windows' 'boarded' 'boarded-up',
          before [;
              Close:
                  "They are. Boards are in place.";
              Enter:
                  "Try using the door. There are boards in place.";
              Examine, Search:
                  "All the windows are covered - boards now in place. It looks like the house was left to rot after the depression.";
              Take, Remove, PushDir, Push, Pull:
                  "You can't get to the windows. They're covered with boards.";
              Open:
                  "You can't. Boards are in place.";
          ],
     has  concealed static openable ~open pluralname;

! 10/26/18

  Object  -> backYardBoards "boards"
    with  name 'board' 'boards',
          before [;
              Examine, Search:
                  "Boards cover the windows, arranged in random order and made out of different types of wood.";
              Take, Remove, Pull:
                  "You tug on them for a bit, but flesh gives way to wood. They won't budge.";
              PushDir, Push:
                  "You try to push them, but they won't budge.";
          ],
     has  concealed static pluralname;
