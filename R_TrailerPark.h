! The place is a little neater than you''ve seen it before, but a lawn mower has been left out.
!

! ---------------------------------------------------------------------------- !
!       TRAILER PARK. 2/16/17
!
  Room    trailerPark "Sunnybrook Trailer Park"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              "Rectangular structures made of aluminum and wood form
              mobile-homes that never move. A few picnic tables are out. A shed
              sits on the edge of the property. The sign out in front of it all
              displays the park's name, and a path runs north by the cliff.";
          ],
          n_to [;
              <<Enter trailerParkCliff>>;
          ],
          w_to [;
              <<Enter trailerParkShed>>;
          ],
          s_to [;
              <<Enter trailerParkHome>>;
          ],
          cant_go [;
              if (trailerParkShed.hasUnlocked) "You can go north to the cliff or west into the shed.";
              "You can go north to the cliff.";
          ],
          before [;
              GoIn:
                  if (trailerParkShed.hasUnlocked) <<Enter trailerParkShed>>;
                  <<Enter trailerParkTrailers>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "It's quiet back here. There doesn't seem to be anybody around.";
              Smell:
                  return PYT();
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          pastFirstTime true;

! 02/16/17

  RoomObj -> trailerParkObj "trailer park"
    with  name 'trailer' 'park' 'area' 'lot' 'property' 'edge' 'yard',
          description [;
              <<Look trailerPark>>;
          ],
          before [;
              Enter, Go:
                  <<Enter trailerParkTrailers>>;
              Search:
                  "It would take too long to search the area properly. Looking down at your feet, you
                  don't see anything out of the ordinary.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 02/16/17

  OutRch  -> trailerParkCliff "cliff"
    with  name 'cliff' 'path' 'trail',
          before [;
              Enter, Go, Follow:
                  PlayerTo(cliff);
                  rtrue;
              Examine:
                  "The cliff runs along the edge of the trailer park.";
          ];

! 05/14/17

  Object  -> trailerParkSign "sign"
    with  name 'sign',
          before [;
              Examine, Search:
                  "In big white letters written across a dark brown background, the sign reads, Sunnybrook Trailer Park.";
              Climb:
                  "It's not that tall - about five feet. You're not going to get anywhere climbing it.";
              LookUnder:
                  "There is a bit of an underside to the sign. It's thick and sitting on two posts. But nothing is attached to it.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The sign doesn't need to go anywhere.";
          ],
     has  concealed static;

! 02/02/18

  Object  -> trailerParkShed "shed"
    with  name 'shed' 'door' 'white' 'paint',
          before [;
              Knock:
                  "It's just a shed. No one is inside.";
              Close:
                  if (self.hasOpen) "You don't need to do that.";
                  "That's already closed.";
              Enter, Go:
                  if (self.hasUnlocked) {
                      if (self.hasOpen == false) {
                          self.hasOpen = true;
                          print "(first opening the shed door)^";
                      }
                      PlayerTo(shed);
                      rtrue;
                  }
                  if (shedKey in player) {
                      if (self.hasUnlocked == false) {
                          self.hasUnlocked = true;
                          self.hasOpen = true;
                          print "(first unlocking the shed door)^";
                          PlayerTo(shed);
                          rtrue;
                      }
                  }
                  "You try the shed door. It's locked.";
              Examine:
                  print "The old, dilapidated shed has a fresh coat of white paint. Rocks form the landscaping around it";
                  if (self.notSeen) {
                      self.notSeen = false;
                      ". Back in your time, Old Johnson used to keep the key hidden around here.";
                  }
                  ".";
              Search:
                  <<Search trailerParkHill>>;
              Lock:
                  if (self.hasUnlocked) "You don't need to do that.";
                  "That's already locked.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Open:
                  if (self.hasOpen) "That's already open.";
                  if (self.hasUnlocked) {
                      self.hasOpen = true;
                      "You open the shed.";
                  }
                  if (shedKey in player) {
                      if (self.hasUnlocked == false) {
                          self.hasUnlocked = true;
                          self.hasOpen = true;
                          print "(first unlocking the shed door)^";
                          "You open the shed.";
                      }
                  }
                  "That won't work. You need the key.";
              Unlock:
                  if (self.hasUnlocked) "That's already unlocked.";
                  if (second == shedKey) {
                      self.hasUnlocked = true;
                      "Using the key, you unlock the door to the shed.";
                  }
                  "That won't work. You need the key.";
          ],
          notSeen true,
          hasUnlocked false,
          hasOpen false,
     has  concealed static;

! 02/02/18

  Object  -> trailerParkRockFormation "rocks"
    with  name 'rock' 'rocks' 'formation' 'landscaping' 'landscape',
          before [;
              Examine:
                  "A few rocks decorate the area around the shed. A cheap attempt at landscaping.";
              Take, Remove, LookUnder, PushDir, Push, Pull, Search, Turn:
                  if (self.foundKey) "You push around a rock or two, but find nothing else.";
                  self.foundKey = true;
                  trailerParkShed.notSeen = false;
                  move shedKey to player;
                  "You push one of the rocks out of the way, finding a key underneath it. You try to brush away some of the dirt before taking it.";
          ],
          foundKey false,
     has  concealed pluralname static;

! 02/02/18

  Object  -> trailerParkHill "hill"
    with  name 'landscaped' 'swell' 'mound' 'hill',
          before [;
              Examine:
                  "A landscaped mound swells underneath a shed that sits on the edge of the lot. There are rocks placed around it.";
              Search:
                  "You search around the hill for a minute but only see the rocks.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  concealed static;

! 05/07/18

  OutRch  -> trailerParkHome "home"
    with  name 'home',
          before [;
              Knock:
                  "You think about it. But what if you run into yourself.";
              Enter, Go:
                  "At this point you doubt that's even your home.";
              Examine:
                  "Your trailer should be the one in the back, but there's no birdbath in front of it.";
          ];

! 01/13/19

  OutRch  -> trailerParkTables "tables"
    with  name 'table' 'tables' 'picnic',
          before [;
              Enter, Go:
                  <<Enter trailerParkTrailers>>;
              Examine, Search:
                  "Picnic tables are out between the trailers and scattered across the lot all the way to the shed.";
              LookUnder:
                  "Looking under the nearest one, you find nothing of interest. And as you scan the yard, it doesn't look like anything has been left out.";
          ],
    has   pluralname;

! 01/13/19

  OutRch  -> trailerParkTrailers "trailers"
    with  name 'trailers' 'homes' 'mobile',
          before [;
              Knock:
                  "You think about it. But who knows who would answer.";
              Enter, Go:
                  "This place looks different. You don't know anybody who lives in the trailers.";
              Examine, Search:
                  "The trailers are almost identical, right down to the fake plastic siding. Some of them are colored differently, and everything looks new.";
          ],
    has   pluralname;
