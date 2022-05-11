
! ---------------------------------------------------------------------------- !
!       MAPLE ROAD. 06/02/19
!
  Room    mapleRoad "Maple Road"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  mapleRoadTom.helpTom = true;
                  remove gasStationScientist;
                  StartDaemon(mapleRoadTom);
                  if (gravelRoadScientist in gravelRoad) remove gravelRoadScientist;
                  iRoom++;
              }
              SelfPlayer.outside = true;
              if (currentTime()) {
                  print "Maple Road runs east to west with a 24-hour diner attached to the south.
                  To the east is the town post office. West a poorly kept dirt road will take you
                  to the bowling alley";
                  if (self.tomTalked) {
                      self.tomTalked = false;
                      ".^^Tom is standing outside the diner and freaking out. He stops you in the street,
                      ~Hey, I... I just saw some lights in the sky. Something is going on. You know.
                      The government covers that stuff up. It has to be a UFO.~";
                  }
                  if (mapleRoadTom in self) ".^^A guy paces back and forth in the street, looking up at the sky now and then.";
                  ".";
              }
              print "Maple Road comes to a bit of a fork here with the town post office to the east.
              A poorly kept dirt road is west. A shortcut through a field is north, and a worn path cuts
              through the tree line to the northeast";
              if (self.seenInPast) {
                  self.seenInPast = false;
                  ".^^There is no diner to the south - only an empty lot. There must not have been one in the past.";
              }
              ".";
          ],
          n_to [;
              <<Enter mapleRoadField>>;
          ],
          s_to [;
              if (currentTime()) <<Enter mapleRoadDiner>>;
          ],
          e_to [;
              <<Enter mapleRoadPostOffice>>;
          ],
          ne_to [;
              <<Enter mapleRoadJunkYard>>;
          ],
          nw_to [;
              if (mapleRoadTom in mapleRoad) return CalmTom();
              if (basement.firstTime) "You can follow the road east or west.";
              "The brush is pretty thick. If you want to take the shortcut, go north.";
          ],
          w_to [;
              <<Enter mapleRoadDirtRoad>>;
          ],
          cant_go [;
              if (mapleRoadTom in self) "You can follow the road east or west.";
              if (basement.firstTime) "You can follow the road east or west.";
              "You can follow the road east or west - head north or northeast.";
          ],
          before [;
              GoIn:
                  if (currentTime()) <<Enter mapleRoadDiner>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (rustyGate.dogBarking) "The peaceful drone is gone replaced by the loud sound of a barking dog.";
                  if (mapleRoadTom in mapleRoad) "Except for Tom's pacing, you can still hear a peaceful drone come from the city around you.";
                  "A peaceful drone comes from the city around you. Other than that, it's quiet.";
              Smell:
                  return PYT();
              Sorry:
                  if (mapleRoadTom in mapleRoad) <<Answer t_sorry mapleRoadTom>>;
              Wave:

              Yes:
                  if (mapleRoadTom in mapleRoad) <<Answer t_yes mapleRoadTom>>;
              No:
                  if (mapleRoadTom in mapleRoad) <<Answer t_no mapleRoadTom>>;
              Sleep:
                  return roomSleep();
          ],
          seenInPast true,
          firstTime true,
          tomTalked true,
          tomGone false,
          exploredTown false;

  [ CalmTom;
        if (mapleRoad.exploredTown) "Tom looks like he's going to have a heart attack. Maybe you should calm him down first.";
        "Tom looks like he's going to have a heart attack. You need to calm him down first. Maybe you should explore the town.";
  ];

