! Needs OutRch Graffiti object for the town hall, plus OutRch GraffitiTags object for the post office
!
!

! ---------------------------------------------------------------------------- !
!       OUTSIDE TOWN HALL. 1/17/17
!
  Room    outsideTownHall "Main Street"
    with  description [;
              if (self.firstTime) {
                  iRoom++;
              }
              iHaveAny = 0;
              SelfPlayer.outside = true;
              print "Along the north side of the street, among some other buildings, sits the town hall. ";
              if (basement.firstTime) {
                  if (self.firstTime) {
                      self.firstTime = false;
                      print "Graffiti covers the building, but there have never been
                      any real gangs here. It's kids causing mischief. ";
                  }
              }
              if (self.firstLook) {
                  self.firstLook = false;
                  print "Graffiti used to cover this building too, but no longer. ";
              }
              if (basement.firstTime) {
                  print "Across from the town hall";
              } else {
                  print "Across from it";
              }
              print " is a small park to the south. Main Street runs east to west
              with the library on the east side and the post office on the west";
              if (dollarBill in self) {
                  move dollarBill to smallPark;
                  print ".^^The wind picks up a dollar bill sitting in the middle of the street, blowing it south";
              }
              ".";
          ],
          e_to [;
              <<Enter outsideTownHallLibrary>>;
          ],
          w_to [;
              <<Enter outsideTownHallPostOffice>>;
          ],
          s_to [;
              <<Enter outsideTownHallPark>>;
          ],
          n_to [;
              <<Enter outsideTownHallTownHall>>;
          ],
          cant_go [;
              "You can head east to the library, west to the post office, or south to the park.";
          ],
          before [;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  print "A peaceful drone comes from the city around you";
                  if (rustyGate.dogBarking) ", but it's broken by a dog barking in the distance.";
                  ". Other than that, it's quiet.";
              Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          infoDump true,
          firstLook false,
          firstTime true;

! 1/17/16

  RoomObj -> outsideTownHallObj "Main Street"
    with  name 'area' 'street' 'road' 'main',
          description [;
              <<Look outsidePostOffice>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 1/17/17

  Object  -> outsideTownHallTownHall "town hall"
    with  name 'town' 'hall' 'building' 'place' 'shade' 'shades',
          before [;
              Enter, Go:
                  if (basement.firstTime)
                      "The town hall is closed and probably won't be open tomorrow. The city doesn't work that hard.";
                  "The town hall is closed by the looks of it. The lights are off and the shades are drawn.";
              Examine, Search:
                  if (basement.firstTime)
                      "This building suffers from the kids' abuse the worst. The village tries to keep
                      it clean, but the punks just come back and paint over it.";
                  "The hall's cleaned up with new brick covering the exterior. It also looks closed with the lights off and shades drawn.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Open, Unlock:
                  if (second == shedKey) "You know better than to try.";
                  "You don't have a set of keys. You're not getting in.";
          ],
      has concealed static;

! 1/17/17

  OutRch  -> outsideTownHallLibrary "library"
    with  name 'library' 'walkway' 'bench' 'benches',
          before [;
              Enter, Go:
                  PlayerTo(outsideLibrary);
                  rtrue;
              Examine:
                  if (basement.firstTime)
                      "The library is tagged with graffiti, and the walkway is lined with benches that are rotted through.";
                  "The library is set off the road and has a walkway lined with benches.";
          ];

! 1/17/17

  OutRch  -> outsideTownHallPostOffice "post office"
    with  name 'post' 'office' 'edifice',
          before [;
              Enter, Go:
                  PlayerTo(outsidePostOffice);
                  rtrue;
              Examine:
                  if (basement.firstTime)
                      "The post office is tagged like most buildings in this town.
                      Too bad it's an edifice made to last forever.";
                  "The post office is a landmark made from granite. An edifice made to last forever.";
          ];

! 2/16/17

  OutRch  -> outsideTownHallPark "park"
    with  name 'park' 'green' 'wall' 'shrub' 'shrubs',
          before [;
              Enter, Go:
                  print "You cross the street, entering the park.^";
                  PlayerTo(smallPark);
                  rtrue;
              Examine:
                  "A wall made from shrubs encloses the park that sits in the middle of the town.";
          ];

! 10/09/19

  ORchGr  -> outsideTownHallGraffiti "graffiti"
    with  name 'graffiti' 'tag' 'tags' 'name' 'names' 'stan' 'satan' 'colorful' 'mess',
          before [;
              Go, Enter:
                  "You are already here.";
              Examine:
                  "Some names are crudely painted on the building with one tag on top of another.";
              Read:
                  "The tag looks like it says, Stan. Or Satan? It's hard to tell.
                  The kid that drew it has no talent.";
              Rub:
                  return PBT();
          ];

! 3/30/20

  OutRch  -> outsideTownHallBuildings "buildings"
    with  name 'buildings' 'shop' 'shops',
          before [;
              Enter, Go:
                  "They're all closed.";
              Examine:
                  "Different shops lie on either side of the town hall, filling in the landscape with commerce.";
          ],
    has   pluralname;
