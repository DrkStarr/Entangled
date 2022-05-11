
! ---------------------------------------------------------------------------- !
!       DIRT ROAD. 08/10/16
!
  Room    dirtRoad "Dirt Road"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  StopDaemon (gravelRoad);
                  iRoom++;
              }
              SelfPlayer.outside = true;
              "This lonely strip of road turns around a corner here. Maple Road connects at the east end
              while it wraps around meeting up with the bowling alley to the north.";
          ],
          n_to [;
              <<Enter dirtRoadBowlingAlley>>;
          ],
          e_to [;
              <<Enter dirtRoadGravelRoad>>;
          ],
          cant_go [;
              "The road comes to an end here, turning north to the bowling alley. East it heads back out to the city.";
          ],
          before [;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  print "A peaceful drone comes from the city around you";
                  if (rustyGate.dogBarking) ", but it's broken by the faint sound of a dog barking in the distance.";
                  ". Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
          ],
          firstTime true;

! 08/10/16

  RoomObj -> dirtRoadObj "dirt road"
    with  name 'dirt' 'road' 'area',
          description [;
              <<Look dirtRoad>>;
          ],
          before [;
              Search:
                  "You look through some dirt, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/10/16

  OutRch  -> dirtRoadGravelRoad "Maple Road"
    with  name 'maple' 'gravel' 'road' 'street',
          before [;
              Enter, Go:
                  PlayerTo(mapleRoad);
                  rtrue;
              Examine:
                  "Maple Road continues east into the town.";
          ],
     has  proper;

! 08/10/16

  OutRch  -> dirtRoadBowlingAlley "bowling alley"
    with  name 'bowling' 'alley' 'lowry' 'lanes' 'parking' 'lot' 'cars',
          before [;
              Enter, Go:
                  print "You walk up to the parking lot.^";
                  PlayerTo(parkingLot);
                  rtrue;
              Examine:
                  print "You can only see the parking lot from here. There doesn't seem to be a lot of cars,
                  but that doesn't mean anything. Lowry Lanes has a lot of foot traffic";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime) print " at night";
                  ".";
          ];