! 08/10/16

  RoomObj -> mapleRoadObj "Maple Road"
    with  name 'maple' 'gravel' 'road' 'area' 'street' 'crossroad' 'crossroads',
          description [;
              <<Look mapleRoad>>;
          ],
          before [;
              Search:
                  "You look around the street, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  proper;

! 08/10/16

  OutRch  -> mapleRoadField "field"
    with  name 'field' 'grass' 'shortcut' 'trail' 'bush' 'shrub' 'bushes' 'shrubs',
          before [;
              Enter, Go:
                  if (mapleRoadTom in mapleRoad) return CalmTom();
                  if (currentTime()) "Thick grass grows through bushes and shrubs making it impassable. You can follow the road east or west.";
                  openFieldPath.followSouth = false;
                  PlayerTo(openField);
                  rtrue;
              Examine:
                  if (currentTime()) "Thick grass grows through bushes and shrubs making it impassable.";
                  "A trail has been cut through the grass, creating a shortcut that leads north.";
          ];

! 08/10/16

  OutRch  -> mapleRoadPostOffice "post office"
    with  name 'post' 'office' 'ph42' 'building' 'city' 'city^s' 'ph83729' 'city?s',
          before [;
              Enter, Go:
                  PlayerTo(outsidePostOffice);
                  rtrue;
              Examine:
                  if (currentTime()) "The post office has seen better days - the kids in the area spray painting graffiti all over it.";
                  "The post office sits where Maple Road meets up with Main Street.";
          ];

! 06/13/20

  ORchGr  -> mapleRoadGraffiti "graffiti"
    with  name 'graffiti' 'tag' 'tags' 'name' 'names' 'colorful' 'mess',
          before [;
              Go, Enter:
                  <<Enter mapleRoadPostOffice>>;
              Examine, Read:
                  "It's too hard to read from here. You only see a colorful mess.";
          ];

! 08/10/16

  OutRch  -> mapleRoadDiner "diner"
    with  name 'diner' 'restaurant' 'building' 'place' 'tinted' 'windows' 'window',
          before [;
              Enter, Go, Open:
                  if (mapleRoad.tomGone) "There's no need to follow Tom. You should head down to the bowling alley and find Sam.";
                  "Tom stops you, ~You don't want to go in there. They won't believe you about the UFOs.~";
              Examine:
                  "The diner is open 24 hours a day, but it looks a bit shady. It's hard to see into
                  the building with tinted windows that block the light.";
          ];

! 08/10/16

  OutRch  -> mapleRoadJunkYard "path"
    with  name 'worn' 'path' 'tree' 'trees' 'line',
          before [;
              Enter, Go, Follow:
                  if (mapleRoadTom in mapleRoad) return CalmTom();
                  if (currentTime()) {
                      "You can follow the road east or west.";
                  }
                  PlayerTo(rustyGate);
                  rtrue;
              Examine:
                  "A path has been cut through the tree line. Something heavy has gone on and off
                  the road at this point with the path shooting off towards the northeast.";
          ];

! 08/10/16

  OutRch  -> mapleRoadDirtRoad "dirt road"
    with  name 'dirt' 'road',
          before [;
              Enter, Go:
                  if (mapleRoadTom in mapleRoad) return CalmTom();
                  PlayerTo(dirtRoad);
                  rtrue;
              Examine:
                  if (mapleRoadTom in mapleRoad) "The dirt road is narrow and shoots north at the end.";
                  print "The dirt road is narrow and shoots north at the end. No one's on the road";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime) print " tonight";
                  ". It's kind of peaceful out here.";
          ];

! 08/15/19

  Object  -> mapleRoadGlasses "glasses"
    with  name 'glasses',
          before [;
              Enter, Go:
                  "You're already here.";
              Examine, Search:
                  "Big circular glasses cover Tom's face. Thick like Coke bottles, you're surprised he can see.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "~What do you think you're doing,~ Tom says, pushing you back.";
          ],
    has   concealed static pluralname;

! 08/18/19

  OutRch  -> mapleRoadStreetLight "street light"
    with  name 'ph005642' 'ph005643' 'ph005644' 'ph005645',
          before [;
              Enter, Go:
                  "You are already here.";
              Climb:
                  "Like a monkey, you think about shooting up the pole. But that's as far as you go.";
              Examine:
                  if (SelfPlayer.eveningTime || SelfPlayer.earlyEvening)
                      "The street light tries to cut through dusk. The sound created by neon softly filling the city.";
                  "The street light illuminates from overhead. The sound created by neon softly filling the city.";
          ];

Include "NPC_Tom";

! 06/10/20

  OutRch  mapleRoadEmptyLot "lot"
    with  name 'empty' 'lot' 'barren',
          before [;
              Enter, Go:
                  "There's nothing over there.";
              Examine:
                  "It's a barren lot where the diner once stood.";
          ];
