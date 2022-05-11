!
!

! ---------------------------------------------------------------------------- !
!       BUS STOP. 1/18/17
!
  Room    busStop "Bus Stop"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              print "Main Street runs east to west with a bus stop on the north side of the street. ";
              if (self.firstLook) {
                  self.firstLook = false;
                  print "You've waited there one too many mornings. ";
              }
              print "To the west is the library. East, the road continues until it eventually meets
              up with the highway";
              if (self.infoDump) {
                  self.infoDump = false;
                  ".^^... Sam moved into your trailer last month with his wife. Things have gone downhill ever since.
                  Your place is small enough as is, and having the two of them take over the living room
                  is wrong. You've gotten little sleep over the last month. It's starting to
                  hit you at work.";
              }
              ".";
          ],
          n_to [;
              <<Enter busStopBusStop>>;
          ],
          e_to [;
              <<Enter busStopRoad>>;
          ],
          w_to [;
              <<Enter busStopTown>>;
          ],
          cant_go [;
              "You can go east or west.";
          ],
          before [;
              GoIn:
                  <<Enter busStopBusStop>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
                    Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          infoDump true,
          firstLook false,
          firstTime true;

! 1/18/17

  RoomObj -> busStopObj "outside"
    with  name 'area' 'road',
          description [;
              <<Look busStop>>;
          ],
          before [;
              Search:
                  "You look around on the ground but find nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 1/18/17

  Object  -> busStopRoad "Main Street"
    with  name 'main' 'street',
          before [;
              Enter, Go:
                  PlayerTo(gravelRoad);
                  rtrue;
              Examine, Search:
                  "Main Street runs east to west.";
          ],
     has  proper concealed static;

! 1/18/17

  Object  -> busStopBusStop "stop"
    with  name 'stop' 'building' 'place' 'bench' 'awning' 'bus',
          before [;
              Enter:
                  if (basement.firstTime) "You need to get to the bowling alley, riding the bus won't help. It's route takes you to Springfield.";
                  "You need to get back, riding the bus won't help.";
              Examine, Search:
                  "No one is sitting under the awning even though the line runs all night.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "That doesn't need to go anywhere.";
          ],
      has concealed static;

! 05/24/17

  OutRch  -> busStopTown "town"
    with  name 'town' 'city' 'village' 'library' 'corner',
          before [;
              Enter, Go:
                  PlayerTo(outsideLibrary);
                  rtrue;
              Examine:
                  if (currentTime())
                      "The town is west, starting with the library on the next corner. It's tagged like others in this town.";
                  "The town is west, starting with the library on the next corner.";
          ];

! 10/09/19

  ORchGr  -> busStopGraffiti "graffiti"
    with  name  'graffiti' 'tag' 'tags' 'name' 'names' 'colorful' 'mess',
          before [;
              Go, Enter:
                  PlayerTo(outsideLibrary);
                  rtrue;
              Examine, Read:
                  "It's too hard to read from here. You only see a colorful mess.";
          ];
