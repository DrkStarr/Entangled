! Needs OutRch outsideLibraryBenches object so the player can sit down on the rotten benches in 2020
!
!
!

! ---------------------------------------------------------------------------- !
!       OUTSIDE LIBRARY. 1/17/17
!
  Room    outsideLibrary
   with   short_name [;
             if (outsideLibraryBench.playerSit == false) {
                 print "Corner of Main & Midland";
                 rtrue;
             }
             print "Corner of Main & Midland ";
             style roman;
             print "(on the bench)";
             rtrue;
          ],
          description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              print "The library is set off Main Street, with an elementary school tucked behind it.
              Lined with benches, the walkway up to the library is covered with trees. Main Street
              runs east out of the city and west to the town hall. Midland Drive heads south to the
              convenience store";
              if (dollarBill in self) {
                  move dollarBill to outsideTownHall;
                  print ".^^The wind picks up a dollar bill sitting in the middle of the street, blowing it west";
              }
              ".";
          ],
          w_to [;
              <<Enter outsideLibraryTownHall>>;
          ],
          e_to [;
              <<Enter outsideLibraryBusStop>>;
          ],
          n_to [;
              <<Enter outsideLibraryLibrary>>;
          ],
          s_to [;
              <<Enter outsideLibraryStore>>;
          ],
          u_to [;
              if (outsideLibraryBench.playerSit) <<GetOff outsideLibraryBench>>;
          ],
          cant_go [;
              "You can head east to the bus stop, west to the town hall, or south to the convenience store.";
          ],
          before [;
              Exit:
                  if (outsideLibraryBench.playerSit) <<GetOff outsideLibraryBench>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  print "A peaceful drone comes from the city around you";
                  if (rustyGate.dogBarking) ", but it's broken by the faint sound of a dog barking in the distance.";
                  ". Other than that, it's quiet.";
              Smell:
                  return PYT();
              Wave:

              Sleep:
                  return roomSleep();
          ],
          firstLook true,
          firstTime true;

! 1/17/17

  RoomObj -> outsideLibraryObj "Main Street"
    with  name 'area' 'main' 'street' 'road',
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

  Object  -> outsideLibraryLibrary "library"
    with  name 'library' 'building' 'place' 'walkway',
          before [;
              Enter, Go:
                  if (currentTime()) "The last time you checked out a book was over a year ago. You don't want to show your face in there.";
                  "The library is closed.";
              Examine, Search:
                  if (currentTime())
                      "The library used to be taken care of, but the benches are decomposing, and the building's
                      tagged like others in this town.";
                  "This library has been well taken care of, the benches that line the walkway look new.
                  There is no garbage or graffiti in the area.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Open:
                  if (currentTime()) {
                      if (SelfPlayer.dayStart) rfalse;
                  }
                  "You don't have a set of keys. You're not getting in.";
              Unlock:
                  if (currentTime()) {
                      "The library is open, but they still don't want you inside.";
                  }
                  if (second == shedKey) "You know better than to try.";
                  "You don't have a set of keys. You're not getting in.";
          ],
     has  concealed static;

! 10/09/19
! ROT is PH40400

  Object  -> outsideLibraryBench "bench"
    with  name 'bench' 'benches' 'rot',
          before [;
              Enter, Go:
                  if (currentTime())
                      "They're rotten and wouldn't support your full weight.";
                  if (self.playerSit) "You are already sitting down.";
                  self.playerSit = true;
                  "You sit down, taking a load off for a minute.";
              Examine, Search:
                  if (currentTime())
                      "The benches are made of oak and are so neglected they're rotting away.";
                  "This library has been well taken care of, the benches that line the walkway look new.
                  There is no garbage or graffiti in the area.";
              GetOff:
                  if (self.playerSit) {
                      self.playerSit = false;
                      "Standing up, you get off the bench.";
                  }
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The bench doesn't need to go anywhere.";
              LookUnder:
                  if (self.playerSit) "Looking between your legs, you see there's nothing hidden beneath the bench.";
                  "There's nothing hidden beneath the bench.";
          ],
          playerSit false,
     has  concealed static;

