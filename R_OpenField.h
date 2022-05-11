
! ---------------------------------------------------------------------------- !
!       OPEN FIELD. 01/01/18
!
  Room    openField "Open Field"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              "Tall, uncut grass waves back and forth in the breeze as animals scurry through the thicket.
              A narrow path cuts through the field. You can take it south or head west to the
              backlot of the bowling alley.";
          ],
          w_to [;
              <<Enter openFieldAlley>>;
          ],
          s_to [;
              <<Enter openFieldPath>>;
          ],
          d_to [;
              <<Enter openFieldPath>>;
          ],
          cant_go [;
              "You can go south down the path or west to the backlot of the bowling alley.";
          ],
          before [;
              Exit:

              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "You can hear small rodents squabble and fight as they run through the thicket.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
          ],
          firstTime true;

! 01/01/18

  RoomObj -> openFieldObj "field"
    with  name 'field' 'area',
          description [;
              <<Look openField>>;
          ],
          before [;
              Search:
                  "You look around the field, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 01/01/18

  OutRch  -> openFieldAlley "bowling alley"
    with  name 'bowling' 'alley' 'back' 'lot',
          before [;
              Enter, Go:
                  print "You follow the path until it opens up to the backlot.^";
                  PlayerTo(backLot);
                  rtrue;
              Examine:
                  "The lot is empty, with no cars parked back there.";
          ];

! 01/01/18

  OutRch  -> openFieldPath "path"
    with  name 'trail' 'path' 'narrow',
          before [;
              Enter, Go, Take:
                  print "You follow the path walking through the field until you come out on the road.^";
                  PlayerTo(mapleRoad);
                  rtrue;
              Examine:
                  "The path cuts through the field to the south.";
              Follow:
                  if (self.followSouth) <<Enter self>>;
                  <<Enter openFieldAlley>>;
          ],
          followSouth false;

! 01/02/18

  OutRch  -> openFieldThicket "thicket"
    with  name 'thick' 'thicket' 'tall' 'grass' 'grassy' 'uncut',
          before [;
              Enter, Go, Search:
                  "It's too dense.";
              Examine:
                  "Uncut grass surrounds you, creating a thicket that's hard to walk through.";
          ];

! 01/12/19

  OutRch  -> openFieldAnimals "animals"
    with  name 'animal' 'animals' 'rodent' 'rodents',
          before [;
              Examine:
                  "You can't see any of them, but hear them fight amongst themselves in the thick grass.";
              default:
                  "You can't do that. You can't see them.";
          ],
    has   pluralname;
