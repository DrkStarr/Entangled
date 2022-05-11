
! ---------------------------------------------------------------------------- !
!       KITCHEN. 1/17/17
!
  Room    kitchenHouse "Kitchen"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = false;
              "Dust covers this room. The window above the sink is boarded up.
              The stove looks forgotten, but the refrigerator next to it is stained and used.
              The backdoor out of here is south, while an open doorway to a hallway lies north.";
          ],
          n_to [;
              <<Enter kitchenLivingRoom>>;
          ],
          s_to [;
              <<Enter kitchenHouseDoor>>;
          ],
          cant_go [;
              if (basement.firstTime) "There's something about this place. It's energy drawing you towards the hallway.";
              "You can go north to the hallway or south out the door.";
          ],
          before [;
              Exit:
                  <<Enter kitchenHouseDoor>>;
              GoIn:
                  <<Enter kitchenLivingRoom>>;
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

! 1/17/17

  RoomObj -> kitchenHouseObj "area"
    with  name 'room' 'area' 'kitchen' 'house' 'home' 'place',
          description [;
              <<Look kitchenHouse>>;
          ],
          before [;
              Search:
                  "You look around the room, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 1/17/17

  Object  -> kitchenHouseDoor "backdoor"
    with  name 'back' 'door' 'backdoor',
          before [;
              Close:
                  "You don't need to do that.";
              Enter, Go, Open:
                  if (basement.firstTime) "There's something about this place. It's energy drawing you towards the hallway.";
                  PlayerTo(backYard);
                  rtrue;
              Examine, Search:
                  "The backdoor to the house is open.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the house.";
              Knock:
                  if (basement.firstTime) "You knock on it, trying to get someone's attention, but no one enters the room.";
                  rfalse;
          ],
     has  concealed static openable ~open;

! 1/18/17

  OutRch  -> kitchenLivingRoom "hallway"
    with  name 'hallway' 'doorway' 'light',
          before [;
              Enter, Go:
                  PlayerTo(hallwayHouse);
                  rtrue;
              Examine:
                  print "Light is coming from the hallway";
                  if (basement.firstTime) " - a pulsating, living sort of thing.";
                  ".";
          ];

! 5/15/18

  Object  -> kitchenHouseRefrigerator "refrigerator"
    with  name 'refrigerator' 'fridge' 'ice' 'box' 'icebox' 'stain' 'stains' 'stained' 'cooler',
          before [;
              Close:
                  "That's already closed.";
              Enter:
                  "I think you know better.";
              Examine:
                  "The refrigerator has grease stains around the handle and it's off. The compressor isn't running.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The refrigerator doesn't need to go anywhere.";
              Search, Open:
                  if (self.openedFridge) "You've already looked in there. There's nothing of interest.";
                  self.openedFridge = true;
                  "Opening the refrigerator, you find some leftover Chinese food and an open beer bottle.
                  The fridge isn't cold and the stuff is warm. You close it leaving it all behind.";
              Rub:
                  "The stains are worn in. You don't have time for that.";
              SwitchOff:
                  "There's no power going to the refrigerator, but it's already off.";
              SwitchOn:
                  "There's no power going to the refrigerator. The compressor isn't working.";
              Fix:
                  "It's not broken. There's no power.";
          ],
          openedFridge false,
     has  concealed static openable open container;

! 5/15/18

  Object  -> kitchenHouseStove "stove"
    with  name 'stove' 'oven',
          before [;
              Blow:
                  <<Blow kitchenHouseDust>>;
              Close:
                  "That's already closed.";
              Enter:
                  "I think you know better.";
              Examine:
                  "The stove's covered in dust. Whoever squats here can't use it. The gas must be off.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The stove doesn't need to go anywhere.";
              Search, Open:
                  "You open the stove, finding little more than cobwebs. There's nothing useful, so you close the oven.";
              SwitchOff:
                  "That's already off.";
              SwitchOn:
                  "You try to turn it on, but the gas has been shut off.";
              Rub:
                  <<Rub kitchenHouseDust>>;
          ],
      has concealed static openable ~open;

! 5/15/18

  Object  -> kitchenHouseSink "sink"
    with  name 'sink' 'basin' 'faucet' 'water',
          before [;
              Examine, Search:
                  "The sink sits in the center of the west wall under a boarded-up window.";
              Take, Remove, PushDir, Push, Pull:
                  "The sink doesn't need to go anywhere.";
              SwitchOff:
                  "That's already off.";
              SwitchOn, Turn:
                  "You turn the faucet, but the pipes only shake. No water comes out.";
              Rub:
                  "If only there was some water.";
          ],
      has concealed static;

! 5/15/18

  Object  -> kitchenHouseWindow "window"
    with  name 'window' 'boarded' 'boarded-up',
          before [;
              Close:
                  "It is. Boards are in place.";
              Enter:
                  "Try using the door.";
              Examine, Search:
                  "The window has been boarded up since the house was deserted.";
              Take, Remove, PushDir, Push, Pull:
                  "You can't get to the window. It's covered with boards.";
              Open:
                  "You can't. Boards are in place.";
          ],
     has concealed static openable ~open;

 ! 5/15/18

   Object  -> kitchenHouseBoards "boards"
     with  name 'board' 'boards',
           before [;
               Examine, Search:
                   "Boards cover the window. A clear sign that the house has been abandoned.";
               Take, Remove, Pull:
                   "You tug on them for a bit, but flesh gives way to wood. They won't budge.";
               PushDir, Push:
                   "You try to push them, but they won't budge.";
           ],
      has  concealed static pluralname;

! 5/15/18

  OutRch  -> kitchenHouseDust "dust"
    with  name 'dust' 'lint',
          before [;
              Blow:
                  "Dust kicks up in the air only to settle, covering the stove once again.";
              SmellNoun:
                  "You try but sneeze, kicking up dust and spreading it through the house.";
              Examine:
                  "Dust covers the room. It hasn't been used in ages.";
              Take, Remove, Rub, PushDir, Push, Pull:
                  "The dust is thick. You'd only make a mess.";
          ];