! 1/17/17

  OutRch  -> outsideLibraryStore "store"
    with  name 'convenience' 'store' 'mart' 'shop' 'building',
          before [;
              Enter, Go:
                  if (outsideLibraryBench.playerSit) {
                      outsideLibraryBench.playerSit = false;
                      print "(first getting up off the bench)^";
                  }
                  PlayerTo(outsideStore);
                  rtrue;
              Examine:
                  if (currentTime())
                      "It's slow right now over at the convenience store. No one's coming or going,
                      but you're sure that'll change.";
                  print "No one is coming or going out of the convenience store";
                  if (self.lookAtFirstTime) {
                      self.lookAtFirstTime = false;
                      outsideComplexStore.lookAtFirstTime = false;
                      ". Strange. The mart is always busy.";
                  }
                  ".";
          ],
          lookAtFirstTime true;

! 1/17/17

  OutRch  -> outsideLibraryTownHall "town hall"
    with  name 'town' 'hall',
          before [;
              Enter, Go:
                  if (outsideLibraryBench.playerSit) {
                      outsideLibraryBench.playerSit = false;
                      print "(first getting up off the bench)^";
                  }
                  PlayerTo(outsideTownHall);
                  rtrue;
              Examine:
                  if (currentTime())
                      "The town hall is tagged with graffiti. The kids that wander this town seem to be out of hand.";
                  "The town hall's another building that was once covered in graffiti.
                  Cleaned up, people must take care of the area.";
          ];

! 9/28/17

  OutRch  -> outsideLibraryBusStop "bus stop"
    with  name 'bus' 'stop',
          before [;
              Enter, Go:
                  if (outsideLibraryBench.playerSit) {
                      outsideLibraryBench.playerSit = false;
                      print "(first getting up off the bench)^";
                  }
                  PlayerTo(busStop);
                  rtrue;
              Examine:
                  "The road out of the town heads east before meeting up with the highway.
                  There's a bus stop along the way.";
          ];

! 1/12/19

  OutRch  -> outsideLibrarySchool "elementary school"
    with  name 'elementary' 'school',
          before [;
              Enter, Go:
                  "The elementary school is closed.";
              Examine:
                  "The elementary school sits behind the library, but the kids have to be bused
                  out of town for middle and high school.";
              default:
                  "You can't do that. It's behind the library.";
          ];

! 7/05/19

  OutRch  -> outsideLibraryTree "tree"
    with  name 'tree' 'trees' 'oak' 'oaks',
          before [;
              Climb:
                  "You think about it for a minute, realizing it would be a waste of time.";
              Enter, Go:
                  "The library is closed.";
              Examine:
                  "Old gnarled oaks line the walkway up to the library.";
          ];

! 07/13/20

  ORchGr  -> outsideLibraryGraffiti "graffiti"
    with  name 'graffiti' 'tag' 'tags' 'name' 'names' 'colorful' 'mess',
          before [;
              Go, Enter:
                  "You are already here.";
              Examine:
                  "A fist coming straight at you is painted on the library with letters sketched in the knuckles.
                  Other names have been quickly spray-painted over trying to cover it up.";
              Read:
                  "The knuckles read DARK as the fist tries to break through the wall. But it's marred and disrespected as others have tried to cover it up with their own names.";
              Rub:
                  return PBT();
          ];

! 08/06/20

  ORchGr  -> outsideLibraryKnuckles "knuckles"
    with  name 'knuckle' 'knuckles' 'fist' 'letter' 'letters' 'sketch',
          before [;
              Go, Enter:
                  "You are already here.";
              Examine, Read:
                  "The knuckles read DARK as the fist tries to break through the wall. But it's marred and disrespected as others have tried to cover it up with their own names.";
              Rub:
                  return PBT();
          ];
