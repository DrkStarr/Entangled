
! ---------------------------------------------------------------------------- !
!       BACKLOT. 08/16/16
!
  Room    backLot "Backlot"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              print "This area opens up into the back parking lot. No cars are parked here since
              the alley gets mostly foot traffic. Further back to the northwest, a brick house sits on
              the property line. The backdoor into the place is south";
              if (basement.firstTime == false) print ". To the east is a shortcut through a field";
              ".^
              ^A dumpster sits along the wall of the bowling alley.";
          ],
          nw_to [;
              <<Enter backLotHouse>>;
          ],
          e_to [;
              if (basement.firstTime == false) <<Enter backLotField>>;
          ],
          s_to [;
              <<Enter backLotBowlingAlley>>;
          ],
          cant_go [;
              if (basement.firstTime) "The bowling alley lies south. Northwest is the brick house.";
              "The bowling alley lies south. East there's a short cut through the field, and northwest is the brick house.";
          ],
          before [;
              Exit:

              GoIn:
                  <<Enter backLotBowlingAlley>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  print "You take the rich autumn air into your lungs for a minute";
                  if (parkingLot.outOfAlley) ", glad to be out of the smoke.";
                  ".";
              Sleep:
                  return roomSleep();
          ],
          firstTime true;

! 08/16/16

  RoomObj -> backLotObj "paved lot"
    with  name 'backlot' 'paved' 'lot' 'area',
          description [;
              <<Look backLot>>;
          ],
          before [;
              Search:
                  "You look around the lot, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/16/16

  Object  -> backLotDumpster "dumpster"
    with  name 'garbage' 'dumpster' 'container' 'trash' 'bin' 'rust' 'rusted',
          before [;
              Climb:
                  "Where are you going to go? There's nothing useful on the roof.";
              Close:
                  "You don't need to do that.";
              Open:
                  "It's already open.";
              Empty:
                  if (self.bottleTaken) "That would take a long time. The dumpster is full.";
                  <<Search self>>;
              Enter, Go:
                  "Now that's just gross.";
              Examine:
                  "The rusted bin is open, giving workers easy access. You can't
                  help but think that some rodents might make their way in at night.";
              LookUnder:
                  "The dumpster sits on the ground. There's no way to look under it.";
              Search, Dig:
                  if (self.bottleTaken) "You push a few pieces of garbage around, but nothing looks promising.";
                  self.bottleTaken = true;
                  playerHands.handsStink = true;
                  move flask to player;
                  "Leaning into a pile of filth, you push some garbage out of the way, finding a metal flask.
                  Reaching down, you pick it out of the grime made of rot and grease. Doing your best, you
                  wipe it off. It feels like there's a bit of alcohol left behind.";
              SmellNoun:
                  "It's ripe and rotten, and hard to get close to without your stomach kicking up.";
              Take, Push, Pull, Remove, Turn, PushDir:
                  "The dumpster doesn't need to go anywhere.";
          ],
          bottleTaken false,
          takenBeforeBasement false,
     has  concealed static container open;

! 08/16/16

  Object  -> backLotBowlingAlley "bowling alley"
    with  name 'bowling' 'alley' 'building' 'back' 'door' 'backdoor' 'wall' 'walls',
          before [;
              Close:
                  "You don't work here. You should leave that alone.";
              Enter, Go, Open:
                  if (self.enterFirstTime) {
                      self.enterFirstTime = false;
                      print "Even though you enter through the backdoor, no one seems to care.^";
                  }
                  PlayerTo(bowlingAlley);
                  rtrue;
              Examine, Search:
                  "The bowling alley isn't as colorful back here. With no mural to decorate things, the wall is painted an off-white. A backdoor to the south leads into the building.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          enterFirstTime true,
     has  concealed static container open;

! 08/16/16

  OutRch  -> backLotPropertyLine "property line"
    with  name 'property' 'line' 'grass',
          before [;
              Examine:
                  "The bowling alley keeps their grass trimmed. The house is overgrown and unkept. The division is stark.";
          ];

! 08/16/16

  OutRch  -> backLotHouse "house"
    with  name 'brick' 'house' 'home' 'building',
          before [;
              Enter, Go:
                  parkingLot.outOfAlley = false;
                  PlayerTo(backYard);
                  rtrue;
              Examine:
                  "A beat-up house sits on the corner edge of the lot. An older building, it's something
                  from the depression era.";
          ],
          lookFirstTime true;

! 08/16/16

  OutRch  backLotField "field"
    with  name 'field' 'open' ' big' 'path' 'trail',
          before [;
              Enter, Go, Follow:
                  openFieldPath.followSouth = true;
                  PlayerTo(openField);
                  rtrue;
              Examine:
                  "The area is undeveloped with a big field that lies to the east. A path has been cut through it.";
          ];
